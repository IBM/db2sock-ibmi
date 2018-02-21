#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <iconv.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"

/* static global resource table
 * Ok, big trick, IBM i db2 resources
 * are unique across all types 
 * henv, hdbc, hstmt, hdesc.
 * Yep-R-Doodle, db2 resources, one big old
 * process resource table with slots (IBMiTable).  
 */
PaseCliResource IBMiTable[PASECLIMAXRESOURCE]; 

/* global data lock (IBM i resources) */
pthread_once_t threadInitObject = PTHREAD_ONCE_INIT;
static pthread_mutex_t threadMutexLockLock = PTHREAD_MUTEX_INITIALIZER;
static int threadMutexLockFlag;
static pthread_mutex_t threadMutexLock;
pthread_mutexattr_t threadMutexAttr;
/*
 * conversion
 */
PaseConvResource IBMiCCSID[PASECLIMAXCCSID];

/* 
 * dlopen handle of PASE json parser
 */
void *dlhandle_json = NULL;
/* 
 * ile activate db2 
 */
int db2_cli_srvpgm_mark;
/*
 * pase ccsid
 */
int db2_pase_ccsid;
int db2_job_ccsid;

/*
 * pase cli trace
 */
char * db2_cli_trace;
char * db2_cli_dbx;
char * db2_cli_dbx_array[128];


/* global table lock
 */
void init_lock() {
  /* flag race condition */
  if (!threadMutexLockFlag) {
    pthread_mutex_lock(&threadMutexLockLock);
    if (!threadMutexLockFlag) {
      pthread_mutexattr_init(&threadMutexAttr);
      pthread_mutexattr_settype(&threadMutexAttr, PTHREAD_MUTEX_RECURSIVE);
      pthread_mutex_init(&threadMutexLock, &threadMutexAttr);
      threadMutexLockFlag = 1;
    }
    pthread_mutex_unlock(&threadMutexLockLock);
  }
  pthread_mutex_lock(&threadMutexLock);
}

void init_unlock() {
  pthread_mutex_unlock(&threadMutexLock);
}

/* ==========================
 * malloc/free
 * ==========================
 */
void * init_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void init_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
}

/*
 * conversion (not threadsafe)
 */
