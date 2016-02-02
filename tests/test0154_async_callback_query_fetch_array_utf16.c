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
char db_utf16[22];
char uid_utf16[22];
char pwd_utf16[22];

char qry0_utf16[1024];

char big_old_buf1[1024];
char big_old_buf2[1024];


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

  sqlrc = SQL400FetchArrayW(hstmt, 
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
    memset(big_old_buf1,0,sizeof(big_old_buf1));
    sqlrc = SQL400FromUtf16(henv,  (SQLPOINTER) opt->szColName, (SQLINTEGER)  lang_strlen_utf16(opt->szColName)*2, (SQLPOINTER)  &big_old_buf1, (SQLINTEGER)  sizeof(big_old_buf1), myccsid);
    printf("%d) %s\n",i,big_old_buf1);
  }
  argv = (char **) out_rows;
  for (i=0; i < cnt_rows; i++) {
    prms = (SQL400ParamStruct *) argv[i];
    for (j=0; j < cnt_cols; j++) {
      opt = (SQL400DescStruct *)&opts[j];
      prm = (SQL400ParamStruct *)&prms[j];
      memset(big_old_buf1,0,sizeof(big_old_buf1));
      sqlrc = SQL400FromUtf16(henv,  (SQLPOINTER) opt->szColName, (SQLINTEGER)  lang_strlen_utf16(opt->szColName)*2, (SQLPOINTER)  &big_old_buf1, (SQLINTEGER)  sizeof(big_old_buf1), myccsid);
      memset(big_old_buf2,0,sizeof(big_old_buf2));
      sqlrc = SQL400FromUtf16(henv,  (SQLPOINTER) prm->pfSqlCValue, (SQLINTEGER)  lang_strlen_utf16(prm->pfSqlCValue)*2, (SQLPOINTER)  &big_old_buf2, (SQLINTEGER)  sizeof(big_old_buf2), myccsid);
      printf("%d) %s %s\n", j, big_old_buf1, big_old_buf2);
    }
  }
  sqlrc = SQL400FetchArrayFree(out_rows, out_decs, cnt_cols);
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
  sqlrc = SQL400ToUtf16(henv, (SQLPOINTER) qry0, (SQLINTEGER) strlen(qry0), (SQLPOINTER) &qry0_utf16, (SQLINTEGER) sizeof(qry0_utf16), myccsid);
  tid = SQLExecDirectWAsync (hstmt, (SQLWCHAR *)&qry0_utf16, lang_strlen_utf16((SQLCHAR *)&qry0_utf16), (void *)SQLExecDirectCallback );
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
  sqlrc = SQL400ToUtf16(henv,  (SQLPOINTER) db, (SQLINTEGER)  strlen(db), (SQLPOINTER)  &db_utf16, (SQLINTEGER) sizeof(db_utf16), myccsid);
  sqlrc = SQL400ToUtf16(henv, (SQLPOINTER) uid, (SQLINTEGER) strlen(uid), (SQLPOINTER) &uid_utf16, (SQLINTEGER) sizeof(uid_utf16), myccsid);
  sqlrc = SQL400ToUtf16(henv, (SQLPOINTER) pwd, (SQLINTEGER) strlen(pwd), (SQLPOINTER) &pwd_utf16, (SQLINTEGER) sizeof(pwd_utf16), myccsid);
  tid = SQL400ConnectWAsync(henv, (SQLWCHAR *) &db_utf16, (SQLWCHAR *) &uid_utf16, (SQLWCHAR *) &pwd_utf16, &hdbc, (SQLPOINTER)&pophdbc, (void *)SQL400ConnectCallback);
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
  sqlrc = SQLOverrideCCSID400( 1200 );
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
