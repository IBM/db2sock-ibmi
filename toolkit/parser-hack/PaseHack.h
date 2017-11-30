#ifndef _PASEHACK_H
#define _PASEHACK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include <sqlcli.h>
#include "../PaseType.h"
#endif

SQLRETURN custom_SQL400Hack(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr, 
 SQLINTEGER cbExecute);

#endif /* _PASEHACK_H */

