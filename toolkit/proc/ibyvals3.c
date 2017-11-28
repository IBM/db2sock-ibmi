#include <miptrnam.h>
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
#include <qp2user.h>
#include <except.h>
#include "../PaseTool.h"
#include "iconf.h" /* see Makefile */
#include "ibyref.h"

bighole_t iCallFctByVal000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
}

bighole_t iCallFctByVal001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2)
    );
  }
}

bighole_t iCallFctByVal010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  }
}

bighole_t iCallFctByVal011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2)
    );
  }
}

bighole_t iCallFctByVal100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
  }
}

bighole_t iCallFctByVal101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2)
    );
  }
}

bighole_t iCallFctByVal110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2)
    );
  }
}

bighole_t iCallFctByVal111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2)
    );
  }
}

bighole_t iCallFctByValSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"000")) {
    return iCallFctByVal000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"001")) {
    return iCallFctByVal001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"010")) {
    return iCallFctByVal010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"011")) {
    return iCallFctByVal011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"100")) {
    return iCallFctByVal100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"101")) {
    return iCallFctByVal101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"110")) {
    return iCallFctByVal110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"111")) {
    return iCallFctByVal111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
