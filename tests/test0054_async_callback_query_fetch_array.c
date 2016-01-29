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
char * qry0 = "select * from qiws.qcustcdt where lstnam like 'Hen%'";

SQLINTEGER myccsid = 819;
char db_utf8[11];
char uid_utf8[11];
char pwd_utf8[11];

char qry0_utf8[1024];


/* ====================
 * fetch
 * ====================
 */

void main_fetch(SQLHANDLE hstmt) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  SQLINTEGER start_row = 0; 
  SQLINTEGER max_rows = 10; 
  SQLINTEGER cnt_rows = 0;
  SQLINTEGER more_rows = 0; 
  SQLINTEGER cnt_cols = 0; 
  SQLPOINTER out_rows = (SQLPOINTER) NULL;
  SQLPOINTER out_decs = (SQLPOINTER) NULL;
  SQLINTEGER all_char = 1; 
  SQLINTEGER expand_factor = 0;
  SQL400DescStruct * opts = (SQL400DescStruct *) NULL;
  SQL400DescStruct * opt = (SQL400DescStruct *) NULL;
  SQL400ParamStruct * prms = (SQL400ParamStruct *) NULL;
  SQL400ParamStruct * prm = (SQL400ParamStruct *) NULL;
  char ** argv = (char **)NULL;
  int i = 0, j = 0, k = 0;

  sqlrc = SQL400FetchArray(hstmt, 
    start_row, 
    max_rows, 
    (SQLINTEGER *) &cnt_rows, 
    (SQLINTEGER *) &more_rows, 
    (SQLINTEGER *) &cnt_cols, 
    (SQLPOINTER *) &out_rows, 
    (SQLPOINTER *) &out_decs, 
    all_char, 
    expand_factor);

  opts = (SQL400DescStruct *) out_decs;
  for (i=0; i < cnt_cols; i++) {
    opt = (SQL400DescStruct *)&opts[i];
    printf("%d) %s\n",i,opt->szColName);
  }
  argv = (char **) out_rows;
  for (i=0; i < cnt_rows; i++) {
    prms = (SQL400ParamStruct *) argv[i];
    for (j=0; j < cnt_cols; j++) {
      opt = (SQL400DescStruct *)&opts[j];
      prm = (SQL400ParamStruct *)&prms[j];
      printf("%d) %s %s\n", j, opt->szColName, prm->pfSqlCValue);
    }
  }
  printf("main_fetch (thread %d): leaving\n",ptid);
}

/* ====================
 * query
 * select * from qiws/qcustcdt where lstnam like 'Hen%'
 * ====================
 */

/* callback sends SQLExecDirectStruct (PaseCliAsync.h) */
void SQLExecDirectCallback(SQLExecDirectStruct* myptr) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  printf("SQLExecDirectCallback (thread %d): starting\n",ptid);
  printf("SQLExecDirectCallback (thread %d): complete: sqlrc=%d, hstmt=%d, sql=%s len=%d callback=%p\n",
    ptid, myptr->sqlrc, myptr->hstmt, myptr->szSqlStr, myptr->cbSqlStr, myptr->callback);
  lang_check_sqlrc(SQL_HANDLE_STMT, myptr->hstmt, myptr->sqlrc, 1, &sqlcode);
  /* query done, next fetch ...*/
  main_fetch(myptr->hstmt);
  free(myptr);
  printf("SQLExecDirectCallback (thread %d): leaving\n",ptid);
}

void main_query(SQLHANDLE hdbc) {
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQLRETURN sqlrc = SQL_SUCCESS;
  printf("main_query (thread %d): starting\n",ptid);
  sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  lang_check_sqlrc(SQL_HANDLE_STMT, hstmt, sqlrc, 1, &sqlcode);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) qry0, (SQLINTEGER) strlen(qry0), (SQLPOINTER) &qry0_utf8, (SQLINTEGER) sizeof(qry0_utf8), myccsid);
  tid = SQLExecDirectAsync (hstmt, (SQLCHAR *)&qry0_utf8, strlen((SQLCHAR *)&qry0_utf8), (void *)SQLExecDirectCallback );
  printf("main_query (thread %d): leaving\n",ptid);
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
  /* connect done, next query ...*/
  main_query(*(myptr->ohnd));
  free(myptr);
  printf("SQL400ConnectCallback (thread %d): leaving\n",ptid);
}
void main_connect(SQLHANDLE henv) {
  SQLRETURN sqlrc = SQL_SUCCESS;
  pthread_t ptid = pthread_self();
  pthread_t tid = 0;
  SQL400ConnectStruct *myptr = (SQL400ConnectStruct *) NULL;
  printf("main_connect (thread %d): starting\n",ptid);
  /* async connection */
  sqlrc = SQL400ToUtf8(henv,  (SQLPOINTER) db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf8, (SQLINTEGER)  sizeof(db_utf8), myccsid);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf8, (SQLINTEGER) sizeof(uid_utf8), myccsid);
  sqlrc = SQL400ToUtf8(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf8, (SQLINTEGER) sizeof(pwd_utf8), myccsid);
  tid = SQL400ConnectAsync(henv, (SQLCHAR *) &db_utf8, (SQLCHAR *) &uid_utf8, (SQLCHAR *) &pwd_utf8, &hdbc, (SQLPOINTER)&pophdbc, (void *)SQL400ConnectCallback);
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
  sqlrc = SQLOverrideCCSID400( 1208 );
  lang_check_sqlrc(SQL_HANDLE_ENV, henv, sqlrc, 1, &sqlcode);
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
  printf("sleeping few seconds, allow you check for QSQ server jobs\n");
  sleep(10);
  sqlrc = SQLDisconnect(hdbc);
  sqlrc = SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  return 1;
}
