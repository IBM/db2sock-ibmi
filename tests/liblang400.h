#ifndef _LIBLANG400_H
#define _LIBLANG400_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>

void lang_expect_count(char * msg, int expect, int actual); 
void lang_expect_count_jobs(int expect, char * uid);
void lang_out_jobs(char * uid); 
void lang_check_sqlrc(SQLSMALLINT hType, SQLHANDLE handle, SQLINTEGER sqlrc, SQLSMALLINT recno, SQLINTEGER * sqlcode);
void lang_check_sqlrcW(SQLSMALLINT hType, SQLHANDLE handle, SQLINTEGER sqlrc, SQLSMALLINT recno, SQLINTEGER * sqlcode);

#endif /* _LIBLANG400_H */