int custom_iconv_open(int myccsid, int utfccsid) {
  int i = 0;
  init_CCSID400( 0 );
  if (!myccsid) {
    myccsid = db2_pase_ccsid;
  }
  if (!myccsid || !utfccsid || myccsid == utfccsid) {
    return -1;
  }
  init_lock();
  for (i=0;i<PASECLIMAXCCSID;i++) {
    if (IBMiCCSID[i].cssid_Ascii == myccsid && IBMiCCSID[i].ccsid_Utf == utfccsid && !IBMiCCSID[i].in_progress) {
      init_unlock();
      return i;
    }
  }
  for (i=0;i<PASECLIMAXCCSID;i++) {
    if (!IBMiCCSID[i].cssid_Ascii) {
      IBMiCCSID[i].charset_Ascii = (char *) ccsidtocs(myccsid);
      IBMiCCSID[i].charset_Utf = (char *) ccsidtocs(utfccsid);
      IBMiCCSID[i].AsciiToUtf = iconv_open(IBMiCCSID[i].charset_Utf, IBMiCCSID[i].charset_Ascii);
      IBMiCCSID[i].UtfToAscii = iconv_open(IBMiCCSID[i].charset_Ascii, IBMiCCSID[i].charset_Utf);
      IBMiCCSID[i].cssid_Ascii = myccsid; /* hamela iconv speed up */
      IBMiCCSID[i].ccsid_Utf = utfccsid; /* hamela iconv speed up */
      pthread_mutexattr_init(&IBMiCCSID[i].threadMutexAttr);
      pthread_mutexattr_settype(&IBMiCCSID[i].threadMutexAttr, PTHREAD_MUTEX_RECURSIVE);
      pthread_mutex_init(&IBMiCCSID[i].threadMutexLock, &IBMiCCSID[i].threadMutexAttr);
      init_unlock();
      return i;
    }
  }
  init_unlock();
  return -1;
}
int custom_iconv(int isInput, char *fromBuffer, char *toBuffer, size_t sourceLen, size_t bufSize, int myccsid, int utfccsid) {
  int i = 0;
  int rc = 0;
  char *source = fromBuffer;
  char *target = toBuffer;
  size_t sourceBytesLeft = sourceLen;
  size_t targetBytesLeft = bufSize;
  /* clear buffer */
  memset(toBuffer,0,bufSize);
  /* get/open convert */
  i = custom_iconv_open(myccsid, utfccsid);
  if (i < 0 ) {
    return -1;
  }
  /* many same type converter running async */
  pthread_mutex_lock(&IBMiCCSID[i].threadMutexLock);
  IBMiCCSID[i].in_progress = 1;
  if (isInput) {
   rc = iconv(IBMiCCSID[i].AsciiToUtf, (char**)(&source), &sourceBytesLeft, &target, &targetBytesLeft);
  } else {
   rc = iconv(IBMiCCSID[i].UtfToAscii, (char**)(&source), &sourceBytesLeft, &target, &targetBytesLeft);
  }
  IBMiCCSID[i].in_progress = 0;
  pthread_mutex_unlock(&IBMiCCSID[i].threadMutexLock);

  return rc;
}
void custom_iconv_close(int myccsid, int utfccsid) {
  int i = 0;
  init_lock();
  for (i=0;i<PASECLIMAXCCSID;i++) {
    if (IBMiCCSID[i].cssid_Ascii == myccsid && IBMiCCSID[i].ccsid_Utf == utfccsid) {
      (void)iconv_close(IBMiCCSID[i].AsciiToUtf);
      (void)iconv_close(IBMiCCSID[i].UtfToAscii);
      IBMiCCSID[i].cssid_Ascii = 0;
      IBMiCCSID[i].ccsid_Utf = 0;
    }
  }
  init_unlock();
}

/* 
 * dlopen handle of PASE json parser
 * Note: dlhandle_json is checked twice,
 * second under global lock,
 * to avoid race conditions
 * multiple threads starting.
 */
void * init_json_dlsym() {
  char *dlservice = NULL;
  if (dlhandle_json  == NULL) {
    init_lock();
#ifdef __64BIT__
    dlservice = getenv(DB2JSONPARSER64_ENV_VAR);
    if (dlservice  == NULL) {
      dlservice = DB2JSONPARSER64;
    }
#else
    dlservice = getenv(DB2JSONPARSER32_ENV_VAR);
    if (dlservice  == NULL) {
      dlservice = DB2JSONPARSER32;
    }
#endif
    if (dlhandle_json  == NULL) {
      dlhandle_json = dlopen(dlservice, RTLD_NOW|RTLD_MEMBER);
      if (dlhandle_json == NULL)  {
        printf("Service %s Not Found:  %s\n", dlservice, dlerror());
        exit(-1);
      }
    }
    init_unlock();
  }
  return dlhandle_json;
}
/* activate db2 srvpgm */
int init_cli_srvpgm() {
  int actMark = 0;
  if (!db2_cli_srvpgm_mark) {
    init_lock();
    if (!db2_cli_srvpgm_mark) {
      actMark = _ILELOAD(DB2CLISRVPGM, ILELOAD_LIBOBJ);
      if (actMark < 0) {
        printf("Service %s Not Found\n", DB2CLISRVPGM);
        exit(-1);
      }
      db2_cli_srvpgm_mark = actMark;
    }
    init_unlock();
  }
  return db2_cli_srvpgm_mark;
}

int init_job_CCSID400() {
  int i = 0;
  int j = 0;
  int paseMark = 0;
  char * lastGood = NULL;
  if (!db2_job_ccsid) {
    init_lock();
    if (!db2_job_ccsid) {
      db2_job_ccsid = Qp2jobCCSID();
    }
    init_unlock();
  }
  return db2_job_ccsid;
}

