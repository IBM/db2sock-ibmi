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

/*
See README.md for details.
*/
#define TOOL400_RANGE_ELEM_RSV_BEG 1
#define TOOL400_RANGE_ELEM_USR_BEG 2
#define TOOL400_RANGE_ELEM_RSV_END 3
#define TOOL400_RANGE_ELEM_USR_END 4
#define TOOL400_RANGE_ATTR_RSV 5
#define TOOL400_RANGE_ATTR_USR 6
#define TOOL400_RANGE_KEY_SPEC 7
#define TOOL400_RANGE_HIGH 8


#define TOOL400_KEY_ELEM_BEG        0   /* key 'action' elem range */
#define TOOL400_KEY_ELEM_RSV_BEG    0   /* toolkit beg action */
#define TOOL400_KEY_ELEM_RSV_BEG2 399   /* toolkit beg action */
#define TOOL400_KEY_ELEM_RSV_END  400   /* toolkit end action */
#define TOOL400_KEY_ELEM_RSV_END2 799   /* toolkit end action */
#define TOOL400_KEY_ELEM_USR_BEG  800   /* user beg elem */
#define TOOL400_KEY_ELEM_USR_BEG2 899   /* user beg elem */
#define TOOL400_KEY_ELEM_USR_END  900   /* user end elem */
#define TOOL400_KEY_ELEM_USR_END2 999   /* user end elem */
#define TOOL400_KEY_ELEM_END      999   /* key 'action' elem range */

#define TOOL400_KEY_ATTR_BEG     1000   /* attribute range */
#define TOOL400_KEY_ATTR_RSV_BEG 1000   /* toolkit beg attribute */
#define TOOL400_KEY_ATTR_RSV_END 1799   /* toolkit end attribute */
#define TOOL400_KEY_ATTR_USR_BEG 1800   /* user beg attribute */
#define TOOL400_KEY_ATTR_USR_END 1899   /* user end attribute */
#define TOOL400_KEY_ATTR_END     1999   /* attribute range */

#define TOOL400_KEY_SPEC_BEG     2000   /* special attribute range */
#define TOOL400_KEY_ARY_BEG      2071   /*"["*/
#define TOOL400_KEY_ARY_SEP      2072   /*","*/
#define TOOL400_KEY_ARY_END      2073   /*"]"*/
#define TOOL400_KEY_SEPC_END     2999   /* special attribute range */

#define TOOL400_KEY_HIGH         9000   /* everything above parser only range (remove before call) */


/*
key[n]                                  val[n] - "names" parser dependent (anything)
--------------------------------        --------------------------------
*/
#define TOOL400_ATTR_MAX          9     /* max 9 attributes per element (TOOL400_KEY_PGM, etc.) */

#define TOOL400_KEY_QUERY        10     /*"query": */
#define TOOL400_QUERY_STMT     1011     /*"stmt":"select * from animals where breed=?"*/
#define TOOL400_KEY_END_QUERY   410     /*"end"*/

#define TOOL400_KEY_PARM         20     /*"parm": */
#define TOOL400_PARM_VALUE     1021     /*"value":"fox"*/
#define TOOL400_KEY_END_PARM    420     /*"end"*/

#define TOOL400_KEY_FETCH        30     /*"fetch": */
#define TOOL400_FETCH_REC      1031     /*"rec":"all"*/
#define TOOL400_KEY_END_FETCH   430     /*"end"*/

#define TOOL400_KEY_CMD          40     /*"cmd"*/
#define TOOL400_CMD_EXEC       1041     /*"exec":"CHGLIBL LIBL(DB2JSON QTEMP) CURLIB(DB2JSON)"*/
#define TOOL400_KEY_END_CMD     440     /*"end"*/

#define TOOL400_KEY_PGM          50     /*"pgm"*/
#define TOOL400_PGM_NAME       1051     /*"name":"MYPGM"*/
#define TOOL400_PGM_LIB        1052     /*"lib":"*LIBL"*/
#define TOOL400_PGM_FUNC       1053     /*"func":"MYFUNC" (SRVPGM function)*/
#define TOOL400_KEY_END_PGM     450     /*"end"*/

