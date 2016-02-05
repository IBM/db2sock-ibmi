#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
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
static pthread_mutex_t threadMutexLock = PTHREAD_MUTEX_INITIALIZER;

/* 
 * dlopen handle of PASE libdb400.a (real driver) 
 */
void *dlhandle = NULL;
/* 
 * ile activate db2 
 */
int db2_cli_srvpgm_mark;
/*
 * pase ccsid
 */
int db2_pase_ccsid;

/* global table lock
 * This lock is 'lock once'.
 * That is, not PTHREAD_MUTEX_RECURSIVE,
 * therefore do not call twice, will hang.
 */
void init_lock() {
  pthread_mutex_lock(&threadMutexLock);
}

void init_unlock() {
  pthread_mutex_unlock(&threadMutexLock);
}

/* 
 * dlopen handle of PASE libdb400.a
 * Note: dlhandle is checked twice,
 * second under global lock,
 * to avoid race conditions
 * multiple threads starting.
 */
void * init_cli_dlsym() {
  char *dlservice = PASECLIDRIVER;
  if (dlhandle  == NULL) {
    init_lock();
    if (dlhandle  == NULL) {
      dlhandle = dlopen(dlservice, RTLD_NOW|RTLD_MEMBER);
      if (dlhandle == NULL)  {
        printf("Service %s Not Found:  %s\n", dlservice, dlerror());
        exit(-1);
      }
    }
    init_unlock();
  }
  return dlhandle;
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
int init_CCSID400( int newCCSID ) {
  int paseMark = 0;
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
    init_unlock();
  }
  return db2_pase_ccsid;
}


/* caller hold resource level lock
 * init_table_ctor(hdbc,0)     -- opening a hdbc (connection)
 * init_table_ctor(hstmt,hdbc) -- map a stmt to a hdbc (connection)
 * These lock are resource level 'lock multiple', any thread.
 * That is, PTHREAD_MUTEX_RECURSIVE, therefore, same thread, 
 * may lock more than once. Other thread will block.
 * Remember to unlock same number times locked to avoid hangs.
 * (see init_table_lock to understand hstmt to hdbc map locks)
 */
void init_table_ctor(int hstmt, int hdbc) {
  init_lock();
  if (!IBMiTable[hstmt].hstmt) {
    pthread_mutexattr_init(&IBMiTable[hstmt].threadMutexAttr);
    pthread_mutexattr_settype(&IBMiTable[hstmt].threadMutexAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&IBMiTable[hstmt].threadMutexLock, &IBMiTable[hstmt].threadMutexAttr);
    IBMiTable[hstmt].in_progress = 0;
  }
  IBMiTable[hstmt].hstmt = hstmt;
  IBMiTable[hstmt].hdbc = hdbc;
  IBMiTable[hstmt].hKey = NULL;
  init_unlock();
}
void init_table_dtor(int hstmt) {
  /* do nothing, 
   * statement handles are unique
   * we only want init mutex ctor
   * once done, we have lock scope
   * either statment or connection
   */
  if (IBMiTable[hstmt].hKey) {
    init_lock();
    if (IBMiTable[hstmt].hKey) {
      free(IBMiTable[hstmt].hKey);
    IBMiTable[hstmt].hKey = (char *) NULL;
    }
    init_unlock();
  }
}
void * init_table_addr(int hstmt) {
  return (void *) &IBMiTable[hstmt];
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
void init_table_lock(int hstmt, int flag) {
  if (flag) {
    pthread_mutex_lock(&IBMiTable[IBMiTable[hstmt].hdbc].threadMutexLock);
    IBMiTable[IBMiTable[hstmt].hdbc].in_progress += 1;
  } else {
    pthread_mutex_lock(&IBMiTable[hstmt].threadMutexLock);
    IBMiTable[hstmt].in_progress += 1;
  }
}
void init_table_unlock(int hstmt,int flag) {
  if (flag) {
    pthread_mutex_unlock(&IBMiTable[IBMiTable[hstmt].hdbc].threadMutexLock);
    if (IBMiTable[hstmt].in_progress > 0) {
      IBMiTable[IBMiTable[hstmt].hdbc].in_progress -= 1;
    }
  } else {
    pthread_mutex_unlock(&IBMiTable[hstmt].threadMutexLock);
    if (IBMiTable[hstmt].in_progress > 0) {
      IBMiTable[hstmt].in_progress -= 1;
    }
  }
}
/* No lock.
 * Used other thread, see if time to join
 * work requested in child thread.
 * This is dicey, but false yes/no is
 * likely ok, when used as 'join'.
 */
int init_table_in_progress(int hstmt,int flag) {
  if (flag) {
    if (IBMiTable[IBMiTable[hstmt].hdbc].in_progress > 0) {
      return 1;
    }
  } else {
    if (IBMiTable[hstmt].in_progress > 0) {
      return 1;
    }
  }
  return 0;
}
/* No lock.
 * Used free resources.
 * This is dicey, but false yes/no is
 * likely ok, when used as 'free'.
 */
int init_table_stmt_2_conn(int hstmt) {
  return IBMiTable[hstmt].hdbc;
}

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
  switch(iswide){
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

char * init_hkey( char * db, char * uid, char * pwd, char * qual ) {
  return init_hkey_both((char *)db, (char *)uid, (char *)pwd, (char *)qual, 0);
}

char * init_hkey_W( unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual) {
  return init_hkey_both((char *)db, (char *)uid, (char *)pwd, (char *)qual, 1);
}


void init_table_add_hash(int hstmt, char * db, char * uid, char * pwd, char * qual, int flag) {
  char * hKey = init_hkey( db, uid, pwd, qual );
  if (flag) {
    IBMiTable[IBMiTable[hstmt].hdbc].hKey = hKey;
  } else {
    IBMiTable[hstmt].hKey = hKey;
  }
}
extern int init_table_hash_2_conn(char * db, char * uid, char * qual, char * pwd) {
  char * hKey = init_hkey( db, uid, pwd, qual );
  int i = 0;
  int len1 = strlen(hKey);
  int len2 = 0;
  for (i=0; i < PASECLIMAXRESOURCE; i++) {
    len2 = strlen(IBMiTable[i].hKey);
    if (len1 == len2) {
      if (!memcmp(IBMiTable[i].hKey, hKey, len1)) {
        return IBMiTable[i].hdbc;
      }
    }
  }
  free(hKey);
  return 0;
}
void init_table_add_hash_W(int hstmt, unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual, int flag) {
  char * hKey = init_hkey_W( db, uid, pwd, qual );
  if (flag) {
    IBMiTable[IBMiTable[hstmt].hdbc].hKey = hKey;
  } else {
    IBMiTable[hstmt].hKey = hKey;
  }
}
extern int init_table_hash_2_conn_W(unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual) {
  char * hKey = init_hkey_W( db, uid, pwd, qual );
  int i = 0;
  int len1 = custom_strlen_utf16((unsigned int *)hKey);
  int len2 = 0;
  for (i=0; i < PASECLIMAXRESOURCE; i++) {
    len2 = custom_strlen_utf16((unsigned int *)IBMiTable[i].hKey);
    if (len1 == len2) {
      if (!memcmp(IBMiTable[i].hKey, hKey, len1)) {
        return IBMiTable[i].hdbc;
      }
    }
  }
  free(hKey);
  return 0;
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



