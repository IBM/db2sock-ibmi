/*
 * ILE CGI interface JSON400
 */
#include <miptrnam.h>
#include <mih/rslvsp.h>
#include <mih/miobjtyp.h>
#include <leawi.h>
#include <qleawi.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <qtqiconv.h>
#include <except.h>
#include "iconf.h" /* see Makefile (see iconf.h) */
#include "../toolkit-parser-json/PaseJson.h"

#define OCCURS_CLOB_MAX 15000000

char * mri037_header_json = "Content-type: text/plain\n\n";
char * mri037_error_BINARY = "CGIConvMode BINARY unsupported";
char * mri037_error_EBCDIC_JCD = "CGIConvMode EBCDIC_JCD unsupported";
char * mri037_error_MIXED = "CGIConvMode MIXED unsupported";
char * mri037_error_empty_input = "empty input";
char * mri037_error_empty_output = "empty output";
/* {"ok":false,"reason":"%s"} */
char mri037_json_error_colon_c = ':';
char mri037_json_error_comma_c = ',';
char mri037_json_error_double_c = '\"';
char mri037_json_error_open_c = '{';
char * mri037_json_error_ok = "\"ok\"";
char * mri037_json_error_false = "false";
char * mri037_json_error_reason = "\"reason\"";
char mri037_json_error_close_c = '}';

/* QHTTPSVR/QZSRCORE
 * url decode function
 * (decode json input)  
 */
typedef int (os_fct_000_t)();
os_fct_000_t *ap_unescape_url_ptr = NULL;

void header037(void) {
  int len = 0;
  len = strlen(mri037_header_json);
  write(1,mri037_header_json,len);
}


void error037(char * reason) {
  int len = 0;
  char talk037[4096];
  memset(talk037,0,sizeof(talk037));
  sprintf(talk037,"%c%s%c%s%c%s%c%c%s%c%c",
    mri037_json_error_open_c,
    mri037_json_error_ok,
    mri037_json_error_colon_c,
    mri037_json_error_false,
    mri037_json_error_comma_c,
    mri037_json_error_reason,
    mri037_json_error_colon_c,
    mri037_json_error_double_c,
    reason,
    mri037_json_error_double_c,
    mri037_json_error_close_c);
  len = strlen(talk037);
  write(1,talk037,len);
} 

void rmvPlus(char *where, int32 size) {
  int i = 0;
  int zero = 0;
  char c = ' ';  
  for (i=0; i < size; i++) {
    c = where[i];   
    if (c == 0x00 || zero) { 
      zero = 1;   
      where[i] = 0x00;
    /* junk "CR" */ 
    } else if (c == 0x0D) {
      where[i] = 0x40;   
    /* @ADC - may lead to errors (fix me) */
    /* junk "+"                           */  
    } else if (c == '+') {
      where[i] = 0x40;   
    }   
  }      
}

int apache_unescape_url(char * pContent)
{
  void *os_pfct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  char * userPgm = "QZSRCORE";
  char * userLib = "QHTTPSVR";
  char * userFunc = "ebcdic_unescape_url";
  int userLenFunc = 19;
  /* load user handle by val call module */
  if (!ap_unescape_url_ptr) {
    os_pgm_ptr = rslvsp(WLI_SRVPGM, userPgm, userLib, _AUTH_OBJ_MGMT);
    os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
    ap_unescape_url_ptr = QleGetExpLong(&os_act_mark, 0, &userLenFunc, userFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  }
  return ap_unescape_url_ptr(pContent);
}


void main() {
  int i = 0;
  int rc = 0;
  int sqlrc = 0;
  char * chkBINARY = "BINARY";
  char * chkMIXED = "MIXED";
  char * chkEBCDIC = "EBCDIC";
  char * chkEBCDIC_JCD = "EBCDIC_JCD";
  char * isBINARY = NULL;
  char * isMIXED = NULL;
  char * isEBCDIC = NULL;
  char * isEBCDIC_JCD = NULL;
  char * chkPost = "POST";
  char * cMode = NULL;
  char * cMethod = NULL;
  char * rCopy = NULL;
  void * pContent = NULL;
  int32 szContent = 0;
  int32 rTot = 0;
  void * outData = NULL;
  int32 outLen = 0;

  char sbang = ccsid_variant_bang();
  char spound = ccsid_variant_pound();
  char sdollar = ccsid_variant_dollar();
  char sat = ccsid_variant_at();
  char sbackslash = ccsid_variant_backslash();
  char sopen_brace = ccsid_variant_open_brace();
  char sclose_brace = ccsid_variant_close_brace();
  char scaret = ccsid_variant_caret();
  char sbacktick = ccsid_variant_backtick();
  char sopen_bracket = ccsid_variant_open_bracket();
  char sclose_bracket = ccsid_variant_close_bracket();
  char sbar = ccsid_variant_bar();
  char stilde = ccsid_variant_tilde();

  /* variant chars */
  mri037_json_error_open_c = sopen_bracket;
  mri037_json_error_close_c = sclose_bracket;

  /* header json */
  header037();

  /* re-open the stdin for the Persistent CGI Program */
  freopen("", "r", stdin);

  /* CGIConvMode */
  cMode = getenv("CGI_MODE");
  if (cMode) {
    isBINARY = strstr(cMode,chkBINARY);
    if (isBINARY) {
      error037(mri037_error_BINARY);
      fflush(stdout);
      return;
    }
    isEBCDIC_JCD = strstr(cMode,chkEBCDIC_JCD);
    if (isEBCDIC_JCD) {
      error037(mri037_error_EBCDIC_JCD);
      fflush(stdout);
      return;
    }
    isMIXED = strstr(cMode,chkMIXED);
    if (isMIXED) {
      error037(mri037_error_MIXED);
      fflush(stdout);
      return;
    }
    isEBCDIC = strstr(cMode,chkEBCDIC);
  }

  /* web request (json input) */
  cMethod = getenv("REQUEST_METHOD");
  /* POST method */
  if (strcmp(cMethod,chkPost) == 0) {
    rCopy = getenv("CONTENT_LENGTH");
    szContent = atoi(rCopy);
    pContent = malloc(szContent);
    if (szContent > 0) {
      /* read from stdin (Apache) */
      rTot = fread(pContent, 1, szContent, stdin);
    }
  /* GET method */
  } else {
    rCopy = getenv("QUERY_STRING");
    szContent= strlen(rCopy);
    pContent = malloc(szContent);
    if (szContent > 0) {
      memcpy(pContent,rCopy,szContent);
    }
  }
  /* empty */
  if (szContent < 1) {
    error037(mri037_error_empty_input);
    fflush(stdout);
    return;
  }
  /* decoding */
  rc = apache_unescape_url(pContent);
  rmvPlus(pContent,szContent);
  szContent = strlen(pContent);

  /* call */
  outLen = OCCURS_CLOB_MAX;
  outData = (char *) malloc(outLen);
  memset(outData,0,outLen);
  sqlrc = custom_SQL400Json(0,
            pContent,
            szContent, 
            outData,
            outLen);
  outLen = strlen(outData);
  if (outLen) {
    write(1,outData,outLen);
  } else {
    error037(mri037_error_empty_output);
  }
  free(pContent);
  free(outData);
  fflush(stdout);

  return;
}


