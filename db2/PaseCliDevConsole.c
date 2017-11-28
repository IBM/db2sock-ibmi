#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "PaseCliPrintf.h"
#include "PaseCliDevConsole.h"
void dev_console(const char * format, ...) {
    char bigbuff[PRINTF_BUFFER_MAX];
    char *p = (char *) &bigbuff; 
    FILE * pFile;

    va_list args;
    va_start(args, format);
    vsprintf(p, format, args);
    va_end(args);

    printf("%s",p);
}
void dev_console_dump() {
  dev_console("%s\n",printf_buffer());
  printf_clear();
}
