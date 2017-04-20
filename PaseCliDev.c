#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliPrintf.h"
#include "PaseCliDevConsole.h"
#include "PaseCliDevFile.h"

void dev_dump() {
  init_lock();
  switch(init_cli_trace()) {
    case DB2CLITRACE_FILE:
    case DB2CLITRACE_FILE_STOP:
    case DB2CLITRACE_FILE_DBX:
      dev_file_dump();
      break;
    default:
      dev_console_dump();
      break;
  }
  init_unlock();
}

int dev_go(int sqlrc, char * name) {
  /* TBD -- filter output */
  return init_cli_trace();
}


int dev_sql_error(short int hType, int hndl) {
  SQLCHAR msg[SQL_MAX_MESSAGE_LENGTH + 1];
  SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
  SQLINTEGER sqlcode = 0;
  SQLSMALLINT length = 0;
  SQLCHAR *p = NULL;
  SQLSMALLINT recno = 1;
  memset(msg, '\0', SQL_MAX_MESSAGE_LENGTH + 1);
  memset(sqlstate, '\0', SQL_SQLSTATE_SIZE + 1);
  SQLGetDiagRec(hType, hndl, recno, sqlstate, &sqlcode, msg, SQL_MAX_MESSAGE_LENGTH + 1, &length);
}


