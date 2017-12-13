#ifndef _PASETOILE_H
#define _PASETOILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#ifdef __IBMC__
#include "PaseType.h"
#else
#include <as400_types.h>
#include <as400_protos.h>
#endif
#include "PaseTool.h"

/* ILE mapping defines */
#define ILE_PGM_BY_REF_IN 1
#define ILE_PGM_BY_REF_OUT 2
#define ILE_PGM_BY_REF_BOTH 3
#define ILE_PGM_BY_VALUE 4
#define ILE_PGM_BY_RETURN 5
#define ILE_PGM_BY_IN_DS 6

#define ILE_VALUE_MAX_LEN 16

#define ILE_PGM_MAX_ARGS 159
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
  short arg_sig[ILE_PGM_MAX_ARGS];
  int arg_pos[ILE_PGM_MAX_ARGS];
  int arg_len[ILE_PGM_MAX_ARGS];
  char pgm[16];
  char lib[16];
  char func[128];
  char debug[128];
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


int ile_pgm_str_2_int8(char * where, const char *str, int tdim);
int ile_pgm_int8_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_int16(char * where, const char *str, int tdim);
int ile_pgm_int16_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_int32(char * where, const char *str, int tdim);
int ile_pgm_int32_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_int64(char * where, const char *str, int tdim);
int ile_pgm_int64_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_uint8(char * where, const char *str, int tdim);
int ile_pgm_uint8_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_uint16(char * where, const char *str, int tdim);
int ile_pgm_uint16_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_uint32(char * where, const char *str, int tdim);
int ile_pgm_uint32_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_uint64(char * where, const char *str, int tdim);
int ile_pgm_uint64_2_output(tool_struct_t *tool, char * where, int tdim);
int ile_pgm_str_2_float(char * where, const char *str, int tdim);
int ile_pgm_float_2_output(tool_struct_t *tool, char * where, int tscale, int tdim);
int ile_pgm_str_2_double(char * where, const char *str, int tdim);
int ile_pgm_double_2_output(tool_struct_t *tool, char * where, int tscale, int tdim);
int ile_pgm_str_2_hole(char * where, int tlen, int tdim);
int ile_pgm_str_2_packed(char * where, char *str, int tdim, int tlen, int tscale);
int ile_pgm_packed_2_output(tool_struct_t *tool, char * where, int tlen, int tscale, int tdim);
int ile_pgm_str_2_zoned(char * where, char *str, int tdim, int tlen, int tscale);
int ile_pgm_zoned_2_output(tool_struct_t *tool, char * where, int tlen, int tscale, int tdim);
int ile_pgm_str_2_char(char * where, char *str, int tdim, int tlen, int tvary, int tccsid);
int ile_pgm_char_2_output(tool_struct_t *tool, char * where, int tlen, int tvary, int tccsid, int tdim);
int ile_pgm_str_2_bin(char * where, char *str, int tdim, int tlen, int tvary);
int ile_pgm_bin_2_output(tool_struct_t *tool, char * where, int tlen, int tvary, int tdim);

int ile_pgm_int8_2_int(char * where);
int ile_pgm_int16_2_int(char * where);
int ile_pgm_int32_2_int(char * where);
int ile_pgm_int64_2_int(char * where);
int ile_pgm_uint8_2_int(char * where);
int ile_pgm_uint16_2_int(char * where);
int ile_pgm_uint32_2_int(char * where);
int ile_pgm_uint64_2_int(char * where);
int ile_pgm_float_2_int(char * where);
int ile_pgm_double_2_int(char * where);
int ile_pgm_packed_2_int(char * where, int tlen, int tscale);
int ile_pgm_zoned_2_int(char * where, int tlen, int tscale);
int ile_pgm_char_2_int(char * where, int tlen, int tvary);
int ile_pgm_bin_2_int(char * where, int tlen);
int ile_pgm_hole_2_int(char * where, int tlen);

int ile_pgm_char_2_int_valid(char * where, int tlen, int tvary);

int ile_pgm_char_is_blank(char * where, int tlen, int tvary);


char ile_pgm_type(char *str, int * tlen, int * tscale, int * tvary);
int ile_pgm_type_size(char typ, int tlen, int tdim, int tvary);
int ile_pgm_by(char *str, char typ, int tlen, int tdim, int tvary, int isDs, int * spill_len, int * pase_sig);
char * ile_pgm_parm_location(int isOut, int by, short sig, int tlen, ile_pgm_call_t * layout);
void ile_pgm_trim_ebcdic(char *str, int len);
void ile_pgm_trim_ascii(char *str, int len);
char * ile_pgm_spill_top_buf(ile_pgm_call_t * layout);
int ile_pgm_spill_top_offset(ile_pgm_call_t * layout);
int ile_pgm_spill_length(ile_pgm_call_t * layout);
char * ile_pgm_argv_top_buf(ile_pgm_call_t * layout);
int ile_pgm_argv_top_offset(ile_pgm_call_t * layout);
int ile_pgm_argv_length(ile_pgm_call_t * layout);
ile_pgm_call_t * ile_pgm_grow(ile_pgm_call_t **playout, int size);

#endif /* _PASETOILE_H */


