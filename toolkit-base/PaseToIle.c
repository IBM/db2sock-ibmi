#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "../ILE-PROC/iconf.h" /* see ILE-PROC/Makefile */
#include "PaseToIle.h"

/*=================================================
 * ebcdic char ccsid mess
 */
#ifdef __IBMC__
#define hex_space 0x40
#define hex_nbr 0xF0
#else
#define hex_space 0x20
#define hex_nbr 0x30
#endif


/*=================================================
 * toolkit copy in/out ILE parm layout
 */

void ile_pgm_trim_ebcdic(char *str, int len) {
  int j = 0;
  char * c = NULL;
  for (c = str, j = len - 1; j >= 0; j--) {
    if (!c[j] || c[j] == 0x40) {
      c[j] = 0x00;
      len = j;
    } else {
      break;
    }
  }
}

int ile_pgm_round_up(int num, int factor) {
  return num + factor - 1 - (num - 1) % factor;
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

char * ile_pgm_spill_top_buf(ile_pgm_call_t * layout) {
  return (char *)&layout->buf;
}
int ile_pgm_spill_top_offset(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->buf - (char *)layout;
  return delta;
}
int ile_pgm_spill_length(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->buf - (char *)layout;
  return layout->pos - delta;
}
char * ile_pgm_argv_top_buf(ile_pgm_call_t * layout) {
  return (char *)&layout->argv[0];
}
int ile_pgm_argv_top_offset(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->argv[0] - (char *)layout;
  return delta;
}
int ile_pgm_argv_length(ile_pgm_call_t * layout) {
  int delta = 0;
  delta = (char *)&layout->argv[0] - (char *)layout;
  return layout->vpos - delta;
}


/* by ref area */
void ile_pgm_reset_spill_pos(ile_pgm_call_t * layout) {
  layout->pos = ile_pgm_spill_top_offset(layout);
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
  layout->vpos = ile_pgm_argv_top_offset(layout);
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
  if (tlen <= 1) {
    /* already at vpos */
  } else if (tlen <= 2) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 2);
  } else if (tlen <= 4) {
    layout->vpos = ile_pgm_round_up(layout->vpos, 4);
  } else if (tlen <= 8) { /* PASE _ILECALL max by value is 8 */
    layout->vpos = ile_pgm_round_up(layout->vpos, 8);
  } else if (tlen <= 16) { /* ILE max value is 16 */
    /* alignment really only 8 byte for two register load
     * we can get PASE _ILECALL to work using two DWORD 'by value' 
     */
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
  int total_len = 0;
  char * tmp = NULL;
  int delta = 0;
  ile_pgm_call_t * layout = *playout;
  /* enough room ? */
  if (layout) {
    /* max length - current position */
    delta = (layout->max - layout->pos) - sizeof(ile_pgm_call_t);
    if (delta > size) {
      return *playout;
    }
    orig_len = layout->max;
    total_len = layout->max + size;
  } else {
    total_len =  size + sizeof(ile_pgm_call_t);
  }
  /* need more space (block size alloc) */
  for (i=0; new_len < total_len; i++) {
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
  /* layout template pointer */
  *playout = layout;
  /* return new location (tmp ptrs) */
  return *playout;
}

/*=================================================
 * toolkit copy in/out ILE converters
 */

int ile_pgm_str_2_int8(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_int8_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  int8 * wherev = (int8 *) where;
  int8 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_int8_2_int(char * where) {
  int8 * wherev = (int8 *) where;
  return (int) *wherev;
}


int ile_pgm_str_2_int16(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_int16_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  int16 * wherev = (int16 *) where;
  int16 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_int16_2_int(char * where) {
  int16 * wherev = (int16 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_int32(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_int32_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  int32 * wherev = (int32 *) where;
  int32 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%d",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_int32_2_int(char * where) {
  int32 * wherev = (int32 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_int64(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_int64_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  int64 * wherev = (int64 *) where;
  int64 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%lld",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_int64_2_int(char * where) {
  int64 * wherev = (int64 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_uint8(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_uint8_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  uint8 * wherev = (uint8 *) where;
  uint8 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%u",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_uint8_2_int(char * where) {
  uint8 * wherev = (uint8 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_uint16(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_uint16_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  uint16 * wherev = (uint16 *) where;
  uint16 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%u",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_uint16_2_int(char * where) {
  uint16 * wherev = (uint16 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_uint32(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_uint32_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  uint32 * wherev = (uint32 *) where;
  uint32 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%u",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_uint32_2_int(char * where) {
  uint32 * wherev = (uint32 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_uint64(char * where, const char *str, int tdim) {
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
  return 0;
}
int ile_pgm_uint64_2_output(tool_struct_t *tool, char * where, int tdim) {
  int i = 0;
  uint64 * wherev = (uint64 *) where;
  uint64 value = 0;
  char str[128];
  for (i=0; i < tdim; i++, wherev++) {
    value = *wherev;
    memset(str,0,sizeof(str));
    sprintf(str,"%llu",value);
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_uint64_2_int(char * where) {
  uint64 * wherev = (uint64 *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_float(char * where, const char *str, int tdim) {
  int i = 0;
  float * wherev = (float *) where;
  float value = 0.0;
  if (str) {
    value = (float) strtof(str,NULL);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return 0;
}
int ile_pgm_float_2_output(tool_struct_t *tool, char * where, int tscale, int tdim) {
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
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_float_2_int(char * where) {
  float * wherev = (float *) where;
  return (int) *wherev;
}

int ile_pgm_str_2_double(char * where, const char *str, int tdim) {
  int i = 0;
  double * wherev = (double *) where;
  double value = 0.0;
  if (str) {
    value = (double) strtod(str,NULL);
  }
  for (i=0; i < tdim; i++, wherev++) {
    *wherev = value;
  }
  return 0;
}
int ile_pgm_double_2_output(tool_struct_t *tool, char * where, int tscale, int tdim) {
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
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_double_2_int(char * where) {
  double * wherev = (double *) where;
  return (int) *wherev;
}


int ile_pgm_str_2_packed(char * where, char *str, int tdim, int tlen, int tscale) {
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
  return 0;
}
int ile_pgm_packed_2_output(tool_struct_t *tool, char * where, int tlen, int tscale, int tdim) {
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
  int actLen = outLength * 2;
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
      if (!isDot && tscale && l >= actLen - tscale) {
        if (!isOk) {
          str[j++] = (char) hex_nbr;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      /* digits */
      leftDigitValue = (char)((c[k] >> 4) & 0x0F);
      if (isOk || leftDigitValue > 0) {
        str[j++] = (char)(hex_nbr + leftDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
      /* decimal point */
      l++;
      if (!isDot && tscale && l >= actLen - tscale) {
        if (!isOk) {
          str[j++] = (char) hex_nbr;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      /* digits */
      rightDigitValue = (char)(c[k] & 0x0F);
      if (k < outLength-1 && (isOk || rightDigitValue > 0)) {
        str[j++] = (char)(hex_nbr + rightDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
    }
    /* zero */
    if (!isOk) {
      str[j++] = (char) hex_nbr;
      str[j++] = '.';
      isOk = 1;
      isDot = 1;
      isScale = 0;
    }
    /* one significant decimal */
    if (isDot && !isScale) {
      str[j++] = (char) hex_nbr;
    }
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_packed_2_int(char * where, int tlen, int tscale) {
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
  int actLen = outLength * 2;
  int leftDigitValue = 0;
  int rightDigitValue = 0;
  char * c = NULL;
  char str[128];

  int32 value = 0;

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
    if (!isDot && tscale && l >= actLen - tscale) {
      if (!isOk) {
        str[j++] = (char) hex_nbr;
      }
      str[j++] = '.';
      isDot = 1;
      isOk = 1;
    }
    /* digits */
    leftDigitValue = (char)((c[k] >> 4) & 0x0F);
    if (isOk || leftDigitValue > 0) {
      str[j++] = (char)(hex_nbr + leftDigitValue);
      isOk = 1;
      if (isDot) {
        isScale++;
      }
    }
    /* decimal point */
    l++;
    if (!isDot && tscale && l >= actLen - tscale) {
      if (!isOk) {
        str[j++] = (char) hex_nbr;
      }
      str[j++] = '.';
      isDot = 1;
      isOk = 1;
    }
    /* digits */
    rightDigitValue = (char)(c[k] & 0x0F);
    if (k < outLength-1 && (isOk || rightDigitValue > 0)) {
      str[j++] = (char)(hex_nbr + rightDigitValue);
      isOk = 1;
      if (isDot) {
        isScale++;
      }
    }
  }
  /* zero */
  if (!isOk) {
    str[j++] = (char) hex_nbr;
    str[j++] = '.';
    isOk = 1;
    isDot = 1;
    isScale = 0;
  }
  /* one significant decimal */
  if (isDot && !isScale) {
    str[j++] = (char) hex_nbr;
  }
  /* string to int */
  value = (int) strtod(str,NULL);
  return (int) value;
}

int ile_pgm_str_2_zoned(char * where, char *str, int tdim, int tlen, int tscale) {
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
  return 0;
}
int ile_pgm_zoned_2_output(tool_struct_t *tool, char * where, int tlen, int tscale, int tdim) {
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
          str[j++] = (char) hex_nbr;
        }
        str[j++] = '.';
        isDot = 1;
        isOk = 1;
      }
      l++;
      /* digits */
      rightDigitValue = (char)(c[k] & 0x0F);
      if (isOk || rightDigitValue > 0) {
        str[j++] = (char)(hex_nbr + rightDigitValue);
        isOk = 1;
        if (isDot) {
          isScale++;
        }
      }
    }
    /* zero */
    if (!isOk) {
      str[j++] = (char) hex_nbr;
      str[j++] = '.';
      isOk = 1;
      isDot = 1;
      isScale = 0;
    }
    /* one significant decimal */
    if (isDot && !isScale) {
      str[j++] = (char) hex_nbr;
    }
    tool_output_pgm_dcl_s_data(tool, str, 1);
  }
  return 0;
}
int ile_pgm_zoned_2_int(char * where, int tlen, int tscale) {
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

  int32 value = 0;

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
        str[j++] = (char) hex_nbr;
      }
      str[j++] = '.';
      isDot = 1;
      isOk = 1;
    }
    l++;
    /* digits */
    rightDigitValue = (char)(c[k] & 0x0F);
    if (isOk || rightDigitValue > 0) {
      str[j++] = (char)(hex_nbr + rightDigitValue);
      isOk = 1;
      if (isDot) {
        isScale++;
      }
    }
  }
  /* zero */
  if (!isOk) {
    str[j++] = (char) hex_nbr;
    str[j++] = '.';
    isOk = 1;
    isDot = 1;
    isScale = 0;
  }
  /* one significant decimal */
  if (isDot && !isScale) {
    str[j++] = (char) hex_nbr;
  }
  /* string to int */
  value = (int) strtod(str,NULL);
  return (int) value;
}

int ile_pgm_str_2_char(char * where, char *str, int tdim, int tlen, int tvary, int tccsid) {
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
    for (i = len*4 - 1; i>-1; i--) {
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
  return 0;
}
int ile_pgm_char_2_output(tool_struct_t *tool, char * where, int tlen, int tvary, int tccsid, int tdim) {
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
    /* bad varchar len 0x40404040*/
    if (len > tlen) {
       len = tlen;
    }
    if (len) {
      /* convert ebcdic to utf8 */
      memset(utf8,0,len*4);
      rc = SQL400ToUtf8(0, wherev, len, utf8, len*4, tccsid);
      /* trim */
      len = strlen(utf8);
      for (c = utf8, j = len - 1; j >= 0; j--) {
        if (!c[j] || c[j] == hex_space) {
          c[j] = 0x00;
          len = j;
        } else {
          break;
        }
      }
    } /* j loop (trim) */
    /* output processing */
    if (len) {
      tool_output_pgm_dcl_s_data(tool, utf8, 0);
    } else {
      tool_output_pgm_dcl_s_data(tool, str_tool_empty, 1);
    }
  } /* i loop (tdim) */
  /* free temp storage */
  if (utf8) {
    tool_free(utf8);
  }
  return 0;
}
int ile_pgm_char_2_int_common(char * where, int ilen, int tvary, int valid, int *isBlank) {
  int32 value = 0;
  int i = 0, j = 0;
  char * c = NULL;
  char v = ' ';
  char ascii[128];
  char str[128];
  int ebcdic = 0;
  char * wherev = NULL;
  int tlen = ilen;

  c = where;

  /* vary */
  if (tvary == 4) {
    tlen = *(int *) c;
    c += 4;
  } else if (tvary) {
    tlen = *(short *) c;
    c += 2;
  } else {
    tlen = ilen;
  }
  /* bad varchar len 0x40404040*/
  if (tlen > ilen) {
     tlen = ilen;
  }
  /* save where now */
  wherev = c;

  /* assume all is blank */
  *isBlank = 1;

#ifndef __IBMC__
  memset(ascii,0,sizeof(ascii));
  for (i=0, j=0; i<tlen; i++) {
    switch (*c) {
    case 0xF0: /* '0' */
      ebcdic = 1;
      ascii[j++] = '0';
      *isBlank = 0;
      break;
    case 0xF1: /* '1' */
      ebcdic = 1;
      ascii[j++] = '1';
      *isBlank = 0;
      break;
    case 0xF2: /* '2' */
      ebcdic = 1;
      ascii[j++] = '2';
      *isBlank = 0;
      break;
    case 0xF3: /* '3' */
      ebcdic = 1;
      ascii[j++] = '3';
      *isBlank = 0;
      break;
    case 0xF4: /* '4' */
      ebcdic = 1;
      ascii[j++] = '4';
      *isBlank = 0;
      break;
    case 0xF5: /* '5' */
      ebcdic = 1;
      ascii[j++] = '5';
      *isBlank = 0;
      break;
    case 0xF6: /* '6' */
      ebcdic = 1;
      ascii[j++] = '6';
      *isBlank = 0;
      break;
    case 0xF7: /* '7' */
      ebcdic = 1;
      ascii[j++] = '7';
      *isBlank = 0;
      break;
    case 0xF8: /* '8' */
      ebcdic = 1;
      ascii[j++] = '8';
      *isBlank = 0;
      break;
    case 0xF9: /* '9' */
      ebcdic = 1;
      ascii[j++] = '9';
      *isBlank = 0;
      break;
    case 0x40: /* ' ' */
      ebcdic = 1;
      ascii[j++] = ' ';
      /* *isBlank = 0; */
      break;
    case 0x4B: /* '.' */
      ebcdic = 1;
      ascii[j++] = '.';
      *isBlank = 0;
      break;
    case 0x60: /* '-' */
      ebcdic = 1;
      ascii[j++] = '-';
      *isBlank = 0;
      break;
    default:
      *isBlank = 0;
      break;
    }
    c++;
  }
  if (ebcdic) {
    c = ascii;
  } else {
    c = wherev;
  }
#endif

  memset(str,0,sizeof(str));
  for (i=0, j=0; i<tlen; i++) {
    switch (*c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '-':
    case '.':
      str[j++] = *c;
      *isBlank = 0;
      break;
    case ' ':
      /* *isBlank = 0; */
      break;
    default:
      *isBlank = 0;
      if (valid) {
        return -1;
      }
      break;
    }
    c++;
  }
  /* string to int */
  value = (int) strtod(str,NULL);
  return (int) value;
}
int ile_pgm_char_2_int(char * where, int tlen, int tvary) {
  int isBlank = 0;
  return ile_pgm_char_2_int_common(where, tlen, tvary, 0, &isBlank);
}
int ile_pgm_char_2_int_valid(char * where, int tlen, int tvary) {
  int isBlank = 0;
  return ile_pgm_char_2_int_common(where, tlen, tvary, 1, &isBlank);
}
int ile_pgm_char_is_blank(char * where, int tlen, int tvary) {
  int isBlank = 0;
  int value = 0;
  value = ile_pgm_char_2_int_common(where, tlen, tvary, 0, &isBlank);
  return isBlank;
}



int ile_pgm_str_2_bin(char * where, char *str, int tdim, int tlen, int tvary) {
  int i = 0;
  int j = 0;
  int k = 0;
  int outDigits = tlen;
  int outLength = outDigits;
  int inLength = 0;
  short * short_value = NULL;
  int * int_value = NULL;
  char * dec = NULL;
  char * c = NULL;
  char * wherev = where;
  char bytex = ' ';
  int hnbr = 0;
  int lnbr = 0;
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
    for (j=0, k=0; j < outDigits && k < inLength; k += 2) {
      bytex = str[k];
      if (bytex=='F' || bytex=='f') {
          hnbr = 15;
      } else if (bytex=='E' || bytex=='e') {
          hnbr = 14;
      } else if (bytex=='D' || bytex=='d') {
          hnbr = 13;
      } else if (bytex=='C' || bytex=='c') {
          hnbr = 12;
      } else if (bytex=='B' || bytex=='b') {
          hnbr = 11;
      } else if (bytex=='A' || bytex=='a') {
          hnbr = 10;
      } else if (bytex=='9') {
          hnbr = 9;
      } else if (bytex=='8') {
          hnbr = 8;
      } else if (bytex=='7') {
          hnbr = 7;
      } else if (bytex=='6') {
          hnbr = 6;
      } else if (bytex=='5') {
          hnbr = 5;
      } else if (bytex=='4') {
          hnbr = 4;
      } else if (bytex=='3') {
          hnbr = 3;
      } else if (bytex=='2') {
          hnbr = 2;
      } else if (bytex=='1') {
          hnbr = 1;
      } else {
          hnbr = 0;
      }
      bytex = str[k + 1];
      if (bytex=='F' || bytex=='f') {
          lnbr = 15;
      } else if (bytex=='E' || bytex=='e') {
          lnbr = 14;
      } else if (bytex=='D' || bytex=='d') {
          lnbr = 13;
      } else if (bytex=='C' || bytex=='c') {
          lnbr = 12;
      } else if (bytex=='B' || bytex=='b') {
          lnbr = 11;
      } else if (bytex=='A' || bytex=='a') {
          lnbr = 10;
      } else if (bytex=='9') {
          lnbr = 9;
      } else if (bytex=='8') {
          lnbr = 8;
      } else if (bytex=='7') {
          lnbr = 7;
      } else if (bytex=='6') {
          lnbr = 6;
      } else if (bytex=='5') {
          lnbr = 5;
      } else if (bytex=='4') {
          lnbr = 4;
      } else if (bytex=='3') {
          lnbr = 3;
      } else if (bytex=='2') {
          lnbr = 2;
      } else if (bytex=='1') {
          lnbr = 1;
      } else {
          lnbr = 0;
      }
      dec[j++] = (char)(hnbr*16 + lnbr);
    }
  }
  return 0;
}
int ile_pgm_bin_2_output(tool_struct_t *tool, char * where, int tlen, int tvary, int tdim) {
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int len = 0;
  char * wherev = (char *) where;
  int outDigits = tlen;
  int outLength = outDigits*2+1;
  char * c = NULL;
  char * str = NULL;
  int hnbr = 0;
  int lnbr = 0;
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
      hnbr = (int)c[k];
      if (hnbr>=240) { /* x'FO' */
          str[j++] = 'F';
          lnbr = hnbr - 240;
      } else if (hnbr>=224 && hnbr<240) { /* x'E0' */
          str[j++] = 'E';
          lnbr = hnbr - 224;
      } else if (hnbr>=208 && hnbr<224) { /* x'D0' */
          str[j++] = 'D';
          lnbr = hnbr - 208;
      } else if (hnbr>=192 && hnbr<208) { /* x'C0' */
          str[j++] = 'C';
          lnbr = hnbr - 192;
      } else if (hnbr>=176 && hnbr<192) { /* x'B0' */
          str[j++] = 'B';
          lnbr = hnbr - 176;
      } else if (hnbr>=160 && hnbr<176) { /* x'A0' */
          str[j++] = 'A';
          lnbr = hnbr - 160;
      } else if (hnbr>=144 && hnbr<160) { /* x'90' */
          str[j++] = '9';
          lnbr = hnbr - 144;
      } else if (hnbr>=128 && hnbr<144) { /* x'80' */
          str[j++] = '8';
          lnbr = hnbr - 128;
      } else if (hnbr>=112 && hnbr<128) { /* x'70' */
          str[j++] = '7';
          lnbr = hnbr - 112;
      } else if (hnbr>=96 && hnbr<112) { /* x'60' */
          str[j++] = '6';
          lnbr = hnbr - 96;
      } else if (hnbr>=80 && hnbr<96) { /* x'50' */
          str[j++] = '5';
          lnbr = hnbr - 80;
      } else if (hnbr>=64 && hnbr<80) { /* x'40' */
          str[j++] = '4';
          lnbr = hnbr - 64;
      } else if (hnbr>=48 && hnbr<64) { /* x'30' */
          str[j++] = '3';
          lnbr = hnbr - 48;
      } else if (hnbr>=32 && hnbr<48) { /* x'20' */
          str[j++] = '2';
          lnbr = hnbr - 32;
      } else if (hnbr>=16 && hnbr<32) { /* x'10' */
          str[j++] = '1';
          lnbr = hnbr - 16;
      } else {
          str[j++] = '0';
          lnbr = hnbr;
      }
      if (lnbr>=15) { /* x'0F' */
          str[j++] = 'F';
      } else if (lnbr>=14 && lnbr<15) { /* x'0E' */
          str[j++] = 'E';
      } else if (lnbr>=13 && lnbr<14) { /* x'0D' */
          str[j++] = 'D';
      } else if (lnbr>=12 && lnbr<13) { /* x'0C' */
          str[j++] = 'C';
      } else if (lnbr>=11 && lnbr<12) { /* x'0B' */
          str[j++] = 'B';
      } else if (lnbr>=10 && lnbr<11) { /* x'0A' */
          str[j++] = 'A';
      } else if (lnbr>=9 && lnbr<10) { /* x'09' */
          str[j++] = '9';
      } else if (lnbr>=8 && lnbr<9) { /* x'08' */
          str[j++] = '8';
      } else if (lnbr>=7 && lnbr<8) { /* x'07' */
          str[j++] = '7';
      } else if (lnbr>=6 && lnbr<7) { /* x'06' */
          str[j++] = '6';
      } else if (lnbr>=5 && lnbr<6) { /* x'05' */
          str[j++] = '5';
      } else if (lnbr>=4 && lnbr<5) { /* x'04' */
          str[j++] = '4';
      } else if (lnbr>=3 && lnbr<4) { /* x'03' */
          str[j++] = '3';
      } else if (lnbr>=2 && lnbr<3) { /* x'02' */
          str[j++] = '2';
      } else if (lnbr>=1 && lnbr<2) { /* x'01' */
          str[j++] = '1';
      } else {
          str[j++] = '0';
      }
    } /* k loop (outLength) */
    tool_output_pgm_dcl_s_data(tool, str, 0);
  } /* i loop (tdim) */
  /* free temp storage */
  if (str) {
    tool_free(str);
  }
  return 0;
}
int ile_pgm_bin_2_int(char * where, int tlen) {
  switch(tlen) {
  case 1:
    return (int) (*(int8 *)where);
  case 2:
    return (int) (*(int16 *)where);
  case 4:
    return (int) (*(int32 *)where);
  case 8:
    return (int) (*(int64 *)where);
  default:
    break;
  }
  return (int) (*(int32 *)where);
}


int ile_pgm_str_2_hole(char * where, int tlen, int tdim) {
  int i = 0;
  char * wherev = where;
  /* copy in */
  for (i=0; i < tdim; i++, wherev += tlen) {
    memset(wherev,0,tlen);
  }
  return 0;
}
int ile_pgm_hole_2_int(char * where, int tlen) {
  return 0;
}

/*=================================================
 * toolkit copy in/out ILE type, by and location
 */

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

int ile_pgm_type_size(char typ, int tlen, int tdim, int tvary) {
  int spill_len = 0;
  /* default length input */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      spill_len = sizeof(int8) * tdim;
      break;
    case 5:
      spill_len = sizeof(int16) * tdim;
      break;
    case 10:
      spill_len = sizeof(int32) * tdim;
      break;
    case 20:
      spill_len = sizeof(int64) * tdim;
      break;
    default:
      spill_len = sizeof(int32) * tdim;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      spill_len = sizeof(uint8) * tdim;
      break;
    case 5:
      spill_len = sizeof(uint16) * tdim;
      break;
    case 10:
      spill_len = sizeof(uint32) * tdim;
      break;
    case 20:
      spill_len = sizeof(uint64) * tdim;
      break;
    default:
      spill_len = sizeof(uint32) * tdim;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      spill_len = sizeof(float) * tdim;
      break;
    case 8:
      spill_len = sizeof(double) * tdim;
      break;
    default:
      spill_len = sizeof(double) * tdim;
      break;
    }
    break;
  case 'p':
    spill_len = (tlen/2+1) * tdim;
    break;
  case 's':
    spill_len = tlen * tdim;
    break;
  case 'a':
    switch(tvary){
    case 2:
      spill_len = (tlen+sizeof(uint16)) * tdim;
      break;
    case 4:
      spill_len = (tlen+sizeof(uint32)) * tdim;
      break;
    default:
      spill_len = tlen * tdim;
      break;
    }
    break;
  case 'b':
    spill_len = tlen * tdim;
    break;
  case 'h':
    spill_len = tlen * tdim;
    break;
  default:
    spill_len = tlen * tdim;
    break;
  }
  return spill_len;
}

/* in|out|both|value|const|return */
int ile_pgm_by(char *str, char typ, int tlen, int tdim, int tvary, int isDs, int * spill_len, int * pase_sig) {
  int by = ILE_PGM_BY_REF_IN;
  /* default length input */
  switch (typ) {
  case 'i':
    switch (tlen) {
    case 3:
      *spill_len = sizeof(int8) * tdim;
      *pase_sig = ARG_INT8;
      break;
    case 5:
      *spill_len = sizeof(int16) * tdim;
      *pase_sig = ARG_INT16;
      break;
    case 10:
      *spill_len = sizeof(int32) * tdim;
      *pase_sig = ARG_INT32;
      break;
    case 20:
      *spill_len = sizeof(int64) * tdim;
      *pase_sig = ARG_INT64;
      break;
    default:
      *spill_len = sizeof(int32) * tdim;
      *pase_sig = ARG_INT32;
      break;
    }
    break;
  case 'u':
    switch (tlen) {
    case 3:
      *spill_len = sizeof(uint8) * tdim;
      *pase_sig = ARG_UINT8;
      break;
    case 5:
      *spill_len = sizeof(uint16) * tdim;
      *pase_sig = ARG_UINT16;
      break;
    case 10:
      *spill_len = sizeof(uint32) * tdim;
      *pase_sig = ARG_UINT32;
      break;
    case 20:
      *spill_len = sizeof(uint64) * tdim;
      *pase_sig = ARG_UINT64;
      break;
    default:
      *spill_len = sizeof(uint32) * tdim;
      *pase_sig = ARG_UINT32;
      break;
    }
    break;
  case 'f':
    switch (tlen) {
    case 4:
      *spill_len = sizeof(float) * tdim;
      *pase_sig = ARG_FLOAT32;
      break;
    case 8:
      *spill_len = sizeof(double) * tdim;
      *pase_sig = ARG_FLOAT64;
      break;
    default:
      *spill_len = sizeof(double) * tdim;
      *pase_sig = ARG_FLOAT64;
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
    *spill_len = tlen * tdim;
    break;
  case 'h':
    *spill_len = tlen * tdim;
    break;
  default:
    *spill_len = tlen * tdim;
    break;
  }
  /* pass by ref/val or isDs (val) */
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
      if (*spill_len > ILE_VALUE_MAX_LEN) {
        by = ILE_PGM_BY_REF_IN;
      /* ok, fit in register (by value/const) */
      } else {
        by = ILE_PGM_BY_VALUE;
      }
    } else if (str[0] == 'r') {
      by = ILE_PGM_BY_RETURN;
    }
  }
  /* PASE type */
  switch (by) {
  case ILE_PGM_BY_REF_IN:
  case ILE_PGM_BY_REF_OUT:
  case ILE_PGM_BY_REF_BOTH:
    *pase_sig = ARG_SPCPTR; /* by ref pointer */
    break;
  case ILE_PGM_BY_VALUE:
    if (*pase_sig == 0) {
      if (*spill_len > 32767) {
        *pase_sig = 32767; /* aggregate */
      } else {
        *pase_sig = *spill_len; /* aggregate */
      }
    }
    break;
  case ILE_PGM_BY_IN_DS:
  case ILE_PGM_BY_RETURN:
  default:
    break;
  }
  /* return by */
  return by;
}

/* dcl-s parms */
char * ile_pgm_parm_location(int isOut, int by, short sig, int tlen, ile_pgm_call_t * layout) {

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
      layout->arg_sig[layout->parmc] = sig;
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
      layout->argv_parm[layout->argc] = -1;
      layout->arg_by[layout->parmc] = by;
      layout->arg_sig[layout->parmc] = sig;
      layout->arg_pos[layout->parmc] = ile_pgm_curr_argv_pos(layout);
      layout->arg_len[layout->parmc] = tlen;
    }
    layout->parmc++;
    /* next position */
    ile_pgm_next_argv_pos(layout, tlen);
    break;
  /* return in buffer */
  case ILE_PGM_BY_RETURN:
    /* start return position */
    if (!layout->return_start) {
      layout->return_start = layout->pos;
    }
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

