#ifndef _PASETOOL_H
#define _PASETOOL_H


#ifdef __IBMC__
/* nothing ILE compiler */
#else
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <iconv.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#endif

/* === experimental (not finished) ===
 * This module has fancy 'big helper' APIs.
 *
 * Goal enable many operatins in one async call. Similar to
 * scripting APIs, one new SQL400xxx API (not CLI), many CLI calls
 * set attributes, bind columns, etc.
 *
 * Warning: 
 * Many bugs still here. Development is trial and error,
 * so don't expect these APIs to be solid until this
 * warning is removed.
 */

/* make sp call to ILE blob call wrapper
 * > export TOOLLIB=DB2JSON
 * (see ILE-PROC)
 */
#define TOOLLIB "TOOLLIB"

#define TOOL400_OUT_MAX_STDOUT 1000000

#define TOOL400_MAX_KEY 65000

#define TOOL400_MAX_ARGS 32
#define TOOL400_MAX_COLS 1024

#ifdef __IBMC__
/* nothing ILE compiler */
#else
#define TOOL400_MAX_ERR_MSG_LEN (SQL_MAX_MESSAGE_LENGTH + SQL_SQLSTATE_SIZE + 10)
#endif

#define TOOL400_EXPAND_CHAR 3
#define TOOL400_EXPAND_BINARY 2
#define TOOL400_EXPAND_OTHER 64
#define TOOL400_EXPAND_COL_NAME 128

#define TOOL400_UNKNOWN -1

#define TOOL400_CMD_HELP 1
#define TOOL400_CMD_QUERY 2

#define TOOL400_OUT_COMMA_STDOUT 11
#define TOOL400_OUT_JSON_STDOUT 12
#define TOOL400_OUT_SPACE_STDOUT 13
#define TOOL400_OUT_COMMA_BUFF 21
#define TOOL400_OUT_JSON_BUFF 22
#define TOOL400_OUT_SPACE_BUFF 23

#define TOOL400_MAX_CMD_BUFF 4096

/* -- types --
 * "5a"    char(5)         char a[5]
 * "5av2"  varchar(5:2)    struct varchar{short,a[5]}
 * "5av4"  varchar(5:4)    struct varchar{int,a[5]}
 * "5b"    binary(5)       char a[5]
 * "5bv2"  varbinary(5:2)  struct varbinary{short,a[5]}
 * "5bv4"  varbinary(5:4)  struct varbinary{int,a[5]}
 * "3i0"   int(3)          int8, char
 * "5i0"   int(5)          int16, short
 * "10i0"  int(10)         int32, int, long
 * "20i0"  int(20)         int64, long long
 * "3u0"   uns(3)          uint8, uchar, char
 * "5u0"   uns(5)          uint16, ushort, unsigned short
 * "10u0"  uns(10)         uint32, uint, unsigned long
 * "20u0"  uns(20)         uint64, ulonglong, unsigned long long
 * "4f2"   float           float
 * "8f2"   double          double
 * "12p2"  packed(12:2)    (no c equiv)
 * "12s2"  zoned(12:2)     (no c equiv)
 * "8h"    hole            hole
 */
#define TOOL400_NBR_KEYS 11
#define TOOL400_KEY_CONN 1
#define TOOL400_KEY_PCONN 2
#define TOOL400_KEY_QUERY 10
#define TOOL400_KEY_PARM 20
#define TOOL400_KEY_FETCH 30
#define TOOL400_KEY_CMD 40
#define TOOL400_KEY_PGM 50
#define TOOL400_KEY_DCL_S 51
#define TOOL400_KEY_DCL_DS 52
#define TOOL400_KEY_END_DS 53
#define TOOL400_KEY_END_PGM 54

#define ILE_PGM_BY_REF_IN 1
#define ILE_PGM_BY_REF_OUT 2
#define ILE_PGM_BY_REF_BOTH 3
#define ILE_PGM_BY_VALUE 4
#define ILE_PGM_BY_RETURN 5
#define ILE_PGM_BY_IN_DS 6