#define TOOL400_KEY_DCL_DS       60     /*"ds"*/
#define TOOL400_DS_NAME        1061     /*"name":"my_ds_t"*/
#define TOOL400_DS_DIM         1062     /*"dim":"4"*/
#define TOOL400_DS_BY          1063     /*"by":"in|out|both|value|const|return"*/
#define TOOL400_KEY_END_DS      460     /*"end"*/

#define TOOL400_KEY_DCL_S        70     /*"s"*/
#define TOOL400_S_NAME         1071     /*"name":"myvar"*/
#define TOOL400_S_DIM          1072     /*"dim":"4"*/
#define TOOL400_S_TYPE         1073     /*"type":"5av2" (see below)*/
#define TOOL400_S_BY           1074     /*"by":"in|out|both|value|const|return"*/
#define TOOL400_S_VALUE        1075     /*"value":"42" */
#define TOOL400_KEY_END_S       470     /*"end"*/
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
#define TOOL400_KEY_CONN         90     /*"connect":*/
#define TOOL400_CONN_DB        1091     /*"database":"*LOCAL"*/
#define TOOL400_CONN_UID       1092     /*"name":"MYUSER"*/
#define TOOL400_CONN_PWD       1093     /*"password":"MYPWD"*/
#define TOOL400_CONN_LIBL      1094     /*"libl":"MYLIB YOURLIB"*/
#define TOOL400_CONN_CURLIB    1095     /*"curlib":"MYLIB"*/
#define TOOL400_CONN_QUAL      1096     /*"qual":"myper1" (persistent connection) */
#define TOOL400_CONN_ISOLATION 1097     /*"isolation":
                                         *  "nc" - SQL_TXN_NO_COMMIT (No Commit)
                                         *  "uc" - SQL_TXN_READ_UNCOMMITTED (Uncommitted Read)
                                         *  "cs" - SQL_TXN_READ_COMMITTED (Cursor Stability)
                                         *  "rr" - SQL_TXN_REPEATABLE_READ (Repeatable Read )
                                         *  "rs" - SQL_TXN_SERIALIZABLE (Read Stability)
                                         */
#define TOOL400_KEY_END_CONN    490     /*"end"*/

/* other defines */
#define TOOL400_EXPAND_CHAR 3
#define TOOL400_EXPAND_BINARY 2
#define TOOL400_EXPAND_OTHER 64
#define TOOL400_EXPAND_COL_NAME 128

#define TOOL400_MAX_ARGS 32
#define TOOL400_MAX_COLS 1024

#define TOOL400_MAX_CMD_BUFF 4096

/* ILE mapping defines */
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
  int step;
  int max;
  int pos;
  int vpos;
  int argc;
  int parmc;
  int return_start;
  int return_end;
  char * buf;
} ile_pgm_call_t;

/* error */
#define TOOL400_JOBLOG_MAX_COLS 15
#define TOOL400_JOBLOG_MAX_SIZE 200
#define TOOL400_JOBLOG_MAX_REC 4


/*
 * Callbacks provided by parser (any json, xml, csv, etc. parser)
 */
#ifdef __IBMC__
/* nothing ILE compiler */
#else

typedef struct tool_node {
  int ord;
  int fin;
  int key;
  char * val;
  int akey[TOOL400_ATTR_MAX];
  char * aval[TOOL400_ATTR_MAX];
  void * ctor;
  void * prev;
  void * next;
} tool_node_t;

