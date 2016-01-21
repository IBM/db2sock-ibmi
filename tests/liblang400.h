#ifndef _LIBLANG400_H
#define _LIBLANG400_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>

void lang_check_sqlrc(SQLSMALLINT hType, SQLHANDLE handle, SQLINTEGER sqlrc, SQLSMALLINT recno, SQLINTEGER * sqlcode);


#endif /* _LIBLANG400_H */

