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
#include "PaseTool.h"

void * tool_new(int size) {
  void * buffer = malloc(size + 1);
  memset(buffer,0,size + 1);
  return buffer;
}
void tool_free(char *buffer) {
  if (buffer) {
    free(buffer);
  }
}

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
) 
{
  tool_struct_t *tool = tool_new(sizeof(tool_struct_t));
  tool->parse_array_values = parse_array_values;
  tool->output_script_beg = output_script_beg;
  tool->output_script_end = output_script_end;
  tool->output_record_array_beg = output_record_array_beg;
  tool->output_record_array_end = output_record_array_end;
  tool->output_record_no_data_found = output_record_no_data_found;
  tool->output_record_row_beg = output_record_row_beg;
  tool->output_record_name_value = output_record_name_value;
  tool->output_record_row_end = output_record_row_end;
  tool->output_sql_errors = output_sql_errors;
  tool->output_pgm_beg = output_pgm_beg;
  tool->output_pgm_end = output_pgm_end;
  tool->output_pgm_dcl_s_beg = output_pgm_dcl_s_beg;
  tool->output_pgm_dcl_s_data = output_pgm_dcl_s_data;
  tool->output_pgm_dcl_s_end = output_pgm_dcl_s_end;
  return tool;
}

void tool_dtor(tool_struct_t *tool){
  tool_free((char *)tool);
}


int tool_parse_array_values(tool_struct_t *tool, char *c, char **v) {
  return tool->parse_array_values(c, v);
}

void tool_output_script_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_script_beg(out_caller);
}
void tool_output_script_end(tool_struct_t *tool, char *out_caller) {
  tool->output_script_end(out_caller);
}
void tool_output_record_array_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_record_array_beg(out_caller);
}
void tool_output_record_array_end(tool_struct_t *tool, char *out_caller) {
  tool->output_record_array_end(out_caller);
}
void tool_output_record_no_data_found(tool_struct_t *tool, char *out_caller) {
  tool->output_record_no_data_found(out_caller);
}
void tool_output_record_row_beg(tool_struct_t *tool, char *out_caller) {
  tool->output_record_row_beg(out_caller);
}
void tool_output_record_name_value(tool_struct_t *tool, char *name, char *value, int type, int fStrLen, char *out_caller) {
  tool->output_record_name_value(name, value, type, fStrLen, out_caller);
}
void tool_output_record_row_end(tool_struct_t *tool, char *out_caller) {
  tool->output_record_row_end(out_caller);
}
int tool_output_sql_errors(tool_struct_t *tool, SQLHANDLE handle, SQLSMALLINT hType, int rc, char *out_caller)
{
  return tool->output_sql_errors(handle, hType, rc, out_caller);
}
void tool_output_pgm_beg(tool_struct_t *tool, char *out_caller, char * name, char * lib, char * func) {
  tool->output_pgm_beg(out_caller, name, lib, func);
}
void tool_output_pgm_end(tool_struct_t *tool, char *out_caller) {
  tool->output_pgm_end(out_caller);
}
void tool_output_pgm_dcl_s_beg(tool_struct_t *tool, char *out_caller, char * name, int tdim) {
  tool->output_pgm_dcl_s_beg(out_caller, name, tdim);
}
void tool_output_pgm_dcl_s_data(tool_struct_t *tool, char *out_caller, char *value, int numFlag) {
  tool->output_pgm_dcl_s_data(out_caller, value, numFlag);
}
void tool_output_pgm_dcl_s_end(tool_struct_t *tool, char *out_caller, int tdim) {
  tool->output_pgm_dcl_s_end(out_caller, tdim);
}


/* by ref area */
void ile_pgm_reset_spill_pos(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->buf - (char *)layout;
  layout->pos = delta;
}
int ile_pgm_curr_spill_pos(ile_pgm_call_t * layout) {
  return layout->pos;
}
char * ile_pgm_curr_spill_ptr(ile_pgm_call_t * layout) {
  return (char *)layout + layout->pos;
}
void ile_pgm_next_spill_pos(ile_pgm_call_t * layout, int spill_len) {
  layout->pos += spill_len;
}

/* by value area (register area) */
void ile_pgm_reset_argv_pos(ile_pgm_call_t * layout) {
  int delta = 0;
  layout->argc = 0;
  layout->parmc = 0;
  layout->vpos = (char *)&layout->argv[0] - (char *)layout;
}
void ile_pgm_argv_full_reg_available(ile_pgm_call_t * layout) {
  int beg_reg  = (char *)&layout->argv[layout->argc] - (char *)layout;
  /* beyond register (use another register location) */
  if (layout->vpos > beg_reg) {
    layout->argc++;
  }
  /* register used for pass by ref, by value start next register location */
  layout->vpos = (char *)&layout->argv[layout->argc + 1] - (char *)layout; 
}
char * ile_pgm_curr_argv_ptr_align(ile_pgm_call_t * layout, int tlen) {
  int beg_reg  = (char *)&layout->argv[layout->argc] - (char *)layout;
  int end_reg  = beg_reg + sizeof(ILEpointer);
  /* natural alignment (by value) */
  if (tlen == 2) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 2);
  } else if (tlen <= 4) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 4);
  } else if (tlen <= 8) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 8);
  }
  /* beyond register (use another register location) */
  if (layout->vpos + tlen > end_reg) {
    layout->argc++;
  } 
  return (char *)layout + layout->vpos;
}
int ile_pgm_curr_argv_pos(ile_pgm_call_t * layout) {
  return layout->vpos;
}
void ile_pgm_next_argv_pos(ile_pgm_call_t * layout, int tlen) {
  layout->vpos += tlen;
}

void ile_pgm_reset_pos(ile_pgm_call_t * layout) {
  ile_pgm_reset_argv_pos(layout);
  ile_pgm_reset_spill_pos(layout);
}

