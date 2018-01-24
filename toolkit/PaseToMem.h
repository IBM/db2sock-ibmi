#ifndef _PASETOMEM_H
#define _PASETOMEM_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include <sqlcli.h>
#else
#include <sqlcli1.h>
#endif


SQLRETURN iCall400Pgm(char * blob);
SQLRETURN iCall400Cmd(char * blob, int len);

#endif /* _PASETOMEM_H */

