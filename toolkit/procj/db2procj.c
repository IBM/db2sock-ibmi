/*
 * ILE stored procedure interface db2procj(ILE)->libdb400.a->SQL400Json->..
 * Variant EBCDIC characters !#$@\[]^`{}|~
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include <sqlcli.h>
#include <except.h>
#include <qusec.h>
#include <qmhchgem.h>
#include <qmhrcvpm.h>
#include <qmhsndm.h>
#include "../parser-json/PaseJson.h"

#define OCCURS_CLOB_MAX 15000000


void iDebugMe(char * msg) {
  typedef struct qual_name_t
  {
    char  name[10];
    char  libr[10];
  } qual_name_t;
  typedef struct error_code_struct {
    Qus_EC_t   ec_fields;
    char       Exception_Data[100];
  } error_code_t;
  typedef struct msg_info_struct {
    Qmh_Rcvpm_RCVM0100_t   F;
    char                   V[1200];
  } msg_info_t;

  qual_name_t  MsgFile;
  char MsgId[7];
  char MsgText[512];
  int  MsgTextLen;
  char MsgType[10];
  qual_name_t MsgQList[1];
  int  NumMsgQ;
  qual_name_t RpyMsgQ;
  char MsgKey[4];

  error_code_t ErrorCode;

  msg_info_t MsgInfo;
  int  MsgInfoLen;
  char Format[8];
  char PgmMsgQ[10];
  int  PgmCount;
  int  WaitTime;
  char MsgAction[10];

  /* send message QSYSOPR */
  memcpy(MsgId,"       ",7);
  memcpy(MsgFile.name,"          ",10);
  memcpy(MsgFile.libr,"          ",10);
  strncpy(MsgText, msg, sizeof(MsgText));
  MsgTextLen = strlen(MsgText);
  memcpy(MsgQList[0].name,"*SYSOPR   ",10);
  memcpy(MsgQList[0].libr,"          ",10);
  NumMsgQ = 1;
  memcpy(MsgType,"*INQ      ",10);
  memcpy(MsgKey,"    ",4);
  memcpy(RpyMsgQ.name,"*PGMQ     ",10);
  memcpy(RpyMsgQ.libr,"          ",10);
  memcpy(ErrorCode.ec_fields.Exception_Id,"       ",7);
  ErrorCode.ec_fields.Bytes_Provided = 0;
  QMHSNDM( MsgId,
          &MsgFile,
           MsgText,
           MsgTextLen,
           MsgType,
          &MsgQList,
           NumMsgQ,
          &RpyMsgQ,
          &MsgKey,
          &ErrorCode);
  /* receive message */
  MsgInfoLen = sizeof(MsgInfo);
  memcpy(Format,"RCVM0100",8);
  memcpy(PgmMsgQ,"*         ",10);
  PgmCount = 0;
  memcpy(MsgType,"*RPY      ",10);
  WaitTime = 3600;
  memcpy(MsgKey,"    ",4);
  memcpy(MsgAction,"*REMOVE   ",10);
  QMHRCVPM(&MsgInfo,
            MsgInfoLen,
            Format,
            PgmMsgQ,
            PgmCount,
            MsgType,
            MsgKey,
            WaitTime,
            MsgAction,
           &ErrorCode);
}

void iDebugMeJson(char *clobData) {
  int lenDebug = 0;
  char * posDebug = NULL;
  char * posDebugEnd = NULL;
  char msg[100];
  /* debug me */
  posDebug = strstr(clobData,"\"debug\":\"");
  if (posDebug) {
    posDebug += 9;
    posDebugEnd = strstr(posDebug,"\"");
    memset(msg,0,sizeof(msg));
    lenDebug = posDebugEnd - posDebug;
    if (lenDebug < 1) {
      strcpy(msg, "debug db2procj");
    } else {
      if (lenDebug > sizeof(msg) - 1) {
        lenDebug = sizeof(msg) - 1;
      }
      strncpy(msg,posDebug,lenDebug);
    }
    iDebugMe(msg);
  }
}


int iJson400(char * clob) {
  /* clob -> |4-byte length|pad|data...| */
  char *clobData = NULL;
  int *clobPassLen = NULL;
  int clobLen = 0;
  char *outData = NULL;
  int outLen = 0;
  int i;
  int sqlrc = 0;
  int nest = 0;

  char sbang = ccsid_variant_bang();
  char spound = ccsid_variant_pound();
  char sdollar = ccsid_variant_dollar();
  char sat = ccsid_variant_at();
  char sbackslash = ccsid_variant_backslash();
  char sopen_brace = ccsid_variant_open_brace();
  char sclose_brace = ccsid_variant_close_brace();
  char scaret = ccsid_variant_caret();
  char sbacktick = ccsid_variant_backtick();
  char sopen_bracket = ccsid_variant_open_bracket();
  char sclose_bracket = ccsid_variant_close_bracket();
  char sbar = ccsid_variant_bar();
  char stilde = ccsid_variant_tilde();

  /* debug message? */
  iDebugMeJson((char *) clob + 4);
 
  /* clob -> |4-byte length|pad|data...| */
  clobPassLen = (int *) clob;
  clobLen = *clobPassLen;
  clobData = (char *) clob + 4;
  /* find true json size (db2 clob anomolies)) */
  for (i=0; i < clobLen; i++) {
    if (clobData[i] == sopen_bracket) { /* '{' */
      nest++;
    } else if (clobData[i] == sclose_bracket) { /* '}' */
      nest--;
      if (!nest) {
        break;
      }
    }
  }
  memset(clobData + i, 0, clobLen - i);
  clobLen = i + 1;

  outLen = OCCURS_CLOB_MAX;
  outData = (char *) malloc(outLen);
  memset(outData,0,outLen);

  sqlrc = custom_SQL400Json(0,
            clobData,
            clobLen, 
            outData,
            outLen);

  /* copy out */
  memset(clobData,0,clobLen);
  strcpy(clobData, outData);
  free(outData);

  return sqlrc;
}



