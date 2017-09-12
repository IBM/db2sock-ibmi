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

#ifdef __IBMC__
/* nothing ILE compiler */
#else
#define TOOL400_MAX_ERR_MSG_LEN (SQL_MAX_MESSAGE_LENGTH + SQL_SQLSTATE_SIZE + 10)
#endif

#define TOOL400_EXPAND_CHAR 3
#define TOOL400_EXPAND_BINARY 2
#define TOOL400_EXPAND_OTHER 64
#define TOOL400_EXPAND_COL_NAME 128

#define TOOL400_MAX_ARGS 32
#define TOOL400_MAX_COLS 1024

#define TOOL400_MAX_CMD_BUFF 4096

/*
Order input array:
  key begin (TOOL400_KEY_CONN)
    key attr (TOOL400_CONN_DB) <- attributes before child nodes (json_sort, xml natural)
      key children (TOOL400_KEY_PGM)

key[n]                                  val[n] - "names" parser dependent (anything)
--------------------------------        --------------------------------
*/
#define TOOL400_KEY_CONN       1        /*"connect":*/
#define TOOL400_KEY_PCONN      2        /*"pconnect":*/
#define TOOL400_CONN_DB     1001        /*"database":"*LOCAL"*/
#define TOOL400_CONN_UID    1002        /*"name":"MYUSER"*/
#define TOOL400_CONN_PWD    1003        /*"password":"MYPWD"*/
#define TOOL400_CONN_LIBL   1004        /*"libl":"MYLIB YOURLIB"*/
#define TOOL400_CONN_CURLIB 1005        /*"curlib":"MYLIB"*/
#define TOOL400_CONN_QUAL   1006        /*"qual":"myprivate1"*/
#define TOOL400_CONN_ISOLATION 1007     /*"isolation":
                                         *  "nc" - SQL_TXN_NO_COMMIT (No Commit)
                                         *  "uc" - SQL_TXN_READ_UNCOMMITTED (Uncommitted Read)
                                         *  "cs" - SQL_TXN_READ_COMMITTED (Cursor Stability)
                                         *  "rr" - SQL_TXN_REPEATABLE_READ (Repeatable Read )
                                         *  "rs" - SQL_TXN_SERIALIZABLE (Read Stability)
                                         */
#define TOOL400_KEY_END_CONN   9        /*"end"*/

#define TOOL400_KEY_QUERY     10        /*"query":
                                         "  select * from animals where breed=?"*/
#define TOOL400_KEY_END_QUERY 19        /*"end"*/

#define TOOL400_KEY_PARM      20        /*"parm":"fox"*/
#define TOOL400_KEY_END_PARM  29        /*"end"*/

#define TOOL400_KEY_FETCH     30        /*"fetch":"all"*/
#define TOOL400_KEY_END_FETCH 39        /*"end"*/

#define TOOL400_KEY_CMD       40        /*"cmd":"CHGLIBL LIBL(DB2JSON QTEMP) CURLIB(DB2JSON)"*/
#define TOOL400_KEY_END_CMD   49        /*"end"*/

#define TOOL400_KEY_PGM       50        /*"pgm"*/
#define TOOL400_PGM_NAME    1051        /*"name":"MYPGM"*/
#define TOOL400_PGM_LIB     1052        /*"lib":"*LIBL"*/
#define TOOL400_PGM_FUNC    1053        /*"func":"MYFUNC" (SRVPGM function)*/
#define TOOL400_KEY_END_PGM   59        /*"end"*/

#define TOOL400_KEY_DCL_DS    60        /*"dcl-ds"*/
#define TOOL400_DS_NAME     1061        /*"name":"my_ds_t"*/
#define TOOL400_DS_DIM      1062        /*"dim":"4"*/
#define TOOL400_DS_BY       1063        /*"by":"in|out|both|value|const|return"*/
#define TOOL400_KEY_END_DS    69        /*"end"*/

#define TOOL400_KEY_DCL_S     70        /*"dcl-s"*/
#define TOOL400_S_NAME      1071        /*"name":"myvar"*/
#define TOOL400_S_DIM       1072        /*"dim":"4"*/
#define TOOL400_S_TYPE      1073        /*"type":"5av2" (see below)*/
#define TOOL400_S_BY        1074        /*"by":"in|out|both|value|const|return"*/
#define TOOL400_S_VALUE     1075        /*"value":"42" */
#define TOOL400_KEY_END_S     79        /*"end"*/

#define TOOL400_KEY_ATTR_BEG 1000       /* attribute range */
#define TOOL400_KEY_ATTR_SEP 1998       /* attribute reserved (internal use only) */
#define TOOL400_KEY_ATTR_END 1999       /* attribute range */

#define TOOL400_KEY_SPEC_BEG 2000       /* special attribute range */
#define TOOL400_KEY_ARY_BEG 2071        /*"["*/
#define TOOL400_KEY_ARY_SEP 2072        /*","*/
#define TOOL400_KEY_ARY_END 2073        /*"]"*/
#define TOOL400_KEY_SEPC_END 2999       /* special attribute range */

#define TOOL400_KEY_HIGH    9000        /* everything above is parser only range */

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
typedef void (*output_pgm_dcl_ds_beg_t)(char *, char *, int);
typedef void (*output_pgm_dcl_ds_end_t)(char *, int);
typedef void (*output_pgm_dcl_s_beg_t)(char *, char *, int);
typedef void (*output_pgm_dcl_s_data_t)(char *, char *, int);
typedef void (*output_pgm_dcl_s_end_t)(char *, int);
typedef struct tool_struct {
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
  output_pgm_dcl_ds_beg_t output_pgm_dcl_ds_beg;
  output_pgm_dcl_ds_end_t output_pgm_dcl_ds_end;
  output_pgm_dcl_s_beg_t output_pgm_dcl_s_beg;
  output_pgm_dcl_s_data_t output_pgm_dcl_s_data;
  output_pgm_dcl_s_end_t output_pgm_dcl_s_end;
} tool_struct_t;

/*
 * toolkit ctor (new) with callbacks by parser (any json parser)
 */
tool_struct_t * tool_ctor(
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
  output_pgm_dcl_ds_beg_t output_pgm_dcl_ds_beg,
  output_pgm_dcl_ds_end_t output_pgm_dcl_ds_end,
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
 tool_struct_t *tool, int *key, char **val, int *lvl);
#endif

#endif /* _PASETOOL_H */


