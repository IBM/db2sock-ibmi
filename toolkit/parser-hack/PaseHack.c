#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "../PaseTool.h"
#include "PaseHkDmp.h"
#include "PaseHack.h"

static char sbang;
static char spound;
static char sdollar;
static char sat;
static char sbackslash;
static char sopen_brace;
static char sclose_brace;
static char scaret;
static char sbacktick;
static char sopen_bracket;
static char sclose_bracket;
static char sbar;
static char stilde;


/* ==========================
 * malloc/free
 * ==========================
 */
void * hack_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void hack_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
}

/* ==========================
 * Check keywords
 * ==========================
 */
SQLRETURN hack_check_sql_keywords(char *sql, int sz, char **injson, int * inlen) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int nest = 0;
  char * low = NULL;
  char * find = NULL;
  char * f1 = NULL;
  char * f2 = NULL;

  /* Variant EBCDIC characters !#$@\[]^`{}|~ */
  sbang = ccsid_variant_bang();
  spound = ccsid_variant_pound();
  sdollar = ccsid_variant_dollar();
  sat = ccsid_variant_at();
  sbackslash = ccsid_variant_backslash();
  sopen_brace = ccsid_variant_open_brace();
  sclose_brace = ccsid_variant_close_brace();
  scaret = ccsid_variant_caret();
  sbacktick = ccsid_variant_backtick();
  sopen_bracket = ccsid_variant_open_bracket();
  sclose_bracket = ccsid_variant_close_bracket();
  sbar = ccsid_variant_bar();
  stilde = ccsid_variant_tilde();

  /* find toolkit call */
  *injson = NULL;
  *inlen = 0;

  /* find null term? */
  if (sql && sz <= 0) {
    sz = strlen(sql);
  }

  /* find keywords */
  if (sz > 0) {
    low = hack_new(sz + 1);
     for (i=0; sql[i]; i++ ) {
        low[i] = tolower(sql[i]);
     }
     find = strstr(low,"select ");
     if (find) {
       find = strstr(find,"toolkitcall");
       if (find) {
         find = strstr(find,"where");
         for (i=0; find[i]; i++ ) {
            if (find[i] == '(') {
               break;
            }
         }
         if (find[i] == '(') {
           f1 = &find[i];
           for (i=0; f1[i]; i++ ) {
              if (f1[i] == '(') {
                nest++;
              } else if (f1[i] == ')') {
                nest--;
                if (nest < 1) {
                  f2 = &f1[i];
                  break;
                }
              }
           }
         }
       }
     }
  }
  /* adjust injson to original upper/lower data (sql) */
  if (low) {
    if (f1 && f2 && f1 + 1 < f2 - 1) {
      f1++;
      *injson = sql + (f1 - low);
      *inlen = f2 - f1;
    } else {
      sqlrc = DB2_HACK_SQL_ERROR;
    }
    hack_free(low);
  } else {
    sqlrc = DB2_HACK_SQL_ERROR;
  }

  return sqlrc;
}


/* ==========================
 * PaseHackResource
 * ==========================
 */
PaseHackResource * hack_resource_ctor(SQLHSTMT hstmt, char *injson, int inlen) {
  int alen = 0;
  PaseHackResource * rsc = NULL;

  /* hstmt hold memeory resource */
  alen = sizeof(PaseHackResource) + inlen + DB2_HACK_MAX_JSON + 8;
  rsc = (PaseHackResource *) init_table_use_data_new(hstmt, alen, 0);

  /* ctor init */
  rsc->inlen = inlen;
  rsc->injson = (char *)rsc + sizeof(PaseHackResource); 
  memcpy(rsc->injson,injson,inlen);
  rsc->outlen = DB2_HACK_MAX_JSON;
  rsc->outjson = (char *)rsc->injson + inlen + 1; 

  return rsc;
}

/* ==========================
 * SQL400Hack interface (dynamic loaded)
 * ==========================
 */
SQLRETURN custom_SQL400HackExecDirect(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHDBC ohnd = 0;
  PaseHackResource * rsc = NULL;
  char *injson = NULL;
  int inlen = 0;

  /* check if toolkit override */
  sqlrc = hack_check_sql_keywords(szSqlStr, cbSqlStr, &injson, &inlen);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }

  /* hstmt hold PaseHackResource */
  rsc = hack_resource_ctor(hstmt, injson, inlen);

  /* find connect with this statement */
  sqlrc = SQL400Stmt2Hdbc(hstmt, (SQLINTEGER *) &ohnd);

  /* call SQL400Json */
  sqlrc = SQL400Json(ohnd, rsc->injson, rsc->inlen, rsc->outjson, rsc->outlen);

  return sqlrc;
}

