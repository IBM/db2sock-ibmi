#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#include "PaseCliRun.h"
#include "PaseCliJson.h"

static char * run_start = 
 "{";
static char * run_start_name[] = 
 {
 "\"",
 "\":{"
 };
static char * run_end = 
 "}";
static char * run_start_array[] = 
 {
 "\"",
 "\":["
 };
static char * run_end_array = 
 "]";
static char * run_error[] = 
 {
 "\"ok\":false,\"reason\":\"",
 "\""
 };
static char * run_ok = 
 "\"ok\":true";
static char * run_name_value_string[] = 
 {
 "\"",
 "\":\"",
 "\""
 };
static char * run_name_value_misc[] = 
 {
 "\"",
 "\":",
 };
static char * run_comma = 
 ",";

void json_output(int flag, char *outrun, int outlen, char *argv[])
{
  int i= 0;
  switch (flag) {
  case RUN_START:
    strcat(outrun,run_start);
    break;
  case RUN_START_NAME:
    strcat(outrun,run_start_name[0]);
    strcat(outrun,argv[0]);
    strcat(outrun,run_start_name[1]);
    break;
  case RUN_START_ARRAY_NAME:
    strcat(outrun,run_start_array[0]);
    strcat(outrun,argv[0]);
    strcat(outrun,run_start_array[1]);
    break;
  case RUN_NAME_VALUE_MISC:
    strcat(outrun,run_name_value_misc[0]);
    strcat(outrun,argv[0]);
    strcat(outrun,run_name_value_misc[1]);
    strcat(outrun,argv[1]);
    break;
  case RUN_NAME_VALUE_STRING:
    strcat(outrun,run_name_value_string[0]);
    strcat(outrun,argv[0]);
    strcat(outrun,run_name_value_string[1]);
    strcat(outrun,argv[1]);
    strcat(outrun,run_name_value_string[2]);
    break;
  case RUN_OK:
    strcat(outrun,run_ok);
    break;
  case RUN_ERROR:
    strcat(outrun,run_error[0]);
    for (i=0; argv[i]; i++) {
      strcat(outrun,argv[i]);
    }
    strcat(outrun,run_error[1]);
    break;
  case RUN_END_ARRAY:
    strcat(outrun,run_end_array);
    break;
  case RUN_COMMA:
    strcat(outrun,run_comma);
    break;
  case RUN_END:
    strcat(outrun,run_end);
    break;
  default:
    break;
  }
}

static char * json_colon(char * j) 
{
  while (j[0]) {
    switch(j[0]) {
    case ':':
      return j;
      break;
    default:
      break;
    }
    j += 1;
  }
  return NULL;
}

static char * json_quote(char * j) 
{
  while (j[0]) {
    switch(j[0]) {
    case '"':
      return j;
      break;
    default:
      break;
    }
    j += 1;
  }
  return NULL;
}

static char * json_nonblank(char * j) 
{
  while (j[0]) {
    switch(j[0]) {
    case ' ':
      break;
    default:
      return j;
      break;
    }
    j += 1;
  }
  return NULL;
}

static char * json_value_end(char * j) 
{
  while (j[0]) {
    switch(j[0]) {
    case ' ':
    case ']':
    case '}':
    case ',':
      return j;
      break;
    default:
      break;
    }
    j += 1;
  }
  return j;
}

int json_parse_hash(char * jsoni, void **out_name, void **out_value) 
{
  int i = 0;
  int argc = 0;
  int oldSz = 0;
  int newSz = 0;
  char * ptr = (char *) NULL;
  char * ptr1 = (char *) NULL;
  char * ptr2 = (char *) NULL;
  char * name_beg = (char *) NULL;
  char * colon_beg = (char *) NULL;
  char * value_beg = (char *) NULL;
  void * namePtr = (void *) NULL;
  void * valuePtr = (void *) NULL;
  char * nameOldPtr = (char *) NULL;
  char * valueOldPtr = (char *) NULL;
  char **name = (char **) NULL;
  char **value = (char **) NULL;

  /* start */
  ptr = jsoni;
  for (i=0; ; i++) {
    /* pointer(s) to name(s) and value(s) */
    if (argc < i + 1) {
      oldSz = argc * sizeof(name_beg);
      argc += 256;
      newSz = argc * sizeof(name_beg);
      namePtr = malloc(newSz);
      valuePtr = malloc(newSz);
      memset(namePtr,0,newSz);
      memset(valuePtr,0,newSz);
      if (oldSz) {
        memcpy(namePtr,nameOldPtr,oldSz);
        free(nameOldPtr);
        memcpy(valuePtr,valueOldPtr,oldSz);
        free(valueOldPtr);
      }
      name = (char **)namePtr;
      value = (char **)valuePtr;
      *out_name = namePtr;
      *out_value = valuePtr;
      nameOldPtr = namePtr;
      valueOldPtr = valuePtr;
    }
    name[i] = (char *) NULL;
    value[i] = (char *) NULL;

    /* (")name":"value" */
    ptr = json_quote(ptr);
    if (!ptr) break;
    ptr += 1;
    name_beg = ptr;
    /* "name("):"value" */
    ptr = json_quote(ptr);
    if (!ptr) break;
    ptr[0] = '\0';
    ptr += 1;
    /* successful "name": */
    name[i] = name_beg;

    /* "name"(:)"value" */
    ptr = json_colon(ptr);
    if (!ptr) break;
    ptr += 1;
    colon_beg = ptr;

    /* "name":(?) */
    ptr = json_nonblank(colon_beg);
    if (!ptr) break;
    switch (ptr[0]) {
    case '"':
      /* "name":(")value" */
      ptr += 1;
      value_beg = ptr;
      /* "name":"value(") */
      ptr = json_quote(ptr);
      if (!ptr) break;
      ptr[0] = '\0';
      ptr += 1;
      /* successful "name":"value" json pair */
      value[i] = value_beg;
      break;
    case '[':
    case '{':
      continue;
      break;
    default:
      /* "name":(v)alue */
      value_beg = ptr;
      ptr += 1;
      /* "name":value() */
      ptr = json_value_end(ptr);
      ptr[0] = '\0';
      ptr += 1;
      /* successful "name":"value" json pair */
      value[i] = value_beg;
      break;
    }
  }
  return i;
}


