#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include <sqlcli.h>
#include "PaseType.h"
#else
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#include "PaseCliDev.h"
#include "PaseCliPrintf.h"
#endif
#include "proc/iconf.h" /* see proc/Makefile */
#include "PaseToIle.h"
#include "PaseToDmp.h"
#include "PaseTool.h"
#include "imemcall.h"


/*=================================================
 * toolkit memory call
 */
#ifndef __IBMC__
#define ROUND_QUAD(x) (((size_t)(x) + 0xf) & ~0xf)
/* load up in memory option */
SQLINTEGER iCall400PgmLoaded;
SQLCHAR iCall400PgmBuf[132];
typedef struct iCall400PgmIleCallStruct {ILEarglist_base base; ILEpointer blob; } iCall400PgmIleCallStruct;

#define ILEMEMCMD "/QSYS/QC2LE"
SQLINTEGER iCall400CmdLoaded;
SQLCHAR iCall400CmdBuf[132];
typedef struct iCall400CmdIleCallStruct {ILEarglist_base base; ILEpointer blob; int len; } iCall400CmdIleCallStruct;
#endif


/*=================================================
 * toolkit in memory option
 */

#ifdef __IBMC__
SQLRETURN iCall400Pgm(char * blob)
{
  iCall400(blob);
  return SQL_SUCCESS;
}
SQLRETURN iCall400Cmd(char * blob)
{
  iCmd400(blob);
  return SQL_SUCCESS;
}
#else
/* in memory option */
SQLRETURN iCall400Pgm(char * blob)
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  iCall400PgmIleCallStruct * arglist = (iCall400PgmIleCallStruct *) NULL;
  char buffer[ sizeof(iCall400PgmIleCallStruct) + 16 ];
  static arg_type_t iCall400PgmIleSigStruct[] = { ARG_MEMPTR, ARG_END };
  arglist = (iCall400PgmIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&iCall400PgmBuf);
  memset(buffer,0,sizeof(buffer));
  actMark = _ILELOAD(ILEMEMCALL, ILELOAD_LIBOBJ); /* imemcall.h (Makefile ) */
  if (!iCall400PgmLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "iCall400");
    if (rc < 0) {
      return SQL_ERROR;
    }
    iCall400PgmLoaded = 1;
  }
  arglist->blob.s.addr = (ulong) blob;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, iCall400PgmIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return SQL_SUCCESS;
}

SQLRETURN iCall400Cmd(char * blob, int len)
{
  int rc = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  int actMark = 0;
  char * ileSymPtr = (char *) NULL;
  iCall400CmdIleCallStruct * arglist = (iCall400CmdIleCallStruct *) NULL;
  char buffer[ sizeof(iCall400CmdIleCallStruct) + 16 ];
  static arg_type_t iCall400CmdIleSigStruct[] = { ARG_MEMPTR, ARG_INT32, ARG_END };
  char cmd[TOOL400_MAX_CMD_BUFF];
  arglist = (iCall400CmdIleCallStruct *)ROUND_QUAD(buffer);
  ileSymPtr = (char *)ROUND_QUAD(&iCall400CmdBuf);
  memset(buffer,0,sizeof(buffer));
  memset(cmd,0,sizeof(cmd));
  actMark = _ILELOAD(ILEMEMCALL, ILELOAD_LIBOBJ); /* imemcall.h (Makefile ) */
  if (!iCall400CmdLoaded) {
    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "iCmd400");
    if (rc < 0) {
      return SQL_ERROR;
    }
    iCall400CmdLoaded = 1;
  }
  rc = ile_pgm_str_2_char(cmd, blob, 1, sizeof(cmd), 0, 0, 1);
  ile_pgm_trim(cmd, sizeof(cmd), FLAG_STR_EBCDIC);
  arglist->blob.s.addr = (ulong) &cmd;
  arglist->len = len;
  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, iCall400CmdIleSigStruct, RESULT_INT32);
  if (rc != ILECALL_NOERROR) {
    return SQL_ERROR;
  }
  return SQL_SUCCESS;
}

#endif

