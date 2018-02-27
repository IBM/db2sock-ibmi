#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"

/*
export MALLOCDEBUG=report_allocations 
*/

#define MAX_TEST_BUFFER 5000000
#define ATTR_TEST_LIB "DB2JSON"
#define ATTR_TEST_NAME "DB2TRANS"
#define ATTR_TEST_INFO_NAME "BOB"

/*
SQLRETURN SQLSetConnectAttr(SQLHDBC hdbc, 
 SQLINTEGER attrib, 
 SQLPOINTER vParam, 
 SQLINTEGER inlen); 


SQLRETURN SQLGetConnectAttr(SQLHDBC hdbc, 
 SQLINTEGER attr, 
 SQLPOINTER oval, 
 SQLINTEGER ilen, 
 SQLINTEGER * olen); 
*/
int test_connect_attribute_info(
  char *db,
  char *uid,
  char *pwd,
  char *libl,
  char *curlib,
  char *trace,
  char * in_msg,
  int in_attr,
  char * in_value
) {
  char * test_name = "test_connect_attribute_info";
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  SQLHANDLE hdbc = 0;
  char buffer[32767];
  SQLINTEGER attr = 0;
  SQLPOINTER oval = (SQLPOINTER) NULL;
  SQLINTEGER ilen = (SQLINTEGER) 0;
  SQLINTEGER len = (SQLINTEGER) 0;
  SQLINTEGER * olen = (SQLINTEGER *) NULL;

  /* default naming, etc. */
  sqlrc = SQL400ConnectUtf8(819, (SQLCHAR *) db, (SQLCHAR *) uid, (SQLCHAR *) pwd, &hdbc, SQL_TXN_NO_COMMIT, libl, curlib);

  /* set */
  if (sqlrc == SQL_SUCCESS) {
    attr = in_attr;
    oval = (SQLPOINTER) buffer;
    memset(buffer,0,sizeof(buffer));
    sprintf(buffer,"%s",in_value); 
    len = strlen(buffer);
    sqlrc = SQLSetConnectAttr(hdbc, attr, oval, len);
  }

  /* get */
  if (sqlrc == SQL_SUCCESS) {
    attr = in_attr;
    oval = (SQLPOINTER) buffer;
    ilen = (SQLINTEGER) sizeof(buffer);
    len = (SQLINTEGER) ilen;
    olen = (SQLINTEGER *) &len;
    memset(buffer,0,sizeof(buffer)); 
    sqlrc = SQLGetConnectAttr(hdbc, attr, oval, ilen, olen);
  }

  /* test data passed? */
  if (sqlrc == SQL_SUCCESS) {
    if (strcmp(buffer,in_value)) {
      printf("%s failed %s (%d) - %s == (%s)\n",test_name, in_msg, attr, in_value, buffer);
      sqlrc = SQL_ERROR;
    } else {
      printf("%s success %s (%d) - %s == (%s)\n",test_name, in_msg, attr, in_value, buffer);
    }
  } else {
    if (attr == SQL_ATTR_SERVERMODE_SUBSYSTEM) {
      printf("%s skip %s (%d) - %s == (%s) - may not be supported release\n",test_name, in_msg, attr, in_value, buffer);
      sqlrc = SQL_SUCCESS;
    } else {
      printf("%s failed %s (%d) - %s == (%s) sqlrc (%d)\n",test_name, in_msg, attr, in_value, buffer, sqlrc);
    }
  }

  sqlrc1 = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

  return sqlrc;
}

/*
SQLRETURN SQLGetInfo (SQLHDBC        hdbc,
                      SQLSMALLINT    fInfoType,
                      SQLPOINTER     rgbInfoValue,
                      SQLSMALLINT    cbInfoValueMax,
                      SQLSMALLINT    *pcbInfoValue);
*/
int test_get_info(
  char *db,
  char *uid,
  char *pwd,
  char *libl,
  char *curlib,
  char *trace,
  char * in_msg,
  int in_attr,
  char * in_value
) {
  char * test_name = "test_get_info";
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLRETURN sqlrc1 = SQL_SUCCESS;
  SQLHANDLE hdbc = 0;
  char buffer[32767];
  SQLSMALLINT attr = 0;
  SQLPOINTER oval = (SQLPOINTER) NULL;
  SQLSMALLINT ilen = (SQLSMALLINT) 0;
  SQLSMALLINT len = (SQLSMALLINT) 0;
  SQLSMALLINT * olen = (SQLSMALLINT *) NULL;

  /* default naming, etc. */
  sqlrc = SQL400ConnectUtf8(819, (SQLCHAR *) db, (SQLCHAR *) uid, (SQLCHAR *) pwd, &hdbc, SQL_TXN_NO_COMMIT, libl, curlib);

  /* get */
  if (sqlrc == SQL_SUCCESS) {
    attr = in_attr;
    oval = (SQLPOINTER) buffer;
    ilen = (SQLSMALLINT) sizeof(buffer);
    len = (SQLSMALLINT) ilen;
    olen = (SQLSMALLINT *) &len;
    memset(buffer,0,sizeof(buffer)); 
    sqlrc = SQLGetInfo (hdbc, attr, oval, ilen, olen);
  }

  /* test data passed? */
  if (sqlrc == SQL_SUCCESS) {
    if (in_value[0] == '?' && !strlen(buffer)) {
      printf("%s failed %s (%d) - %s == (%s)\n",test_name, in_msg, attr, in_value, buffer);
      sqlrc = SQL_ERROR;
    } else if (in_value[0] != '?' && strcmp(buffer,in_value)) {
      printf("%s failed %s (%d) - %s == (%s)\n",test_name, in_msg, attr, in_value, buffer);
      sqlrc = SQL_ERROR;
    } else {
      printf("%s success %s (%d) - %s == (%s)\n",test_name, in_msg, attr, in_value, buffer);
    }
  } else {
    printf("%s failed %s (%d) - %s == (%s) sqlrc (%d)\n",test_name, in_msg, attr, in_value, buffer, sqlrc);
  }

  sqlrc1 = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

  return sqlrc;
}