ile_pgm_call_t * ile_pgm_grow(ile_pgm_call_t **playout, int size) {
  int i = 0;
  int new_len = 0;
  int orig_len = 0;
  char * tmp = NULL;
  int delta = 0;
  ile_pgm_call_t * layout = *playout;
  /* enough room ? */
  if (layout) {
    /* max length - current position */
    delta = layout->max - layout->pos;
    if (delta > size) {
      return *playout;
    }
    new_len = layout->max;
    orig_len = new_len;
  }
  /* need more space (block size alloc) */
  for (i=0; new_len < size + sizeof(ile_pgm_call_t); i++) {
    new_len += ILE_PGM_ALLOC_BLOCK;
  }
  /* expanded layout template */
  tmp = tool_new(new_len);
  /* copy original data */
  if (orig_len) {
    memcpy(tmp, layout, orig_len);
  }
  /* layout to new pointer */
  layout = (ile_pgm_call_t *) tmp;
  /* max template */
  layout->max = new_len;
  /* current spill pos */
  if (!orig_len) {
    ile_pgm_reset_pos(layout);
  }
  /* old layout free */
  tmp = (char *)(*playout);
  if (tmp) {
    tool_free(tmp);
  }
  /* rest layout template pointer */
  *playout = layout;
  /* return new location (tmp ptrs) */
  return *playout;
}

int ile_pgm_isnum_decorated(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  switch(c){
  case '-':
  case '.':
    return 1;
  default:
    break;
  }
  return 0;
}
int ile_pgm_isnum_digit(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}


int ile_pgm_round_up(int num, int factor) {
  return num + factor - 1 - (num - 1) % factor;
}

