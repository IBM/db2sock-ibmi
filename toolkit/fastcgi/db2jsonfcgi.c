#include "fcgi_stdio.h" /* fcgi library; put it first*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../db2/PaseCliAsync.h"

#define OCCURS_CLOB_MAX 15000000

static void db2fcgi_http_200(char *json)
{
  printf("HTTP/1.1 200 Ok\r\n"
         "Content-type: application/json; charset=utf-8\r\n"
         "\r\n"
         "%s",json);
}

static void db2fcgi_http_user_error_200(char *reason)
{
  printf("HTTP/1.1 403 Forbidden\r\n"
         "Content-type: application/json; charset=utf-8\r\n"
         "\r\n"
         "{\"ok\":false,\"reason\":\"%s\"}", reason);
}


static void db2fcgi_http_403(char *reason)
{
  printf("HTTP/1.1 403 Forbidden\r\n"
         "Content-type: application/json; charset=utf-8\r\n"
         "\r\n"
         "{\"ok\":false,\"reason\":\"%s\"}", reason);
}

int main(int argc, char * argv[])
{
  int retcode = 0, szContent=0, rTot = 0, rSz = 0;
  char * req = (char *) NULL;
  char * get = (char *) NULL;
  char * pContent = NULL;
  char getbuf[OCCURS_CLOB_MAX];
  char buff[OCCURS_CLOB_MAX];
  int len = 0;
  SQLHDBC hdbc = 0;

  while (FCGI_Accept() >= 0)   {
    hdbc = 0;
    /* http://www.restapitutorial.com/lessons/httpmethods.html
     * POST   - create
     * GET    - read
     * PUT    - update/replace
     * PATCH  - update/modify
     * DELETE - delete
     */
    req = getenv("REQUEST_METHOD");
    switch (req[0]) {
    case 'P':
      switch (req[1]) {
      case 'O':
        get = getenv("CONTENT_LENGTH");
        szContent = atoi(get);
        // -----
        // read from stdin (Apache)
        pContent = (char *) &getbuf;
        memset(getbuf,0,sizeof(getbuf));
        fread(getbuf, szContent, 1, stdin);
        len = strlen(getbuf);
        if (len < 1) {
          db2fcgi_http_user_error_200("empty");
          continue;
        }
        memset(buff,0,sizeof(buff));
        retcode = SQL400Json(hdbc, getbuf, len, buff, sizeof(buff));
        db2fcgi_http_200(buff);
        continue;
        break;
      default:
        break;
      }
      break;
    case 'G':
      get = getenv("QUERY_STRING");
      len = strlen(get);
      if (len < 1) {
        db2fcgi_http_user_error_200("empty");
        continue;
      }
      memset(buff,0,sizeof(buff));
      retcode = SQL400Json(hdbc, get, len, buff, sizeof(buff));
      db2fcgi_http_200(buff);
      continue;
      break;
    default:
      break;
    }
    /* error */
    sprintf(buff,"REQUEST_METHOD %s is unsupported.",req);
    db2fcgi_http_403(buff);
  } /* while */
  return 0;
}