int init_CCSID400( int newCCSID ) {
  int i = 0;
  int j = 0;
  int paseMark = 0;
  char * lastGood = NULL;
  if (!db2_pase_ccsid) {
    init_lock();
    if (!db2_pase_ccsid) {
      if (newCCSID) {
        paseMark = newCCSID;
      } else {
        paseMark = Qp2paseCCSID();
      }
      db2_pase_ccsid = paseMark;
    }
    // trace
    db2_cli_trace = getenv(DB2CLITRACE);
    db2_cli_dbx = getenv(DB2CLIDBX);
    db2_cli_dbx_array[0] = NULL;
    for (i=0,j=0;db2_cli_dbx[i]; i++) {
      switch (db2_cli_dbx[i]) {
      case ':':
        db2_cli_dbx[i] = 0x00;
        db2_cli_dbx_array[j] = lastGood;
        j++;
        db2_cli_dbx_array[j] = NULL;
        lastGood = NULL;
        break;
      case ' ':
        break;
      default:
        if (lastGood == NULL) {
          lastGood = (char *)&db2_cli_dbx[i];
        }
        break;
      }
    }
    if (lastGood != NULL) {
      db2_cli_dbx_array[j] = lastGood;
      j++;
      db2_cli_dbx_array[j] = NULL;
      lastGood = NULL;
    }
    init_unlock();
  }
  return db2_pase_ccsid;
}

int init_cli_trace() {
  if (db2_cli_trace) {
    if (db2_cli_trace[0] == 'o' && db2_cli_trace[1] == 'f') {
      return DB2CLITRACE_OFF;
    }
    if (db2_cli_trace[0] == 'o' && db2_cli_trace[1] == 'n') {
      return DB2CLITRACE_FILE;
    }
    if (db2_cli_trace[0] == 'w' || db2_cli_trace[0] == 'c') {
      return DB2CLITRACE_WS;
    }
    if (db2_cli_trace[0] == 's' && db2_cli_trace[1] == 't') {
      return DB2CLITRACE_FILE_STOP;
    }
    if (db2_cli_trace[0] == 'd' && db2_cli_trace[1] == 'b') {
      return DB2CLITRACE_FILE_DBX;
    }
    return DB2CLITRACE_FILE;
  }
  return DB2CLITRACE_OFF;
}

char ** init_cli_dbx() {
  return (char **)&db2_cli_dbx_array;
}


/* caller hold resource level lock
 * init_table_ctor(hdbc,hdbc)  -- opening a hdbc (connection)
 * init_table_ctor(hstmt,hdbc) -- map a stmt to a hdbc (connection)
 * These lock are resource level 'lock multiple', any thread.
 * That is, PTHREAD_MUTEX_RECURSIVE, therefore, same thread, 
 * may lock more than once. Other thread will block.
 * Remember to unlock same number times locked to avoid hangs.
 * (see init_table_lock to understand hstmt to hdbc map locks)
 */
void init_table_ctor(int handle, int hdbc) {
  // init_lock(); - lock in Alloc routine
  if (!IBMiTable[handle].hstmt && !IBMiTable[handle].thread_init) {
    pthread_mutexattr_init(&IBMiTable[handle].threadMutexAttr);
    pthread_mutexattr_settype(&IBMiTable[handle].threadMutexAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&IBMiTable[handle].threadMutexLock, &IBMiTable[handle].threadMutexAttr);
    IBMiTable[handle].thread_init = 1;
    IBMiTable[handle].in_progress = 0;
  }
  IBMiTable[handle].hstmt = handle;
  IBMiTable[handle].hdbc = hdbc;
  IBMiTable[handle].hKey = NULL;
  IBMiTable[handle].tid = 0;
  // init_unlock(); - lock in Alloc routine
}
/* DB2 free not thread safe
 */