#define ILE_PGM_MAX_ARGS 128
#define ILE_PGM_ALLOC_BLOCK 4096
typedef struct ile_pgm_call_struct {
#ifdef __IBMC__
  /* pad blob alignment */
  int blob_pad[3];
  /* ILE address (set ILE side) */
  char * argv[ILE_PGM_MAX_ARGS];
#else
  /* pad pase alignment */
  int blob_pad[4];
  /* ILE address (untouched PASE side) */
  ILEpointer argv[ILE_PGM_MAX_ARGS];
#endif
  int argv_parm[ILE_PGM_MAX_ARGS];
  int arg_by[ILE_PGM_MAX_ARGS];
  int arg_pos[ILE_PGM_MAX_ARGS];
  int arg_len[ILE_PGM_MAX_ARGS];
  char pgm[16];
  char lib[16];
  char func[128];
  int max;
  int pos;
  int vpos;
  int argc;
  int parmc;
  int return_start;
  int return_end;
  char * buf;
} ile_pgm_call_t;

#ifdef __IBMC__
/* nothing ILE compiler */
#else
/*
 * Callbacks provided by parser (any json parser)
 */
typedef int (*parse_array_values_t)(char *c, char **v);
typedef void (*output_script_beg_t)(char *);
typedef void (*output_script_end_t)(char *);
typedef void (*output_record_array_beg_t)(char *);
typedef void (*output_record_array_end_t)(char *);
typedef void (*output_record_no_data_found_t)(char *);
typedef void (*output_record_row_beg_t)(char *);
typedef void (*output_record_name_value_t)(char *, char *, int, int, char *);
typedef void (*output_record_row_end_t)(char *);
typedef int (*output_sql_errors_t)(SQLHANDLE, SQLSMALLINT, int, char *);
typedef void (*output_pgm_beg_t)(char *, char *, char *, char *);
typedef void (*output_pgm_end_t)(char *);
typedef void (*output_pgm_dcl_s_beg_t)(char *, char *, int);
typedef void (*output_pgm_dcl_s_data_t)(char *, char *, int);
typedef void (*output_pgm_dcl_s_end_t)(char *, int);
typedef struct tool_struct {
  parse_array_values_t parse_array_values;
  output_script_beg_t output_script_beg;
  output_script_end_t output_script_end;
  output_record_array_beg_t output_record_array_beg;
  output_record_array_end_t output_record_array_end;
  output_record_no_data_found_t output_record_no_data_found;
  output_record_row_beg_t output_record_row_beg;
  output_record_name_value_t output_record_name_value;
  output_record_row_end_t output_record_row_end;
  output_sql_errors_t output_sql_errors;
  output_pgm_beg_t output_pgm_beg;
  output_pgm_end_t output_pgm_end;
  output_pgm_dcl_s_beg_t output_pgm_dcl_s_beg;
  output_pgm_dcl_s_data_t output_pgm_dcl_s_data;
  output_pgm_dcl_s_end_t output_pgm_dcl_s_end;
} tool_struct_t;

/*
 * toolkit ctor (new) with callbacks by parser (any json parser)
 */
tool_struct_t * tool_ctor(
  parse_array_values_t parse_array_values,
  output_script_beg_t output_script_beg,
  output_script_end_t output_script_end,
  output_record_array_beg_t output_record_array_beg,
  output_record_array_end_t output_record_array_end,
  output_record_no_data_found_t output_record_no_data_found,
  output_record_row_beg_t output_record_row_beg,
  output_record_name_value_t output_record_name_value,
  output_record_row_end_t output_record_row_end,
  output_sql_errors_t output_sql_errors,
  output_pgm_beg_t output_pgm_beg,
  output_pgm_end_t output_pgm_end,
  output_pgm_dcl_s_beg_t output_pgm_dcl_s_beg,
  output_pgm_dcl_s_data_t output_pgm_dcl_s_data,
  output_pgm_dcl_s_end_t output_pgm_dcl_s_end
);

/*
 * toolkit dtor (delete) by parser (any json parser)
 */
void tool_dtor(tool_struct_t *tool);

/*
 * toolkit run name/value operations by parser (any json parser)
 */
int tool_run(int ihdbc, char * outarea, int outlen,
 tool_struct_t *tool, int *key, char **val, int *arr);
#endif

#endif /* _PASETOOL_H */


