/*
 * ILE stored procedure interface PASE libdb400.a->SQL400Json
 */
#include <miptrnam.h>
#include <mih/rslvsp.h>
#include <mih/miobjtyp.h>
#include <leawi.h>
#include <qleawi.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <qtqiconv.h>
#include <qp2user.h>
#include <except.h>
#include <qmhchgem.h>
#include <qmhrcvpm.h>
#include <qmhsndm.h>
#include "../PaseTool.h"
#include "iconf.h" /* see Makefile */
#include "ibyref.h" /* see gen.py */

#define ILEPROC "DB2USER"
#define ILEFUNC "UserCallSrvPgm"
#define ILEFUNCSIZE 14
#define ILEPGM "UserCallPgm"
#define ILEPGMSIZE 11

bighole_t iCallSrvPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, int * isDone)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000_t)();
  os_fct_000_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  char * userPgm = ILEPROC;
  char * userLib = ILELIB;
  char * userFunc = ILEFUNC;
  int userLenFunc = ILEFUNCSIZE;
  int i = 0;
  char pattern[ILE_PGM_MAX_ARGS+1];
  /* load user handle by val call module */
  os_pgm_ptr = rslvsp(WLI_SRVPGM, userPgm, userLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &userLenFunc, userFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  /* srvprm pattern */
  memset(pattern,0,sizeof(pattern));
  for (i=0; i < layout->parmc; i++) {
    if (layout->arg_by[i] == ILE_PGM_BY_VALUE) {
      switch(layout->arg_len[i]) {
      case 1:
        pattern[i] = '1';
        break;
      case 2:
        pattern[i] = '2';
        break;
      case 3:
        pattern[i] = '3';
        break;
      case 4:
        pattern[i] = '4';
        break;
      case 5:
        pattern[i] = '5';
        break;
      case 6:
        pattern[i] = '6';
        break;
      case 7:
        pattern[i] = '7';
        break;
      case 8:
        pattern[i] = '8';
        break;
      case 9:
        pattern[i] = '9';
        break;
      case 10:
        pattern[i] = 'A';
        break;
      case 11:
        pattern[i] = 'B';
        break;
      case 12:
        pattern[i] = 'C';
        break;
      case 13:
        pattern[i] = 'D';
        break;
      case 14:
        pattern[i] = 'E';
        break;
      case 15:
        pattern[i] = 'F';
        break;
      case 16:
        pattern[i] = 'G';
        break;
      }
    } else {
      pattern[i] = '0';
    }
  }
  /* user handle (if wanted) */
  *isDone = 0;
  return os_fct_ptr(layout, myPgm, myLib, myFunc, lenFunc, pattern, isDone);

}

void iCallPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, int * isDone)
{
  void *os_pfct_ptr = NULL;
  typedef void (os_fct_000_t)();
  os_fct_000_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  char * userPgm = ILEPROC;
  char * userLib = ILELIB;
  char * userFunc = ILEPGM;
  int userLenFunc = ILEPGMSIZE;
  /* load user handle by val call module */
  os_pgm_ptr = rslvsp(WLI_SRVPGM, userPgm, userLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &userLenFunc, userFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  /* user handle (if wanted) */
  *isDone = 0;
  os_fct_ptr(layout, myPgm, myLib, isDone);

}

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

void iCall400(char * blob) 
{
  /* blob -> |4-byte length|pad|data...| */
  ile_pgm_call_t* layout = (ile_pgm_call_t*)blob;
  int argc = 0;
  int parmc = 0;
  int offset = 0;
  int by = 0;
  int lenPgm = 0;
  int lenLib = 0;
  int lenFunc = 0;
  int lenRet = 0;
  int isDone = 0;
  int isOneLen = 0;
  int one_len = 0;
  char * myPgm = NULL;
  char * myLib = NULL;
  char * myFunc = NULL;
  char * myLibl = "*LIBL";
  char * myRet = NULL;
  bighole_t bighole;
  int i = 0;
  char pattern[ILE_PGM_MAX_ARGS+1];
  int isRef = 1;

  /* hey adc debug */
  /* sleep(30); */
  if (layout->debug[0]) {
    iDebugMe(layout->debug);
  }
  layout->step = 1;

  /* set ILE addresses based memory spill location offset */
  for (argc=0; argc < ILE_PGM_MAX_ARGS; argc++) {
    if (argc < layout->argc) {
      /*  by reference */
      if (layout->argv_parm[argc] > -1) {
        /* ILE address parm location (skip by value slots) */
        parmc = layout->argv_parm[argc];
        offset = layout->arg_pos[parmc];
        /* set ILE address to data */
        layout->argv[argc] = (char *)layout + offset;
      } else {
        isRef = 0;
      }
    } else {
      layout->argv[argc] = NULL;
    }
  }
  layout->step = 2;

  /* resolve call  */
  myPgm = layout->pgm;
  myLib = layout->lib;
  myFunc = layout->func;
  lenPgm = strlen(myPgm);
  lenLib = strlen(myLib);
  if (!lenLib) {
    myLib = myLibl;
    lenLib = 5;
  }
  lenFunc = strlen(myFunc);
  layout->step = 3;

  if (!lenFunc) {
    /* high speed user handled */
    iCallPgm(layout, myPgm, myLib, &isDone);
    if (!isDone) {
      /* pgm call by ref */
      if (isRef) {
        if (layout->argc < 32) {
          iCallPgmByRefSub1(layout, myPgm, myLib);
        } else if (layout->argc < 64) {
          iCallPgmByRefSub2(layout, myPgm, myLib);
        } else if (layout->argc < 96) {
          iCallPgmByRefSub3(layout, myPgm, myLib);
        } else if (layout->argc < 128) {
          iCallPgmByRefSub4(layout, myPgm, myLib);
        } else if (layout->argc < 160) {
          iCallPgmByRefSub5(layout, myPgm, myLib);
        }
      }
    } /* pgm user handle (optional) */
  } else {
    /* high speed user handled */
    bighole = iCallSrvPgm(layout, myPgm, myLib, myFunc, lenFunc, &isDone);
    if (!isDone) {
      /* srvpgm call by ref */
      if (isRef) {
        if (layout->argc < 32) {
          bighole = iCallFctByRefSub1(layout, myPgm, myLib, myFunc, lenFunc);
        } else if (layout->argc < 64) {
          bighole = iCallFctByRefSub2(layout, myPgm, myLib, myFunc, lenFunc);
        } else if (layout->argc < 96) {
          bighole = iCallFctByRefSub3(layout, myPgm, myLib, myFunc, lenFunc);
        } else if (layout->argc < 128) {
          bighole = iCallFctByRefSub4(layout, myPgm, myLib, myFunc, lenFunc);
        } else if (layout->argc < 160) {
          bighole = iCallFctByRefSub5(layout, myPgm, myLib, myFunc, lenFunc);
        }
      /* srvpgm call by val */
      } else {
        /* single size by val defaults (QZRUCLSP(ish) style API) */
        memset(pattern,0,sizeof(pattern));
        for (i=0; i < layout->parmc; i++) {
          if (layout->arg_by[i] == ILE_PGM_BY_VALUE) {
            pattern[i] = '1';
            if (!one_len && layout->arg_len[i]) {
              one_len = layout->arg_len[i];
              isOneLen = 1;
            } else if (one_len != layout->arg_len[i]) {
              isOneLen = 0;
            }
          } else {
            pattern[i] = '0';
          }
        }
        /* high speed call one size value arguments */
        if (isOneLen && layout->argc < 9) {
          switch(layout->parmc) {
          case 1:
            bighole = iCallFctByValSub1(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 2:
            bighole = iCallFctByValSub2(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 3:
            bighole = iCallFctByValSub3(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 4:
            bighole = iCallFctByValSub4(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 5:
            bighole = iCallFctByValSub5(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 6:
            bighole = iCallFctByValSub6(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 7:
            bighole = iCallFctByValSub7(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          case 8:
            bighole = iCallFctByValSub8(layout, myPgm, myLib, myFunc, lenFunc, (char*)&pattern);
            break;
          default:
            break;
          }
        } else {
          /* no signature match, maybe use PASE _ILECALL for slow path (TBD)???*/
          memset(pattern,'1',8);
          bighole = iCallFctByValSub8(layout, "UNSUPPORT", "UNSUPPORT", "UNSUPPORT", 9, (char*)&pattern);
        }
      } /* ! isDone */
    } /* srvpgm user handle (optional) */
  }
  layout->step = 4;

  /* return aggregate? */
  if (layout->return_start && layout->return_start < layout->return_end) {
    myRet = (char *)layout + layout->return_start;
    lenRet = layout->return_end - layout->return_start;
    memcpy(myRet,(char *)&bighole,lenRet);
  }
  layout->step = 5;
}