typedef void (*output_script_beg_t)(tool_node_t *, char *);
typedef void (*output_script_end_t)(tool_node_t *, char *);
typedef void (*output_query_beg_t)(tool_node_t *, char *,char *);
typedef void (*output_record_array_beg_t)(tool_node_t *, char *);
typedef void (*output_record_array_end_t)(tool_node_t *, char *);
typedef void (*output_record_no_data_found_t)(tool_node_t *, char *);
typedef void (*output_record_row_beg_t)(tool_node_t *, char *);
#define TOOL400_DATA_TYPE_NBR 1
#define TOOL400_DATA_TYPE_CHAR 2
#define TOOL400_DATA_IS_NULL SQL_NULL_DATA
typedef void (*output_record_name_value_t)(tool_node_t *, char *, char *, char *, int, int);
typedef void (*output_record_row_end_t)(tool_node_t *, char *);
typedef void (*output_query_end_t)(tool_node_t *, char *);
typedef void (*output_sql_errors_t)(tool_node_t *, char *, int, int, char *, char *);
typedef void (*output_pgm_beg_t)(tool_node_t *, char *, char *, char *, char *);
typedef void (*output_pgm_end_t)(tool_node_t *, char *);
typedef void (*output_pgm_dcl_ds_beg_t)(tool_node_t *, char *, char *, int);
typedef void (*output_pgm_dcl_ds_end_t)(tool_node_t *, char *, int);
typedef void (*output_pgm_dcl_s_beg_t)(tool_node_t *, char *, char *, int);
typedef void (*output_pgm_dcl_s_data_t)(tool_node_t *, char *, char *, int);
typedef void (*output_pgm_dcl_s_end_t)(tool_node_t *, char *, int);
typedef void (*output_cmd_beg_t)(tool_node_t *, char *, char *);
typedef void (*output_cmd_end_t)(tool_node_t *, char *);
typedef void (*output_joblog_beg_t)(tool_node_t *, char *);
typedef void (*output_joblog_rec_t)(tool_node_t *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *);
typedef void (*output_joblog_end_t)(tool_node_t *, char *);

typedef struct tool_struct {
  output_script_beg_t output_script_beg;
  output_script_end_t output_script_end;
  output_query_beg_t output_query_beg;
  output_query_end_t output_query_end;
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
  output_cmd_beg_t output_cmd_beg;
  output_cmd_end_t output_cmd_end;
  output_joblog_beg_t output_joblog_beg;
  output_joblog_rec_t output_joblog_rec;
  output_joblog_end_t output_joblog_end;
  tool_node_t * first;
  tool_node_t * curr;
  tool_node_t * last;
  SQLINTEGER sqlCode;
  SQLCHAR sqlState[SQL_SQLSTATE_SIZE + 1];
  SQLCHAR sqlMsg[SQL_MAX_MESSAGE_LENGTH + 1];
} tool_struct_t;

/*
 * toolkit ctor (new) with callbacks by parser (any json parser)
 */
tool_struct_t * tool_ctor(
  output_script_beg_t output_script_beg,
  output_script_end_t output_script_end,
  output_query_beg_t output_query_beg,
  output_query_end_t output_query_end,
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
  output_pgm_dcl_s_end_t output_pgm_dcl_s_end,
  output_cmd_beg_t output_cmd_beg,
  output_cmd_end_t output_cmd_end,
  output_joblog_beg_t output_joblog_beg,
  output_joblog_rec_t output_joblog_rec,
  output_joblog_end_t output_joblog_end
);

/*
 * toolkit node by parser (any json parser)
 */
tool_node_t * tool_node_beg(tool_struct_t * tool, int key, int ord);
tool_node_t * tool_node_sep(tool_struct_t * tool, tool_node_t * node, int key, int ord);
tool_node_t * tool_node_end(tool_struct_t * tool, tool_node_t * node, int key, int ord);
tool_node_t * tool_node_attr(tool_struct_t * tool, tool_node_t * node, int key, char *val, int ord);

int tool_key_range(int key);
int tool_key_match_beg_2_end(int key);
int tool_key_match_end_2_beg(int key);
int tool_key_match_attr_2_beg(int key);
/*
 * toolkit dtor (delete) by parser (any json parser)
 */
void tool_dtor(tool_struct_t *tool);

/*
 * toolkit run name/value operations by parser (any json parser)
 */
int tool_run(int ihdbc, char * outarea, int outlen, tool_struct_t *tool);
#endif

#endif /* _PASETOOL_H */


