#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/*
 * utilities
 */ 

int custom_trim_CVAR(SQL400ParamStruct * prm) {
  int ib = 0;
  char * ibc = (char *) NULL;

  if (prm->indPtr) {
    ib = *(prm->indPtr);
    if (ib > 0) {
      ib = *(prm->indPtr) - 1;
      ibc = (char *) prm->pfSqlCValue;
      for (; ib && (ibc[ib] == 0x00 || ibc[ib] == 0x20); ib--) ibc[ib] = '\0';
    }
    *(prm->indPtr) = ib;
  }
}

/*
 * options
 */

SQLRETURN custom_SQL400Cmd(SQLHDBC hdbc, SQLCHAR * cmd)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHSTMT hstmt = 0;
  int cmd_len = strlen(cmd);
  char *len_string= (char *) NULL;
  int len_len = 0;
  char *query_string= (char *) NULL;
  int query_len = 0;
  /* setup call to QSYS2/QCMDEXC('cmd',cmdlength) */
  if (!cmd_len) {
    return SQL_ERROR;
  }
  len_string = custom_alloc_zero(40);
  len_len = sprintf(len_string, "%d", cmd_len);
  query_len = 23 + cmd_len + len_len ;
  query_string = custom_alloc_zero(query_len);
  strcpy(query_string, "CALL QSYS2.QCMDEXC('");
  strcat(query_string, cmd);
  strcat(query_string, "',");
  strcat(query_string, len_string);
  strcat(query_string, ")");
  /* make call */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  if ( sqlrc == SQL_SUCCESS ) {
    sqlrc = SQLExecDirect(hstmt, query_string, query_len);
    SQLFreeHandle( SQL_HANDLE_STMT, hstmt );
  }
  free(len_string);
  free(query_string);
  return sqlrc;
}

SQLRETURN custom_SQL400ChgLibl(SQLHDBC hdbc, SQLCHAR * libl)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int in_len = strlen(libl);
  char *cmd_string= (char *) NULL;
  int cmd_len = 0;
  /* setup CHGLIBL LIBL(QGPL QTEMP QDEVELOP QBLDSYS QBLDSYSR) */
  if (!in_len) {
    return SQL_ERROR;
  }
  cmd_len = 15 + in_len;
  cmd_string = custom_alloc_zero(cmd_len);
  strcpy(cmd_string, "CHGLIBL LIBL(");
  strcat(cmd_string, libl);
  strcat(cmd_string, ")");
  /* make call */
  sqlrc = custom_SQL400Cmd(hdbc, cmd_string);
  free(cmd_string);
  return sqlrc;
}
SQLRETURN custom_SQL400ChgCurLib(SQLHDBC hdbc, SQLCHAR * curlib)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int in_len = strlen(curlib);
  char *cmd_string= (char *) NULL;
  int cmd_len = 0;
  /* setup CHGCURLIB CURLIB(FROG) */
  if (!in_len) {
    return SQL_ERROR;
  }
  cmd_len = 19 + in_len;
  cmd_string = custom_alloc_zero(cmd_len);
  strcpy(cmd_string, "CHGCURLIB CURLIB(");
  strcat(cmd_string, curlib);
  strcat(cmd_string, ")");
  /* make call */
  sqlrc = custom_SQL400Cmd(hdbc, cmd_string);
  free(cmd_string);
  return sqlrc;
}

