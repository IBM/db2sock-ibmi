#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "PaseCliPrintf.h"
#include "PaseCliDevFile.h"

void dev_file(const char * format, ...) {
    char filebuff[PRINTF_FILE_MAX];
    char *f = (char *) &filebuff; 
    char bigbuff[PRINTF_BUFFER_MAX * 2];
    char *p = (char *) &bigbuff; 
    FILE * pFile;

    va_list args;
    va_start(args, format);
    vsprintf(p, format, args);
    va_end(args);

    sprintf(f,"%s%d","/tmp/libdb400_trace_",getpid());

    /* reset in case overrun bigbuff */
    p = (char *) &bigbuff;

    pFile = fopen (f,"a+");
    if (pFile!=NULL)
    {
      fputs (p,pFile);
      fclose (pFile);
    }
}
void dev_file_dump() {
  dev_file("%s",printf_buffer());
  printf_clear();
}
