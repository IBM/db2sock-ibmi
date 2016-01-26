#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sqlcli1.h>
#include "test.h"
#include "PaseCliAsync.h"
#include "liblang400.h"

char *db  = NULL;
char *uid = NULL;
char *pwd = NULL;
SQL400SetAttrStruct options[100];
SQLHANDLE henv;
SQLHANDLE hdbc;
SQLHANDLE hstmt;
SQLINTEGER ccsid = SQL_CCSID;
SQLINTEGER yes = SQL_TRUE;
SQL400AttrStruct pophenv[3];
SQL400AttrStruct pophdbc[3];
SQLINTEGER sqlcode;
SQL400ParamStruct call_parms[100];
SQL400DescStruct desc_parms[100];
SQLINTEGER indPtr = 0;
SQL400ParamStruct call_cols[100];
SQL400DescStruct desc_cols[100];
SQLPOINTER data_cols[100];
char * qry1 = "select * from qiws.qcustcdt where lstnam like ?";
char * prm1 = "Hen%";


/* ====================
 * fetch
 * ====================
 */

void main_fetch(SQLHANDLE hstmt) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLSMALLINT pccol = 0;
  SQLINTEGER start_row = 0;
  int i = 0;
  printf("main_fetch (thread %d): starting\n",ptid);
  sqlrc = SQLNumResultCols(hstmt, (SQLSMALLINT *)&pccol );
  lang_check_sqlrc(SQL_HANDLE_STMT, hstmt, sqlrc, 1, &sqlcode);
  printf("main_fetch (thread %d): nbr cols %d\n",ptid, pccol);
  for (i=0;i<pccol;i++) {
    sqlrc = SQL400AddDesc(hstmt, i + 1, SQL400_DESC_COL, (SQLPOINTER)&desc_cols);
    lang_check_sqlrc(SQL_HANDLE_STMT, hstmt, sqlrc, 1, &sqlcode);
    data_cols[i] = (SQLPOINTER) malloc(1024);
    indPtr = 1024;
    sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)data_cols[i], &indPtr, (SQLPOINTER) &call_cols);
  }
  sqlrc = SQL400Fetch(hstmt, start_row, (SQLPOINTER)&call_cols, (SQLPOINTER)&desc_cols);
  lang_check_sqlrc(SQL_HANDLE_STMT, hstmt, sqlrc, 1, &sqlcode);
  for (i=0;i<pccol;i++) {
    printf("main_fetch (thread %d): %s %s\n", ptid, (char *)desc_cols[i].szColName, (char *)data_cols[i]);
  }
  printf("main_fetch (thread %d): leaving\n",ptid);
}


/* ====================
 * execute
 * select * from qiws/qcustcdt where lstnam like 'Hen%'
 * ====================
 */

/* callback sends SQL400ExecuteStruct (PaseCliAsync.h) */
void SQL400ExecuteCallback(SQL400ExecuteStruct* myptr) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  printf("SQL400ExecuteCallback (thread %d): starting\n",ptid);
  printf("SQL400ExecuteCallback (thread %d): complete: sqlrc=%d, hstmt=%d, parms=%p desc_parms=%p callback=%p\n",
    ptid, myptr->sqlrc, myptr->hstmt, myptr->parms, myptr->desc_parms, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_STMT, myptr->hstmt, myptr->sqlrc, 1, &sqlcode);
  /* execute done, next fetch ...*/
  main_fetch(myptr->hstmt);
  free(myptr);
  printf("SQL400ExecuteCallback (thread %d): leaving\n",ptid);
}

void main_execute(SQLHANDLE hstmt) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  printf("main_execute (thread %d): starting\n",ptid);
  sqlrc = SQL400AddDesc(hstmt, 1, SQL400_DESC_PARM, (SQLPOINTER)&desc_parms);
  lang_check_sqlrc(SQL_HANDLE_STMT, hstmt, sqlrc, 1, &sqlcode);
  indPtr = strlen(prm1);
  sqlrc = SQL400AddCVar(1, SQL_PARAM_INPUT, SQL_C_CHAR, (SQLPOINTER)prm1, &indPtr, (SQLPOINTER) &call_parms ); 
  tid = SQL400ExecuteAsync(hstmt, (SQLPOINTER)&call_parms, (SQLPOINTER)&desc_parms, (void *)SQL400ExecuteCallback);
  printf("main_execute (thread %d): leaving\n",ptid);
}