SQLRETURN ile_pgm_str_2_int8(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int8 * wherev = (int8 *) where;
  int8 value = 0;
  if (str) {
    value = (int8) strtol(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_int8_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int8 * wherev = (int8 *) where;
  int8 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_int16(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int16 * wherev = (int16 *) where;
  int16 value = 0;
  if (str) {
    value = (int16) strtol(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_int16_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int16 * wherev = (int16 *) where;
  int16 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_int32(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int32 * wherev = (int32 *) where;
  int32 value = 0;
  if (str) {
    value = (int32) strtol(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_int32_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int32 * wherev = (int32 *) where;
  int32 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_int64(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  int64 * wherev = (int64 *) where;
  int64 value = 0;
  if (str) {
    value = (int64) strtoll(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_int64_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  int64 * wherev = (int64 *) where;
  int64 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint8(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint8 * wherev = (uint8 *) where;
  uint8 value = 0;
  if (str) {
    value = (uint8) strtoul(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_uint8_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint8 * wherev = (uint8 *) where;
  uint8 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint16(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint16 * wherev = (uint16 *) where;
  uint16 value = 0;
  if (str) {
    value = (uint16) strtoul(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_uint16_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint16 * wherev = (uint16 *) where;
  uint16 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint32(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint32 * wherev = (uint32 *) where;
  uint32 value = 0;
  if (str) {
    value = (uint32) strtoul(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_uint32_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint32 * wherev = (uint32 *) where;
  uint32 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_uint64(char * where, const char *str, int tdim) {
  char * endptr = NULL;
  int i = 0;
  uint64 * wherev = (uint64 *) where;
  uint64 value = 0;
  if (str) {
    value = (uint64) strtoull(str, &endptr, 10);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_uint64_2_output(tool_struct_t *tool, char *out_caller, char * where, int tdim) {
  int i = 0;
  uint64 * wherev = (uint64 *) where;
  uint64 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_float(char * where, const char *str, int tdim) {
  int i = 0;
  float * wherev = (float *) where;
  float value = 0.0;
  if (str) {
    value = (float) strtof(str,NULL);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_float_2_output(tool_struct_t *tool, char *out_caller, char * where, int tscale, int tdim) {
  int i = 0;
  float * wherev = (float *) where;
  float value = 0;
  char str[128];
  char outfmt[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    if (tscale) {
      memset(outfmt,0,sizeof(outfmt));
      sprintf(outfmt,"%%.%df",tscale);
      sprintf(str,outfmt,value);
    } else {
      sprintf(str,"%f",value);
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_double(char * where, const char *str, int tdim) {
  int i = 0;
  double * wherev = (double *) where;
  double value = 0.0;
  if (str) {
    value = (double) strtod(str,NULL);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_double_2_output(tool_struct_t *tool, char *out_caller, char * where, int tscale, int tdim) {
  int i = 0;
  double * wherev = (double *) where;
  double value = 0;
  char str[128];
  char outfmt[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    if (tscale) {
      memset(outfmt,0,sizeof(outfmt));
      sprintf(outfmt,"%%.%df",tscale);
      sprintf(str,outfmt,value);
    } else {
      sprintf(str,"%f",value);
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_hole(char * where, int tlen, int tdim) {
  int i = 0;
  char * wherev = where;
  /* copy in */
  for (i=0; i < tdim; i++, wherev += tlen) {
    memset(wherev,0,tlen);
  }
  return SQL_SUCCESS;
}


SQLRETURN ile_pgm_str_2_packed(char * where, char *str, int tdim, int tlen, int tscale) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outDecimalPlaces = tscale;
  int outLength = outDigits/2+1;
  int inLength = 0;
  int sign = 0;
  char chr[256];
  char dec[256];
  char * c = NULL;
  int leadingZeros = 0;
  int firstNibble = 0;
  int secondNibble = 0;
  char * wherev = where;
  /* fix up input */
  if (!str) {
    str = "0";
  }
  memset(chr,0,sizeof(chr));
  memset(dec,0,sizeof(dec));
  c = str;
  inLength = strlen(c);
  for (i=0, j=0; i < inLength; i++) {
    if (c[i] == '-') {
      sign = i + 1;
    } else {
      if (ile_pgm_isnum_digit(c[i])) {
        chr[j++] = c[i];
      }
    }
  }
  /* convert string to packed */
  c = chr;
  inLength = strlen(c); 
  j = 0;
  if (outDigits % 2 == 0) {
   leadingZeros = outDigits - inLength + 1;
  } else {
   leadingZeros = outDigits - inLength;
  }
  /* write correct number of leading zero's */
  for (i=0; i<leadingZeros-1; i+=2) {
    dec[j++] = 0;
  }
  if (leadingZeros > 0) {
    if (leadingZeros % 2 != 0) {
      dec[j++] = (char)(c[k++] & 0x000F);
    }
  }
  /* place all the digits except last one */
  while (j < outLength-1) {
    firstNibble = (char)(c[k++] & 0x000F) << 4;
    secondNibble = (char)(c[k++] & 0x000F);
    dec[j++] = (char)(firstNibble + secondNibble);
  }
  /* place last digit and sign nibble */
  firstNibble = (char)(c[k++] & 0x000F) << 4;
  if (!sign) {
    dec[j++] = (char)(firstNibble + 0x000F);
  }
  else {
    dec[j++] = (char)(firstNibble + 0x000D);
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    memcpy(wherev, dec, outLength);
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_packed_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tscale, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int isOk = 0;
  int isDot = 0;
  int isScale = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits/2+1;
  int leftDigitValue = 0;
  int rightDigitValue = 0;
  char * c = NULL;
  char str[128];
  for (i=0; i < tdim; i++, wherev += outLength) {
    memset(str,0,sizeof(str));
    /* sign negative */
    c = wherev;
    rightDigitValue = (char)(c[outLength-1] & 0x0F);
    if (rightDigitValue == 0x0D) {
      str[j++] = '-';
    }
    for (j=0, k=0, l=0, isOk=0, isDot=0, isScale=0; k < outLength; k++) {
      /* decimal point */
      l++;
      if (!isDot && tscale && l >= tlen) {
        if (!isOk) {
          str[j++] = (char) 0x30;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      /* digits */
      leftDigitValue = (char)((c[k] >> 4) & 0x0F);
      if (isOk || leftDigitValue > 0) {
        str[j++] = (char)(0x30 + leftDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
      /* decimal point */
      l++;
      if (!isDot && tscale && l >= tlen) {
        if (!isOk) {
          str[j++] = (char) 0x30;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      /* digits */
      rightDigitValue = (char)(c[k] & 0x0F);
      if (k < outLength-1 && (isOk || rightDigitValue > 0)) {
        str[j++] = (char)(0x30 + rightDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
    }
    /* zero */
    if (!isOk) {
      str[j++] = (char) 0x30;
      str[j++] = '.';
      isOk = 1;
      isDot = 1;
      isScale = 0;
    }
    /* one significant decimal */
    if (isDot && !isScale) {
      str[j++] = (char) 0x30;
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_zoned(char * where, char *str, int tdim, int tlen, int tscale) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outDecimalPlaces = tscale;
  int outLength = outDigits;
  int inLength = 0;
  int sign = 0;
  char chr[256];
  char dec[256];
  char * c = NULL;
  char * wherev = where;
  /* fix up input */
  if (!str) {
    str = "0";
  }
  memset(chr,0,sizeof(chr));
  memset(dec,0,sizeof(dec));
  c = str;
  inLength = strlen(c);
  for (i=0, j=0; i < inLength; i++) {
    if (c[i] == '-') {
      sign = i + 1;
    } else {
      if (ile_pgm_isnum_digit(c[i])) {
        chr[j++] = c[i];
      }
    }
  }
  /* convert string to zoned */
  c = chr;
  inLength = strlen(c); 
  j = 0;
  /* write correct number of leading zero's */
  for (i=0; i < outDigits-inLength; i++) {
    dec[j++] = (char)0xF0;
  }
  /* place all the digits except the last one */
  while (j < outLength-1) {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00F0);
  }
  /* place the sign and last digit */
  if (!sign) {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00F0);
  } else {
    dec[j++] = (char)((c[k++] & 0x000F) | 0x00D0);
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    memcpy(wherev, dec, outLength);
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_zoned_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tscale, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int isOk = 0;
  int isDot = 0;
  int isScale = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits;
  int leftDigitValue = 0;
  int rightDigitValue = 0;
  char * c = NULL;
  char str[128];
  for (i=0; i < tdim; i++, wherev += outLength) {
    memset(str,0,sizeof(str));
    /* sign negative */
    c = wherev;
    leftDigitValue = (char)((c[outLength-1] >> 4) & 0x0F);
    if (leftDigitValue == 0x0D) {
      str[j++] = '-';
    }
    for (j=0, k=0, l=0, isOk=0, isDot=0, isScale=0; k < outLength; k++) {
      /* digits */
      leftDigitValue = (char)((c[k] >> 4) & 0x0F);
      /* decimal point */
      if (!isDot && tscale && l >= tlen - tscale) {
        if (!isOk) {
          str[j++] = (char) 0x30;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      l++;
      /* digits */
      rightDigitValue = (char)(c[k] & 0x0F);
      if (isOk || rightDigitValue > 0) {
        str[j++] = (char)(0x30 + rightDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
    }
    /* zero */
    if (!isOk) {
      str[j++] = (char) 0x30;
      str[j++] = '.';
      isOk = 1;
      isDot = 1;
      isScale = 0;
    }
    /* one significant decimal */
    if (isDot && !isScale) {
      str[j++] = (char) 0x30;
    }
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 1);
  }
  return SQL_SUCCESS;
}



SQLRETURN ile_pgm_str_2_char(char * where, char *str, int tdim, int tlen, int tvary, int tccsid) {
  int rc = 0;
  int i = 0;
  int j = 0;
  char * wherev = where;
  int len = 0;
  char * value = NULL;
  short * short_value = NULL;
  int * int_value = NULL;
  char * ebcdic = NULL;
  char * c = NULL;
  if (!str) {
    str = "";
  }
  /* truncate user overflow field area */
  len = strlen(str);
  if (len > tlen) {
    len = tlen;
  }
  /* ebcdic ccsid? */
  if (!tccsid) {
    tccsid = Qp2jobCCSID();
  }
  /* convert ccsid */
  if (len) {
    ebcdic = tool_new(len*4);
    rc = SQL400FromUtf8(0, str, len, ebcdic, len*4, tccsid);
    c = ebcdic;
    j = 0;
    for (i = len*4 - 1; i; i--) {
      if (c[i]) {
        j = i + 1;
        break;
      } 
    }
    len = j;
  }
  /* truncate */
  if (len > tlen) {
    len = tlen;
  }
  /* copy in ebcdic space pad (0x40) */
  for (i=0; i < tdim; i++, wherev += tlen) {
    /* vary */
    if (tvary == 4) {
      int_value = (int *) wherev;
      *int_value = len;
      wherev += 4;
    } else if (tvary) {
      short_value = (short *) wherev;
      *short_value = len;
      wherev += 2;
    }
    /* ebcdic space pad (0x40) */
    if (len < tlen) {
      memset(wherev,0x40,tlen);
    }
    /* ebcdic chars */
    if (len && ebcdic) {
      memcpy(wherev,ebcdic,len);
    }
  }
  /* free temp storage */
  if (ebcdic) {
    tool_free(ebcdic);
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_char_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tvary, int tccsid, int tdim) {
  int rc = 0;
  int i = 0;
  int j = 0;
  char * wherev = where;
  int len = 0;
  char * utf8 = NULL;
  char * c = NULL;
  char * str_empty = "";
  char * str_tool_empty = "{}";
  /* ebcdic ccsid? */
  if (!tccsid) {
    tccsid = Qp2jobCCSID();
  }
  /* copy in ebcdic 2 utf8 */
  len = tlen;
  utf8 = tool_new(len*4);
  for (i=0; i < tdim; i++, wherev += tlen) {
    /* vary */
    if (tvary == 4) {
      len = *(int *) wherev;
      wherev += 4;
    } else if (tvary) {
      len = *(short *) wherev;
      wherev += 2;
    } else {
      len = tlen;
    }
    if (len) {
      /* convert ebcdic to utf8 */
      memset(utf8,0,len*4);
      rc = SQL400ToUtf8(0, wherev, len, utf8, len*4, tccsid);
      /* trim */
      len = strlen(utf8);
      for (c = utf8, j = len - 1; j >= 0; j--) {
        if (!c[j] || c[j] == 0x20) {
          c[j] = 0x00;
          len = j;
        } else {
          break;
        }
      }
    } /* j loop (trim) */
    /* output processing */
    if (len) {
      tool_output_pgm_dcl_s_data(tool, out_caller, utf8, 0);
    } else {
      tool_output_pgm_dcl_s_data(tool, out_caller, str_tool_empty, 1);
    }
  } /* i loop (tdim) */
  /* free temp storage */
  if (utf8) {
    tool_free(utf8);
  }
  return SQL_SUCCESS;
}

SQLRETURN ile_pgm_str_2_bin(char * where, char *str, int tdim, int tlen, int tvary) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outLength = outDigits;
  int inLength = 0;
  int firstNibble = 0;
  int secondNibble = 0;
  short * short_value = NULL;
  int * int_value = NULL;
  char * dec = NULL;
  char * c = NULL;
  char * wherev = where;
  /* length of char hex binary input */
  if (str) {
    inLength = strlen(str);
  }
  /* truncate user overflow field area */
  if (inLength > tlen * 2) {
    inLength = tlen * 2;
  }
  /* copy in */
  for (i=0; i < tdim; i++, wherev += outLength) {
    /* vary */
    if (tvary == 4) {
      int_value = (int *) wherev;
      *int_value = inLength/2;
      wherev += 4;
    } else if (tvary) {
      short_value = (short *) wherev;
      *short_value = inLength/2;
      wherev += 2;
    }
    /* digits */
    memset(wherev, 0, outLength);
    dec = wherev;
    c = str;
    for (j=0, k=0; j < outDigits && k < inLength; ) {
      firstNibble = (char)(c[k++] & 0x000F) << 4;
      secondNibble = (char)(c[k++] & 0x000F);
      dec[j++] = (char)(firstNibble + secondNibble);
    }
  }
  return SQL_SUCCESS;
}
SQLRETURN ile_pgm_bin_2_output(tool_struct_t *tool, char *out_caller, char * where, int tlen, int tvary, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int len = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits*2+1;
  int leftDigitValue = 0;
  int rightDigitValue = 0;
  int anyDigitValue = 0;
  char * c = NULL;
  char * str = NULL;
  str = tool_new(outLength);
  for (i=0; i < tdim; i++, wherev += outDigits) {
    /* vary */
    if (tvary == 4) {
      len = *(int *) wherev;
      wherev += 4;
    } else if (tvary) {
      len = *(short *) wherev;
      wherev += 2;
    } else {
      len = tlen;
    }
    /* digits */
    memset(str,0,outLength);
    for (k=0, c = wherev; k < len; k++) {
      leftDigitValue = (char)((c[k] >> 4) & 0x0F);
      rightDigitValue = (char)(c[k] & 0x0F);
      for (l=0; l<2; l++) {
        switch(l) {
        case 0:
          anyDigitValue = leftDigitValue;
          break;
        case 1:
          anyDigitValue = rightDigitValue;
          break;
        default:
          break;
        }
        /* digit to string */
        switch(anyDigitValue) {
        case 0:
          str[j++] = '0';
          break;
        case 1:
          str[j++] = '1';
          break;
        case 2:
          str[j++] = '2';
          break;
        case 3:
          str[j++] = '3';
          break;
        case 4:
          str[j++] = '4';
          break;
        case 5:
          str[j++] = '5';
          break;
        case 6:
          str[j++] = '6';
          break;
        case 7:
          str[j++] = '7';
          break;
        case 8:
          str[j++] = '8';
          break;
        case 9:
          str[j++] = '9';
          break;
        case 0xA:
          str[j++] = 'A';
          break;
        case 0xB:
          str[j++] = 'B';
          break;
        case 0xC:
          str[j++] = 'C';
          break;
        case 0xD:
          str[j++] = 'D';
          break;
        case 0xE:
          str[j++] = 'E';
          break;
        case 0xF:
          str[j++] = 'F';
          break;
        default:
          break;
        }
      } /* l loop (digits) */
    } /* k loop (outLength) */
    tool_output_pgm_dcl_s_data(tool, out_caller, str, 0);
  } /* i loop (tdim) */
  /* free temp storage */
  if (str) {
    tool_free(str);
  }
  return SQL_SUCCESS;
}


/* parse "12p2", "5a", "5av2", ... */
char ile_pgm_type(char *str, int * tlen, int * tscale, int * tvary) {
  int rc = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  char t = ' ';
  char v1 = ' ';
  int v2 = 0;
  char * c = NULL;
  int cl = 0;
  char clen[32];
  char cscale[32];
  char cvary[32];

  /* no data */
  *tlen = 0;
  *tscale = 0;
  *tvary = 0;
  if (!str) {
    return t;
  }
  /* parse type */
  memset(clen,0,sizeof(clen));
  memset(cscale,0,sizeof(cscale));
  memset(cvary,0,sizeof(cvary));
  c = str;
  cl = strlen(c);
  for (i=0; cl && i < cl; i++) {
    if (ile_pgm_isnum_digit(c[i])) {
      /* len */
      if (t == ' ') {
        clen[j] = c[i];
        j++;
      /* scale */
      } else if (v1 == ' ') {
        cscale[k] = c[i];
        k++;
      /* varying 2 or 4 */
      } else {
        cvary[l] = c[i];
        l++;
      }
    } else {
      if (t == ' ') {
        t = c[i];
      } else if (v1 == ' ') {
        v1 = c[i];
      }
    }
  }
  /* len */
  if (j) {
    rc = ile_pgm_str_2_int32((char *)tlen, clen, 1);
  }
  /* scale */
  if (k) {
    rc = ile_pgm_str_2_int32((char *)tscale, cscale, 1);
  }
  /* varying 2 or 4 */
  if (v1 != ' ') {
    if (l) {
      rc = ile_pgm_str_2_int32((char *)tvary, cvary, 1);
    } else {
      *tvary = 2;
    }
  }
  /* return type */
  return t;
}

/* in|out|both|value|const|return */
int ile_pgm_by(char *str, char typ, int tlen, int tdim, int tvary, int isDs, int * spill_len) {
  int by = ILE_PGM_BY_REF_IN;
  /* default length input */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      *spill_len = sizeof(int8) * tdim;
      break;
    case 5:
      *spill_len = sizeof(int16) * tdim;
      break;
    case 10:
      *spill_len = sizeof(int32) * tdim;
      break;
    case 20:
      *spill_len = sizeof(int64) * tdim;
      break;
    default:
      *spill_len = sizeof(int32) * tdim;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      *spill_len = sizeof(uint8) * tdim;
      break;
    case 5:
      *spill_len = sizeof(uint16) * tdim;
      break;
    case 10:
      *spill_len = sizeof(uint32) * tdim;
      break;
    case 20:
      *spill_len = sizeof(uint64) * tdim;
      break;
    default:
      *spill_len = sizeof(uint32) * tdim;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      *spill_len = sizeof(float) * tdim;
      break;
    case 8:
      *spill_len = sizeof(double) * tdim;
      break;
    default:
      *spill_len = sizeof(double) * tdim;
      break;
    }
    break;
  case 'p':
    *spill_len = (tlen/2+1) * tdim;
    break;
  case 's':
    *spill_len = tlen * tdim;
    break;
  case 'a':
    switch(tvary){
    case 2:
      *spill_len = (tlen+sizeof(uint16)) * tdim;
      break;
    case 4:
      *spill_len = (tlen+sizeof(uint32)) * tdim;
      break;
    default:
      *spill_len = tlen * tdim;
      break;
    }
    break;
  case 'b':
    switch(tvary){
    case 2:
      *spill_len = (tlen+sizeof(uint16)) * tdim;
      break;
    case 4:
      *spill_len = (tlen+sizeof(uint32)) * tdim;
      break;
    default:
      *spill_len = tlen * tdim;
      break;
    }
    break;
  case 'h':
    *spill_len = tlen * tdim;
    break;
  default:
    *spill_len = tlen * tdim;
    break;
  }
  /* pass by ref/val or isDS (val) */
  if (isDs) {
    by = ILE_PGM_BY_IN_DS;
  } else if (!str) {
    by = ILE_PGM_BY_REF_BOTH;
  } else {
    if (str[0] == 'i') {
      by = ILE_PGM_BY_REF_IN;
    } else if (str[0] == 'o') {
      by = ILE_PGM_BY_REF_OUT;
    } else if (str[0] == 'b') {
      by = ILE_PGM_BY_REF_BOTH;
    } else if (str[0] == 'v' || str[0] == 'c') {
      /* not fit in register (not by value) */
      if (*spill_len > 8) {
        by = ILE_PGM_BY_REF_IN;
      /* ok, fit in register (by value/const) */
      } else {
        by = ILE_PGM_BY_VALUE;
      }
    } else if (str[0] == 'r') {
      by = ILE_PGM_BY_RETURN;
    }
  }
  /* return by */
  return by;
}

/* dcl-s parms */
char * ile_pgm_parm_location(int isOut, int by, int tlen, ile_pgm_call_t * layout) {

  char * where = NULL;

  /* current value assumed by ref buffer (or ds data)*/
  where = ile_pgm_curr_spill_ptr(layout);
  switch (by) {
  /* parm pass by ref (spill area) */
  case ILE_PGM_BY_REF_IN:
  case ILE_PGM_BY_REF_OUT:
  case ILE_PGM_BY_REF_BOTH:
    ile_pgm_argv_full_reg_available(layout);
    if (!isOut) {
      layout->argv_parm[layout->argc] = layout->parmc;
      layout->arg_by[layout->parmc] = by;
      layout->arg_pos[layout->parmc] = ile_pgm_curr_spill_pos(layout);
      layout->arg_len[layout->parmc] = tlen;
    }
    layout->argc++;
    layout->parmc++;
    /* next position */
    ile_pgm_next_spill_pos(layout, tlen);
    break;
  /* parm pass by value */
  case ILE_PGM_BY_VALUE:
    where = ile_pgm_curr_argv_ptr_align(layout, tlen);
    if (!isOut) {
      layout->argv_parm[layout->argc] = 0;
      layout->arg_by[layout->parmc] = by;
      layout->arg_pos[layout->parmc] = ile_pgm_curr_argv_pos(layout);
      layout->arg_len[layout->parmc] = tlen;
    }
    layout->parmc++;
    /* next position */
    ile_pgm_next_argv_pos(layout, tlen);
    break;
  /* return in buffer */
  case ILE_PGM_BY_RETURN:
    /* next position */
    ile_pgm_next_spill_pos(layout, tlen);
    break;
  /* ds data */
  case ILE_PGM_BY_IN_DS:
    /* next position */
    ile_pgm_next_spill_pos(layout, tlen);
    break;
  /* other??? */
  default:
    return NULL;
    break;
  }
  /* location of value */
  return where;
}


/* "dcl-s":["name","type", value, dimension, "in|out|both|value|const|return"], */
SQLRETURN tool_dcl_s(tool_struct_t *tool, char *out_caller, int isOut, int argc, char * argv[], int isDs, ile_pgm_call_t **playout) {

  ile_pgm_call_t * layout = *playout;

  char * in_name = NULL;
  char * in_type = NULL;
  char * in_value = NULL;
  char * in_dim = NULL;
  char * in_by = NULL;
  char * in_ccsid = NULL;

  char typ = ' ';
  int tlen = 0;
  int tscale = 0;
  int tvary = 0;
  int tdim = 0;
  int tccsid = 0;

  int spill_len = 0;
  int rc = 0;
  int by = 0;
  char * where = NULL;

  /* manditory - "name", "type" */
  if (argc < 2) {
    return SQL_ERROR;
  }
  /* manitory - name */
  in_name = argv[0];
  /* manitory - type */
  in_type = argv[1];
  /* optional - value */
  if (argc > 2) {
    in_value = argv[2];
  }
  /* optional - dimension */
  if (argc > 3) {
    in_dim = argv[3];
  }
  /* optional - by */
  if (argc > 4) {
    in_by = argv[4];
  }
  /* optional - ccsid */
  if (argc > 5) {
    in_ccsid = argv[5];
  }

  /* parse "12p2", "5a", "5av2", ... */
  typ = ile_pgm_type(in_type, &tlen, &tscale, &tvary);
  if (tlen < 1) {
    return SQL_ERROR;
  }

  /* parse dimension */
  rc = ile_pgm_str_2_int32((char *)&tdim, in_dim, 1);
  if (tdim < 1) {
    tdim = 1;
  }

  /* parse ccsid */
  rc = ile_pgm_str_2_int32((char *)&tccsid, in_ccsid, 1);
  if (tccsid < 1) {
    tccsid = 0;
  }

  /* parse in|out|both|value|const|return */
  by = ile_pgm_by(in_by, typ, tlen, tdim, tvary, isDs, &spill_len);
  if (!isOut && spill_len) {
    /* grow template (if need) */
    layout = ile_pgm_grow(playout, spill_len);
  }

  /* location of parm or ds data */
  where = ile_pgm_parm_location(isOut, by, spill_len, layout);
  if (!where) {
    return SQL_ERROR;
  }

  /* output processing */
  if (isOut) {
    tool_output_pgm_dcl_s_beg(tool, out_caller, in_name, tdim);
  }

  /* dcl-s type */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      if (isOut) {
        rc = ile_pgm_int8_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int8(where, in_value, tdim);
      }
      break;
    case 5:
      if (isOut) {
        rc = ile_pgm_int16_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int16(where, in_value, tdim);
      }
      break;
    case 10:
      if (isOut) {
        rc = ile_pgm_int32_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int32(where, in_value, tdim);
      }
      break;
    case 20:
      if (isOut) {
        rc = ile_pgm_int64_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_int64(where, in_value, tdim);
      }
      break;
    default:
      rc = SQL_ERROR;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      if (isOut) {
        rc = ile_pgm_uint8_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint8(where, in_value, tdim);
      }
      break;
    case 5:
      if (isOut) {
        rc = ile_pgm_uint16_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint16(where, in_value, tdim);
      }
      break;
    case 10:
      if (isOut) {
        rc = ile_pgm_uint32_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint32(where, in_value, tdim);
      }
      break;
    case 20:
      if (isOut) {
        rc = ile_pgm_uint64_2_output(tool, out_caller, where, tdim);
      } else {
        rc = ile_pgm_str_2_uint64(where, in_value, tdim);
      }
      break;
    default:
      rc = SQL_ERROR;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      if (isOut) {
        rc = ile_pgm_float_2_output(tool, out_caller, where, tscale, tdim);
      } else {
        rc = ile_pgm_str_2_float(where, in_value, tdim);
      }
      break;
    case 8:
      if (isOut) {
        rc = ile_pgm_double_2_output(tool, out_caller, where, tscale, tdim);
      } else {
        rc = ile_pgm_str_2_double(where, in_value, tdim);
      }
      break;
    default:
      rc = SQL_ERROR;
      break;
    }
    break;
  case 'p':
    if (isOut) {
      ile_pgm_packed_2_output(tool, out_caller, where, tlen, tscale, tdim);
    } else {
      rc = ile_pgm_str_2_packed(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 's':
    if (isOut) {
      ile_pgm_zoned_2_output(tool, out_caller, where, tlen, tscale, tdim);
    } else {
      rc = ile_pgm_str_2_zoned(where, in_value, tdim, tlen, tscale);
    }
    break;
  case 'a':
    if (isOut) {
      ile_pgm_char_2_output(tool, out_caller, where, tlen, tvary, tccsid, tdim);
    } else {
      rc = ile_pgm_str_2_char(where, in_value, tdim, tlen, tvary, tccsid);
    }
    break;
  case 'b':
    if (isOut) {
      ile_pgm_bin_2_output(tool, out_caller, where, tlen, tvary, tdim);
    } else {
      rc = ile_pgm_str_2_bin(where, in_value, tdim, tlen, tvary);
    }
    break;
  case 'h':
    if (!isOut) {
      rc = ile_pgm_str_2_hole(where, tdim, tlen);
    }
    break;
  default:
    rc = SQL_ERROR;
    break;
  }
  /* output processing */
  if (isOut) {
    tool_output_pgm_dcl_s_end(tool, out_caller, tdim);
  }
  return rc;
}

/* "dcl-ds":["name",dimension, "in|out|both|value|return", "dou-name"], */
SQLRETURN tool_dcl_ds(int isOut, int argc, char * arv[], int isDs, ile_pgm_call_t **playout) {
  return SQL_SUCCESS;
}

SQLRETURN tool_run_data(SQLHDBC ihdbc, SQLCHAR * outarea, SQLINTEGER outlen,
 tool_struct_t *tool, int *key, char **val, int *arr) 
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  int i = 0;
  int j = 0;
  int nbr_arv = 0;
  char * arv[TOOL400_MAX_KEY];
  int recs = 0;
  int hdbc_external = 0;
  int isDs = 0;
  int isOut = 0;
  int pgmOut = 0;
  int pgmOk = 0;
  char * pgmVal = NULL;
  int pgmValLen = 0;
  ile_pgm_call_t * layout = NULL;
  SQLHENV henv = 0;
  SQLHANDLE hdbc = ihdbc;
  SQLHANDLE hstmt = 0;
  SQLINTEGER attr = SQL_TRUE;
  SQLINTEGER attr_isolation = SQL_TXN_NO_COMMIT;
  SQLSMALLINT nParms = 0;
  SQLSMALLINT nResultCols = 0;
  SQLSMALLINT name_length = 0;
  SQLCHAR *buff_name[TOOL400_MAX_COLS];
  SQLCHAR *buff_value[TOOL400_MAX_COLS];
  SQLINTEGER buff_len[TOOL400_MAX_COLS];
  SQLSMALLINT buff_type[TOOL400_MAX_COLS];
  SQLSMALLINT type = 0;
  SQLUINTEGER size = 0;
  SQLSMALLINT scale = 0;
  SQLSMALLINT nullable = 0;
  SQLINTEGER lob_loc = 0;
  SQLINTEGER loc_ind = 0;
  SQLSMALLINT loc_type = 0;
  SQLINTEGER fStrLen[TOOL400_MAX_COLS];
  SQLSMALLINT sql_data_type = 0;
  SQLUINTEGER sql_precision = 0;
  SQLSMALLINT sql_scale = 0;
  SQLSMALLINT sql_nullable = SQL_NO_NULLS;
  SQLCHAR cmd_buff[TOOL400_MAX_CMD_BUFF];
  SQLINTEGER cmd_len = 0;
  /* hdbc external (caller?) */
  if (ihdbc) {
    hdbc_external = 1;
  }
  /* process */
  for (i=0;key[i];i++) {
    switch (key[i]) {
    /* SQLRETURN SQL400pConnect( SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, 
     *   SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib );
     */
    case TOOL400_KEY_PCONN:
      if (arr[i]) {
        nbr_arv = tool_parse_array_values(tool, val[i], arv);
        switch (nbr_arv) {
        case 4:
          sqlrc = SQL400pConnect( arv[0], arv[1], arv[2], arv[3], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 3:
          sqlrc = SQL400pConnect( NULL, arv[0], arv[1], arv[2], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 1:
          sqlrc = SQL400pConnect( NULL, NULL, NULL, arv[0], &hdbc, attr_isolation, NULL, NULL );
        default:
          sqlrc = SQL400pConnect( NULL, NULL, NULL, "ALL", &hdbc, attr_isolation, NULL, NULL );
          break;
        }
        sqlrc = tool_output_sql_errors(tool, hdbc, SQL_HANDLE_DBC, sqlrc, outarea);
      }
      /* do not close (pool connection) */
      if (hdbc) {
        hdbc_external = 1;
      }
      break;
    case TOOL400_KEY_CONN:
      if (arr[i]) {
        nbr_arv = tool_parse_array_values(tool, val[i], arv);
        switch (nbr_arv) {
        case 3:
          sqlrc = SQL400Connect( arv[0], arv[1], arv[2], &hdbc, attr_isolation, NULL, NULL );
          break;
        case 2:
          sqlrc = SQL400Connect( NULL, arv[0], arv[1], &hdbc, attr_isolation, NULL, NULL );
          break;
        default:
          sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, attr_isolation, NULL, NULL );
          break;
        }
        sqlrc = tool_output_sql_errors(tool, hdbc, SQL_HANDLE_DBC, sqlrc, outarea);
      }
      break;
    case TOOL400_KEY_QUERY:
      if (!hdbc) {
        sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
        sqlrc = tool_output_sql_errors(tool, hdbc, SQL_HANDLE_DBC, sqlrc, outarea);
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* prepare */
      sqlrc = SQLPrepare((SQLHSTMT)hstmt, (SQLCHAR*)val[i], (SQLINTEGER)SQL_NTS);
      sqlrc = tool_output_sql_errors(tool, hstmt, SQL_HANDLE_STMT, sqlrc, outarea);
      /* no parm? execute */
      if (key[i+1] != TOOL400_KEY_PARM) {
        sqlrc = SQLExecute((SQLHSTMT)hstmt);
        sqlrc = tool_output_sql_errors(tool, hstmt, SQL_HANDLE_STMT, sqlrc, outarea);
      }
      break;
    case TOOL400_KEY_PARM:
      if (arr[i]) {
        nbr_arv = tool_parse_array_values(tool, val[i], arv);
        /* number of input parms */
        sqlrc = SQLNumParams((SQLHSTMT)hstmt, (SQLSMALLINT*)&nParms);
        if (nParms > 0) {
          for (j = 0; j < nParms; j++) {
            sqlrc = SQLDescribeParam((SQLHSTMT)hstmt, (SQLUSMALLINT)(j + 1), 
                   &sql_data_type, &sql_precision, &sql_scale, &sql_nullable);
            buff_len[j] = SQL_NTS;
            sqlrc = SQLBindParameter((SQLHSTMT)hstmt, (SQLUSMALLINT)(j + 1),
                   SQL_PARAM_INPUT, SQL_CHAR, sql_data_type,
                   sql_precision, sql_scale, arv[j], 0, &buff_len[j]);
          }
        }
      }
      /* execute */
      sqlrc = SQLExecute((SQLHSTMT)hstmt);
      sqlrc = tool_output_sql_errors(tool, hstmt, SQL_HANDLE_STMT, sqlrc, outarea);
      /* no fetch? close */
      if (key[i+1] != TOOL400_KEY_FETCH) {
        sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      }
      break;
    case TOOL400_KEY_FETCH:
      /* result set */
      sqlrc = SQLNumResultCols((SQLHSTMT)hstmt, &nResultCols);
      sqlrc = tool_output_sql_errors(tool, hstmt, SQL_HANDLE_STMT, sqlrc, outarea);
      if (nResultCols > 0) {
        for (j = 0 ; j < nResultCols; j++) {
          size = TOOL400_EXPAND_COL_NAME;
          buff_name[j] = tool_new(size);
          buff_value[j] = NULL;
          buff_type[j] = 0;
          fStrLen[j] = SQL_NTS;
          sqlrc = SQLDescribeCol((SQLHSTMT)hstmt, (SQLSMALLINT)(j + 1), (SQLCHAR *)buff_name[j], size, &name_length, &buff_type[j], &size, &scale, &nullable);
          /* dbcs expansion */
          switch (buff_type[j]) {
          case SQL_CHAR:
          case SQL_VARCHAR:
          case SQL_CLOB:
          case SQL_DBCLOB:
          case SQL_UTF8_CHAR:
          case SQL_WCHAR:
          case SQL_WVARCHAR:
          case SQL_GRAPHIC:
          case SQL_VARGRAPHIC:
          case SQL_XML:
            size = size * TOOL400_EXPAND_CHAR;
            buff_value[j] = tool_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
            break;
          case SQL_BINARY:
          case SQL_VARBINARY:
          case SQL_BLOB:
            size = size * TOOL400_EXPAND_BINARY;
            buff_value[j] = tool_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
            break;
          case SQL_TYPE_DATE:
          case SQL_TYPE_TIME:
          case SQL_TYPE_TIMESTAMP:
          case SQL_DATETIME:
          case SQL_BIGINT:
          case SQL_DECFLOAT:
          case SQL_SMALLINT:
          case SQL_INTEGER:
          case SQL_REAL:
          case SQL_FLOAT:
          case SQL_DOUBLE:
          case SQL_DECIMAL:
          case SQL_NUMERIC:
          default:
            size = TOOL400_EXPAND_OTHER;
            buff_value[j] = tool_new(size);
            sqlrc = SQLBindCol((SQLHSTMT)hstmt, (j + 1), SQL_CHAR, buff_value[j], size, &fStrLen[j]);
            break;
          }
        }
        sqlrc = SQL_SUCCESS;
        tool_output_record_array_beg(tool, outarea);
        while (sqlrc == SQL_SUCCESS) {
          sqlrc = SQLFetch(hstmt);
          if (sqlrc == SQL_NO_DATA_FOUND || sqlrc < SQL_SUCCESS ) {
            if (!recs) {
              tool_output_record_no_data_found(tool, outarea);
            }
            break;
          }
          tool_output_record_row_beg(tool, outarea);
          recs += 1;
          for (j = 0 ; j < nResultCols; j++) {
            if (buff_value[j]) {
              tool_output_record_name_value(tool, buff_name[j], buff_value[j], buff_type[j], fStrLen[j], outarea);
            }
          }
          tool_output_record_row_end(tool, outarea);
        }
        tool_output_record_array_end(tool, outarea);
        for (j = 0 ; j < nResultCols; j++) {
          if (buff_value[j]) {
            tool_free(buff_name[j]);
            buff_name[j] = NULL;
          }
          if (buff_name[j]) {
            tool_free(buff_name[j]);
            buff_name[j] = NULL;
          }
        }
      } else {
        tool_output_record_array_beg(tool, outarea);
        tool_output_record_no_data_found(tool, outarea);
        tool_output_record_array_end(tool, outarea);
      }
      /* close */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      break;
    case TOOL400_KEY_CMD:
      if (!hdbc) {
        sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
        sqlrc = tool_output_sql_errors(tool, hdbc, SQL_HANDLE_DBC, sqlrc, outarea);
      }
      /* statement */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
      /* sql */
      cmd_len = strlen(val[i]);
      memset(cmd_buff,0,TOOL400_MAX_CMD_BUFF);
      sprintf(cmd_buff,"CALL QSYS2.QCMDEXC('%s',%d)",val[i],cmd_len);
      /* prepare */
      sqlrc = SQLPrepare((SQLHSTMT)hstmt, cmd_buff, (SQLINTEGER)SQL_NTS);
      sqlrc = tool_output_sql_errors(tool, hstmt, SQL_HANDLE_STMT, sqlrc, outarea);
      /* execute */
      sqlrc = SQLExecute((SQLHSTMT)hstmt);
      sqlrc = tool_output_sql_errors(tool, hstmt, SQL_HANDLE_STMT, sqlrc, outarea);
      /* close */
      sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
      break;
    /* don't bother trying ...
     * still working on input pgm
     */
    case TOOL400_KEY_PGM:
      pgmOut = i;
      switch(isOut) {
      case 0:
        if (!hdbc) {
          sqlrc = SQL400Connect( NULL, NULL, NULL, &hdbc, SQL_TXN_NO_COMMIT, NULL, NULL );
          sqlrc = tool_output_sql_errors(tool, hdbc, SQL_HANDLE_DBC, sqlrc, outarea);
        }
        /* statement */
        sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, (SQLHDBC) hdbc, &hstmt);
        break;
      case 1:
        /* "pgm":["CLIMATE","MYLIB","RegionTemps"] */
        arv[0] = NULL;
        arv[1] = NULL;
        arv[2] = NULL;
        nbr_arv = tool_parse_array_values(tool, val[i], arv);
        tool_output_pgm_beg(tool, outarea, arv[0], arv[1], arv[2]);
        break;
      default:
        break;
      }
      break;
    /*
     * input copy in any dcl-s, dcl-ds
     */
    case TOOL400_KEY_DCL_S:
      pgmVal = val[i];
      pgmValLen = strlen(pgmVal);
      if (pgmValLen > 0) {
        val[i] = tool_new(pgmValLen);
        strcpy(val[i], pgmVal);
        nbr_arv = tool_parse_array_values(tool, val[i], arv);
        sqlrc = tool_dcl_s(tool, outarea, isOut, nbr_arv, arv, isDs, &layout);
        tool_free(val[i]);
        val[i] = pgmVal;
      }
      break;
    case TOOL400_KEY_DCL_DS:
      isDs = 1;
      break;
    case TOOL400_KEY_END_DS:
      isDs = 0;
      break;
    /*
     * end-pgm we can run then copy out to format
     */
    case TOOL400_KEY_END_PGM:
      /* make sp call to ILE blob call wrapper
       * (sp is simple load, activate, call, return) 
       */
      /* output processing */
      switch(isOut) {
      case 0:
        /* close */
        sqlrc = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
        /* reset top of parms */
        ile_pgm_reset_pos(layout);
        isOut = 1;
        pgmOk = 1;
        /* replay from start of "pgm" */
        i = pgmOut - 1;
        break;
      case 1:
        tool_output_pgm_end(tool, outarea);
        isOut = 0;
        break;
      default:
        break;
      }
      break;
    default:
      break;
    }
  } /* end for */
  /* hdbc external (caller?) or pool (pConnect) */
  if (!hdbc_external) {
    sqlrc = SQL400Close(hdbc);
  }
}

int tool_run(int hdbc, char * outarea, int outlen,
 tool_struct_t *tool, int *key, char **val, int *arr) 
{
  SQLRETURN sqlrc = SQL_SUCCESS;
  tool_output_script_beg(tool, outarea);
  sqlrc = tool_run_data(hdbc, outarea, outlen, tool, key, val, arr);
  tool_output_script_end(tool, outarea);
  return sqlrc;
}



