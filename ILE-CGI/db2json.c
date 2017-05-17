#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <qtqiconv.h>
#include <qp2user.h>
#include <except.h>
#include "iconf.h" /* see make_libdb400.sh */

#ifndef int16
#define int16 short
#endif
#ifndef uint16
#define uint16 unsigned short
#endif
#ifndef int32
#define int32 int
#endif
#ifndef uint32
#define uint32 unsigned int
#endif
#ifndef int64
#define int64 long long
#endif
#ifndef uint64
#define uint64 unsigned long long
#endif

#pragma convert(1208)
char * mri1208_header_json = "Content-type: application/json; charset=utf-8\n\n";
char * mri1208_json_error = "{\"ok\":false,\"reason\":\"%s\"}";
char * mri1208_error_pase_term = "SQL400Json call error, PASE terminating";
char * mri1208_error_pase_sql400json_call_error = "SQL400Json call error";
char * mri1208_error_pase_sql400json_not_found = "SQL400Json was not found in libdb400.a";

#pragma convert(37)
char * mri37_header_plain = "Content-type: text/plain\n\n";
char * mri37_json_error = "{\"ok\":false,\"reason\":\"%s\"}";
char * mri37_error_binary = "CGIConvMode BINARY required";

typedef struct PaseAlloc_t { 
  void * ilePtr; 
  uint64 pasePtr;
  int32 sz;
} PaseAlloc_t;
typedef struct JsonAlloc_t {
  int32 inhdbc; 
  uint32 injson; 
  int32 inlen; 
  uint32 outjson;
  int32 outlen; 
  int16 sig0;
  int16 sig1;
  int16 sig2;
  int16 sig3;
  int16 sig4;
  int32 ret;
} JsonAlloc_t;

#define DB2_ARG0_PGM "/usr/lib/start32"
#define DB2_ENV_PATH "PATH=/usr/bin"
#define DB2_ENV_LIBPATH "LIBPATH=/usr/lib"
#define DB2_ENV_ATTACH "PASE_THREAD_ATTACH=Y"
#define DB2_MAX_JSON_OUT 512000

/* paseDead reset */
uint64 sLibDB400;
void * SQL400Json;
int32 webPaseAllocFlag;
int32 jsonPaseAllocFlag;
PaseAlloc_t webPaseAlloc;
PaseAlloc_t jsonPaseAlloc;

extern int32 ap_unescape_url(void * value);

void paseDead(void) {
  sLibDB400 = 0;
  SQL400Json = NULL;
  webPaseAllocFlag = 0;
  jsonPaseAllocFlag = 0;
}

void paseAlive(void) {
  int * pErrnop = NULL;
  volatile int com_area = 0;
#pragma exception_handler(paseDead, com_area, 0, _C2_ALL, _CTLA_IGNORE)
  pErrnop = Qp2errnop();
  *pErrnop = 0;
#pragma disable_handler
}

void libdb400Pase32(void) {
  int rc = 0;
  char * pgm = DB2_ARG0_PGM;
  char * envp[] = {
    DB2_ENV_PATH, 
    DB2_ENV_LIBPATH, 
    DB2_ENV_ATTACH, 
    /* DB2_ENV_TRACE, */
    NULL
    };
  char * argv[] = {
    DB2_ARG0_PGM, 
    NULL
    };
  char * apilib = DB2_FILE_LIBDB400;
  char * apiname = DB2_SYM_SQL400JSON;

  /* start PASE */
  if (sLibDB400 != 0 && SQL400Json != NULL) {
    paseAlive();
  }
  if (sLibDB400 == 0) {
    rc = Qp2RunPase(pgm,NULL,NULL,0,819,argv,envp);
    /* find libdb400.a(shr.o) */
    sLibDB400 = Qp2dlopen(apilib,QP2_RTLD_MEMBER|QP2_RTLD_NOW,0);
    /* find libdb400.a->SQL400Json*/
    SQL400Json = Qp2dlsym(sLibDB400,apiname,0,NULL);
  }
}

void header37 (void) {
  int len = 0;
  len = strlen(mri37_header_plain);
  write(1,mri37_header_plain,len);
}

void error37 (char * reason) {
  int len = 0;
  char talk37[4096];
  memset(talk37,0,sizeof(talk37));
  sprintf(talk37,mri37_json_error,reason);
  len = strlen(talk37);
  write(1,talk37,len);
}

void header1208(void) {
  int len = 0;
  len = strlen(mri1208_header_json);
  write(1,mri1208_header_json,len);
}

void error1208(char * reason) {
  int len = 0;
  char talk1208[4096];
  memset(talk1208,0,sizeof(talk1208));
  sprintf(talk1208,mri1208_json_error,reason);
  len = strlen(talk1208);
  write(1,talk1208,len);
} 

void * allocPaseBlock(int32 sz) {
  void * newIlePtr = NULL;
  uint64 newPasePtr = 0;
  /* allocate PASE memeory and clear */
  newIlePtr = webPaseAlloc.ilePtr;
  if (webPaseAllocFlag == 0
  || (sz > 0 && webPaseAlloc.sz < sz)) {
    if (webPaseAllocFlag > 0) {
      Qp2free(newIlePtr);
      newIlePtr = NULL;
    }
    newIlePtr = Qp2malloc(sz,&newPasePtr);
    webPaseAlloc.ilePtr = newIlePtr;
    webPaseAlloc.pasePtr = newPasePtr;
    webPaseAlloc.sz = sz;
    webPaseAllocFlag = 1;
  }
  if (webPaseAlloc.sz > 0) {
    memset(newIlePtr,0,webPaseAlloc.sz);
  }
  return newIlePtr;
}

