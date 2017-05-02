#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "PaseCliAsync.h"

#define SYS400_MAX_CMD 5000
#define SYS400_MAX_BUF 5000000

void str_replace(char *target, const char *needle, const char *replacement)
{
  char buffer[1024] = { 0 };
  char *insert_point = &buffer[0];
  const char *tmp = target;
  size_t needle_len = strlen(needle);
  size_t repl_len = strlen(replacement);
  while (1) {
    const char *p = strstr(tmp, needle);
    // walked past last occurrence of needle; copy remaining part
    if (p == NULL) {
      strcpy(insert_point, tmp);
      break;
    }
    // copy part before needle
    memcpy(insert_point, tmp, p - tmp);
    insert_point += p - tmp;
    // copy replacement string
    memcpy(insert_point, replacement, repl_len);
    insert_point += repl_len;
    // adjust pointers, move on
    tmp = p + needle_len;
  }
  // write altered string back to target
  strcpy(target, buffer);
}

SQLRETURN STRQSH_QSQSRVR(SQLHANDLE hdbc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sql_exec_rc = SQL_SUCCESS;
  SQLHANDLE hstmt = 0;
  char user_buff[SYS400_MAX_CMD];
  char sys_buff[SYS400_MAX_CMD];
  SQLINTEGER sys_len = SYS400_MAX_CMD;
  char cmd_buff[SYS400_MAX_CMD];
  SQLINTEGER cmd_len = SYS400_MAX_CMD;
  SQLSMALLINT sql_data_type = 0;
  SQLUINTEGER sql_precision = 0;
  SQLSMALLINT sql_scale = 0;
  SQLSMALLINT sql_nullable = SQL_NO_NULLS;
  FILE *source = NULL;
  char ile_file[SYS400_MAX_CMD];
  char ile_buf[SYS400_MAX_BUF];
  SQLINTEGER ile_len = SYS400_MAX_BUF;
  char pase_buf[SYS400_MAX_BUF];
  SQLINTEGER pase_len = SYS400_MAX_BUF;

  /* system */
  memset(ile_file,0,SYS400_MAX_CMD);
  sprintf(ile_file,"/tmp/output%d.txt",getpid());
  memset(user_buff,0,SYS400_MAX_CMD);
  strcpy(user_buff,argv[1]);
  str_replace(user_buff, "'", "''");
  memset(sys_buff,0,SYS400_MAX_CMD);
  sprintf(sys_buff,"STRQSH CMD('/usr/bin/system -i \"%s\" > %s%s')",
    user_buff,argv[2],ile_file);
  printf("%s\n",sys_buff);

  /* call */
  memset(cmd_buff,0,SYS400_MAX_CMD);
  sprintf(cmd_buff,"CALL QSYS2.QCMDEXC(?,?)");
  /* statement */
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
  /* prepare */
  sqlrc = SQLPrepare((SQLHSTMT)hstmt, cmd_buff, (SQLINTEGER)SQL_NTS);
  /* string */
  sqlrc = SQLDescribeParam((SQLHSTMT)hstmt, 1, 
          &sql_data_type, &sql_precision, &sql_scale, &sql_nullable);
  sys_len = SQL_NTS;
  sqlrc = SQLBindParameter((SQLHSTMT)hstmt, 1,
          SQL_PARAM_INPUT, SQL_CHAR, sql_data_type,
          sql_precision, sql_scale, (SQLPOINTER)&sys_buff, 0, &sys_len);
  /* length */
  sqlrc = SQLDescribeParam((SQLHSTMT)hstmt, 2, 
          &sql_data_type, &sql_precision, &sql_scale, &sql_nullable);
  cmd_len = strlen(sys_buff);
  sqlrc = SQLBindParameter((SQLHSTMT)hstmt, 2,
          SQL_PARAM_INPUT, SQL_C_LONG, sql_data_type,
          sql_precision, sql_scale, (SQLPOINTER)&cmd_len, 0, NULL);
  /* execute */
  sqlrc = SQLExecute((SQLHSTMT)hstmt);
  sql_exec_rc = sqlrc;
  printf("==>STRQSH -- %d return code\n",sqlrc);
  /* close */
  sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);

  /* output to ascii */
  memset(ile_buf,0,ile_len);
  memset(pase_buf,0,pase_len);
  source = fopen(ile_file, "r");
  if (source) {
    ile_len = fread(ile_buf, 1, SYS400_MAX_BUF, source);
  }
  fclose(source);
  sqlrc = SQL400ToUtf8(hdbc,ile_buf,ile_len,pase_buf,pase_len,37);
  printf("%s\n",pase_buf);
  /* remove file */
  unlink(ile_file);

  /* sqlrc */
  return sql_exec_rc;
}

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHANDLE hdbc = 0;

  /* environment db2 */
  sqlrc = SQLOverrideCCSID400( 819 );
  /* connection(s) db2 (server mode QSQSRVR job) */
  sqlrc = SQL400Connect(NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL);
  /* make request */
  sqlrc = STRQSH_QSQSRVR(hdbc, argv);
  /* clean up */
  sqlrc = SQLDisconnect((SQLHDBC)hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return sqlrc;
}