void init_table_dtor(int handle) {
  int hstmt = 0;
  // init_lock(); - lock in Free routine
  if (IBMiTable[handle].hKey) {
    free(IBMiTable[handle].hKey);
  }
  IBMiTable[handle].hKey = (char *) NULL;
  // connection
  if (IBMiTable[handle].hdbc == IBMiTable[handle].hstmt) {
    // clear statements this hdbc (re-use)
    while (hstmt = init_table_find_stmt(IBMiTable[handle].hdbc)) {
      init_table_dtor(hstmt);
    }
  }
  IBMiTable[handle].hdbc = 0;
  IBMiTable[handle].hstmt = 0;
  IBMiTable[handle].in_progress = 0;
  IBMiTable[handle].use_flag = 0;
  IBMiTable[handle].use_size = 0;
  if (IBMiTable[handle].use_data) {
    init_free(IBMiTable[handle].use_data);
  }
  IBMiTable[handle].use_data = NULL;
  IBMiTable[handle].tid = 0;
  // init_unlock(); - lock in Free routine
}
void * init_table_addr(int handle) {
  return (void *) &IBMiTable[handle];
}
/*
 * find any hstmt associated with this hdbc
 * (connection lock assumed client)
 */
int init_table_find_stmt(int hdbc) {
  int i = 0;
  // any statements this hdbc
  for (i=0;i<PASECLIMAXRESOURCE;i++) {
    if (IBMiTable[i].hstmt > 0
    && IBMiTable[i].hdbc != IBMiTable[i].hstmt
    && IBMiTable[i].hdbc == hdbc) 
    {
      return IBMiTable[i].hstmt;
    }
  }
  return 0;
}
/*
 * find hdbc associated with this hstmt
 * (connection lock assumed client)
 */
int init_table_stmt_2_conn(int hstmt) {
  return IBMiTable[hstmt].hdbc;
}
/* hdbc and/or hstmt scope locks
 * flag = 0 -- lock hdbc (or hstmt, if we ever dare)
 * flag = 1 -- lock hdbc of hstmt (lock parent of statment)
 * 
 * Locking scope hdbc, obvious, aka, lock the connection
 * to one thread at a time usage. Mode typical most database driver 
 * scripting connection pools, aka, one thread<2>one connection (at a time).
 * (... pool says do not share 'resource' across threads)
 *  
 * Locking scope hstmt, currently, flag=1, is recommended
 * for safe hstmt-map2-hdbc connection locks (one statement at time).
 *
 * Future wild, reckless behaviour (Good morning Hal):
 *
 * Nobody (i know), ever tried multiple statement threads 
 * requesting on a single connection at the same time. 
 * However, flag=0, at hstmt level is possible with lock (gulp).
 */
void init_table_lock(int handle, int flag) {
  if (flag) {
    pthread_mutex_lock(&IBMiTable[IBMiTable[handle].hdbc].threadMutexLock);
    IBMiTable[IBMiTable[handle].hdbc].in_progress += 1;
    IBMiTable[IBMiTable[handle].hdbc].tid = pthread_self();
  } else {
    pthread_mutex_lock(&IBMiTable[handle].threadMutexLock);
    IBMiTable[handle].in_progress += 1;
    IBMiTable[handle].tid = pthread_self();
  }
}
void init_table_unlock(int handle,int flag) {
  if (flag) {
    if (IBMiTable[handle].in_progress > 0) {
      IBMiTable[IBMiTable[handle].hdbc].in_progress -= 1;
    }
    if (!IBMiTable[handle].in_progress) {
      IBMiTable[IBMiTable[handle].hdbc].tid = 0;
    }
    pthread_mutex_unlock(&IBMiTable[IBMiTable[handle].hdbc].threadMutexLock);
  } else {
    if (IBMiTable[handle].in_progress > 0) {
      IBMiTable[handle].in_progress -= 1;
    }
    if (!IBMiTable[handle].in_progress) {
      IBMiTable[handle].tid = 0;
    }
    pthread_mutex_unlock(&IBMiTable[handle].threadMutexLock);
  }
}
/* No lock.
 * Used other thread, see if time to join
 * work requested in child thread.
 * This is dicey, but false yes/no is
 * likely ok, when used as 'join'.
 */
