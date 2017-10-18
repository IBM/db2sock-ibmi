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
#include "../toolkit-base/PaseTool.h"
#include "iconf.h" /* see Makefile */
#include "ibyref.h"

bighole_t iCallFctByVal000000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
}

bighole_t iCallFctByVal000001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[5]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal000010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal000011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal000100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal000101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal000110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal000111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal001111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal010111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal011111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal100111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal101111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal110111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5)
    );
  }
}

bighole_t iCallFctByVal111111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5)
    );
  }
}

bighole_t iCallFctByValSub6(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"000000")) {
    return iCallFctByVal000000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000001")) {
    return iCallFctByVal000001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000010")) {
    return iCallFctByVal000010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000011")) {
    return iCallFctByVal000011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000100")) {
    return iCallFctByVal000100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000101")) {
    return iCallFctByVal000101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000110")) {
    return iCallFctByVal000110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000111")) {
    return iCallFctByVal000111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001000")) {
    return iCallFctByVal001000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001001")) {
    return iCallFctByVal001001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001010")) {
    return iCallFctByVal001010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001011")) {
    return iCallFctByVal001011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001100")) {
    return iCallFctByVal001100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001101")) {
    return iCallFctByVal001101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001110")) {
    return iCallFctByVal001110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001111")) {
    return iCallFctByVal001111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010000")) {
    return iCallFctByVal010000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010001")) {
    return iCallFctByVal010001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010010")) {
    return iCallFctByVal010010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010011")) {
    return iCallFctByVal010011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010100")) {
    return iCallFctByVal010100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010101")) {
    return iCallFctByVal010101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010110")) {
    return iCallFctByVal010110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010111")) {
    return iCallFctByVal010111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011000")) {
    return iCallFctByVal011000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011001")) {
    return iCallFctByVal011001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011010")) {
    return iCallFctByVal011010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011011")) {
    return iCallFctByVal011011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011100")) {
    return iCallFctByVal011100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011101")) {
    return iCallFctByVal011101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011110")) {
    return iCallFctByVal011110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011111")) {
    return iCallFctByVal011111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100000")) {
    return iCallFctByVal100000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100001")) {
    return iCallFctByVal100001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100010")) {
    return iCallFctByVal100010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100011")) {
    return iCallFctByVal100011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100100")) {
    return iCallFctByVal100100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100101")) {
    return iCallFctByVal100101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100110")) {
    return iCallFctByVal100110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100111")) {
    return iCallFctByVal100111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101000")) {
    return iCallFctByVal101000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101001")) {
    return iCallFctByVal101001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101010")) {
    return iCallFctByVal101010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101011")) {
    return iCallFctByVal101011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101100")) {
    return iCallFctByVal101100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101101")) {
    return iCallFctByVal101101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101110")) {
    return iCallFctByVal101110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101111")) {
    return iCallFctByVal101111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110000")) {
    return iCallFctByVal110000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110001")) {
    return iCallFctByVal110001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110010")) {
    return iCallFctByVal110010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110011")) {
    return iCallFctByVal110011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110100")) {
    return iCallFctByVal110100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110101")) {
    return iCallFctByVal110101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110110")) {
    return iCallFctByVal110110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110111")) {
    return iCallFctByVal110111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111000")) {
    return iCallFctByVal111000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111001")) {
    return iCallFctByVal111001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111010")) {
    return iCallFctByVal111010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111011")) {
    return iCallFctByVal111011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111100")) {
    return iCallFctByVal111100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111101")) {
    return iCallFctByVal111101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111110")) {
    return iCallFctByVal111110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111111")) {
    return iCallFctByVal111111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