/* ====================
 * prepare
 * select * from qiws/qcustcdt where lstnam like 'Hen%'
 * ====================
 */

/* callback sends SQLPrepareStruct (PaseCliAsync.h) */
void SQLPrepareCallback(SQLPrepareStruct* myptr) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  printf("SQLPrepareCallback (thread %d): starting\n",ptid);
  printf("SQLPrepareCallback (thread %d): complete: sqlrc=%d, hstmt=%d, sql=%s len=%d callback=%p\n",
    ptid, myptr->sqlrc, myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_STMT, myptr->hstmt, myptr->sqlrc, 1, &sqlcode);
  /* prepare done, next execute ...*/
  main_execute(myptr->hstmt);
  free(myptr);
  printf("SQLPrepareCallback (thread %d): leaving\n",ptid);
}

void main_prepare(SQLHANDLE hdbc) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  printf("main_prepare (thread %d): starting\n",ptid);
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  lang_check_sqlrc(SQL_HANDLE_STMT, hstmt, sqlrc, 1, &sqlcode);
  tid = SQLPrepareAsync (hstmt, (SQLCHAR *)qry1, strlen(qry1), (void *)SQLPrepareCallback );
  printf("main_prepare (thread %d): leaving\n",ptid);
}

/* ====================
 * connection
 * ====================
 */

/* callback sends SQL400ConnectStruct (PaseCliAsync.h) */
void SQL400ConnectCallback(SQL400ConnectStruct* myptr) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  printf("SQL400ConnectCallback (thread %d): starting\n",ptid);
  printf("SQL400ConnectCallback (thread %d): complete: sqlrc=%d, henv=%d, db=%s uid=%s pwd=xxxx *ohnd=%d options=%p callback=%p\n",
    ptid, myptr->sqlrc, myptr->henv, myptr->db, myptr->uid, *(myptr->ohnd), myptr->options, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_DBC, *(myptr->ohnd), myptr->sqlrc, 1, &sqlcode);
  /* connect done, next prepare ...*/
  main_prepare(*(myptr->ohnd));
  free(myptr);
  printf("SQL400ConnectCallback (thread %d): leaving\n",ptid);
}
void main_connect(SQLHANDLE henv) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQL400ConnectStruct *myptr = (SQL400ConnectStruct *) NULL;
  printf("main_connect (thread %d): starting\n",ptid);
  /* async connection */
  tid = SQL400ConnectAsync(henv, db, uid, pwd, &hdbc, (SQLPOINTER)&pophdbc, (void *)SQL400ConnectCallback);
  printf("main_connect (thread %d): leaving\n",ptid);
}

/* ====================
 * environment
 * ====================
 */

/* callback sends SQL400EnvironmentStruct (PaseCliAsync.h) */
void SQL400EnvironmentCallback(SQL400EnvironmentStruct* myptr) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  printf("SQL400EnvironmentCallback (thread %d): starting\n",ptid);
  printf("SQL400EnvironmentCallback (thread %d): complete: sqlrc=%d, *ohnd=%d options=%p callback=%p\n",
    ptid, myptr->sqlrc, *(myptr->ohnd), myptr->options, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_DBC, *(myptr->ohnd), myptr->sqlrc, 1, &sqlcode);
  /* environ done, next connect ... */
  main_connect(*(myptr->ohnd));
  free(myptr);
  printf("SQL400EnvironmentCallback (thread %d): leaving\n",ptid);
}
void main_environ() {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  printf("main_environ (thread %d): starting\n",ptid);
  /* async environment db2 */
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL400_ATTR_PASE_CCSID, &ccsid, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  if (ccsid == 1208) {
    sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_UTF8, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  }
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  tid = SQL400EnvironmentAsync( &henv, (SQLPOINTER)&pophenv, (void *)SQL400EnvironmentCallback);
  printf("main_environ (thread %d): leaving\n",ptid);
}

/* ====================
 * main
 * ====================
 */
int main(int argc, char * argv[]) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  /* profile db2 */
  db  = getenv(SQL_DB400);
  uid = getenv(SQL_UID400);
  pwd = getenv(SQL_PWD400);
  /* async environment db2 */
  main_environ();
  sleep(20);
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return 1;
}