int init_table_in_progress(pthread_t tid,int flag) {
  int i = 0;
  // any statements this hdbc
  for (i=0;i<PASECLIMAXRESOURCE;i++) {
    if (IBMiTable[i].tid == tid) 
    {
      return 1;
    }
  }
  return 0;
}

/* No lock.
 * handle -- hstmt
 */
void init_table_use_set(int handle, int usage) {
  IBMiTable[handle].use_flag = usage;
}
int init_table_use_flag(int handle) {
  return IBMiTable[handle].use_flag;
}
void * init_table_use_data(int handle) {
  return IBMiTable[handle].use_data;
}
void * init_table_use_data_new(int handle, int size, int nullterm) {
  char * tmp = NULL;
  int toldSz = 0;
  char * told = NULL;
  int tnewSz = 0;
  char * tnew = NULL;
  told = IBMiTable[handle].use_data;
  toldSz = IBMiTable[handle].use_size;
  if (!(size + nullterm)) {
    return told;
  }
  if (toldSz) {
    init_free(told);
  }
  tnewSz = toldSz + size;
  tnew = init_new(tnewSz + nullterm);
  return tnew;
}
void * init_table_use_data_copy_in(int handle, char *data, int size, int nullterm) {
  char * tmp = NULL;
  int toldSz = 0;
  char * told = NULL;
  int tnewSz = 0;
  char * tnew = NULL;
  told = IBMiTable[handle].use_data;
  toldSz = IBMiTable[handle].use_size;
  if (!(size + nullterm)) {
    return told;
  }
  tnewSz = toldSz + size;
  tnew = init_new(tnewSz + nullterm);
  if (toldSz) {
    memcpy(tnew, told, toldSz);
    init_free(told);
    tmp = tnew + toldSz;
  } else {
    tmp = tnew;
  }
  memcpy(tmp, data, size);
  IBMiTable[handle].use_data = tnew;
  IBMiTable[handle].use_size = tnewSz;
  return tnew;
}
int init_table_use_data_copy_out(int handle, char *data, int size, int nullterm) {
  int tmpSz = 0;
  char * tmp = NULL;
  tmp = IBMiTable[handle].use_data;
  tmpSz = IBMiTable[handle].use_size;
  if (!data || !size) {
    return -1;
  }
  if (!tmp || !tmpSz) {
    return 0;
  }
  if (size + nullterm > tmpSz) {
    memcpy(data, tmp, size - nullterm);
  } else {
    memcpy(data, tmp, tmpSz);
  }
  return 0;
}


/*
 * persistent connection
 */
char * init_hkey_both( char * db, char * uid, char * pwd, char * qual, short iswide) {
  int hKeyLen = 0;
  char *hKey = NULL;
  char * key = NULL;
  char key16[] = {0x00,0x5F,0x00,0x5F,0x00,0x64,0x00,0x98,0x00,0x32,0x00,0x5F,0x00,0x00}; /* _._.d.b.2._nil*/
  int key_len = 0;
  int db_len = 0;
  int uid_len = 0;
  int pwd_len = 0;
  int qual_len = 0;
  int null_len = 2;
  switch (iswide) {
  case 1:
    key = (char *)&key16;
    key_len = custom_strlen_utf16((unsigned int *)key);
    db_len = custom_strlen_utf16((unsigned int *)db);
    uid_len = custom_strlen_utf16((unsigned int *)uid);
    pwd_len = custom_strlen_utf16((unsigned int *)pwd);
    qual_len = custom_strlen_utf16((unsigned int *)qual);
    null_len = 2;
    break;
  default:
    key = "__db2_";
    key_len = strlen(key);
    db_len = strlen(db);
    uid_len = strlen(uid);
    pwd_len = strlen(pwd);
    qual_len = strlen(qual);
    null_len = 2;
    break;
  }
  hKeyLen = key_len + db_len + uid_len + pwd_len + qual_len + null_len;
  hKey = (char *) custom_alloc_zero(hKeyLen);
  memcpy(hKey,key,key_len);
  if (db_len) {
    memcpy(hKey+key_len,db,db_len);
  }
  if (uid_len) {
    memcpy(hKey+key_len+db_len,uid,uid_len);
  }
  if (pwd_len) {
    memcpy(hKey+key_len+db_len+uid_len,pwd,pwd_len);
  }
  if (qual_len) {
    memcpy(hKey+key_len+db_len+uid_len+pwd_len,qual,qual_len);
  }
  return hKey;
}