int test_version() {

  SQLRETURN sqlrc = SQL_SUCCESS;
  char ver[128];
  memset(ver,0,sizeof(ver));
  sqlrc = SQL400Version((SQLPOINTER) &ver, sizeof(ver));

  printf("version (%s)\n",ver);

  return sqlrc;
}

int main(int argc, char * argv[]) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  char *db  = NULL;
  char *uid = NULL;
  char *pwd = NULL;
  char *libl  = NULL;
  char *curlib = NULL;
  char *trace  = NULL;

  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  trace = getenv(SQL_TRACE);
  printf("run (trace=%s)\n",trace);

  sqlrc = SQLOverrideCCSID400(819);

  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_version();
  }

  /* SQLSetConnectAttr, SQLGetConnectAttr*/
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "DEFAULT_LIB", SQL_ATTR_DBC_DEFAULT_LIB, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "SAVEPOINT", SQL_ATTR_SAVEPOINT_NAME, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "ACCTSTR", SQL_ATTR_INFO_ACCTSTR, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "APPLNAME", SQL_ATTR_INFO_APPLNAME, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "PROGRAMID", SQL_ATTR_INFO_PROGRAMID, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "USERID", SQL_ATTR_INFO_USERID, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "WRKSTNNAME", SQL_ATTR_INFO_WRKSTNNAME, ATTR_TEST_INFO_NAME);
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_connect_attribute_info(db, uid, pwd, libl, curlib, trace, "SUBSYSTEM", SQL_ATTR_SERVERMODE_SUBSYSTEM, ATTR_TEST_INFO_NAME);
  }

  /* SQLGetInfo */
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "CATALOG_NAME", SQL_CATALOG_NAME, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "COLUMN_ALIAS", SQL_COLUMN_ALIAS, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "CONNECTION_JOB_NAME", SQL_CONNECTION_JOB_NAME, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DATA_SOURCE_NAME", SQL_DATA_SOURCE_NAME, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DATA_SOURCE_READ_ONLY", SQL_DATA_SOURCE_READ_ONLY, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DATABASE_NAME", SQL_DATABASE_NAME, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DBMS_NAME", SQL_DBMS_NAME, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DBMS_VER", SQL_DBMS_VER, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DESCRIBE_PARAMETER", SQL_DESCRIBE_PARAMETER, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DRIVER_NAME", SQL_DRIVER_NAME, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "DRIVER_ODBC_VER", SQL_DRIVER_ODBC_VER, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "IDENTIFIER_QUOTE_CHAR", SQL_IDENTIFIER_QUOTE_CHAR, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "KEYWORDS", SQL_KEYWORDS, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "LIKE_ESCAPE_CLAUSE", SQL_LIKE_ESCAPE_CLAUSE, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "MULTIPLE_ACTIVE_TXN", SQL_MULTIPLE_ACTIVE_TXN, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "ORDER_BY_COLUMNS_IN_SELECT", SQL_ORDER_BY_COLUMNS_IN_SELECT, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "OUTER_JOINS", SQL_OUTER_JOINS, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "OWNER_TERM", SQL_OWNER_TERM, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "SCHEMA_TERM", SQL_SCHEMA_TERM, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "PROCEDURE_TERM", SQL_PROCEDURE_TERM, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "SQL_PROCEDURES", SQL_PROCEDURES, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "QUALIFIER_NAME_SEPARATOR", SQL_QUALIFIER_NAME_SEPARATOR, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "CATALOG_NAME_SEPARATOR", SQL_CATALOG_NAME_SEPARATOR, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "QUALIFIER_TERM", SQL_QUALIFIER_TERM, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "CATALOG_TERM", SQL_CATALOG_TERM, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "SEARCH_PATTERN_ESCAPE", SQL_SEARCH_PATTERN_ESCAPE, "?");
  }
  if (sqlrc == SQL_SUCCESS) {
    sqlrc = test_get_info(db, uid, pwd, libl, curlib, trace, "USER_NAME", SQL_USER_NAME, "?");
  }

  /* test passed? */
  if (sqlrc == SQL_SUCCESS) {
    printf("success (%d)\n",sqlrc);
  } else {
    printf("failed (%d)\n",sqlrc);
  }


  return sqlrc;
}
