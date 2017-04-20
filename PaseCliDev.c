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