void rmvPlus(char *where, int32 size) {
  int i = 0;
  int zero = 0;
  char c = ' ';  
  for (i=0; i < size; i++) {
    c = where[i];   
    if (c == 0x00 || zero) { 
      zero = 1;   
      where[i] = 0x00;
    /* junk "CR" */ 
    } else if (c == 0x0D) {
      where[i] = 0x20;   
    /* @ADC - may lead to errors (fix me) */
    /* junk "+"                           */  
    } else if (c == 0x2B) {
      where[i] = 0x20;   
    }   
  }      
}

void main() {
  int i = 0;
  int32 rc = 0;
  char * isBinary = "BINARY";
  char * isPost = "POST";
  char * cMode = NULL;
  char * cMethod = NULL;
  char * rCopy = NULL;
  void * pContent = NULL;
  int32 szContent = 0;
  int32 rTot = 0;
  void * newIlePtr = NULL;
  uint64 newPasePtr = 0;
  void * outPtr = NULL;
  int32 outLen = 0;
  int32 outSqlRc = 0;
  JsonAlloc_t jsonIleCall;

  /* re-open the stdin for the Persistent CGI Program */
  freopen("", "r", stdin);

  /* must CGIConvMode BINARY */
  cMode = getenv("CGI_MODE");
  if (!cMode || strcmp(cMode,isBinary) != 0) {
    header37();
    error37(mri37_error_binary);
    return;
  }

  /* header json */
  header1208();
  /* set-up pase (if needed) */
  libdb400Pase32();
  /* web request (json input) */
  cMethod = getenv("REQUEST_METHOD");
  /* POST method */
  if (strcmp(cMethod,isPost) == 0) {
    rCopy = getenv("CONTENT_LENGTH");
    szContent = atoi(rCopy);
    pContent = allocPaseBlock(szContent);
    if (szContent > 0) {
      /* read from stdin (Apache) */
      rTot = fread(pContent, 1, szContent, stdin);
    }
  /* GET method */
  } else {
    rCopy = getenv("QUERY_STRING");
    szContent= strlen(rCopy);
    pContent = allocPaseBlock(szContent);
    if (szContent > 0) {
      memcpy(pContent,rCopy,szContent);
    }
  }
  if (szContent > 0) {
    rc = ap_unescape_url(pContent);
    rmvPlus(pContent,szContent);
  }
  /* PASE path/libdb400.a->SQL400Json
   * (iconf.h - see make_libdb400.sh)
   * SQLRETURN SQL400Json(
   *   SQLCHAR * injson,
   *   SQLINTEGER inlen,
   *   SQLCHAR * outjson,
   *   SQLINTEGER outlen
   *   )
   */
  if (jsonPaseAllocFlag == 0 ) {
    newIlePtr = Qp2malloc(DB2_MAX_JSON_OUT,&newPasePtr);
    jsonPaseAlloc.ilePtr = newIlePtr;
    jsonPaseAlloc.pasePtr = newPasePtr;
    jsonPaseAlloc.sz = DB2_MAX_JSON_OUT;
    jsonPaseAllocFlag = 1;
  }
  jsonIleCall.inhdbc = 0;
  jsonIleCall.injson = webPaseAlloc.pasePtr;
  jsonIleCall.inlen = webPaseAlloc.sz;
  jsonIleCall.outjson = jsonPaseAlloc.pasePtr;
  jsonIleCall.outlen = jsonPaseAlloc.sz;
  jsonIleCall.sig0 = QP2_ARG_WORD;
  jsonIleCall.sig1 = QP2_ARG_PTR32;
  jsonIleCall.sig2 = QP2_ARG_WORD;
  jsonIleCall.sig3 = QP2_ARG_PTR32;
  jsonIleCall.sig4 = QP2_ARG_WORD;
  jsonIleCall.ret = QP2_RESULT_WORD;
  if (SQL400Json) {
    memset(jsonPaseAlloc.ilePtr,0,jsonPaseAlloc.sz);
    rc = Qp2CallPase(SQL400Json,
       &jsonIleCall.inhdbc,
       &jsonIleCall.sig0,
       jsonIleCall.ret,
       &outSqlRc);
    if (rc == QP2CALLPASE_NORMAL) {
      outPtr = jsonPaseAlloc.ilePtr;
      outLen = strlen(outPtr);
      write(1,outPtr,outLen);
    } else if (rc == QP2CALLPASE_TERMINATING) {
      error1208(mri1208_error_pase_term);
      sLibDB400 = 0;
      SQL400Json = NULL;
      jsonPaseAllocFlag = 0;
      webPaseAllocFlag = 0;
    } else {
      error1208(mri1208_error_pase_sql400json_call_error);
    }
  } else {
    error1208(mri1208_error_pase_sql400json_not_found);
  }
  /* flush stdout */
  fflush(stdout);
  return;
}


