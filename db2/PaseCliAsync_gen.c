#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"


SQLRETURN SQLAllocConnect( SQLHENV  henv, SQLHDBC * phdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLAllocConnect( henv, phdbc );
    break;
  default:
    sqlrc = libdb400_SQLAllocConnect( henv, phdbc );
    break;
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phdbc, *phdbc);
  }
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLAllocConnect(sqlrc,  henv, phdbc );
  }
  return sqlrc;
}
SQLRETURN SQLAllocEnv( SQLHENV * phenv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLAllocEnv( phenv );
    break;
  default:
    sqlrc = libdb400_SQLAllocEnv( phenv );
    break;
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phenv, *phenv);
  }
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLAllocEnv(sqlrc,  phenv );
  }
  return sqlrc;
}
SQLRETURN SQLAllocHandle( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLAllocHandle( htype, ihnd, ohnd );
    break;
  default:
    sqlrc = libdb400_SQLAllocHandle( htype, ihnd, ohnd );
    break;
  }
  switch (htype) {
  case SQL_HANDLE_ENV:
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, *ohnd);
    }
    break;
  case SQL_HANDLE_DBC:
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, *ohnd);
    }
    break;
  case SQL_HANDLE_STMT:
  case SQL_HANDLE_DESC:
    if (sqlrc == SQL_SUCCESS) {
      init_table_ctor(*ohnd, ihnd);
    }
    break;
  }
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLAllocHandle(sqlrc,  htype, ihnd, ohnd );
  }
  return sqlrc;
}
SQLRETURN SQLAllocStmt( SQLHDBC  hdbc, SQLHSTMT * phstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLAllocStmt( hdbc, phstmt );
    break;
  default:
    sqlrc = libdb400_SQLAllocStmt( hdbc, phstmt );
    break;
  }
  if (sqlrc == SQL_SUCCESS) {
    init_table_ctor(*phstmt, hdbc);
  }
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLAllocStmt(sqlrc,  hdbc, phstmt );
  }
  return sqlrc;
}
SQLRETURN SQLBindCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLBindCol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLBindCol( hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindCol(sqlrc,  hstmt, icol, iType, rgbValue, cbValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLBindColThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLBindColStruct * myptr = (SQLBindColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLBindCol( myptr->hstmt, myptr->icol, myptr->iType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLBindCol( myptr->hstmt, myptr->icol, myptr->iType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindCol(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->iType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindColCallback(SQLBindColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindColStruct * myptr = (SQLBindColStruct *) malloc(sizeof(SQLBindColStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->iType = iType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindColThread, (void *)myptr);
  return tid;
}
SQLBindColStruct * SQLBindColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindColStruct * myptr = (SQLBindColStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindColStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLBindFileToCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLBindFileToCol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLBindFileToCol( hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindFileToCol(sqlrc,  hstmt, icol, fName, fNameLen, fOptions, fValueMax, sLen, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLBindFileToColThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLBindFileToColStruct * myptr = (SQLBindFileToColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLBindFileToCol( myptr->hstmt, myptr->icol, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->sLen, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLBindFileToCol( myptr->hstmt, myptr->icol, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->sLen, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindFileToCol(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->sLen, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindFileToColCallback(SQLBindFileToColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindFileToColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindFileToColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindFileToColStruct * myptr = (SQLBindFileToColStruct *) malloc(sizeof(SQLBindFileToColStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fName = fName;
  myptr->fNameLen = fNameLen;
  myptr->fOptions = fOptions;
  myptr->fValueMax = fValueMax;
  myptr->sLen = sLen;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindFileToColThread, (void *)myptr);
  return tid;
}
SQLBindFileToColStruct * SQLBindFileToColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindFileToColStruct * myptr = (SQLBindFileToColStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindFileToColStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLBindFileToParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLBindFileToParam( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLBindFileToParam( hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindFileToParam(sqlrc,  hstmt, ipar, iType, fName, fNameLen, fOptions, fValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLBindFileToParamThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLBindFileToParamStruct * myptr = (SQLBindFileToParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLBindFileToParam( myptr->hstmt, myptr->ipar, myptr->iType, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLBindFileToParam( myptr->hstmt, myptr->ipar, myptr->iType, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindFileToParam(myptr->sqlrc,  myptr->hstmt, myptr->ipar, myptr->iType, myptr->fName, myptr->fNameLen, myptr->fOptions, myptr->fValueMax, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindFileToParamCallback(SQLBindFileToParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindFileToParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindFileToParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindFileToParamStruct * myptr = (SQLBindFileToParamStruct *) malloc(sizeof(SQLBindFileToParamStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->iType = iType;
  myptr->fName = fName;
  myptr->fNameLen = fNameLen;
  myptr->fOptions = fOptions;
  myptr->fValueMax = fValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindFileToParamThread, (void *)myptr);
  return tid;
}
SQLBindFileToParamStruct * SQLBindFileToParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindFileToParamStruct * myptr = (SQLBindFileToParamStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindFileToParamStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLBindParam( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLBindParam( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLBindParam( hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindParam(sqlrc,  hstmt, iparm, iType, pType, pLen, pScale, pData, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLBindParamThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLBindParamStruct * myptr = (SQLBindParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLBindParam( myptr->hstmt, myptr->iparm, myptr->iType, myptr->pType, myptr->pLen, myptr->pScale, myptr->pData, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLBindParam( myptr->hstmt, myptr->iparm, myptr->iType, myptr->pType, myptr->pLen, myptr->pScale, myptr->pData, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindParam(myptr->sqlrc,  myptr->hstmt, myptr->iparm, myptr->iType, myptr->pType, myptr->pLen, myptr->pScale, myptr->pData, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindParamCallback(SQLBindParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindParamStruct * myptr = (SQLBindParamStruct *) malloc(sizeof(SQLBindParamStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->iparm = iparm;
  myptr->iType = iType;
  myptr->pType = pType;
  myptr->pLen = pLen;
  myptr->pScale = pScale;
  myptr->pData = pData;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindParamThread, (void *)myptr);
  return tid;
}
SQLBindParamStruct * SQLBindParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindParamStruct * myptr = (SQLBindParamStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindParamStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLBindParameter( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLBindParameter( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLBindParameter( hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindParameter(sqlrc,  hstmt, ipar, fParamType, fCType, fSQLType, pLen, pScale, pData, cbValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLBindParameterThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLBindParameterStruct * myptr = (SQLBindParameterStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLBindParameter( myptr->hstmt, myptr->ipar, myptr->fParamType, myptr->fCType, myptr->fSQLType, myptr->pLen, myptr->pScale, myptr->pData, myptr->cbValueMax, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLBindParameter( myptr->hstmt, myptr->ipar, myptr->fParamType, myptr->fCType, myptr->fSQLType, myptr->pLen, myptr->pScale, myptr->pData, myptr->cbValueMax, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLBindParameter(myptr->sqlrc,  myptr->hstmt, myptr->ipar, myptr->fParamType, myptr->fCType, myptr->fSQLType, myptr->pLen, myptr->pScale, myptr->pData, myptr->cbValueMax, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLBindParameterCallback(SQLBindParameterStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLBindParameterStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLBindParameterAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLBindParameterStruct * myptr = (SQLBindParameterStruct *) malloc(sizeof(SQLBindParameterStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->fParamType = fParamType;
  myptr->fCType = fCType;
  myptr->fSQLType = fSQLType;
  myptr->pLen = pLen;
  myptr->pScale = pScale;
  myptr->pData = pData;
  myptr->cbValueMax = cbValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLBindParameterThread, (void *)myptr);
  return tid;
}
SQLBindParameterStruct * SQLBindParameterJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLBindParameterStruct * myptr = (SQLBindParameterStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLBindParameterStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLCancel( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLCancel( hstmt );
    break;
  default:
    sqlrc = libdb400_SQLCancel( hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLCancel(sqlrc,  hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLCancelThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLCancelStruct * myptr = (SQLCancelStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLCancel( myptr->hstmt );
    break;
  default:
    myptr->sqlrc = libdb400_SQLCancel( myptr->hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLCancel(myptr->sqlrc,  myptr->hstmt );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLCancelCallback(SQLCancelStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLCancelStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLCancelAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLCancelStruct * myptr = (SQLCancelStruct *) malloc(sizeof(SQLCancelStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLCancelThread, (void *)myptr);
  return tid;
}
SQLCancelStruct * SQLCancelJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLCancelStruct * myptr = (SQLCancelStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCancelStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLCloseCursor( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLCloseCursor( hstmt );
    break;
  default:
    sqlrc = libdb400_SQLCloseCursor( hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLCloseCursor(sqlrc,  hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLCloseCursorThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLCloseCursorStruct * myptr = (SQLCloseCursorStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLCloseCursor( myptr->hstmt );
    break;
  default:
    myptr->sqlrc = libdb400_SQLCloseCursor( myptr->hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLCloseCursor(myptr->sqlrc,  myptr->hstmt );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLCloseCursorCallback(SQLCloseCursorStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLCloseCursorStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLCloseCursorAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLCloseCursorStruct * myptr = (SQLCloseCursorStruct *) malloc(sizeof(SQLCloseCursorStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLCloseCursorThread, (void *)myptr);
  return tid;
}
SQLCloseCursorStruct * SQLCloseCursorJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLCloseCursorStruct * myptr = (SQLCloseCursorStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCloseCursorStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColAttribute( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColAttribute( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  default:
    sqlrc = libdb400_SQLColAttribute( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttribute(sqlrc,  hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColAttributeThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColAttributeStruct * myptr = (SQLColAttributeStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColAttribute( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColAttribute( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttribute(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributeCallback(SQLColAttributeStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributeStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributeAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributeStruct * myptr = (SQLColAttributeStruct *) malloc(sizeof(SQLColAttributeStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributeThread, (void *)myptr);
  return tid;
}
SQLColAttributeStruct * SQLColAttributeJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributeStruct * myptr = (SQLColAttributeStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributeStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColAttributeW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColAttributeW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  default:
    sqlrc = libdb400_SQLColAttributeW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttributeW(sqlrc,  hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColAttributeWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColAttributeWStruct * myptr = (SQLColAttributeWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColAttributeW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColAttributeW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttributeW(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributeWCallback(SQLColAttributeWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributeWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributeWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributeWStruct * myptr = (SQLColAttributeWStruct *) malloc(sizeof(SQLColAttributeWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributeWThread, (void *)myptr);
  return tid;
}
SQLColAttributeWStruct * SQLColAttributeWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributeWStruct * myptr = (SQLColAttributeWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributeWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColAttributes( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColAttributes( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  default:
    sqlrc = libdb400_SQLColAttributes( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttributes(sqlrc,  hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColAttributesThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColAttributes( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColAttributes( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttributes(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributesCallback(SQLColAttributesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributesAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) malloc(sizeof(SQLColAttributesStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributesThread, (void *)myptr);
  return tid;
}
SQLColAttributesStruct * SQLColAttributesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributesStruct * myptr = (SQLColAttributesStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributesStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColAttributesW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColAttributesW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  default:
    sqlrc = libdb400_SQLColAttributesW( hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttributesW(sqlrc,  hstmt, icol, fDescType, rgbDesc, cbDescMax, pcbDesc, pfDesc );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColAttributesWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColAttributesWStruct * myptr = (SQLColAttributesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColAttributesW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColAttributesW( myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColAttributesW(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->fDescType, myptr->rgbDesc, myptr->cbDescMax, myptr->pcbDesc, myptr->pfDesc );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColAttributesWCallback(SQLColAttributesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColAttributesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColAttributesWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColAttributesWStruct * myptr = (SQLColAttributesWStruct *) malloc(sizeof(SQLColAttributesWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fDescType = fDescType;
  myptr->rgbDesc = rgbDesc;
  myptr->cbDescMax = cbDescMax;
  myptr->pcbDesc = pcbDesc;
  myptr->pfDesc = pfDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColAttributesWThread, (void *)myptr);
  return tid;
}
SQLColAttributesWStruct * SQLColAttributesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColAttributesWStruct * myptr = (SQLColAttributesWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColAttributesWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColumnPrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColumnPrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  default:
    sqlrc = libdb400_SQLColumnPrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumnPrivileges(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColumnPrivilegesThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColumnPrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColumnPrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumnPrivileges(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnPrivilegesCallback(SQLColumnPrivilegesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnPrivilegesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnPrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) malloc(sizeof(SQLColumnPrivilegesStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnPrivilegesThread, (void *)myptr);
  return tid;
}
SQLColumnPrivilegesStruct * SQLColumnPrivilegesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnPrivilegesStruct * myptr = (SQLColumnPrivilegesStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnPrivilegesStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColumnPrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColumnPrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  default:
    sqlrc = libdb400_SQLColumnPrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumnPrivilegesW(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColumnPrivilegesWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColumnPrivilegesWStruct * myptr = (SQLColumnPrivilegesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColumnPrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColumnPrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumnPrivilegesW(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnPrivilegesWCallback(SQLColumnPrivilegesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnPrivilegesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnPrivilegesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnPrivilegesWStruct * myptr = (SQLColumnPrivilegesWStruct *) malloc(sizeof(SQLColumnPrivilegesWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnPrivilegesWThread, (void *)myptr);
  return tid;
}
SQLColumnPrivilegesWStruct * SQLColumnPrivilegesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnPrivilegesWStruct * myptr = (SQLColumnPrivilegesWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnPrivilegesWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColumns( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColumns( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  default:
    sqlrc = libdb400_SQLColumns( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumns(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColumnsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColumns( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColumns( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumns(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnsCallback(SQLColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) malloc(sizeof(SQLColumnsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnsThread, (void *)myptr);
  return tid;
}
SQLColumnsStruct * SQLColumnsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnsStruct * myptr = (SQLColumnsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLColumnsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  default:
    sqlrc = libdb400_SQLColumnsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumnsW(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLColumnsWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLColumnsWStruct * myptr = (SQLColumnsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLColumnsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLColumnsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLColumnsW(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLColumnsWCallback(SQLColumnsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLColumnsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLColumnsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLColumnsWStruct * myptr = (SQLColumnsWStruct *) malloc(sizeof(SQLColumnsWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLColumnsWThread, (void *)myptr);
  return tid;
}
SQLColumnsWStruct * SQLColumnsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLColumnsWStruct * myptr = (SQLColumnsWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLColumnsWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLConnect( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLConnect( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
    break;
  default:
    sqlrc = libdb400_SQLConnect( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLConnect(sqlrc,  hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLConnectThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLConnectStruct * myptr = (SQLConnectStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLConnect( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLConnect( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLConnect(myptr->sqlrc,  myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLConnectCallback(SQLConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLConnectAsync ( SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLConnectStruct * myptr = (SQLConnectStruct *) malloc(sizeof(SQLConnectStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szDSN = szDSN;
  myptr->cbDSN = cbDSN;
  myptr->szUID = szUID;
  myptr->cbUID = cbUID;
  myptr->szAuthStr = szAuthStr;
  myptr->cbAuthStr = cbAuthStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLConnectThread, (void *)myptr);
  return tid;
}
SQLConnectStruct * SQLConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLConnectStruct * myptr = (SQLConnectStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLConnectStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLConnectW( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLConnectW( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
    break;
  default:
    sqlrc = libdb400_SQLConnectW( hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLConnectW(sqlrc,  hdbc, szDSN, cbDSN, szUID, cbUID, szAuthStr, cbAuthStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLConnectWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLConnectWStruct * myptr = (SQLConnectWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLConnectW( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLConnectW( myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLConnectW(myptr->sqlrc,  myptr->hdbc, myptr->szDSN, myptr->cbDSN, myptr->szUID, myptr->cbUID, myptr->szAuthStr, myptr->cbAuthStr );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLConnectWCallback(SQLConnectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLConnectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLConnectWAsync ( SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLConnectWStruct * myptr = (SQLConnectWStruct *) malloc(sizeof(SQLConnectWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szDSN = szDSN;
  myptr->cbDSN = cbDSN;
  myptr->szUID = szUID;
  myptr->cbUID = cbUID;
  myptr->szAuthStr = szAuthStr;
  myptr->cbAuthStr = cbAuthStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLConnectWThread, (void *)myptr);
  return tid;
}
SQLConnectWStruct * SQLConnectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLConnectWStruct * myptr = (SQLConnectWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLConnectWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLCopyDesc( SQLHDESC  sDesc, SQLHDESC  tDesc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(sDesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLCopyDesc( sDesc, tDesc );
    break;
  default:
    sqlrc = libdb400_SQLCopyDesc( sDesc, tDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLCopyDesc(sqlrc,  sDesc, tDesc );
  }
  init_table_unlock(sDesc, 1);
  return sqlrc;
}
void * SQLCopyDescThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) ptr;
  init_table_lock(myptr->sDesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLCopyDesc( myptr->sDesc, myptr->tDesc );
    break;
  default:
    myptr->sqlrc = libdb400_SQLCopyDesc( myptr->sDesc, myptr->tDesc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLCopyDesc(myptr->sqlrc,  myptr->sDesc, myptr->tDesc );
  }
  init_table_unlock(myptr->sDesc, 1);
  /* void SQLCopyDescCallback(SQLCopyDescStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLCopyDescStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLCopyDescAsync ( SQLHDESC  sDesc, SQLHDESC  tDesc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) malloc(sizeof(SQLCopyDescStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->sDesc = sDesc;
  myptr->tDesc = tDesc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLCopyDescThread, (void *)myptr);
  return tid;
}
SQLCopyDescStruct * SQLCopyDescJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLCopyDescStruct * myptr = (SQLCopyDescStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLCopyDescStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDataSources( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDataSources( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
    break;
  default:
    sqlrc = libdb400_SQLDataSources( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDataSources(sqlrc,  henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  }
  return sqlrc;
}
void * SQLDataSourcesThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDataSourcesStruct * myptr = (SQLDataSourcesStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDataSources( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDataSources( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDataSources(myptr->sqlrc,  myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  }
  /* not lock */
  /* void SQLDataSourcesCallback(SQLDataSourcesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDataSourcesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDataSourcesAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDataSourcesStruct * myptr = (SQLDataSourcesStruct *) malloc(sizeof(SQLDataSourcesStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->fDirection = fDirection;
  myptr->szDSN = szDSN;
  myptr->cbDSNMax = cbDSNMax;
  myptr->pcbDSN = pcbDSN;
  myptr->szDescription = szDescription;
  myptr->cbDescriptionMax = cbDescriptionMax;
  myptr->pcbDescription = pcbDescription;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDataSourcesThread, (void *)myptr);
  return tid;
}
SQLDataSourcesStruct * SQLDataSourcesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDataSourcesStruct * myptr = (SQLDataSourcesStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDataSourcesStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDataSourcesW( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDataSourcesW( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
    break;
  default:
    sqlrc = libdb400_SQLDataSourcesW( henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDataSourcesW(sqlrc,  henv, fDirection, szDSN, cbDSNMax, pcbDSN, szDescription, cbDescriptionMax, pcbDescription );
  }
  return sqlrc;
}
void * SQLDataSourcesWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDataSourcesWStruct * myptr = (SQLDataSourcesWStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDataSourcesW( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDataSourcesW( myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDataSourcesW(myptr->sqlrc,  myptr->henv, myptr->fDirection, myptr->szDSN, myptr->cbDSNMax, myptr->pcbDSN, myptr->szDescription, myptr->cbDescriptionMax, myptr->pcbDescription );
  }
  /* not lock */
  /* void SQLDataSourcesWCallback(SQLDataSourcesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDataSourcesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDataSourcesWAsync ( SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDataSourcesWStruct * myptr = (SQLDataSourcesWStruct *) malloc(sizeof(SQLDataSourcesWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->fDirection = fDirection;
  myptr->szDSN = szDSN;
  myptr->cbDSNMax = cbDSNMax;
  myptr->pcbDSN = pcbDSN;
  myptr->szDescription = szDescription;
  myptr->cbDescriptionMax = cbDescriptionMax;
  myptr->pcbDescription = pcbDescription;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDataSourcesWThread, (void *)myptr);
  return tid;
}
SQLDataSourcesWStruct * SQLDataSourcesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDataSourcesWStruct * myptr = (SQLDataSourcesWStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDataSourcesWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDescribeCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
    break;
  default:
    sqlrc = libdb400_SQLDescribeCol( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDescribeCol(sqlrc,  hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLDescribeColThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDescribeCol( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDescribeCol( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDescribeCol(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLDescribeColCallback(SQLDescribeColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDescribeColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDescribeColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) malloc(sizeof(SQLDescribeColStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->szColName = szColName;
  myptr->cbColNameMax = cbColNameMax;
  myptr->pcbColName = pcbColName;
  myptr->pfSqlType = pfSqlType;
  myptr->pcbColDef = pcbColDef;
  myptr->pibScale = pibScale;
  myptr->pfNullable = pfNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDescribeColThread, (void *)myptr);
  return tid;
}
SQLDescribeColStruct * SQLDescribeColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDescribeColStruct * myptr = (SQLDescribeColStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeColStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDescribeColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDescribeColW( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
    break;
  default:
    sqlrc = libdb400_SQLDescribeColW( hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDescribeColW(sqlrc,  hstmt, icol, szColName, cbColNameMax, pcbColName, pfSqlType, pcbColDef, pibScale, pfNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLDescribeColWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDescribeColWStruct * myptr = (SQLDescribeColWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDescribeColW( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDescribeColW( myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDescribeColW(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->szColName, myptr->cbColNameMax, myptr->pcbColName, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLDescribeColWCallback(SQLDescribeColWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDescribeColWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDescribeColWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDescribeColWStruct * myptr = (SQLDescribeColWStruct *) malloc(sizeof(SQLDescribeColWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->szColName = szColName;
  myptr->cbColNameMax = cbColNameMax;
  myptr->pcbColName = pcbColName;
  myptr->pfSqlType = pfSqlType;
  myptr->pcbColDef = pcbColDef;
  myptr->pibScale = pibScale;
  myptr->pfNullable = pfNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDescribeColWThread, (void *)myptr);
  return tid;
}
SQLDescribeColWStruct * SQLDescribeColWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDescribeColWStruct * myptr = (SQLDescribeColWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeColWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDescribeParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDescribeParam( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
    break;
  default:
    sqlrc = libdb400_SQLDescribeParam( hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDescribeParam(sqlrc,  hstmt, ipar, pfSqlType, pcbColDef, pibScale, pfNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLDescribeParamThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDescribeParam( myptr->hstmt, myptr->ipar, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDescribeParam( myptr->hstmt, myptr->ipar, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDescribeParam(myptr->sqlrc,  myptr->hstmt, myptr->ipar, myptr->pfSqlType, myptr->pcbColDef, myptr->pibScale, myptr->pfNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLDescribeParamCallback(SQLDescribeParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDescribeParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDescribeParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) malloc(sizeof(SQLDescribeParamStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->pfSqlType = pfSqlType;
  myptr->pcbColDef = pcbColDef;
  myptr->pibScale = pibScale;
  myptr->pfNullable = pfNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDescribeParamThread, (void *)myptr);
  return tid;
}
SQLDescribeParamStruct * SQLDescribeParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDescribeParamStruct * myptr = (SQLDescribeParamStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDescribeParamStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDisconnect( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  int persistent = init_table_hash_active(hdbc, 0);
  /* persistent connect only close with SQL400pClose */
  if (persistent) {
    /* return now */
    return SQL_ERROR;
  }
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDisconnect( hdbc );
    break;
  default:
    sqlrc = libdb400_SQLDisconnect( hdbc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDisconnect(sqlrc,  hdbc );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLDisconnectThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDisconnectStruct * myptr = (SQLDisconnectStruct *) ptr;
  int persistent = init_table_hash_active(myptr->hdbc, 0);
  /* persistent connect only close with SQL400pClose */
  if (persistent) {
    myptr->sqlrc = SQL_ERROR;
    pthread_exit((void *)myptr);
  }
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDisconnect( myptr->hdbc );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDisconnect( myptr->hdbc );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDisconnect(myptr->sqlrc,  myptr->hdbc );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLDisconnectCallback(SQLDisconnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDisconnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDisconnectAsync ( SQLHDBC  hdbc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDisconnectStruct * myptr = (SQLDisconnectStruct *) malloc(sizeof(SQLDisconnectStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDisconnectThread, (void *)myptr);
  return tid;
}
SQLDisconnectStruct * SQLDisconnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDisconnectStruct * myptr = (SQLDisconnectStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDisconnectStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDriverConnect( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDriverConnect( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
    break;
  default:
    sqlrc = libdb400_SQLDriverConnect( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDriverConnect(sqlrc,  hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLDriverConnectThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDriverConnectStruct * myptr = (SQLDriverConnectStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDriverConnect( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDriverConnect( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDriverConnect(myptr->sqlrc,  myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLDriverConnectCallback(SQLDriverConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDriverConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDriverConnectAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDriverConnectStruct * myptr = (SQLDriverConnectStruct *) malloc(sizeof(SQLDriverConnectStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->hwnd = hwnd;
  myptr->szConnStrIn = szConnStrIn;
  myptr->cbConnStrin = cbConnStrin;
  myptr->szConnStrOut = szConnStrOut;
  myptr->cbConnStrOutMax = cbConnStrOutMax;
  myptr->pcbConnStrOut = pcbConnStrOut;
  myptr->fDriverCompletion = fDriverCompletion;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDriverConnectThread, (void *)myptr);
  return tid;
}
SQLDriverConnectStruct * SQLDriverConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDriverConnectStruct * myptr = (SQLDriverConnectStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDriverConnectStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLDriverConnectW( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLDriverConnectW( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
    break;
  default:
    sqlrc = libdb400_SQLDriverConnectW( hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDriverConnectW(sqlrc,  hdbc, hwnd, szConnStrIn, cbConnStrin, szConnStrOut, cbConnStrOutMax, pcbConnStrOut, fDriverCompletion );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLDriverConnectWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLDriverConnectWStruct * myptr = (SQLDriverConnectWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLDriverConnectW( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
    break;
  default:
    myptr->sqlrc = libdb400_SQLDriverConnectW( myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLDriverConnectW(myptr->sqlrc,  myptr->hdbc, myptr->hwnd, myptr->szConnStrIn, myptr->cbConnStrin, myptr->szConnStrOut, myptr->cbConnStrOutMax, myptr->pcbConnStrOut, myptr->fDriverCompletion );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLDriverConnectWCallback(SQLDriverConnectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLDriverConnectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLDriverConnectWAsync ( SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLDriverConnectWStruct * myptr = (SQLDriverConnectWStruct *) malloc(sizeof(SQLDriverConnectWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->hwnd = hwnd;
  myptr->szConnStrIn = szConnStrIn;
  myptr->cbConnStrin = cbConnStrin;
  myptr->szConnStrOut = szConnStrOut;
  myptr->cbConnStrOutMax = cbConnStrOutMax;
  myptr->pcbConnStrOut = pcbConnStrOut;
  myptr->fDriverCompletion = fDriverCompletion;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLDriverConnectWThread, (void *)myptr);
  return tid;
}
SQLDriverConnectWStruct * SQLDriverConnectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLDriverConnectWStruct * myptr = (SQLDriverConnectWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLDriverConnectWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLEndTran( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLEndTran( htype, henv, ctype );
    break;
  default:
    sqlrc = libdb400_SQLEndTran( htype, henv, ctype );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLEndTran(sqlrc,  htype, henv, ctype );
  }
  return sqlrc;
}
void * SQLEndTranThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) ptr;
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLEndTran( myptr->htype, myptr->henv, myptr->ctype );
    break;
  default:
    myptr->sqlrc = libdb400_SQLEndTran( myptr->htype, myptr->henv, myptr->ctype );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLEndTran(myptr->sqlrc,  myptr->htype, myptr->henv, myptr->ctype );
  }
  /* void SQLEndTranCallback(SQLEndTranStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLEndTranStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLEndTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) malloc(sizeof(SQLEndTranStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->htype = htype;
  myptr->henv = henv;
  myptr->ctype = ctype;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLEndTranThread, (void *)myptr);
  return tid;
}
SQLEndTranStruct * SQLEndTranJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLEndTranStruct * myptr = (SQLEndTranStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLEndTranStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLError( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLError( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
    break;
  default:
    sqlrc = libdb400_SQLError( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLError(sqlrc,  henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  }
  return sqlrc;
}
void * SQLErrorThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLErrorStruct * myptr = (SQLErrorStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLError( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
    break;
  default:
    myptr->sqlrc = libdb400_SQLError( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLError(myptr->sqlrc,  myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  }
  /* not lock */
  /* void SQLErrorCallback(SQLErrorStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLErrorStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLErrorAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLErrorStruct * myptr = (SQLErrorStruct *) malloc(sizeof(SQLErrorStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->hdbc = hdbc;
  myptr->hstmt = hstmt;
  myptr->szSqlState = szSqlState;
  myptr->pfNativeError = pfNativeError;
  myptr->szErrorMsg = szErrorMsg;
  myptr->cbErrorMsgMax = cbErrorMsgMax;
  myptr->pcbErrorMsg = pcbErrorMsg;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLErrorThread, (void *)myptr);
  return tid;
}
SQLErrorStruct * SQLErrorJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLErrorStruct * myptr = (SQLErrorStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLErrorStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLErrorW( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLErrorW( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
    break;
  default:
    sqlrc = libdb400_SQLErrorW( henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLErrorW(sqlrc,  henv, hdbc, hstmt, szSqlState, pfNativeError, szErrorMsg, cbErrorMsgMax, pcbErrorMsg );
  }
  return sqlrc;
}
void * SQLErrorWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLErrorWStruct * myptr = (SQLErrorWStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLErrorW( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
    break;
  default:
    myptr->sqlrc = libdb400_SQLErrorW( myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLErrorW(myptr->sqlrc,  myptr->henv, myptr->hdbc, myptr->hstmt, myptr->szSqlState, myptr->pfNativeError, myptr->szErrorMsg, myptr->cbErrorMsgMax, myptr->pcbErrorMsg );
  }
  /* not lock */
  /* void SQLErrorWCallback(SQLErrorWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLErrorWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLErrorWAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLErrorWStruct * myptr = (SQLErrorWStruct *) malloc(sizeof(SQLErrorWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->hdbc = hdbc;
  myptr->hstmt = hstmt;
  myptr->szSqlState = szSqlState;
  myptr->pfNativeError = pfNativeError;
  myptr->szErrorMsg = szErrorMsg;
  myptr->cbErrorMsgMax = cbErrorMsgMax;
  myptr->pcbErrorMsg = pcbErrorMsg;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLErrorWThread, (void *)myptr);
  return tid;
}
SQLErrorWStruct * SQLErrorWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLErrorWStruct * myptr = (SQLErrorWStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLErrorWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLExecDirect( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLExecDirect( hstmt, szSqlStr, cbSqlStr );
    break;
  default:
    sqlrc = libdb400_SQLExecDirect( hstmt, szSqlStr, cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExecDirect(sqlrc,  hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLExecDirectThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLExecDirect( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLExecDirect( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExecDirect(myptr->sqlrc,  myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExecDirectCallback(SQLExecDirectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExecDirectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExecDirectAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) malloc(sizeof(SQLExecDirectStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExecDirectThread, (void *)myptr);
  return tid;
}
SQLExecDirectStruct * SQLExecDirectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExecDirectStruct * myptr = (SQLExecDirectStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecDirectStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLExecDirectW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLExecDirectW( hstmt, szSqlStr, cbSqlStr );
    break;
  default:
    sqlrc = libdb400_SQLExecDirectW( hstmt, szSqlStr, cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExecDirectW(sqlrc,  hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLExecDirectWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLExecDirectWStruct * myptr = (SQLExecDirectWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLExecDirectW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLExecDirectW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExecDirectW(myptr->sqlrc,  myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExecDirectWCallback(SQLExecDirectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExecDirectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExecDirectWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExecDirectWStruct * myptr = (SQLExecDirectWStruct *) malloc(sizeof(SQLExecDirectWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExecDirectWThread, (void *)myptr);
  return tid;
}
SQLExecDirectWStruct * SQLExecDirectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExecDirectWStruct * myptr = (SQLExecDirectWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecDirectWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLExecute( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLExecute( hstmt );
    break;
  default:
    sqlrc = libdb400_SQLExecute( hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExecute(sqlrc,  hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLExecuteThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLExecute( myptr->hstmt );
    break;
  default:
    myptr->sqlrc = libdb400_SQLExecute( myptr->hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExecute(myptr->sqlrc,  myptr->hstmt );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExecuteCallback(SQLExecuteStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExecuteStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExecuteAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) malloc(sizeof(SQLExecuteStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExecuteThread, (void *)myptr);
  return tid;
}
SQLExecuteStruct * SQLExecuteJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExecuteStruct * myptr = (SQLExecuteStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExecuteStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLExtendedFetch( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLExtendedFetch( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
    break;
  default:
    sqlrc = libdb400_SQLExtendedFetch( hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExtendedFetch(sqlrc,  hstmt, fOrient, fOffset, pcrow, rgfRowStatus );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLExtendedFetchThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLExtendedFetchStruct * myptr = (SQLExtendedFetchStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLExtendedFetch( myptr->hstmt, myptr->fOrient, myptr->fOffset, myptr->pcrow, myptr->rgfRowStatus );
    break;
  default:
    myptr->sqlrc = libdb400_SQLExtendedFetch( myptr->hstmt, myptr->fOrient, myptr->fOffset, myptr->pcrow, myptr->rgfRowStatus );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLExtendedFetch(myptr->sqlrc,  myptr->hstmt, myptr->fOrient, myptr->fOffset, myptr->pcrow, myptr->rgfRowStatus );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLExtendedFetchCallback(SQLExtendedFetchStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLExtendedFetchStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLExtendedFetchAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLExtendedFetchStruct * myptr = (SQLExtendedFetchStruct *) malloc(sizeof(SQLExtendedFetchStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOrient = fOrient;
  myptr->fOffset = fOffset;
  myptr->pcrow = pcrow;
  myptr->rgfRowStatus = rgfRowStatus;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLExtendedFetchThread, (void *)myptr);
  return tid;
}
SQLExtendedFetchStruct * SQLExtendedFetchJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLExtendedFetchStruct * myptr = (SQLExtendedFetchStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLExtendedFetchStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLFetch( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLFetch( hstmt );
    break;
  default:
    sqlrc = libdb400_SQLFetch( hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLFetch(sqlrc,  hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLFetchThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLFetchStruct * myptr = (SQLFetchStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLFetch( myptr->hstmt );
    break;
  default:
    myptr->sqlrc = libdb400_SQLFetch( myptr->hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLFetch(myptr->sqlrc,  myptr->hstmt );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLFetchCallback(SQLFetchStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLFetchStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLFetchAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLFetchStruct * myptr = (SQLFetchStruct *) malloc(sizeof(SQLFetchStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLFetchThread, (void *)myptr);
  return tid;
}
SQLFetchStruct * SQLFetchJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLFetchStruct * myptr = (SQLFetchStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLFetchStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLFetchScroll( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLFetchScroll( hstmt, fOrient, fOffset );
    break;
  default:
    sqlrc = libdb400_SQLFetchScroll( hstmt, fOrient, fOffset );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLFetchScroll(sqlrc,  hstmt, fOrient, fOffset );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLFetchScrollThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLFetchScrollStruct * myptr = (SQLFetchScrollStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLFetchScroll( myptr->hstmt, myptr->fOrient, myptr->fOffset );
    break;
  default:
    myptr->sqlrc = libdb400_SQLFetchScroll( myptr->hstmt, myptr->fOrient, myptr->fOffset );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLFetchScroll(myptr->sqlrc,  myptr->hstmt, myptr->fOrient, myptr->fOffset );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLFetchScrollCallback(SQLFetchScrollStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLFetchScrollStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLFetchScrollAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLFetchScrollStruct * myptr = (SQLFetchScrollStruct *) malloc(sizeof(SQLFetchScrollStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOrient = fOrient;
  myptr->fOffset = fOffset;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLFetchScrollThread, (void *)myptr);
  return tid;
}
SQLFetchScrollStruct * SQLFetchScrollJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLFetchScrollStruct * myptr = (SQLFetchScrollStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLFetchScrollStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLForeignKeys( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLForeignKeys( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
    break;
  default:
    sqlrc = libdb400_SQLForeignKeys( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLForeignKeys(sqlrc,  hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLForeignKeysThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLForeignKeysStruct * myptr = (SQLForeignKeysStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLForeignKeys( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLForeignKeys( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLForeignKeys(myptr->sqlrc,  myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLForeignKeysCallback(SQLForeignKeysStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLForeignKeysStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLForeignKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLForeignKeysStruct * myptr = (SQLForeignKeysStruct *) malloc(sizeof(SQLForeignKeysStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szPkTableQualifier = szPkTableQualifier;
  myptr->cbPkTableQualifier = cbPkTableQualifier;
  myptr->szPkTableOwner = szPkTableOwner;
  myptr->cbPkTableOwner = cbPkTableOwner;
  myptr->szPkTableName = szPkTableName;
  myptr->cbPkTableName = cbPkTableName;
  myptr->szFkTableQualifier = szFkTableQualifier;
  myptr->cbFkTableQualifier = cbFkTableQualifier;
  myptr->szFkTableOwner = szFkTableOwner;
  myptr->cbFkTableOwner = cbFkTableOwner;
  myptr->szFkTableName = szFkTableName;
  myptr->cbFkTableName = cbFkTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLForeignKeysThread, (void *)myptr);
  return tid;
}
SQLForeignKeysStruct * SQLForeignKeysJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLForeignKeysStruct * myptr = (SQLForeignKeysStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLForeignKeysStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLForeignKeysW( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLForeignKeysW( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
    break;
  default:
    sqlrc = libdb400_SQLForeignKeysW( hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLForeignKeysW(sqlrc,  hstmt, szPkTableQualifier, cbPkTableQualifier, szPkTableOwner, cbPkTableOwner, szPkTableName, cbPkTableName, szFkTableQualifier, cbFkTableQualifier, szFkTableOwner, cbFkTableOwner, szFkTableName, cbFkTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLForeignKeysWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLForeignKeysWStruct * myptr = (SQLForeignKeysWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLForeignKeysW( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLForeignKeysW( myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLForeignKeysW(myptr->sqlrc,  myptr->hstmt, myptr->szPkTableQualifier, myptr->cbPkTableQualifier, myptr->szPkTableOwner, myptr->cbPkTableOwner, myptr->szPkTableName, myptr->cbPkTableName, myptr->szFkTableQualifier, myptr->cbFkTableQualifier, myptr->szFkTableOwner, myptr->cbFkTableOwner, myptr->szFkTableName, myptr->cbFkTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLForeignKeysWCallback(SQLForeignKeysWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLForeignKeysWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLForeignKeysWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLForeignKeysWStruct * myptr = (SQLForeignKeysWStruct *) malloc(sizeof(SQLForeignKeysWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szPkTableQualifier = szPkTableQualifier;
  myptr->cbPkTableQualifier = cbPkTableQualifier;
  myptr->szPkTableOwner = szPkTableOwner;
  myptr->cbPkTableOwner = cbPkTableOwner;
  myptr->szPkTableName = szPkTableName;
  myptr->cbPkTableName = cbPkTableName;
  myptr->szFkTableQualifier = szFkTableQualifier;
  myptr->cbFkTableQualifier = cbFkTableQualifier;
  myptr->szFkTableOwner = szFkTableOwner;
  myptr->cbFkTableOwner = cbFkTableOwner;
  myptr->szFkTableName = szFkTableName;
  myptr->cbFkTableName = cbFkTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLForeignKeysWThread, (void *)myptr);
  return tid;
}
SQLForeignKeysWStruct * SQLForeignKeysWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLForeignKeysWStruct * myptr = (SQLForeignKeysWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLForeignKeysWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLFreeConnect( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  int active = init_table_hash_active(hdbc, 0);
  /* persistent connect only close with SQL400pClose */
  if (active) {
    return SQL_ERROR;
  }
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLFreeConnect( hdbc );
    break;
  default:
    sqlrc = libdb400_SQLFreeConnect( hdbc );
    break;
  }
  init_table_dtor(hdbc);
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLFreeConnect(sqlrc,  hdbc );
  }
  return sqlrc;
}
SQLRETURN SQLFreeEnv( SQLHENV  henv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLFreeEnv( henv );
    break;
  default:
    sqlrc = libdb400_SQLFreeEnv( henv );
    break;
  }
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLFreeEnv(sqlrc,  henv );
  }
  return sqlrc;
}
SQLRETURN SQLFreeStmt( SQLHSTMT  hstmt, SQLSMALLINT  fOption )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLFreeStmt( hstmt, fOption );
    break;
  default:
    sqlrc = libdb400_SQLFreeStmt( hstmt, fOption );
    break;
  }
  init_table_dtor(hstmt);
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLFreeStmt(sqlrc,  hstmt, fOption );
  }
  return sqlrc;
}
SQLRETURN SQLFreeHandle( SQLSMALLINT  htype, SQLINTEGER  hndl )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  int persistent = init_table_hash_active(hndl, 0);
  /* persistent connect only close with SQL400pClose */
  switch (htype) {
  case SQL_HANDLE_DBC:
    if (persistent) {
      return SQL_ERROR;
    }
    break;
  default:
    break;
  }
  init_lock();
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLFreeHandle( htype, hndl );
    break;
  default:
    sqlrc = libdb400_SQLFreeHandle( htype, hndl );
    break;
  }
  switch (htype) {
  case SQL_HANDLE_ENV:
    break;
  default:
    init_table_dtor(hndl);
    break;
  }
  init_unlock();
  if (init_cli_trace()) {
    dump_SQLFreeHandle(sqlrc,  htype, hndl );
  }
  return sqlrc;
}
SQLRETURN SQLGetCol( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetCol( hstmt, icol, itype, tval, blen, olen );
    break;
  default:
    sqlrc = libdb400_SQLGetCol( hstmt, icol, itype, tval, blen, olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetCol(sqlrc,  hstmt, icol, itype, tval, blen, olen );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetColThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetColStruct * myptr = (SQLGetColStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetCol( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetCol( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetCol(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetColCallback(SQLGetColStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetColStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetColAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetColStruct * myptr = (SQLGetColStruct *) malloc(sizeof(SQLGetColStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->itype = itype;
  myptr->tval = tval;
  myptr->blen = blen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetColThread, (void *)myptr);
  return tid;
}
SQLGetColStruct * SQLGetColJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetColStruct * myptr = (SQLGetColStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetColStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetColW( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetColW( hstmt, icol, itype, tval, blen, olen );
    break;
  default:
    sqlrc = libdb400_SQLGetColW( hstmt, icol, itype, tval, blen, olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetColW(sqlrc,  hstmt, icol, itype, tval, blen, olen );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetColWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetColWStruct * myptr = (SQLGetColWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetColW( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetColW( myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetColW(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->itype, myptr->tval, myptr->blen, myptr->olen );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetColWCallback(SQLGetColWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetColWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetColWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetColWStruct * myptr = (SQLGetColWStruct *) malloc(sizeof(SQLGetColWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->itype = itype;
  myptr->tval = tval;
  myptr->blen = blen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetColWThread, (void *)myptr);
  return tid;
}
SQLGetColWStruct * SQLGetColWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetColWStruct * myptr = (SQLGetColWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetColWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetConnectAttr( hdbc, attr, oval, ilen, olen );
    break;
  default:
    sqlrc = libdb400_SQLGetConnectAttr( hdbc, attr, oval, ilen, olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectAttr(sqlrc,  hdbc, attr, oval, ilen, olen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetConnectAttrThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetConnectAttr( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetConnectAttr( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectAttr(myptr->sqlrc,  myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectAttrCallback(SQLGetConnectAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) malloc(sizeof(SQLGetConnectAttrStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attr = attr;
  myptr->oval = oval;
  myptr->ilen = ilen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectAttrThread, (void *)myptr);
  return tid;
}
SQLGetConnectAttrStruct * SQLGetConnectAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectAttrStruct * myptr = (SQLGetConnectAttrStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectAttrStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetConnectAttrW( hdbc, attr, oval, ilen, olen );
    break;
  default:
    sqlrc = libdb400_SQLGetConnectAttrW( hdbc, attr, oval, ilen, olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectAttrW(sqlrc,  hdbc, attr, oval, ilen, olen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetConnectAttrWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetConnectAttrWStruct * myptr = (SQLGetConnectAttrWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetConnectAttrW( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetConnectAttrW( myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectAttrW(myptr->sqlrc,  myptr->hdbc, myptr->attr, myptr->oval, myptr->ilen, myptr->olen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectAttrWCallback(SQLGetConnectAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectAttrWAsync ( SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectAttrWStruct * myptr = (SQLGetConnectAttrWStruct *) malloc(sizeof(SQLGetConnectAttrWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attr = attr;
  myptr->oval = oval;
  myptr->ilen = ilen;
  myptr->olen = olen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectAttrWThread, (void *)myptr);
  return tid;
}
SQLGetConnectAttrWStruct * SQLGetConnectAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectAttrWStruct * myptr = (SQLGetConnectAttrWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectAttrWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetConnectOption( hdbc, iopt, oval );
    break;
  default:
    sqlrc = libdb400_SQLGetConnectOption( hdbc, iopt, oval );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectOption(sqlrc,  hdbc, iopt, oval );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetConnectOptionThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetConnectOption( myptr->hdbc, myptr->iopt, myptr->oval );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetConnectOption( myptr->hdbc, myptr->iopt, myptr->oval );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectOption(myptr->sqlrc,  myptr->hdbc, myptr->iopt, myptr->oval );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectOptionCallback(SQLGetConnectOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) malloc(sizeof(SQLGetConnectOptionStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->iopt = iopt;
  myptr->oval = oval;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectOptionThread, (void *)myptr);
  return tid;
}
SQLGetConnectOptionStruct * SQLGetConnectOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectOptionStruct * myptr = (SQLGetConnectOptionStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectOptionStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetConnectOptionW( hdbc, iopt, oval );
    break;
  default:
    sqlrc = libdb400_SQLGetConnectOptionW( hdbc, iopt, oval );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectOptionW(sqlrc,  hdbc, iopt, oval );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetConnectOptionWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetConnectOptionWStruct * myptr = (SQLGetConnectOptionWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetConnectOptionW( myptr->hdbc, myptr->iopt, myptr->oval );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetConnectOptionW( myptr->hdbc, myptr->iopt, myptr->oval );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetConnectOptionW(myptr->sqlrc,  myptr->hdbc, myptr->iopt, myptr->oval );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetConnectOptionWCallback(SQLGetConnectOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetConnectOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetConnectOptionWAsync ( SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetConnectOptionWStruct * myptr = (SQLGetConnectOptionWStruct *) malloc(sizeof(SQLGetConnectOptionWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->iopt = iopt;
  myptr->oval = oval;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetConnectOptionWThread, (void *)myptr);
  return tid;
}
SQLGetConnectOptionWStruct * SQLGetConnectOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetConnectOptionWStruct * myptr = (SQLGetConnectOptionWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetConnectOptionWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetCursorName( hstmt, szCursor, cbCursorMax, pcbCursor );
    break;
  default:
    sqlrc = libdb400_SQLGetCursorName( hstmt, szCursor, cbCursorMax, pcbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetCursorName(sqlrc,  hstmt, szCursor, cbCursorMax, pcbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetCursorNameThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetCursorName(myptr->sqlrc,  myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetCursorNameCallback(SQLGetCursorNameStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetCursorNameStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) malloc(sizeof(SQLGetCursorNameStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursorMax = cbCursorMax;
  myptr->pcbCursor = pcbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetCursorNameThread, (void *)myptr);
  return tid;
}
SQLGetCursorNameStruct * SQLGetCursorNameJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetCursorNameStruct * myptr = (SQLGetCursorNameStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetCursorNameStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetCursorNameW( hstmt, szCursor, cbCursorMax, pcbCursor );
    break;
  default:
    sqlrc = libdb400_SQLGetCursorNameW( hstmt, szCursor, cbCursorMax, pcbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetCursorNameW(sqlrc,  hstmt, szCursor, cbCursorMax, pcbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetCursorNameWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetCursorNameWStruct * myptr = (SQLGetCursorNameWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetCursorNameW(myptr->sqlrc,  myptr->hstmt, myptr->szCursor, myptr->cbCursorMax, myptr->pcbCursor );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetCursorNameWCallback(SQLGetCursorNameWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetCursorNameWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetCursorNameWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetCursorNameWStruct * myptr = (SQLGetCursorNameWStruct *) malloc(sizeof(SQLGetCursorNameWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursorMax = cbCursorMax;
  myptr->pcbCursor = pcbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetCursorNameWThread, (void *)myptr);
  return tid;
}
SQLGetCursorNameWStruct * SQLGetCursorNameWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetCursorNameWStruct * myptr = (SQLGetCursorNameWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetCursorNameWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetData( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetData( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLGetData( hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetData(sqlrc,  hstmt, icol, fCType, rgbValue, cbValueMax, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetDataThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetData( myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetData( myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetData(myptr->sqlrc,  myptr->hstmt, myptr->icol, myptr->fCType, myptr->rgbValue, myptr->cbValueMax, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetDataCallback(SQLGetDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDataAsync ( SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) malloc(sizeof(SQLGetDataStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->icol = icol;
  myptr->fCType = fCType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDataThread, (void *)myptr);
  return tid;
}
SQLGetDataStruct * SQLGetDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDataStruct * myptr = (SQLGetDataStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDataStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDescField( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
    break;
  default:
    sqlrc = libdb400_SQLGetDescField( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescField(sqlrc,  hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLGetDescFieldThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDescFieldStruct * myptr = (SQLGetDescFieldStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDescField( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDescField( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescField(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescFieldCallback(SQLGetDescFieldStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescFieldStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescFieldStruct * myptr = (SQLGetDescFieldStruct *) malloc(sizeof(SQLGetDescFieldStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fieldID = fieldID;
  myptr->fValue = fValue;
  myptr->fLength = fLength;
  myptr->stLength = stLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescFieldThread, (void *)myptr);
  return tid;
}
SQLGetDescFieldStruct * SQLGetDescFieldJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescFieldStruct * myptr = (SQLGetDescFieldStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescFieldStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDescFieldW( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
    break;
  default:
    sqlrc = libdb400_SQLGetDescFieldW( hdesc, rcdNum, fieldID, fValue, fLength, stLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescFieldW(sqlrc,  hdesc, rcdNum, fieldID, fValue, fLength, stLength );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLGetDescFieldWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDescFieldWStruct * myptr = (SQLGetDescFieldWStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescFieldW(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->fieldID, myptr->fValue, myptr->fLength, myptr->stLength );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescFieldWCallback(SQLGetDescFieldWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescFieldWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescFieldWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescFieldWStruct * myptr = (SQLGetDescFieldWStruct *) malloc(sizeof(SQLGetDescFieldWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fieldID = fieldID;
  myptr->fValue = fValue;
  myptr->fLength = fLength;
  myptr->stLength = stLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescFieldWThread, (void *)myptr);
  return tid;
}
SQLGetDescFieldWStruct * SQLGetDescFieldWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescFieldWStruct * myptr = (SQLGetDescFieldWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescFieldWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDescRec( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
    break;
  default:
    sqlrc = libdb400_SQLGetDescRec( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescRec(sqlrc,  hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLGetDescRecThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDescRec( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDescRec( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescRec(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescRecCallback(SQLGetDescRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) malloc(sizeof(SQLGetDescRecStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fname = fname;
  myptr->bufLen = bufLen;
  myptr->sLength = sLength;
  myptr->sType = sType;
  myptr->sbType = sbType;
  myptr->fLength = fLength;
  myptr->fprec = fprec;
  myptr->fscale = fscale;
  myptr->fnull = fnull;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescRecThread, (void *)myptr);
  return tid;
}
SQLGetDescRecStruct * SQLGetDescRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescRecStruct * myptr = (SQLGetDescRecStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescRecStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDescRecW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDescRecW( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
    break;
  default:
    sqlrc = libdb400_SQLGetDescRecW( hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescRecW(sqlrc,  hdesc, rcdNum, fname, bufLen, sLength, sType, sbType, fLength, fprec, fscale, fnull );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLGetDescRecWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDescRecWStruct * myptr = (SQLGetDescRecWStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDescRecW( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDescRecW( myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDescRecW(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->fname, myptr->bufLen, myptr->sLength, myptr->sType, myptr->sbType, myptr->fLength, myptr->fprec, myptr->fscale, myptr->fnull );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLGetDescRecWCallback(SQLGetDescRecWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDescRecWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDescRecWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDescRecWStruct * myptr = (SQLGetDescRecWStruct *) malloc(sizeof(SQLGetDescRecWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fname = fname;
  myptr->bufLen = bufLen;
  myptr->sLength = sLength;
  myptr->sType = sType;
  myptr->sbType = sbType;
  myptr->fLength = fLength;
  myptr->fprec = fprec;
  myptr->fscale = fscale;
  myptr->fnull = fnull;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDescRecWThread, (void *)myptr);
  return tid;
}
SQLGetDescRecWStruct * SQLGetDescRecWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDescRecWStruct * myptr = (SQLGetDescRecWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDescRecWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDiagField( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDiagField( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
    break;
  default:
    sqlrc = libdb400_SQLGetDiagField( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagField(sqlrc,  hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  }
  return sqlrc;
}
void * SQLGetDiagFieldThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) ptr;
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDiagField( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDiagField( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagField(myptr->sqlrc,  myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  }
  /* void SQLGetDiagFieldCallback(SQLGetDiagFieldStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagFieldStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagFieldAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) malloc(sizeof(SQLGetDiagFieldStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->diagID = diagID;
  myptr->dValue = dValue;
  myptr->bLength = bLength;
  myptr->sLength = sLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagFieldThread, (void *)myptr);
  return tid;
}
SQLGetDiagFieldStruct * SQLGetDiagFieldJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagFieldStruct * myptr = (SQLGetDiagFieldStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagFieldStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDiagFieldW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDiagFieldW( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
    break;
  default:
    sqlrc = libdb400_SQLGetDiagFieldW( hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagFieldW(sqlrc,  hType, hndl, rcdNum, diagID, dValue, bLength, sLength );
  }
  return sqlrc;
}
void * SQLGetDiagFieldWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDiagFieldWStruct * myptr = (SQLGetDiagFieldWStruct *) ptr;
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDiagFieldW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDiagFieldW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagFieldW(myptr->sqlrc,  myptr->hType, myptr->hndl, myptr->rcdNum, myptr->diagID, myptr->dValue, myptr->bLength, myptr->sLength );
  }
  /* void SQLGetDiagFieldWCallback(SQLGetDiagFieldWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagFieldWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagFieldWAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagFieldWStruct * myptr = (SQLGetDiagFieldWStruct *) malloc(sizeof(SQLGetDiagFieldWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->diagID = diagID;
  myptr->dValue = dValue;
  myptr->bLength = bLength;
  myptr->sLength = sLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagFieldWThread, (void *)myptr);
  return tid;
}
SQLGetDiagFieldWStruct * SQLGetDiagFieldWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagFieldWStruct * myptr = (SQLGetDiagFieldWStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagFieldWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDiagRec( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDiagRec( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
    break;
  default:
    sqlrc = libdb400_SQLGetDiagRec( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagRec(sqlrc,  hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  }
  return sqlrc;
}
void * SQLGetDiagRecThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) ptr;
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDiagRec( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDiagRec( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagRec(myptr->sqlrc,  myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
  }
  /* void SQLGetDiagRecCallback(SQLGetDiagRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagRecAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) malloc(sizeof(SQLGetDiagRecStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->SQLstate = SQLstate;
  myptr->SQLcode = SQLcode;
  myptr->msgText = msgText;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagRecThread, (void *)myptr);
  return tid;
}
SQLGetDiagRecStruct * SQLGetDiagRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagRecStruct * myptr = (SQLGetDiagRecStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagRecStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetDiagRecW( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetDiagRecW( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
    break;
  default:
    sqlrc = libdb400_SQLGetDiagRecW( hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagRecW(sqlrc,  hType, hndl, rcdNum, SQLstate, SQLcode, msgText, bLength, SLength );
  }
  return sqlrc;
}
void * SQLGetDiagRecWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetDiagRecWStruct * myptr = (SQLGetDiagRecWStruct *) ptr;
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetDiagRecW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetDiagRecW( myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetDiagRecW(myptr->sqlrc,  myptr->hType, myptr->hndl, myptr->rcdNum, myptr->SQLstate, myptr->SQLcode, myptr->msgText, myptr->bLength, myptr->SLength );
  }
  /* void SQLGetDiagRecWCallback(SQLGetDiagRecWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetDiagRecWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetDiagRecWAsync ( SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetDiagRecWStruct * myptr = (SQLGetDiagRecWStruct *) malloc(sizeof(SQLGetDiagRecWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hType = hType;
  myptr->hndl = hndl;
  myptr->rcdNum = rcdNum;
  myptr->SQLstate = SQLstate;
  myptr->SQLcode = SQLcode;
  myptr->msgText = msgText;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetDiagRecWThread, (void *)myptr);
  return tid;
}
SQLGetDiagRecWStruct * SQLGetDiagRecWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetDiagRecWStruct * myptr = (SQLGetDiagRecWStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetDiagRecWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetEnvAttr( hEnv, fAttribute, pParam, cbParamMax, pcbParam );
    break;
  default:
    sqlrc = libdb400_SQLGetEnvAttr( hEnv, fAttribute, pParam, cbParamMax, pcbParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetEnvAttr(sqlrc,  hEnv, fAttribute, pParam, cbParamMax, pcbParam );
  }
  return sqlrc;
}
void * SQLGetEnvAttrThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParamMax, myptr->pcbParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParamMax, myptr->pcbParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetEnvAttr(myptr->sqlrc,  myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParamMax, myptr->pcbParam );
  }
  /* not lock */
  /* void SQLGetEnvAttrCallback(SQLGetEnvAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetEnvAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetEnvAttrAsync ( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) malloc(sizeof(SQLGetEnvAttrStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hEnv = hEnv;
  myptr->fAttribute = fAttribute;
  myptr->pParam = pParam;
  myptr->cbParamMax = cbParamMax;
  myptr->pcbParam = pcbParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetEnvAttrThread, (void *)myptr);
  return tid;
}
SQLGetEnvAttrStruct * SQLGetEnvAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetEnvAttrStruct * myptr = (SQLGetEnvAttrStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetEnvAttrStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetFunctions( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetFunctions( hdbc, fFunction, pfExists );
    break;
  default:
    sqlrc = libdb400_SQLGetFunctions( hdbc, fFunction, pfExists );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetFunctions(sqlrc,  hdbc, fFunction, pfExists );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetFunctionsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetFunctionsStruct * myptr = (SQLGetFunctionsStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetFunctions( myptr->hdbc, myptr->fFunction, myptr->pfExists );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetFunctions( myptr->hdbc, myptr->fFunction, myptr->pfExists );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetFunctions(myptr->sqlrc,  myptr->hdbc, myptr->fFunction, myptr->pfExists );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetFunctionsCallback(SQLGetFunctionsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetFunctionsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetFunctionsAsync ( SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetFunctionsStruct * myptr = (SQLGetFunctionsStruct *) malloc(sizeof(SQLGetFunctionsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fFunction = fFunction;
  myptr->pfExists = pfExists;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetFunctionsThread, (void *)myptr);
  return tid;
}
SQLGetFunctionsStruct * SQLGetFunctionsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetFunctionsStruct * myptr = (SQLGetFunctionsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetFunctionsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetInfo( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetInfo( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
    break;
  default:
    sqlrc = libdb400_SQLGetInfo( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetInfo(sqlrc,  hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetInfoThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetInfoStruct * myptr = (SQLGetInfoStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetInfo( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetInfo( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetInfo(myptr->sqlrc,  myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetInfoCallback(SQLGetInfoStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetInfoStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetInfoAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetInfoStruct * myptr = (SQLGetInfoStruct *) malloc(sizeof(SQLGetInfoStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fInfoType = fInfoType;
  myptr->rgbInfoValue = rgbInfoValue;
  myptr->cbInfoValueMax = cbInfoValueMax;
  myptr->pcbInfoValue = pcbInfoValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetInfoThread, (void *)myptr);
  return tid;
}
SQLGetInfoStruct * SQLGetInfoJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetInfoStruct * myptr = (SQLGetInfoStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetInfoStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetInfoW( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetInfoW( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
    break;
  default:
    sqlrc = libdb400_SQLGetInfoW( hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetInfoW(sqlrc,  hdbc, fInfoType, rgbInfoValue, cbInfoValueMax, pcbInfoValue );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLGetInfoWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetInfoWStruct * myptr = (SQLGetInfoWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetInfoW( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetInfoW( myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetInfoW(myptr->sqlrc,  myptr->hdbc, myptr->fInfoType, myptr->rgbInfoValue, myptr->cbInfoValueMax, myptr->pcbInfoValue );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLGetInfoWCallback(SQLGetInfoWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetInfoWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetInfoWAsync ( SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetInfoWStruct * myptr = (SQLGetInfoWStruct *) malloc(sizeof(SQLGetInfoWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fInfoType = fInfoType;
  myptr->rgbInfoValue = rgbInfoValue;
  myptr->cbInfoValueMax = cbInfoValueMax;
  myptr->pcbInfoValue = pcbInfoValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetInfoWThread, (void *)myptr);
  return tid;
}
SQLGetInfoWStruct * SQLGetInfoWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetInfoWStruct * myptr = (SQLGetInfoWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetInfoWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetLength( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetLength( hstmt, locType, locator, sLength, ind );
    break;
  default:
    sqlrc = libdb400_SQLGetLength( hstmt, locType, locator, sLength, ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetLength(sqlrc,  hstmt, locType, locator, sLength, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetLengthThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetLength( myptr->hstmt, myptr->locType, myptr->locator, myptr->sLength, myptr->ind );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetLength( myptr->hstmt, myptr->locType, myptr->locator, myptr->sLength, myptr->ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetLength(myptr->sqlrc,  myptr->hstmt, myptr->locType, myptr->locator, myptr->sLength, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetLengthCallback(SQLGetLengthStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetLengthStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetLengthAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) malloc(sizeof(SQLGetLengthStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->locator = locator;
  myptr->sLength = sLength;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetLengthThread, (void *)myptr);
  return tid;
}
SQLGetLengthStruct * SQLGetLengthJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetLengthStruct * myptr = (SQLGetLengthStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetLengthStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetPosition( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetPosition( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
    break;
  default:
    sqlrc = libdb400_SQLGetPosition( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetPosition(sqlrc,  hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetPositionThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetPositionStruct * myptr = (SQLGetPositionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetPosition( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetPosition( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetPosition(myptr->sqlrc,  myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetPositionCallback(SQLGetPositionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetPositionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetPositionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetPositionStruct * myptr = (SQLGetPositionStruct *) malloc(sizeof(SQLGetPositionStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->srceLocator = srceLocator;
  myptr->srchLocator = srchLocator;
  myptr->srchLiteral = srchLiteral;
  myptr->srchLiteralLen = srchLiteralLen;
  myptr->fPosition = fPosition;
  myptr->located = located;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetPositionThread, (void *)myptr);
  return tid;
}
SQLGetPositionStruct * SQLGetPositionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetPositionStruct * myptr = (SQLGetPositionStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetPositionStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetPositionW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetPositionW( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
    break;
  default:
    sqlrc = libdb400_SQLGetPositionW( hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetPositionW(sqlrc,  hstmt, locType, srceLocator, srchLocator, srchLiteral, srchLiteralLen, fPosition, located, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetPositionWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetPositionWStruct * myptr = (SQLGetPositionWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetPositionW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetPositionW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetPositionW(myptr->sqlrc,  myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->srchLocator, myptr->srchLiteral, myptr->srchLiteralLen, myptr->fPosition, myptr->located, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetPositionWCallback(SQLGetPositionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetPositionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetPositionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetPositionWStruct * myptr = (SQLGetPositionWStruct *) malloc(sizeof(SQLGetPositionWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->srceLocator = srceLocator;
  myptr->srchLocator = srchLocator;
  myptr->srchLiteral = srchLiteral;
  myptr->srchLiteralLen = srchLiteralLen;
  myptr->fPosition = fPosition;
  myptr->located = located;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetPositionWThread, (void *)myptr);
  return tid;
}
SQLGetPositionWStruct * SQLGetPositionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetPositionWStruct * myptr = (SQLGetPositionWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetPositionWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetStmtAttr( hstmt, fAttr, pvParam, bLength, SLength );
    break;
  default:
    sqlrc = libdb400_SQLGetStmtAttr( hstmt, fAttr, pvParam, bLength, SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtAttr(sqlrc,  hstmt, fAttr, pvParam, bLength, SLength );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetStmtAttrThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtAttr(myptr->sqlrc,  myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtAttrCallback(SQLGetStmtAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) malloc(sizeof(SQLGetStmtAttrStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pvParam = pvParam;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtAttrThread, (void *)myptr);
  return tid;
}
SQLGetStmtAttrStruct * SQLGetStmtAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtAttrStruct * myptr = (SQLGetStmtAttrStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtAttrStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetStmtAttrW( hstmt, fAttr, pvParam, bLength, SLength );
    break;
  default:
    sqlrc = libdb400_SQLGetStmtAttrW( hstmt, fAttr, pvParam, bLength, SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtAttrW(sqlrc,  hstmt, fAttr, pvParam, bLength, SLength );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetStmtAttrWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetStmtAttrWStruct * myptr = (SQLGetStmtAttrWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtAttrW(myptr->sqlrc,  myptr->hstmt, myptr->fAttr, myptr->pvParam, myptr->bLength, myptr->SLength );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtAttrWCallback(SQLGetStmtAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtAttrWAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtAttrWStruct * myptr = (SQLGetStmtAttrWStruct *) malloc(sizeof(SQLGetStmtAttrWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pvParam = pvParam;
  myptr->bLength = bLength;
  myptr->SLength = SLength;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtAttrWThread, (void *)myptr);
  return tid;
}
SQLGetStmtAttrWStruct * SQLGetStmtAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtAttrWStruct * myptr = (SQLGetStmtAttrWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtAttrWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetStmtOption( hstmt, fOption, pvParam );
    break;
  default:
    sqlrc = libdb400_SQLGetStmtOption( hstmt, fOption, pvParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtOption(sqlrc,  hstmt, fOption, pvParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetStmtOptionThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetStmtOption( myptr->hstmt, myptr->fOption, myptr->pvParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetStmtOption( myptr->hstmt, myptr->fOption, myptr->pvParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtOption(myptr->sqlrc,  myptr->hstmt, myptr->fOption, myptr->pvParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtOptionCallback(SQLGetStmtOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) malloc(sizeof(SQLGetStmtOptionStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->pvParam = pvParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtOptionThread, (void *)myptr);
  return tid;
}
SQLGetStmtOptionStruct * SQLGetStmtOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtOptionStruct * myptr = (SQLGetStmtOptionStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtOptionStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetStmtOptionW( hstmt, fOption, pvParam );
    break;
  default:
    sqlrc = libdb400_SQLGetStmtOptionW( hstmt, fOption, pvParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtOptionW(sqlrc,  hstmt, fOption, pvParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetStmtOptionWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetStmtOptionWStruct * myptr = (SQLGetStmtOptionWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->pvParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->pvParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetStmtOptionW(myptr->sqlrc,  myptr->hstmt, myptr->fOption, myptr->pvParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetStmtOptionWCallback(SQLGetStmtOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetStmtOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetStmtOptionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetStmtOptionWStruct * myptr = (SQLGetStmtOptionWStruct *) malloc(sizeof(SQLGetStmtOptionWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->pvParam = pvParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetStmtOptionWThread, (void *)myptr);
  return tid;
}
SQLGetStmtOptionWStruct * SQLGetStmtOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetStmtOptionWStruct * myptr = (SQLGetStmtOptionWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetStmtOptionWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetSubString( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetSubString( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
    break;
  default:
    sqlrc = libdb400_SQLGetSubString( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetSubString(sqlrc,  hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetSubStringThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetSubString( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetSubString( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetSubString(myptr->sqlrc,  myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetSubStringCallback(SQLGetSubStringStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetSubStringStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetSubStringAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) malloc(sizeof(SQLGetSubStringStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->srceLocator = srceLocator;
  myptr->fPosition = fPosition;
  myptr->length = length;
  myptr->tType = tType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->StringLength = StringLength;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetSubStringThread, (void *)myptr);
  return tid;
}
SQLGetSubStringStruct * SQLGetSubStringJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetSubStringStruct * myptr = (SQLGetSubStringStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetSubStringStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetSubStringW( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetSubStringW( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
    break;
  default:
    sqlrc = libdb400_SQLGetSubStringW( hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetSubStringW(sqlrc,  hstmt, locType, srceLocator, fPosition, length, tType, rgbValue, cbValueMax, StringLength, ind );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetSubStringWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetSubStringWStruct * myptr = (SQLGetSubStringWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetSubStringW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetSubStringW( myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetSubStringW(myptr->sqlrc,  myptr->hstmt, myptr->locType, myptr->srceLocator, myptr->fPosition, myptr->length, myptr->tType, myptr->rgbValue, myptr->cbValueMax, myptr->StringLength, myptr->ind );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetSubStringWCallback(SQLGetSubStringWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetSubStringWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetSubStringWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetSubStringWStruct * myptr = (SQLGetSubStringWStruct *) malloc(sizeof(SQLGetSubStringWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->locType = locType;
  myptr->srceLocator = srceLocator;
  myptr->fPosition = fPosition;
  myptr->length = length;
  myptr->tType = tType;
  myptr->rgbValue = rgbValue;
  myptr->cbValueMax = cbValueMax;
  myptr->StringLength = StringLength;
  myptr->ind = ind;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetSubStringWThread, (void *)myptr);
  return tid;
}
SQLGetSubStringWStruct * SQLGetSubStringWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetSubStringWStruct * myptr = (SQLGetSubStringWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetSubStringWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetTypeInfo( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetTypeInfo( hstmt, fSqlType );
    break;
  default:
    sqlrc = libdb400_SQLGetTypeInfo( hstmt, fSqlType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetTypeInfo(sqlrc,  hstmt, fSqlType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetTypeInfoThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetTypeInfo( myptr->hstmt, myptr->fSqlType );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetTypeInfo( myptr->hstmt, myptr->fSqlType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetTypeInfo(myptr->sqlrc,  myptr->hstmt, myptr->fSqlType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetTypeInfoCallback(SQLGetTypeInfoStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetTypeInfoStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetTypeInfoAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) malloc(sizeof(SQLGetTypeInfoStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fSqlType = fSqlType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetTypeInfoThread, (void *)myptr);
  return tid;
}
SQLGetTypeInfoStruct * SQLGetTypeInfoJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetTypeInfoStruct * myptr = (SQLGetTypeInfoStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetTypeInfoStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLGetTypeInfoW( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLGetTypeInfoW( hstmt, fSqlType );
    break;
  default:
    sqlrc = libdb400_SQLGetTypeInfoW( hstmt, fSqlType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetTypeInfoW(sqlrc,  hstmt, fSqlType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLGetTypeInfoWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLGetTypeInfoWStruct * myptr = (SQLGetTypeInfoWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLGetTypeInfoW( myptr->hstmt, myptr->fSqlType );
    break;
  default:
    myptr->sqlrc = libdb400_SQLGetTypeInfoW( myptr->hstmt, myptr->fSqlType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLGetTypeInfoW(myptr->sqlrc,  myptr->hstmt, myptr->fSqlType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLGetTypeInfoWCallback(SQLGetTypeInfoWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLGetTypeInfoWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLGetTypeInfoWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fSqlType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLGetTypeInfoWStruct * myptr = (SQLGetTypeInfoWStruct *) malloc(sizeof(SQLGetTypeInfoWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fSqlType = fSqlType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLGetTypeInfoWThread, (void *)myptr);
  return tid;
}
SQLGetTypeInfoWStruct * SQLGetTypeInfoWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLGetTypeInfoWStruct * myptr = (SQLGetTypeInfoWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLGetTypeInfoWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLLanguages( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLLanguages( hstmt );
    break;
  default:
    sqlrc = libdb400_SQLLanguages( hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLLanguages(sqlrc,  hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLLanguagesThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLLanguages( myptr->hstmt );
    break;
  default:
    myptr->sqlrc = libdb400_SQLLanguages( myptr->hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLLanguages(myptr->sqlrc,  myptr->hstmt );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLLanguagesCallback(SQLLanguagesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLLanguagesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLLanguagesAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) malloc(sizeof(SQLLanguagesStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLLanguagesThread, (void *)myptr);
  return tid;
}
SQLLanguagesStruct * SQLLanguagesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLLanguagesStruct * myptr = (SQLLanguagesStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLLanguagesStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLMoreResults( SQLHSTMT  hstmt )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLMoreResults( hstmt );
    break;
  default:
    sqlrc = libdb400_SQLMoreResults( hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLMoreResults(sqlrc,  hstmt );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLMoreResultsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLMoreResultsStruct * myptr = (SQLMoreResultsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLMoreResults( myptr->hstmt );
    break;
  default:
    myptr->sqlrc = libdb400_SQLMoreResults( myptr->hstmt );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLMoreResults(myptr->sqlrc,  myptr->hstmt );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLMoreResultsCallback(SQLMoreResultsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLMoreResultsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLMoreResultsAsync ( SQLHSTMT  hstmt, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLMoreResultsStruct * myptr = (SQLMoreResultsStruct *) malloc(sizeof(SQLMoreResultsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLMoreResultsThread, (void *)myptr);
  return tid;
}
SQLMoreResultsStruct * SQLMoreResultsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLMoreResultsStruct * myptr = (SQLMoreResultsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLMoreResultsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLNativeSql( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLNativeSql( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
    break;
  default:
    sqlrc = libdb400_SQLNativeSql( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNativeSql(sqlrc,  hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLNativeSqlThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLNativeSqlStruct * myptr = (SQLNativeSqlStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLNativeSql( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLNativeSql( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNativeSql(myptr->sqlrc,  myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLNativeSqlCallback(SQLNativeSqlStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNativeSqlStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNativeSqlAsync ( SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNativeSqlStruct * myptr = (SQLNativeSqlStruct *) malloc(sizeof(SQLNativeSqlStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szSqlStrIn = szSqlStrIn;
  myptr->cbSqlStrIn = cbSqlStrIn;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStrMax = cbSqlStrMax;
  myptr->pcbSqlStr = pcbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNativeSqlThread, (void *)myptr);
  return tid;
}
SQLNativeSqlStruct * SQLNativeSqlJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNativeSqlStruct * myptr = (SQLNativeSqlStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNativeSqlStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLNativeSqlW( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLNativeSqlW( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
    break;
  default:
    sqlrc = libdb400_SQLNativeSqlW( hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNativeSqlW(sqlrc,  hdbc, szSqlStrIn, cbSqlStrIn, szSqlStr, cbSqlStrMax, pcbSqlStr );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLNativeSqlWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLNativeSqlWStruct * myptr = (SQLNativeSqlWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLNativeSqlW( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLNativeSqlW( myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNativeSqlW(myptr->sqlrc,  myptr->hdbc, myptr->szSqlStrIn, myptr->cbSqlStrIn, myptr->szSqlStr, myptr->cbSqlStrMax, myptr->pcbSqlStr );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLNativeSqlWCallback(SQLNativeSqlWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNativeSqlWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNativeSqlWAsync ( SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNativeSqlWStruct * myptr = (SQLNativeSqlWStruct *) malloc(sizeof(SQLNativeSqlWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->szSqlStrIn = szSqlStrIn;
  myptr->cbSqlStrIn = cbSqlStrIn;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStrMax = cbSqlStrMax;
  myptr->pcbSqlStr = pcbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNativeSqlWThread, (void *)myptr);
  return tid;
}
SQLNativeSqlWStruct * SQLNativeSqlWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNativeSqlWStruct * myptr = (SQLNativeSqlWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNativeSqlWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLNextResult( SQLHSTMT  hstmt, SQLHSTMT  hstmt2 )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLNextResult( hstmt, hstmt2 );
    break;
  default:
    sqlrc = libdb400_SQLNextResult( hstmt, hstmt2 );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNextResult(sqlrc,  hstmt, hstmt2 );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLNextResultThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLNextResult( myptr->hstmt, myptr->hstmt2 );
    break;
  default:
    myptr->sqlrc = libdb400_SQLNextResult( myptr->hstmt, myptr->hstmt2 );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNextResult(myptr->sqlrc,  myptr->hstmt, myptr->hstmt2 );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLNextResultCallback(SQLNextResultStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNextResultStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNextResultAsync ( SQLHSTMT  hstmt, SQLHSTMT  hstmt2, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) malloc(sizeof(SQLNextResultStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->hstmt2 = hstmt2;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNextResultThread, (void *)myptr);
  return tid;
}
SQLNextResultStruct * SQLNextResultJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNextResultStruct * myptr = (SQLNextResultStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNextResultStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLNumParams( SQLHSTMT  hstmt, SQLSMALLINT * pcpar )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLNumParams( hstmt, pcpar );
    break;
  default:
    sqlrc = libdb400_SQLNumParams( hstmt, pcpar );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNumParams(sqlrc,  hstmt, pcpar );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLNumParamsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLNumParamsStruct * myptr = (SQLNumParamsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLNumParams( myptr->hstmt, myptr->pcpar );
    break;
  default:
    myptr->sqlrc = libdb400_SQLNumParams( myptr->hstmt, myptr->pcpar );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNumParams(myptr->sqlrc,  myptr->hstmt, myptr->pcpar );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLNumParamsCallback(SQLNumParamsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNumParamsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNumParamsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pcpar, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNumParamsStruct * myptr = (SQLNumParamsStruct *) malloc(sizeof(SQLNumParamsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->pcpar = pcpar;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNumParamsThread, (void *)myptr);
  return tid;
}
SQLNumParamsStruct * SQLNumParamsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNumParamsStruct * myptr = (SQLNumParamsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNumParamsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLNumResultCols( SQLHSTMT  hstmt, SQLSMALLINT * pccol )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLNumResultCols( hstmt, pccol );
    break;
  default:
    sqlrc = libdb400_SQLNumResultCols( hstmt, pccol );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNumResultCols(sqlrc,  hstmt, pccol );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLNumResultColsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLNumResultColsStruct * myptr = (SQLNumResultColsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLNumResultCols( myptr->hstmt, myptr->pccol );
    break;
  default:
    myptr->sqlrc = libdb400_SQLNumResultCols( myptr->hstmt, myptr->pccol );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLNumResultCols(myptr->sqlrc,  myptr->hstmt, myptr->pccol );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLNumResultColsCallback(SQLNumResultColsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLNumResultColsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLNumResultColsAsync ( SQLHSTMT  hstmt, SQLSMALLINT * pccol, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLNumResultColsStruct * myptr = (SQLNumResultColsStruct *) malloc(sizeof(SQLNumResultColsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->pccol = pccol;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLNumResultColsThread, (void *)myptr);
  return tid;
}
SQLNumResultColsStruct * SQLNumResultColsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLNumResultColsStruct * myptr = (SQLNumResultColsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLNumResultColsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLParamData( hstmt, Value );
    break;
  default:
    sqlrc = libdb400_SQLParamData( hstmt, Value );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLParamData(sqlrc,  hstmt, Value );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLParamDataThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLParamData( myptr->hstmt, myptr->Value );
    break;
  default:
    myptr->sqlrc = libdb400_SQLParamData( myptr->hstmt, myptr->Value );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLParamData(myptr->sqlrc,  myptr->hstmt, myptr->Value );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLParamDataCallback(SQLParamDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLParamDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLParamDataAsync ( SQLHSTMT  hstmt, SQLPOINTER * Value, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) malloc(sizeof(SQLParamDataStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->Value = Value;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLParamDataThread, (void *)myptr);
  return tid;
}
SQLParamDataStruct * SQLParamDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLParamDataStruct * myptr = (SQLParamDataStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLParamDataStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLParamOptions( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLParamOptions( hstmt, crow, pirow );
    break;
  default:
    sqlrc = libdb400_SQLParamOptions( hstmt, crow, pirow );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLParamOptions(sqlrc,  hstmt, crow, pirow );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLParamOptionsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLParamOptionsStruct * myptr = (SQLParamOptionsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLParamOptions( myptr->hstmt, myptr->crow, myptr->pirow );
    break;
  default:
    myptr->sqlrc = libdb400_SQLParamOptions( myptr->hstmt, myptr->crow, myptr->pirow );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLParamOptions(myptr->sqlrc,  myptr->hstmt, myptr->crow, myptr->pirow );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLParamOptionsCallback(SQLParamOptionsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLParamOptionsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLParamOptionsAsync ( SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLParamOptionsStruct * myptr = (SQLParamOptionsStruct *) malloc(sizeof(SQLParamOptionsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->crow = crow;
  myptr->pirow = pirow;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLParamOptionsThread, (void *)myptr);
  return tid;
}
SQLParamOptionsStruct * SQLParamOptionsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLParamOptionsStruct * myptr = (SQLParamOptionsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLParamOptionsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLPrepare( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLPrepare( hstmt, szSqlStr, cbSqlStr );
    break;
  default:
    sqlrc = libdb400_SQLPrepare( hstmt, szSqlStr, cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrepare(sqlrc,  hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLPrepareThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLPrepareStruct * myptr = (SQLPrepareStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLPrepare( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLPrepare( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrepare(myptr->sqlrc,  myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrepareCallback(SQLPrepareStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrepareStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrepareAsync ( SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrepareStruct * myptr = (SQLPrepareStruct *) malloc(sizeof(SQLPrepareStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrepareThread, (void *)myptr);
  return tid;
}
SQLPrepareStruct * SQLPrepareJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrepareStruct * myptr = (SQLPrepareStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrepareStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLPrepareW( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLPrepareW( hstmt, szSqlStr, cbSqlStr );
    break;
  default:
    sqlrc = libdb400_SQLPrepareW( hstmt, szSqlStr, cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrepareW(sqlrc,  hstmt, szSqlStr, cbSqlStr );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLPrepareWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLPrepareWStruct * myptr = (SQLPrepareWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLPrepareW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  default:
    myptr->sqlrc = libdb400_SQLPrepareW( myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrepareW(myptr->sqlrc,  myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrepareWCallback(SQLPrepareWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrepareWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrepareWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrepareWStruct * myptr = (SQLPrepareWStruct *) malloc(sizeof(SQLPrepareWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szSqlStr = szSqlStr;
  myptr->cbSqlStr = cbSqlStr;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrepareWThread, (void *)myptr);
  return tid;
}
SQLPrepareWStruct * SQLPrepareWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrepareWStruct * myptr = (SQLPrepareWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrepareWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLPrimaryKeys( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  default:
    sqlrc = libdb400_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrimaryKeys(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLPrimaryKeysThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLPrimaryKeys( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLPrimaryKeys( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrimaryKeys(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrimaryKeysCallback(SQLPrimaryKeysStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrimaryKeysStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrimaryKeysAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) malloc(sizeof(SQLPrimaryKeysStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrimaryKeysThread, (void *)myptr);
  return tid;
}
SQLPrimaryKeysStruct * SQLPrimaryKeysJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrimaryKeysStruct * myptr = (SQLPrimaryKeysStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrimaryKeysStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLPrimaryKeysW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLPrimaryKeysW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  default:
    sqlrc = libdb400_SQLPrimaryKeysW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrimaryKeysW(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLPrimaryKeysWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLPrimaryKeysWStruct * myptr = (SQLPrimaryKeysWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLPrimaryKeysW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLPrimaryKeysW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPrimaryKeysW(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPrimaryKeysWCallback(SQLPrimaryKeysWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPrimaryKeysWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPrimaryKeysWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPrimaryKeysWStruct * myptr = (SQLPrimaryKeysWStruct *) malloc(sizeof(SQLPrimaryKeysWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPrimaryKeysWThread, (void *)myptr);
  return tid;
}
SQLPrimaryKeysWStruct * SQLPrimaryKeysWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPrimaryKeysWStruct * myptr = (SQLPrimaryKeysWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPrimaryKeysWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLProcedureColumns( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLProcedureColumns( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
    break;
  default:
    sqlrc = libdb400_SQLProcedureColumns( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProcedureColumns(sqlrc,  hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLProcedureColumnsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLProcedureColumns( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLProcedureColumns( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProcedureColumns(myptr->sqlrc,  myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProcedureColumnsCallback(SQLProcedureColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProcedureColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProcedureColumnsAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) malloc(sizeof(SQLProcedureColumnsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProcedureColumnsThread, (void *)myptr);
  return tid;
}
SQLProcedureColumnsStruct * SQLProcedureColumnsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProcedureColumnsStruct * myptr = (SQLProcedureColumnsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProcedureColumnsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLProcedureColumnsW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLProcedureColumnsW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
    break;
  default:
    sqlrc = libdb400_SQLProcedureColumnsW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProcedureColumnsW(sqlrc,  hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName, szColumnName, cbColumnName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLProcedureColumnsWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLProcedureColumnsWStruct * myptr = (SQLProcedureColumnsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLProcedureColumnsW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLProcedureColumnsW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProcedureColumnsW(myptr->sqlrc,  myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName, myptr->szColumnName, myptr->cbColumnName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProcedureColumnsWCallback(SQLProcedureColumnsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProcedureColumnsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProcedureColumnsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProcedureColumnsWStruct * myptr = (SQLProcedureColumnsWStruct *) malloc(sizeof(SQLProcedureColumnsWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->szColumnName = szColumnName;
  myptr->cbColumnName = cbColumnName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProcedureColumnsWThread, (void *)myptr);
  return tid;
}
SQLProcedureColumnsWStruct * SQLProcedureColumnsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProcedureColumnsWStruct * myptr = (SQLProcedureColumnsWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProcedureColumnsWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLProcedures( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLProcedures( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
    break;
  default:
    sqlrc = libdb400_SQLProcedures( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProcedures(sqlrc,  hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLProceduresThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLProcedures( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLProcedures( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProcedures(myptr->sqlrc,  myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProceduresCallback(SQLProceduresStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProceduresStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProceduresAsync ( SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) malloc(sizeof(SQLProceduresStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProceduresThread, (void *)myptr);
  return tid;
}
SQLProceduresStruct * SQLProceduresJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProceduresStruct * myptr = (SQLProceduresStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProceduresStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLProceduresW( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLProceduresW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
    break;
  default:
    sqlrc = libdb400_SQLProceduresW( hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProceduresW(sqlrc,  hstmt, szProcQualifier, cbProcQualifier, szProcOwner, cbProcOwner, szProcName, cbProcName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLProceduresWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLProceduresWStruct * myptr = (SQLProceduresWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLProceduresW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLProceduresW( myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLProceduresW(myptr->sqlrc,  myptr->hstmt, myptr->szProcQualifier, myptr->cbProcQualifier, myptr->szProcOwner, myptr->cbProcOwner, myptr->szProcName, myptr->cbProcName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLProceduresWCallback(SQLProceduresWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLProceduresWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLProceduresWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLProceduresWStruct * myptr = (SQLProceduresWStruct *) malloc(sizeof(SQLProceduresWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szProcQualifier = szProcQualifier;
  myptr->cbProcQualifier = cbProcQualifier;
  myptr->szProcOwner = szProcOwner;
  myptr->cbProcOwner = cbProcOwner;
  myptr->szProcName = szProcName;
  myptr->cbProcName = cbProcName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLProceduresWThread, (void *)myptr);
  return tid;
}
SQLProceduresWStruct * SQLProceduresWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLProceduresWStruct * myptr = (SQLProceduresWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLProceduresWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLPutData( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLPutData( hstmt, Data, SLen );
    break;
  default:
    sqlrc = libdb400_SQLPutData( hstmt, Data, SLen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPutData(sqlrc,  hstmt, Data, SLen );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLPutDataThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLPutData( myptr->hstmt, myptr->Data, myptr->SLen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLPutData( myptr->hstmt, myptr->Data, myptr->SLen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLPutData(myptr->sqlrc,  myptr->hstmt, myptr->Data, myptr->SLen );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLPutDataCallback(SQLPutDataStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLPutDataStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLPutDataAsync ( SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) malloc(sizeof(SQLPutDataStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->Data = Data;
  myptr->SLen = SLen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLPutDataThread, (void *)myptr);
  return tid;
}
SQLPutDataStruct * SQLPutDataJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLPutDataStruct * myptr = (SQLPutDataStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLPutDataStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLReleaseEnv( SQLHENV  henv )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLReleaseEnv( henv );
    break;
  default:
    sqlrc = libdb400_SQLReleaseEnv( henv );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLReleaseEnv(sqlrc,  henv );
  }
  return sqlrc;
}
void * SQLReleaseEnvThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLReleaseEnvStruct * myptr = (SQLReleaseEnvStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLReleaseEnv( myptr->henv );
    break;
  default:
    myptr->sqlrc = libdb400_SQLReleaseEnv( myptr->henv );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLReleaseEnv(myptr->sqlrc,  myptr->henv );
  }
  /* not lock */
  /* void SQLReleaseEnvCallback(SQLReleaseEnvStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLReleaseEnvStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLReleaseEnvAsync ( SQLHENV  henv, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLReleaseEnvStruct * myptr = (SQLReleaseEnvStruct *) malloc(sizeof(SQLReleaseEnvStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLReleaseEnvThread, (void *)myptr);
  return tid;
}
SQLReleaseEnvStruct * SQLReleaseEnvJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLReleaseEnvStruct * myptr = (SQLReleaseEnvStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLReleaseEnvStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLRowCount( SQLHSTMT  hstmt, SQLINTEGER * pcrow )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLRowCount( hstmt, pcrow );
    break;
  default:
    sqlrc = libdb400_SQLRowCount( hstmt, pcrow );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLRowCount(sqlrc,  hstmt, pcrow );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLRowCountThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLRowCountStruct * myptr = (SQLRowCountStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLRowCount( myptr->hstmt, myptr->pcrow );
    break;
  default:
    myptr->sqlrc = libdb400_SQLRowCount( myptr->hstmt, myptr->pcrow );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLRowCount(myptr->sqlrc,  myptr->hstmt, myptr->pcrow );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLRowCountCallback(SQLRowCountStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLRowCountStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLRowCountAsync ( SQLHSTMT  hstmt, SQLINTEGER * pcrow, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLRowCountStruct * myptr = (SQLRowCountStruct *) malloc(sizeof(SQLRowCountStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->pcrow = pcrow;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLRowCountThread, (void *)myptr);
  return tid;
}
SQLRowCountStruct * SQLRowCountJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLRowCountStruct * myptr = (SQLRowCountStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLRowCountStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetConnectAttr( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetConnectAttr( hdbc, attrib, vParam, inlen );
    break;
  default:
    sqlrc = libdb400_SQLSetConnectAttr( hdbc, attrib, vParam, inlen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectAttr(sqlrc,  hdbc, attrib, vParam, inlen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLSetConnectAttrThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetConnectAttrStruct * myptr = (SQLSetConnectAttrStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetConnectAttr( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetConnectAttr( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectAttr(myptr->sqlrc,  myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectAttrCallback(SQLSetConnectAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectAttrAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectAttrStruct * myptr = (SQLSetConnectAttrStruct *) malloc(sizeof(SQLSetConnectAttrStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attrib = attrib;
  myptr->vParam = vParam;
  myptr->inlen = inlen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectAttrThread, (void *)myptr);
  return tid;
}
SQLSetConnectAttrStruct * SQLSetConnectAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectAttrStruct * myptr = (SQLSetConnectAttrStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectAttrStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetConnectAttrW( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetConnectAttrW( hdbc, attrib, vParam, inlen );
    break;
  default:
    sqlrc = libdb400_SQLSetConnectAttrW( hdbc, attrib, vParam, inlen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectAttrW(sqlrc,  hdbc, attrib, vParam, inlen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLSetConnectAttrWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetConnectAttrWStruct * myptr = (SQLSetConnectAttrWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetConnectAttrW( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetConnectAttrW( myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectAttrW(myptr->sqlrc,  myptr->hdbc, myptr->attrib, myptr->vParam, myptr->inlen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectAttrWCallback(SQLSetConnectAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectAttrWAsync ( SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectAttrWStruct * myptr = (SQLSetConnectAttrWStruct *) malloc(sizeof(SQLSetConnectAttrWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->attrib = attrib;
  myptr->vParam = vParam;
  myptr->inlen = inlen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectAttrWThread, (void *)myptr);
  return tid;
}
SQLSetConnectAttrWStruct * SQLSetConnectAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectAttrWStruct * myptr = (SQLSetConnectAttrWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectAttrWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetConnectOption( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetConnectOption( hdbc, fOption, vParam );
    break;
  default:
    sqlrc = libdb400_SQLSetConnectOption( hdbc, fOption, vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectOption(sqlrc,  hdbc, fOption, vParam );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLSetConnectOptionThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetConnectOption( myptr->hdbc, myptr->fOption, myptr->vParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetConnectOption( myptr->hdbc, myptr->fOption, myptr->vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectOption(myptr->sqlrc,  myptr->hdbc, myptr->fOption, myptr->vParam );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectOptionCallback(SQLSetConnectOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectOptionAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) malloc(sizeof(SQLSetConnectOptionStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectOptionThread, (void *)myptr);
  return tid;
}
SQLSetConnectOptionStruct * SQLSetConnectOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectOptionStruct * myptr = (SQLSetConnectOptionStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectOptionStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetConnectOptionW( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetConnectOptionW( hdbc, fOption, vParam );
    break;
  default:
    sqlrc = libdb400_SQLSetConnectOptionW( hdbc, fOption, vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectOptionW(sqlrc,  hdbc, fOption, vParam );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQLSetConnectOptionWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetConnectOptionWStruct * myptr = (SQLSetConnectOptionWStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetConnectOptionW( myptr->hdbc, myptr->fOption, myptr->vParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetConnectOptionW( myptr->hdbc, myptr->fOption, myptr->vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetConnectOptionW(myptr->sqlrc,  myptr->hdbc, myptr->fOption, myptr->vParam );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQLSetConnectOptionWCallback(SQLSetConnectOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetConnectOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetConnectOptionWAsync ( SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetConnectOptionWStruct * myptr = (SQLSetConnectOptionWStruct *) malloc(sizeof(SQLSetConnectOptionWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetConnectOptionWThread, (void *)myptr);
  return tid;
}
SQLSetConnectOptionWStruct * SQLSetConnectOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetConnectOptionWStruct * myptr = (SQLSetConnectOptionWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetConnectOptionWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetCursorName( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetCursorName( hstmt, szCursor, cbCursor );
    break;
  default:
    sqlrc = libdb400_SQLSetCursorName( hstmt, szCursor, cbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetCursorName(sqlrc,  hstmt, szCursor, cbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetCursorNameThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetCursorName( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetCursorName(myptr->sqlrc,  myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetCursorNameCallback(SQLSetCursorNameStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetCursorNameStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetCursorNameAsync ( SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) malloc(sizeof(SQLSetCursorNameStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursor = cbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetCursorNameThread, (void *)myptr);
  return tid;
}
SQLSetCursorNameStruct * SQLSetCursorNameJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetCursorNameStruct * myptr = (SQLSetCursorNameStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetCursorNameStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetCursorNameW( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetCursorNameW( hstmt, szCursor, cbCursor );
    break;
  default:
    sqlrc = libdb400_SQLSetCursorNameW( hstmt, szCursor, cbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetCursorNameW(sqlrc,  hstmt, szCursor, cbCursor );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetCursorNameWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetCursorNameWStruct * myptr = (SQLSetCursorNameWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetCursorNameW( myptr->hstmt, myptr->szCursor, myptr->cbCursor );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetCursorNameW(myptr->sqlrc,  myptr->hstmt, myptr->szCursor, myptr->cbCursor );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetCursorNameWCallback(SQLSetCursorNameWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetCursorNameWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetCursorNameWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetCursorNameWStruct * myptr = (SQLSetCursorNameWStruct *) malloc(sizeof(SQLSetCursorNameWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szCursor = szCursor;
  myptr->cbCursor = cbCursor;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetCursorNameWThread, (void *)myptr);
  return tid;
}
SQLSetCursorNameWStruct * SQLSetCursorNameWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetCursorNameWStruct * myptr = (SQLSetCursorNameWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetCursorNameWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetDescField( hdesc, rcdNum, fID, Value, buffLen );
    break;
  default:
    sqlrc = libdb400_SQLSetDescField( hdesc, rcdNum, fID, Value, buffLen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetDescField(sqlrc,  hdesc, rcdNum, fID, Value, buffLen );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLSetDescFieldThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetDescField( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetDescField( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetDescField(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLSetDescFieldCallback(SQLSetDescFieldStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetDescFieldStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetDescFieldAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) malloc(sizeof(SQLSetDescFieldStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fID = fID;
  myptr->Value = Value;
  myptr->buffLen = buffLen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetDescFieldThread, (void *)myptr);
  return tid;
}
SQLSetDescFieldStruct * SQLSetDescFieldJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetDescFieldStruct * myptr = (SQLSetDescFieldStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescFieldStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetDescFieldW( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetDescFieldW( hdesc, rcdNum, fID, Value, buffLen );
    break;
  default:
    sqlrc = libdb400_SQLSetDescFieldW( hdesc, rcdNum, fID, Value, buffLen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetDescFieldW(sqlrc,  hdesc, rcdNum, fID, Value, buffLen );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLSetDescFieldWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetDescFieldWStruct * myptr = (SQLSetDescFieldWStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetDescFieldW( myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetDescFieldW(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->fID, myptr->Value, myptr->buffLen );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLSetDescFieldWCallback(SQLSetDescFieldWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetDescFieldWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetDescFieldWAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetDescFieldWStruct * myptr = (SQLSetDescFieldWStruct *) malloc(sizeof(SQLSetDescFieldWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->fID = fID;
  myptr->Value = Value;
  myptr->buffLen = buffLen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetDescFieldWThread, (void *)myptr);
  return tid;
}
SQLSetDescFieldWStruct * SQLSetDescFieldWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetDescFieldWStruct * myptr = (SQLSetDescFieldWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescFieldWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetDescRec( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetDescRec( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
    break;
  default:
    sqlrc = libdb400_SQLSetDescRec( hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetDescRec(sqlrc,  hdesc, rcdNum, Type, subType, fLength, fPrec, fScale, Value, sLength, indic );
  }
  init_table_unlock(hdesc, 1);
  return sqlrc;
}
void * SQLSetDescRecThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) ptr;
  init_table_lock(myptr->hdesc, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetDescRec( myptr->hdesc, myptr->rcdNum, myptr->Type, myptr->subType, myptr->fLength, myptr->fPrec, myptr->fScale, myptr->Value, myptr->sLength, myptr->indic );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetDescRec( myptr->hdesc, myptr->rcdNum, myptr->Type, myptr->subType, myptr->fLength, myptr->fPrec, myptr->fScale, myptr->Value, myptr->sLength, myptr->indic );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetDescRec(myptr->sqlrc,  myptr->hdesc, myptr->rcdNum, myptr->Type, myptr->subType, myptr->fLength, myptr->fPrec, myptr->fScale, myptr->Value, myptr->sLength, myptr->indic );
  }
  init_table_unlock(myptr->hdesc, 1);
  /* void SQLSetDescRecCallback(SQLSetDescRecStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetDescRecStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetDescRecAsync ( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) malloc(sizeof(SQLSetDescRecStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdesc = hdesc;
  myptr->rcdNum = rcdNum;
  myptr->Type = Type;
  myptr->subType = subType;
  myptr->fLength = fLength;
  myptr->fPrec = fPrec;
  myptr->fScale = fScale;
  myptr->Value = Value;
  myptr->sLength = sLength;
  myptr->indic = indic;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetDescRecThread, (void *)myptr);
  return tid;
}
SQLSetDescRecStruct * SQLSetDescRecJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetDescRecStruct * myptr = (SQLSetDescRecStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetDescRecStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetEnvAttr( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetEnvAttr( hEnv, fAttribute, pParam, cbParam );
    break;
  default:
    sqlrc = libdb400_SQLSetEnvAttr( hEnv, fAttribute, pParam, cbParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetEnvAttr(sqlrc,  hEnv, fAttribute, pParam, cbParam );
  }
  return sqlrc;
}
void * SQLSetEnvAttrThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetEnvAttr( myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetEnvAttr(myptr->sqlrc,  myptr->hEnv, myptr->fAttribute, myptr->pParam, myptr->cbParam );
  }
  /* not lock */
  /* void SQLSetEnvAttrCallback(SQLSetEnvAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetEnvAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetEnvAttrAsync ( SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) malloc(sizeof(SQLSetEnvAttrStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hEnv = hEnv;
  myptr->fAttribute = fAttribute;
  myptr->pParam = pParam;
  myptr->cbParam = cbParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetEnvAttrThread, (void *)myptr);
  return tid;
}
SQLSetEnvAttrStruct * SQLSetEnvAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetEnvAttrStruct * myptr = (SQLSetEnvAttrStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetEnvAttrStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetParam( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetParam( hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
    break;
  default:
    sqlrc = libdb400_SQLSetParam( hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetParam(sqlrc,  hstmt, ipar, fCType, fSqlType, cbColDef, ibScale, rgbValue, pcbValue );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetParamThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetParam( myptr->hstmt, myptr->ipar, myptr->fCType, myptr->fSqlType, myptr->cbColDef, myptr->ibScale, myptr->rgbValue, myptr->pcbValue );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetParam( myptr->hstmt, myptr->ipar, myptr->fCType, myptr->fSqlType, myptr->cbColDef, myptr->ibScale, myptr->rgbValue, myptr->pcbValue );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetParam(myptr->sqlrc,  myptr->hstmt, myptr->ipar, myptr->fCType, myptr->fSqlType, myptr->cbColDef, myptr->ibScale, myptr->rgbValue, myptr->pcbValue );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetParamCallback(SQLSetParamStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetParamStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetParamAsync ( SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) malloc(sizeof(SQLSetParamStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ipar = ipar;
  myptr->fCType = fCType;
  myptr->fSqlType = fSqlType;
  myptr->cbColDef = cbColDef;
  myptr->ibScale = ibScale;
  myptr->rgbValue = rgbValue;
  myptr->pcbValue = pcbValue;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetParamThread, (void *)myptr);
  return tid;
}
SQLSetParamStruct * SQLSetParamJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetParamStruct * myptr = (SQLSetParamStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetParamStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetStmtAttr( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetStmtAttr( hstmt, fAttr, pParam, vParam );
    break;
  default:
    sqlrc = libdb400_SQLSetStmtAttr( hstmt, fAttr, pParam, vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtAttr(sqlrc,  hstmt, fAttr, pParam, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetStmtAttrThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetStmtAttrStruct * myptr = (SQLSetStmtAttrStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetStmtAttr( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtAttr(myptr->sqlrc,  myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtAttrCallback(SQLSetStmtAttrStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtAttrStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtAttrAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtAttrStruct * myptr = (SQLSetStmtAttrStruct *) malloc(sizeof(SQLSetStmtAttrStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pParam = pParam;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtAttrThread, (void *)myptr);
  return tid;
}
SQLSetStmtAttrStruct * SQLSetStmtAttrJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtAttrStruct * myptr = (SQLSetStmtAttrStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtAttrStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetStmtAttrW( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetStmtAttrW( hstmt, fAttr, pParam, vParam );
    break;
  default:
    sqlrc = libdb400_SQLSetStmtAttrW( hstmt, fAttr, pParam, vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtAttrW(sqlrc,  hstmt, fAttr, pParam, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetStmtAttrWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetStmtAttrWStruct * myptr = (SQLSetStmtAttrWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetStmtAttrW( myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtAttrW(myptr->sqlrc,  myptr->hstmt, myptr->fAttr, myptr->pParam, myptr->vParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtAttrWCallback(SQLSetStmtAttrWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtAttrWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtAttrWAsync ( SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtAttrWStruct * myptr = (SQLSetStmtAttrWStruct *) malloc(sizeof(SQLSetStmtAttrWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fAttr = fAttr;
  myptr->pParam = pParam;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtAttrWThread, (void *)myptr);
  return tid;
}
SQLSetStmtAttrWStruct * SQLSetStmtAttrWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtAttrWStruct * myptr = (SQLSetStmtAttrWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtAttrWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetStmtOption( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetStmtOption( hstmt, fOption, vParam );
    break;
  default:
    sqlrc = libdb400_SQLSetStmtOption( hstmt, fOption, vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtOption(sqlrc,  hstmt, fOption, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetStmtOptionThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetStmtOption( myptr->hstmt, myptr->fOption, myptr->vParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetStmtOption( myptr->hstmt, myptr->fOption, myptr->vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtOption(myptr->sqlrc,  myptr->hstmt, myptr->fOption, myptr->vParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtOptionCallback(SQLSetStmtOptionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtOptionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtOptionAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) malloc(sizeof(SQLSetStmtOptionStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtOptionThread, (void *)myptr);
  return tid;
}
SQLSetStmtOptionStruct * SQLSetStmtOptionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtOptionStruct * myptr = (SQLSetStmtOptionStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtOptionStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSetStmtOptionW( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSetStmtOptionW( hstmt, fOption, vParam );
    break;
  default:
    sqlrc = libdb400_SQLSetStmtOptionW( hstmt, fOption, vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtOptionW(sqlrc,  hstmt, fOption, vParam );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSetStmtOptionWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSetStmtOptionWStruct * myptr = (SQLSetStmtOptionWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->vParam );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSetStmtOptionW( myptr->hstmt, myptr->fOption, myptr->vParam );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSetStmtOptionW(myptr->sqlrc,  myptr->hstmt, myptr->fOption, myptr->vParam );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSetStmtOptionWCallback(SQLSetStmtOptionWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSetStmtOptionWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSetStmtOptionWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSetStmtOptionWStruct * myptr = (SQLSetStmtOptionWStruct *) malloc(sizeof(SQLSetStmtOptionWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fOption = fOption;
  myptr->vParam = vParam;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSetStmtOptionWThread, (void *)myptr);
  return tid;
}
SQLSetStmtOptionWStruct * SQLSetStmtOptionWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSetStmtOptionWStruct * myptr = (SQLSetStmtOptionWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSetStmtOptionWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSpecialColumns( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSpecialColumns( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
    break;
  default:
    sqlrc = libdb400_SQLSpecialColumns( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSpecialColumns(sqlrc,  hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSpecialColumnsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSpecialColumns( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSpecialColumns( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSpecialColumns(myptr->sqlrc,  myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSpecialColumnsCallback(SQLSpecialColumnsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSpecialColumnsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) malloc(sizeof(SQLSpecialColumnsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fColType = fColType;
  myptr->szTableQual = szTableQual;
  myptr->cbTableQual = cbTableQual;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fScope = fScope;
  myptr->fNullable = fNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSpecialColumnsThread, (void *)myptr);
  return tid;
}
SQLSpecialColumnsStruct * SQLSpecialColumnsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSpecialColumnsStruct * myptr = (SQLSpecialColumnsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSpecialColumnsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLSpecialColumnsW( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLSpecialColumnsW( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
    break;
  default:
    sqlrc = libdb400_SQLSpecialColumnsW( hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSpecialColumnsW(sqlrc,  hstmt, fColType, szTableQual, cbTableQual, szTableOwner, cbTableOwner, szTableName, cbTableName, fScope, fNullable );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLSpecialColumnsWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLSpecialColumnsWStruct * myptr = (SQLSpecialColumnsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLSpecialColumnsW( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
    break;
  default:
    myptr->sqlrc = libdb400_SQLSpecialColumnsW( myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLSpecialColumnsW(myptr->sqlrc,  myptr->hstmt, myptr->fColType, myptr->szTableQual, myptr->cbTableQual, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fScope, myptr->fNullable );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLSpecialColumnsWCallback(SQLSpecialColumnsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLSpecialColumnsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLSpecialColumnsWAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLSpecialColumnsWStruct * myptr = (SQLSpecialColumnsWStruct *) malloc(sizeof(SQLSpecialColumnsWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->fColType = fColType;
  myptr->szTableQual = szTableQual;
  myptr->cbTableQual = cbTableQual;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fScope = fScope;
  myptr->fNullable = fNullable;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLSpecialColumnsWThread, (void *)myptr);
  return tid;
}
SQLSpecialColumnsWStruct * SQLSpecialColumnsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLSpecialColumnsWStruct * myptr = (SQLSpecialColumnsWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLSpecialColumnsWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLStartTran( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLStartTran( htype, henv, mode, clevel );
    break;
  default:
    sqlrc = libdb400_SQLStartTran( htype, henv, mode, clevel );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLStartTran(sqlrc,  htype, henv, mode, clevel );
  }
  return sqlrc;
}
void * SQLStartTranThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) ptr;
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLStartTran( myptr->htype, myptr->henv, myptr->mode, myptr->clevel );
    break;
  default:
    myptr->sqlrc = libdb400_SQLStartTran( myptr->htype, myptr->henv, myptr->mode, myptr->clevel );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLStartTran(myptr->sqlrc,  myptr->htype, myptr->henv, myptr->mode, myptr->clevel );
  }
  /* void SQLStartTranCallback(SQLStartTranStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStartTranStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStartTranAsync ( SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) malloc(sizeof(SQLStartTranStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->htype = htype;
  myptr->henv = henv;
  myptr->mode = mode;
  myptr->clevel = clevel;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStartTranThread, (void *)myptr);
  return tid;
}
SQLStartTranStruct * SQLStartTranJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStartTranStruct * myptr = (SQLStartTranStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStartTranStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLStatistics( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLStatistics( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
    break;
  default:
    sqlrc = libdb400_SQLStatistics( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLStatistics(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLStatisticsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLStatistics( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
    break;
  default:
    myptr->sqlrc = libdb400_SQLStatistics( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLStatistics(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLStatisticsCallback(SQLStatisticsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStatisticsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStatisticsAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) malloc(sizeof(SQLStatisticsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fUnique = fUnique;
  myptr->fres = fres;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStatisticsThread, (void *)myptr);
  return tid;
}
SQLStatisticsStruct * SQLStatisticsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStatisticsStruct * myptr = (SQLStatisticsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStatisticsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLStatisticsW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLStatisticsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
    break;
  default:
    sqlrc = libdb400_SQLStatisticsW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLStatisticsW(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, fUnique, fres );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLStatisticsWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLStatisticsWStruct * myptr = (SQLStatisticsWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLStatisticsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
    break;
  default:
    myptr->sqlrc = libdb400_SQLStatisticsW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLStatisticsW(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->fUnique, myptr->fres );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLStatisticsWCallback(SQLStatisticsWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLStatisticsWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLStatisticsWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLStatisticsWStruct * myptr = (SQLStatisticsWStruct *) malloc(sizeof(SQLStatisticsWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->fUnique = fUnique;
  myptr->fres = fres;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLStatisticsWThread, (void *)myptr);
  return tid;
}
SQLStatisticsWStruct * SQLStatisticsWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLStatisticsWStruct * myptr = (SQLStatisticsWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLStatisticsWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLTablePrivileges( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLTablePrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  default:
    sqlrc = libdb400_SQLTablePrivileges( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTablePrivileges(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLTablePrivilegesThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLTablePrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLTablePrivileges( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTablePrivileges(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablePrivilegesCallback(SQLTablePrivilegesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablePrivilegesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablePrivilegesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) malloc(sizeof(SQLTablePrivilegesStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablePrivilegesThread, (void *)myptr);
  return tid;
}
SQLTablePrivilegesStruct * SQLTablePrivilegesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablePrivilegesStruct * myptr = (SQLTablePrivilegesStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablePrivilegesStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLTablePrivilegesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLTablePrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  default:
    sqlrc = libdb400_SQLTablePrivilegesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTablePrivilegesW(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLTablePrivilegesWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLTablePrivilegesWStruct * myptr = (SQLTablePrivilegesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLTablePrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  default:
    myptr->sqlrc = libdb400_SQLTablePrivilegesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTablePrivilegesW(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablePrivilegesWCallback(SQLTablePrivilegesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablePrivilegesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablePrivilegesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablePrivilegesWStruct * myptr = (SQLTablePrivilegesWStruct *) malloc(sizeof(SQLTablePrivilegesWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablePrivilegesWThread, (void *)myptr);
  return tid;
}
SQLTablePrivilegesWStruct * SQLTablePrivilegesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablePrivilegesWStruct * myptr = (SQLTablePrivilegesWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablePrivilegesWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLTables( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLTables( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
    break;
  default:
    sqlrc = libdb400_SQLTables( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTables(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLTablesThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLTablesStruct * myptr = (SQLTablesStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLTables( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
    break;
  default:
    myptr->sqlrc = libdb400_SQLTables( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTables(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablesCallback(SQLTablesStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablesStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablesAsync ( SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablesStruct * myptr = (SQLTablesStruct *) malloc(sizeof(SQLTablesStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szTableType = szTableType;
  myptr->cbTableType = cbTableType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablesThread, (void *)myptr);
  return tid;
}
SQLTablesStruct * SQLTablesJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablesStruct * myptr = (SQLTablesStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablesStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLTablesW( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLTablesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
    break;
  default:
    sqlrc = libdb400_SQLTablesW( hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTablesW(sqlrc,  hstmt, szTableQualifier, cbTableQualifier, szTableOwner, cbTableOwner, szTableName, cbTableName, szTableType, cbTableType );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQLTablesWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLTablesWStruct * myptr = (SQLTablesWStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLTablesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
    break;
  default:
    myptr->sqlrc = libdb400_SQLTablesW( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTablesW(myptr->sqlrc,  myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, myptr->szTableOwner, myptr->cbTableOwner, myptr->szTableName, myptr->cbTableName, myptr->szTableType, myptr->cbTableType );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQLTablesWCallback(SQLTablesWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTablesWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTablesWAsync ( SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTablesWStruct * myptr = (SQLTablesWStruct *) malloc(sizeof(SQLTablesWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->szTableQualifier = szTableQualifier;
  myptr->cbTableQualifier = cbTableQualifier;
  myptr->szTableOwner = szTableOwner;
  myptr->cbTableOwner = cbTableOwner;
  myptr->szTableName = szTableName;
  myptr->cbTableName = cbTableName;
  myptr->szTableType = szTableType;
  myptr->cbTableType = cbTableType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTablesWThread, (void *)myptr);
  return tid;
}
SQLTablesWStruct * SQLTablesWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTablesWStruct * myptr = (SQLTablesWStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTablesWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQLTransact( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    sqlrc = ILE_SQLTransact( henv, hdbc, fType );
    break;
  default:
    sqlrc = libdb400_SQLTransact( henv, hdbc, fType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTransact(sqlrc,  henv, hdbc, fType );
  }
  return sqlrc;
}
void * SQLTransactThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQLTransactStruct * myptr = (SQLTransactStruct *) ptr;
  /* not lock */
  switch(myccsid) {
  case 1208: /* UTF-8 */
  case 1200: /* UTF-16 */
    myptr->sqlrc = ILE_SQLTransact( myptr->henv, myptr->hdbc, myptr->fType );
    break;
  default:
    myptr->sqlrc = libdb400_SQLTransact( myptr->henv, myptr->hdbc, myptr->fType );
    break;
  }
  if (init_cli_trace()) {
    dump_SQLTransact(myptr->sqlrc,  myptr->henv, myptr->hdbc, myptr->fType );
  }
  /* not lock */
  /* void SQLTransactCallback(SQLTransactStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQLTransactStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQLTransactAsync ( SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQLTransactStruct * myptr = (SQLTransactStruct *) malloc(sizeof(SQLTransactStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->henv = henv;
  myptr->hdbc = hdbc;
  myptr->fType = fType;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQLTransactThread, (void *)myptr);
  return tid;
}
SQLTransactStruct * SQLTransactJoin (pthread_t tid, SQLINTEGER flag)
{
  SQLTransactStruct * myptr = (SQLTransactStruct *) NULL;
  int active = 0;
  /* not lock */
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQLTransactStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400Version( SQLPOINTER  outversion, SQLINTEGER  outlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400Version( outversion, outlen );
  if (init_cli_trace()) {
    dump_SQL400Version(sqlrc,  outversion, outlen );
  }
  return sqlrc;
}
void * SQL400VersionThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400VersionStruct * myptr = (SQL400VersionStruct *) ptr;
  myptr->sqlrc = custom_SQL400Version( myptr->outversion, myptr->outlen );
  if (init_cli_trace()) {
    dump_SQL400Version(myptr->sqlrc,  myptr->outversion, myptr->outlen );
  }
  /* void SQL400VersionCallback(SQL400VersionStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400VersionStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400VersionAsync ( SQLPOINTER  outversion, SQLINTEGER  outlen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400VersionStruct * myptr = (SQL400VersionStruct *) malloc(sizeof(SQL400VersionStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->outversion = outversion;
  myptr->outlen = outlen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400VersionThread, (void *)myptr);
  return tid;
}
SQL400VersionStruct * SQL400VersionJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400VersionStruct * myptr = (SQL400VersionStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400VersionStruct *) NULL;
  }
  return myptr;
}
int SQLOverrideCCSID400(int newCCSID)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  sqlrc = custom_SQLOverrideCCSID400( newCCSID );
  return sqlrc;
}
SQLRETURN SQL400Stmt2Hdbc( SQLHSTMT  hstmt, SQLINTEGER * ohnd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hstmt, 1);
  sqlrc = custom_SQL400Stmt2Hdbc( hstmt, ohnd );
  if (init_cli_trace()) {
    dump_SQL400Stmt2Hdbc(sqlrc,  hstmt, ohnd );
  }
  init_table_unlock(hstmt, 1);
  return sqlrc;
}
void * SQL400Stmt2HdbcThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400Stmt2HdbcStruct * myptr = (SQL400Stmt2HdbcStruct *) ptr;
  init_table_lock(myptr->hstmt, 1);
  myptr->sqlrc = custom_SQL400Stmt2Hdbc( myptr->hstmt, myptr->ohnd );
  if (init_cli_trace()) {
    dump_SQL400Stmt2Hdbc(myptr->sqlrc,  myptr->hstmt, myptr->ohnd );
  }
  init_table_unlock(myptr->hstmt, 1);
  /* void SQL400Stmt2HdbcCallback(SQL400Stmt2HdbcStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400Stmt2HdbcStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400Stmt2HdbcAsync ( SQLHSTMT  hstmt, SQLINTEGER * ohnd, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400Stmt2HdbcStruct * myptr = (SQL400Stmt2HdbcStruct *) malloc(sizeof(SQL400Stmt2HdbcStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hstmt = hstmt;
  myptr->ohnd = ohnd;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400Stmt2HdbcThread, (void *)myptr);
  return tid;
}
SQL400Stmt2HdbcStruct * SQL400Stmt2HdbcJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400Stmt2HdbcStruct * myptr = (SQL400Stmt2HdbcStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 1);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400Stmt2HdbcStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400Connect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400Connect( db, uid, pwd, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400Connect(sqlrc,  db, uid, pwd, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400ConnectThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ConnectStruct * myptr = (SQL400ConnectStruct *) ptr;
  myptr->sqlrc = custom_SQL400Connect( myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400Connect(myptr->sqlrc,  myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400ConnectCallback(SQL400ConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ConnectAsync ( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ConnectStruct * myptr = (SQL400ConnectStruct *) malloc(sizeof(SQL400ConnectStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ConnectThread, (void *)myptr);
  return tid;
}
SQL400ConnectStruct * SQL400ConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400ConnectStruct * myptr = (SQL400ConnectStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ConnectStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ConnectW( SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400ConnectW( db, uid, pwd, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400ConnectW(sqlrc,  db, uid, pwd, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400ConnectWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ConnectWStruct * myptr = (SQL400ConnectWStruct *) ptr;
  myptr->sqlrc = custom_SQL400ConnectW( myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400ConnectW(myptr->sqlrc,  myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400ConnectWCallback(SQL400ConnectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ConnectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ConnectWAsync ( SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ConnectWStruct * myptr = (SQL400ConnectWStruct *) malloc(sizeof(SQL400ConnectWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ConnectWThread, (void *)myptr);
  return tid;
}
SQL400ConnectWStruct * SQL400ConnectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400ConnectWStruct * myptr = (SQL400ConnectWStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ConnectWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400pConnect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400pConnect( db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnect(sqlrc,  db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400pConnectThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400pConnectStruct * myptr = (SQL400pConnectStruct *) ptr;
  myptr->sqlrc = custom_SQL400pConnect( myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnect(myptr->sqlrc,  myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400pConnectCallback(SQL400pConnectStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400pConnectStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400pConnectAsync ( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400pConnectStruct * myptr = (SQL400pConnectStruct *) malloc(sizeof(SQL400pConnectStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->qual = qual;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400pConnectThread, (void *)myptr);
  return tid;
}
SQL400pConnectStruct * SQL400pConnectJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400pConnectStruct * myptr = (SQL400pConnectStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400pConnectStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400pConnectW( SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400pConnectW( db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnectW(sqlrc,  db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400pConnectWThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400pConnectWStruct * myptr = (SQL400pConnectWStruct *) ptr;
  myptr->sqlrc = custom_SQL400pConnectW( myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnectW(myptr->sqlrc,  myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400pConnectWCallback(SQL400pConnectWStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400pConnectWStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400pConnectWAsync ( SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400pConnectWStruct * myptr = (SQL400pConnectWStruct *) malloc(sizeof(SQL400pConnectWStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->qual = qual;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400pConnectWThread, (void *)myptr);
  return tid;
}
SQL400pConnectWStruct * SQL400pConnectWJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400pConnectWStruct * myptr = (SQL400pConnectWStruct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400pConnectWStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ConnectUtf8( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400ConnectUtf8( accsid, db, uid, pwd, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400ConnectUtf8(sqlrc,  accsid, db, uid, pwd, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400ConnectUtf8Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ConnectUtf8Struct * myptr = (SQL400ConnectUtf8Struct *) ptr;
  myptr->sqlrc = custom_SQL400ConnectUtf8( myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400ConnectUtf8(myptr->sqlrc,  myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400ConnectUtf8Callback(SQL400ConnectUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ConnectUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ConnectUtf8Async ( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ConnectUtf8Struct * myptr = (SQL400ConnectUtf8Struct *) malloc(sizeof(SQL400ConnectUtf8Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->accsid = accsid;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ConnectUtf8Thread, (void *)myptr);
  return tid;
}
SQL400ConnectUtf8Struct * SQL400ConnectUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400ConnectUtf8Struct * myptr = (SQL400ConnectUtf8Struct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ConnectUtf8Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400pConnectUtf8( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400pConnectUtf8( accsid, db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnectUtf8(sqlrc,  accsid, db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400pConnectUtf8Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400pConnectUtf8Struct * myptr = (SQL400pConnectUtf8Struct *) ptr;
  myptr->sqlrc = custom_SQL400pConnectUtf8( myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnectUtf8(myptr->sqlrc,  myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400pConnectUtf8Callback(SQL400pConnectUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400pConnectUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400pConnectUtf8Async ( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400pConnectUtf8Struct * myptr = (SQL400pConnectUtf8Struct *) malloc(sizeof(SQL400pConnectUtf8Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->accsid = accsid;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->qual = qual;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400pConnectUtf8Thread, (void *)myptr);
  return tid;
}
SQL400pConnectUtf8Struct * SQL400pConnectUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400pConnectUtf8Struct * myptr = (SQL400pConnectUtf8Struct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400pConnectUtf8Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ConnectUtf16( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400ConnectUtf16( accsid, db, uid, pwd, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400ConnectUtf16(sqlrc,  accsid, db, uid, pwd, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400ConnectUtf16Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ConnectUtf16Struct * myptr = (SQL400ConnectUtf16Struct *) ptr;
  myptr->sqlrc = custom_SQL400ConnectUtf16( myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400ConnectUtf16(myptr->sqlrc,  myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400ConnectUtf16Callback(SQL400ConnectUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ConnectUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ConnectUtf16Async ( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ConnectUtf16Struct * myptr = (SQL400ConnectUtf16Struct *) malloc(sizeof(SQL400ConnectUtf16Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->accsid = accsid;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ConnectUtf16Thread, (void *)myptr);
  return tid;
}
SQL400ConnectUtf16Struct * SQL400ConnectUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400ConnectUtf16Struct * myptr = (SQL400ConnectUtf16Struct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ConnectUtf16Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400pConnectUtf16( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  sqlrc = custom_SQL400pConnectUtf16( accsid, db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnectUtf16(sqlrc,  accsid, db, uid, pwd, qual, ohnd, acommit, alibl, acurlib );
  }
  return sqlrc;
}
void * SQL400pConnectUtf16Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400pConnectUtf16Struct * myptr = (SQL400pConnectUtf16Struct *) ptr;
  myptr->sqlrc = custom_SQL400pConnectUtf16( myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  if (init_cli_trace()) {
    dump_SQL400pConnectUtf16(myptr->sqlrc,  myptr->accsid, myptr->db, myptr->uid, myptr->pwd, myptr->qual, myptr->ohnd, myptr->acommit, myptr->alibl, myptr->acurlib );
  }
  /* void SQL400pConnectUtf16Callback(SQL400pConnectUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400pConnectUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400pConnectUtf16Async ( SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400pConnectUtf16Struct * myptr = (SQL400pConnectUtf16Struct *) malloc(sizeof(SQL400pConnectUtf16Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->accsid = accsid;
  myptr->db = db;
  myptr->uid = uid;
  myptr->pwd = pwd;
  myptr->qual = qual;
  myptr->ohnd = ohnd;
  myptr->acommit = acommit;
  myptr->alibl = alibl;
  myptr->acurlib = acurlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400pConnectUtf16Thread, (void *)myptr);
  return tid;
}
SQL400pConnectUtf16Struct * SQL400pConnectUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400pConnectUtf16Struct * myptr = (SQL400pConnectUtf16Struct *) NULL;
  int active = 0;
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400pConnectUtf16Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400Close( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400Close( hdbc );
  if (init_cli_trace()) {
    dump_SQL400Close(sqlrc,  hdbc );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400CloseThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400CloseStruct * myptr = (SQL400CloseStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400Close( myptr->hdbc );
  if (init_cli_trace()) {
    dump_SQL400Close(myptr->sqlrc,  myptr->hdbc );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400CloseCallback(SQL400CloseStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400CloseStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400CloseAsync ( SQLHDBC  hdbc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400CloseStruct * myptr = (SQL400CloseStruct *) malloc(sizeof(SQL400CloseStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400CloseThread, (void *)myptr);
  return tid;
}
SQL400CloseStruct * SQL400CloseJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400CloseStruct * myptr = (SQL400CloseStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400CloseStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400pClose( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400pClose( hdbc );
  if (init_cli_trace()) {
    dump_SQL400pClose(sqlrc,  hdbc );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400pCloseThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400pCloseStruct * myptr = (SQL400pCloseStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400pClose( myptr->hdbc );
  if (init_cli_trace()) {
    dump_SQL400pClose(myptr->sqlrc,  myptr->hdbc );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400pCloseCallback(SQL400pCloseStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400pCloseStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400pCloseAsync ( SQLHDBC  hdbc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400pCloseStruct * myptr = (SQL400pCloseStruct *) malloc(sizeof(SQL400pCloseStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400pCloseThread, (void *)myptr);
  return tid;
}
SQL400pCloseStruct * SQL400pCloseJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400pCloseStruct * myptr = (SQL400pCloseStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400pCloseStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400CloseAllStmts( SQLHDBC  hdbc )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400CloseAllStmts( hdbc );
  if (init_cli_trace()) {
    dump_SQL400CloseAllStmts(sqlrc,  hdbc );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400CloseAllStmtsThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400CloseAllStmtsStruct * myptr = (SQL400CloseAllStmtsStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400CloseAllStmts( myptr->hdbc );
  if (init_cli_trace()) {
    dump_SQL400CloseAllStmts(myptr->sqlrc,  myptr->hdbc );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400CloseAllStmtsCallback(SQL400CloseAllStmtsStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400CloseAllStmtsStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400CloseAllStmtsAsync ( SQLHDBC  hdbc, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400CloseAllStmtsStruct * myptr = (SQL400CloseAllStmtsStruct *) malloc(sizeof(SQL400CloseAllStmtsStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400CloseAllStmtsThread, (void *)myptr);
  return tid;
}
SQL400CloseAllStmtsStruct * SQL400CloseAllStmtsJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400CloseAllStmtsStruct * myptr = (SQL400CloseAllStmtsStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400CloseAllStmtsStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400Cmd( SQLHDBC  hdbc, SQLCHAR * cmd )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400Cmd( hdbc, cmd );
  if (init_cli_trace()) {
    dump_SQL400Cmd(sqlrc,  hdbc, cmd );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400CmdThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400CmdStruct * myptr = (SQL400CmdStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400Cmd( myptr->hdbc, myptr->cmd );
  if (init_cli_trace()) {
    dump_SQL400Cmd(myptr->sqlrc,  myptr->hdbc, myptr->cmd );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400CmdCallback(SQL400CmdStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400CmdStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400CmdAsync ( SQLHDBC  hdbc, SQLCHAR * cmd, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400CmdStruct * myptr = (SQL400CmdStruct *) malloc(sizeof(SQL400CmdStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->cmd = cmd;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400CmdThread, (void *)myptr);
  return tid;
}
SQL400CmdStruct * SQL400CmdJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400CmdStruct * myptr = (SQL400CmdStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400CmdStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ChgLibl( SQLHDBC  hdbc, SQLCHAR * libl )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400ChgLibl( hdbc, libl );
  if (init_cli_trace()) {
    dump_SQL400ChgLibl(sqlrc,  hdbc, libl );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400ChgLiblThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ChgLiblStruct * myptr = (SQL400ChgLiblStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400ChgLibl( myptr->hdbc, myptr->libl );
  if (init_cli_trace()) {
    dump_SQL400ChgLibl(myptr->sqlrc,  myptr->hdbc, myptr->libl );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400ChgLiblCallback(SQL400ChgLiblStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ChgLiblStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ChgLiblAsync ( SQLHDBC  hdbc, SQLCHAR * libl, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ChgLiblStruct * myptr = (SQL400ChgLiblStruct *) malloc(sizeof(SQL400ChgLiblStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->libl = libl;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ChgLiblThread, (void *)myptr);
  return tid;
}
SQL400ChgLiblStruct * SQL400ChgLiblJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400ChgLiblStruct * myptr = (SQL400ChgLiblStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ChgLiblStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ChgCurLib( SQLHDBC  hdbc, SQLCHAR * curlib )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400ChgCurLib( hdbc, curlib );
  if (init_cli_trace()) {
    dump_SQL400ChgCurLib(sqlrc,  hdbc, curlib );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400ChgCurLibThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ChgCurLibStruct * myptr = (SQL400ChgCurLibStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400ChgCurLib( myptr->hdbc, myptr->curlib );
  if (init_cli_trace()) {
    dump_SQL400ChgCurLib(myptr->sqlrc,  myptr->hdbc, myptr->curlib );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400ChgCurLibCallback(SQL400ChgCurLibStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ChgCurLibStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ChgCurLibAsync ( SQLHDBC  hdbc, SQLCHAR * curlib, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ChgCurLibStruct * myptr = (SQL400ChgCurLibStruct *) malloc(sizeof(SQL400ChgCurLibStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->curlib = curlib;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ChgCurLibThread, (void *)myptr);
  return tid;
}
SQL400ChgCurLibStruct * SQL400ChgCurLibJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400ChgCurLibStruct * myptr = (SQL400ChgCurLibStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ChgCurLibStruct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400ToUtf8( hdbc, inparm, inlen, outparm, outlen, inccsid );
  if (init_cli_trace()) {
    dump_SQL400ToUtf8(sqlrc,  hdbc, inparm, inlen, outparm, outlen, inccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400ToUtf8Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ToUtf8Struct * myptr = (SQL400ToUtf8Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400ToUtf8( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  if (init_cli_trace()) {
    dump_SQL400ToUtf8(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400ToUtf8Callback(SQL400ToUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ToUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ToUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ToUtf8Struct * myptr = (SQL400ToUtf8Struct *) malloc(sizeof(SQL400ToUtf8Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->inccsid = inccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ToUtf8Thread, (void *)myptr);
  return tid;
}
SQL400ToUtf8Struct * SQL400ToUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400ToUtf8Struct * myptr = (SQL400ToUtf8Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ToUtf8Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400FromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400FromUtf8( hdbc, inparm, inlen, outparm, outlen, outccsid );
  if (init_cli_trace()) {
    dump_SQL400FromUtf8(sqlrc,  hdbc, inparm, inlen, outparm, outlen, outccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400FromUtf8Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400FromUtf8Struct * myptr = (SQL400FromUtf8Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400FromUtf8( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  if (init_cli_trace()) {
    dump_SQL400FromUtf8(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400FromUtf8Callback(SQL400FromUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400FromUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400FromUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400FromUtf8Struct * myptr = (SQL400FromUtf8Struct *) malloc(sizeof(SQL400FromUtf8Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->outccsid = outccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400FromUtf8Thread, (void *)myptr);
  return tid;
}
SQL400FromUtf8Struct * SQL400FromUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400FromUtf8Struct * myptr = (SQL400FromUtf8Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400FromUtf8Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400ToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400ToUtf16( hdbc, inparm, inlen, outparm, outlen, inccsid );
  if (init_cli_trace()) {
    dump_SQL400ToUtf16(sqlrc,  hdbc, inparm, inlen, outparm, outlen, inccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400ToUtf16Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400ToUtf16Struct * myptr = (SQL400ToUtf16Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400ToUtf16( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  if (init_cli_trace()) {
    dump_SQL400ToUtf16(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400ToUtf16Callback(SQL400ToUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400ToUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400ToUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400ToUtf16Struct * myptr = (SQL400ToUtf16Struct *) malloc(sizeof(SQL400ToUtf16Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->inccsid = inccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400ToUtf16Thread, (void *)myptr);
  return tid;
}
SQL400ToUtf16Struct * SQL400ToUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400ToUtf16Struct * myptr = (SQL400ToUtf16Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400ToUtf16Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400FromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400FromUtf16( hdbc, inparm, inlen, outparm, outlen, outccsid );
  if (init_cli_trace()) {
    dump_SQL400FromUtf16(sqlrc,  hdbc, inparm, inlen, outparm, outlen, outccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400FromUtf16Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400FromUtf16Struct * myptr = (SQL400FromUtf16Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400FromUtf16( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  if (init_cli_trace()) {
    dump_SQL400FromUtf16(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400FromUtf16Callback(SQL400FromUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400FromUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400FromUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400FromUtf16Struct * myptr = (SQL400FromUtf16Struct *) malloc(sizeof(SQL400FromUtf16Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->outccsid = outccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400FromUtf16Thread, (void *)myptr);
  return tid;
}
SQL400FromUtf16Struct * SQL400FromUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400FromUtf16Struct * myptr = (SQL400FromUtf16Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400FromUtf16Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400IgnoreNullToUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400IgnoreNullToUtf8( hdbc, inparm, inlen, outparm, outlen, inccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullToUtf8(sqlrc,  hdbc, inparm, inlen, outparm, outlen, inccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400IgnoreNullToUtf8Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400IgnoreNullToUtf8Struct * myptr = (SQL400IgnoreNullToUtf8Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400IgnoreNullToUtf8( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullToUtf8(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400IgnoreNullToUtf8Callback(SQL400IgnoreNullToUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400IgnoreNullToUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400IgnoreNullToUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400IgnoreNullToUtf8Struct * myptr = (SQL400IgnoreNullToUtf8Struct *) malloc(sizeof(SQL400IgnoreNullToUtf8Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->inccsid = inccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400IgnoreNullToUtf8Thread, (void *)myptr);
  return tid;
}
SQL400IgnoreNullToUtf8Struct * SQL400IgnoreNullToUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400IgnoreNullToUtf8Struct * myptr = (SQL400IgnoreNullToUtf8Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400IgnoreNullToUtf8Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400IgnoreNullFromUtf8( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400IgnoreNullFromUtf8( hdbc, inparm, inlen, outparm, outlen, outccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullFromUtf8(sqlrc,  hdbc, inparm, inlen, outparm, outlen, outccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400IgnoreNullFromUtf8Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400IgnoreNullFromUtf8Struct * myptr = (SQL400IgnoreNullFromUtf8Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400IgnoreNullFromUtf8( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullFromUtf8(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400IgnoreNullFromUtf8Callback(SQL400IgnoreNullFromUtf8Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400IgnoreNullFromUtf8Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400IgnoreNullFromUtf8Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400IgnoreNullFromUtf8Struct * myptr = (SQL400IgnoreNullFromUtf8Struct *) malloc(sizeof(SQL400IgnoreNullFromUtf8Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->outccsid = outccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400IgnoreNullFromUtf8Thread, (void *)myptr);
  return tid;
}
SQL400IgnoreNullFromUtf8Struct * SQL400IgnoreNullFromUtf8Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400IgnoreNullFromUtf8Struct * myptr = (SQL400IgnoreNullFromUtf8Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400IgnoreNullFromUtf8Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400IgnoreNullToUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400IgnoreNullToUtf16( hdbc, inparm, inlen, outparm, outlen, inccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullToUtf16(sqlrc,  hdbc, inparm, inlen, outparm, outlen, inccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400IgnoreNullToUtf16Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400IgnoreNullToUtf16Struct * myptr = (SQL400IgnoreNullToUtf16Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400IgnoreNullToUtf16( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullToUtf16(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->inccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400IgnoreNullToUtf16Callback(SQL400IgnoreNullToUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400IgnoreNullToUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400IgnoreNullToUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400IgnoreNullToUtf16Struct * myptr = (SQL400IgnoreNullToUtf16Struct *) malloc(sizeof(SQL400IgnoreNullToUtf16Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->inccsid = inccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400IgnoreNullToUtf16Thread, (void *)myptr);
  return tid;
}
SQL400IgnoreNullToUtf16Struct * SQL400IgnoreNullToUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400IgnoreNullToUtf16Struct * myptr = (SQL400IgnoreNullToUtf16Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400IgnoreNullToUtf16Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400IgnoreNullFromUtf16( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400IgnoreNullFromUtf16( hdbc, inparm, inlen, outparm, outlen, outccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullFromUtf16(sqlrc,  hdbc, inparm, inlen, outparm, outlen, outccsid );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400IgnoreNullFromUtf16Thread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400IgnoreNullFromUtf16Struct * myptr = (SQL400IgnoreNullFromUtf16Struct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400IgnoreNullFromUtf16( myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  if (init_cli_trace()) {
    dump_SQL400IgnoreNullFromUtf16(myptr->sqlrc,  myptr->hdbc, myptr->inparm, myptr->inlen, myptr->outparm, myptr->outlen, myptr->outccsid );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400IgnoreNullFromUtf16Callback(SQL400IgnoreNullFromUtf16Struct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400IgnoreNullFromUtf16Struct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400IgnoreNullFromUtf16Async ( SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400IgnoreNullFromUtf16Struct * myptr = (SQL400IgnoreNullFromUtf16Struct *) malloc(sizeof(SQL400IgnoreNullFromUtf16Struct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->inparm = inparm;
  myptr->inlen = inlen;
  myptr->outparm = outparm;
  myptr->outlen = outlen;
  myptr->outccsid = outccsid;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400IgnoreNullFromUtf16Thread, (void *)myptr);
  return tid;
}
SQL400IgnoreNullFromUtf16Struct * SQL400IgnoreNullFromUtf16Join (pthread_t tid, SQLINTEGER flag)
{
  SQL400IgnoreNullFromUtf16Struct * myptr = (SQL400IgnoreNullFromUtf16Struct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400IgnoreNullFromUtf16Struct *) NULL;
  }
  return myptr;
}
SQLRETURN SQL400Json( SQLHDBC  hdbc, SQLCHAR * injson, SQLINTEGER  inlen, SQLCHAR * outjson, SQLINTEGER  outlen )
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  init_table_lock(hdbc, 0);
  sqlrc = custom_SQL400Json( hdbc, injson, inlen, outjson, outlen );
  if (init_cli_trace()) {
    dump_SQL400Json(sqlrc,  hdbc, injson, inlen, outjson, outlen );
  }
  init_table_unlock(hdbc, 0);
  return sqlrc;
}
void * SQL400JsonThread (void *ptr)
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int myccsid = init_CCSID400(0);
  SQL400JsonStruct * myptr = (SQL400JsonStruct *) ptr;
  init_table_lock(myptr->hdbc, 0);
  myptr->sqlrc = custom_SQL400Json( myptr->hdbc, myptr->injson, myptr->inlen, myptr->outjson, myptr->outlen );
  if (init_cli_trace()) {
    dump_SQL400Json(myptr->sqlrc,  myptr->hdbc, myptr->injson, myptr->inlen, myptr->outjson, myptr->outlen );
  }
  init_table_unlock(myptr->hdbc, 0);
  /* void SQL400JsonCallback(SQL400JsonStruct* ); */
  if (myptr->callback) {
    void (*ptrFunc)(SQL400JsonStruct* ) = myptr->callback;
    ptrFunc( myptr );
  }
  pthread_exit((void *)myptr);
}
pthread_t SQL400JsonAsync ( SQLHDBC  hdbc, SQLCHAR * injson, SQLINTEGER  inlen, SQLCHAR * outjson, SQLINTEGER  outlen, void * callback )
{
  int rc = 0;
  pthread_t tid = 0;
  SQL400JsonStruct * myptr = (SQL400JsonStruct *) malloc(sizeof(SQL400JsonStruct));
  myptr->sqlrc = SQL_SUCCESS;
  myptr->hdbc = hdbc;
  myptr->injson = injson;
  myptr->inlen = inlen;
  myptr->outjson = outjson;
  myptr->outlen = outlen;
  myptr->callback = callback;
  rc = pthread_create(&tid, NULL, SQL400JsonThread, (void *)myptr);
  return tid;
}
SQL400JsonStruct * SQL400JsonJoin (pthread_t tid, SQLINTEGER flag)
{
  SQL400JsonStruct * myptr = (SQL400JsonStruct *) NULL;
  int active = 0;
  active = init_table_in_progress(tid, 0);
  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {
    pthread_join(tid,(void**)&myptr);
  } else {
    return (SQL400JsonStruct *) NULL;
  }
  return myptr;
}
