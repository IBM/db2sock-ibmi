#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"

/*
 * conversion
 */
SQLRETURN custom_SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(1, inparm, outparm, inlen, outlen, inccsid, 1208);
  return sqlrc;
}
SQLRETURN custom_SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(0, inparm, outparm, inlen, outlen, outccsid, 1208);
  return sqlrc;
}
SQLRETURN custom_SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(1, inparm, outparm, inlen, outlen, inccsid, 1200);
  return sqlrc;
}
SQLRETURN custom_SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ){
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_iconv(0, inparm, outparm, inlen, outlen, outccsid, 1200);
  return sqlrc;
}

SQLRETURN custom_SQL400IgnoreNullToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf8( hdbc, inparm, inlen, outparm, outlen, inccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}
SQLRETURN custom_SQL400IgnoreNullFromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf8( hdbc, inparm, inlen, outparm, outlen, outccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}
SQLRETURN custom_SQL400IgnoreNullToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf16( hdbc, inparm, inlen, outparm, outlen, inccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}
SQLRETURN custom_SQL400IgnoreNullFromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  if (inparm != NULL && inlen != 0 && outparm != NULL && outlen != 0) {
    return custom_SQL400ToUtf16( hdbc, inparm, inlen, outparm, outlen, outccsid );
  } else if (outparm != NULL && outlen != 0) {
    memset(outparm,0,outlen);
  }
  return sqlrc;
}