void init_table_add_hash_both(int handle, char * db, char * uid, char * pwd, char * qual, int flag, short iswide) {
  char * hKey = (char *) NULL;
  switch (iswide) {
  case 1:
    hKey = init_hkey_both((char *)db, (char *)uid, (char *)pwd, (char *)qual, 1);
    break;
  default:
    hKey = init_hkey_both((char *)db, (char *)uid, (char *)pwd, (char *)qual, 0);
    break;
  }
  init_lock();
  if (flag) {
    IBMiTable[IBMiTable[handle].hdbc].hKey = hKey;
  } else {
    IBMiTable[handle].hKey = hKey;
  }
  init_unlock();
}
void init_table_add_hash(int handle, char * db, char * uid, char * pwd, char * qual, int flag) {
  init_table_add_hash_both(handle, (char *)db, (char *)uid, (char *)pwd, (char *)qual, flag, 0);
}
void init_table_add_hash_W(int handle, unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual, int flag) {
  init_table_add_hash_both(handle, (char *)db, (char *)uid, (char *)pwd, (char *)qual, flag, 1);
}

int init_table_hash_2_conn_both(char * db, char * uid, char * pwd, char * qual, short iswide) {
  char * hKey = (char *)NULL;
  int i = 0;
  int len1 = 0;
  int len2 = 0;
  int retv_hdbc = 0;
  switch (iswide) {
  case 1:
    hKey = init_hkey_both((char *)db, (char *)uid, (char *)pwd, (char *)qual, 1);
    len1 = custom_strlen_utf16((unsigned int *)hKey);
    break;
  default:
    hKey = init_hkey_both((char *)db, (char *)uid, (char *)pwd, (char *)qual, 0);
    len1 = strlen((char *)hKey);
    break;
  }
  init_lock();
  for (i=0; i < PASECLIMAXRESOURCE; i++) {
    switch (iswide) {
    case 1:
      len2 = custom_strlen_utf16((unsigned int *)IBMiTable[i].hKey);
    default:
      len2 = strlen((char *)IBMiTable[i].hKey);
      break;
    }
    if (len1 == len2) {
      if (!memcmp(IBMiTable[i].hKey, hKey, len1)) {
        retv_hdbc = IBMiTable[i].hdbc;
        break;
      }
    }
  }
  init_unlock();
  free(hKey);
  return retv_hdbc;
}
int init_table_hash_2_conn(char * db, char * uid, char * pwd, char * qual) {
  return init_table_hash_2_conn_both( (char *) db, (char *) uid, (char *) pwd, (char *) qual, 0 );
}
int init_table_hash_2_conn_W(unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual) {
  return init_table_hash_2_conn_both( (char *) db, (char *) uid, (char *) pwd, (char *) qual, 1 );
}

int init_table_hash_active(int handle, int flag) {
  int active = 0;
  init_lock();
  if (IBMiTable[handle].hKey) {
    active = 1;
  }
  if (flag) {
    if (IBMiTable[IBMiTable[handle].hdbc].hKey){
      active = 1;
    }
  } else {
    if (IBMiTable[handle].hKey){
      active = 1;
    }
  }
  init_unlock();
  return active;
}


int custom_strlen_utf16(unsigned int * src) {
  int len = 0;
  char *tgt = (char *) src;
  while (*(unsigned short *)tgt) { 
    len++;
    tgt += 2;
  }
  return len;
}

void * custom_alloc_zero(int sz) {
  void * ibc = (char *) malloc(sz);
  memset(ibc,0,sz);
  return ibc;
}