SQLRETURN custom_SQL400HackPrepare(SQLHSTMT hstmt, 
 SQLCHAR * szSqlStr, 
 SQLINTEGER cbSqlStr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHDBC ohnd = 0;
  PaseHackResource * rsc = NULL;
  char *injson = NULL;
  int inlen = 0;

  /* check if toolkit override */
  sqlrc = hack_check_sql_keywords(szSqlStr, cbSqlStr, &injson, &inlen);
  if (sqlrc != SQL_SUCCESS) {
    return sqlrc;
  }

  /* hstmt hold PaseHackResource */
  rsc = hack_resource_ctor(hstmt, injson, inlen);

  return sqlrc;
}

SQLRETURN custom_SQL400HackExecute(SQLHSTMT hstmt)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLHDBC ohnd = 0;
  PaseHackResource * rsc = NULL;

  /* hstmt hold PaseHackResource */
  rsc = (PaseHackResource *) init_table_use_data(hstmt);

  /* find connect with this statement */
  sqlrc = SQL400Stmt2Hdbc(hstmt, (SQLINTEGER *) &ohnd);

  /* call SQL400Json */
  sqlrc = SQL400Json(ohnd, rsc->injson, rsc->inlen, rsc->outjson, rsc->outlen);

  return sqlrc;
}

SQLRETURN custom_SQL400HackFetch(SQLHSTMT hstmt)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  PaseHackResource * rsc = NULL;
  int alen = 0;

  /* hstmt hold PaseHackResource */
  rsc = (PaseHackResource *) init_table_use_data(hstmt);

  /* output into user buffer (TBD -- need multi-fetch partial json) */
  if (rsc->userjson && rsc->userlen) {
    alen = strlen(rsc->outjson);
    if (alen && alen < rsc->userlen) {
      memcpy(rsc->userjson,rsc->outjson,alen);
    } else {
      sqlrc = SQL_ERROR;
    }
  } else {
    sqlrc = SQL_ERROR;
  }
 
  return sqlrc;
}

SQLRETURN custom_SQL400HackDescribeCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLCHAR * szColName, 
 SQLSMALLINT cbColNameMax, 
 SQLSMALLINT * pcbColName, 
 SQLSMALLINT * pfSqlType, 
 SQLINTEGER * pcbColDef, 
 SQLSMALLINT * pibScale, 
 SQLSMALLINT * pfNullable)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  PaseHackResource * rsc = NULL;
  int alen = 0;

  /* hstmt hold PaseHackResource */
  rsc = (PaseHackResource *) init_table_use_data(hstmt);

  /* output parms */
  if (szColName && cbColNameMax) {
    memset(szColName,'0',cbColNameMax);
  } else {
    *pcbColName = 0;
  }
  *pfSqlType = SQL_CLOB;
  *pcbColDef = DB2_HACK_MAX_JSON;
  *pibScale = 0;
  *pfNullable = SQL_NULLABLE;
 
  return sqlrc;
}

SQLRETURN custom_SQL400HackBindCol(SQLHSTMT hstmt, 
 SQLSMALLINT icol, 
 SQLSMALLINT iType, 
 SQLPOINTER rgbValue, 
 SQLINTEGER cbValueMax, 
 SQLINTEGER * pcbValue)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  PaseHackResource * rsc = NULL;
  int alen = 0;

  /* hstmt hold PaseHackResource */
  rsc = (PaseHackResource *) init_table_use_data(hstmt);

  /* output parms */
  if (rgbValue) {
    rsc->userjson = rgbValue;
  }
  if (pcbValue && *pcbValue > 0) {
    rsc->userlen = *pcbValue;
  }
 
  return sqlrc;
}

SQLRETURN custom_SQL400HackParamData(SQLHSTMT hstmt, 
 SQLPOINTER * Value)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  PaseHackResource * rsc = NULL;
  int alen = 0;

  /* hstmt hold PaseHackResource */
  rsc = (PaseHackResource *) init_table_use_data(hstmt);

  /* output parms */
  if (Value) {
    Value = (SQLPOINTER *) &rsc->userjson;
  }
 
  return sqlrc;
}

SQLRETURN custom_SQL400HackPutData(SQLHSTMT hstmt, 
 SQLPOINTER Data, 
 SQLINTEGER SLen)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  PaseHackResource * rsc = NULL;
  int alen = 0;

  /* hstmt hold PaseHackResource */
  rsc = (PaseHackResource *) init_table_use_data(hstmt);

  /* output parms */
  if (Data) {
    rsc->userjson = Data;
  }
  if (SLen > 0) {
    rsc->userlen = SLen;
  }
 
  return sqlrc;
}


