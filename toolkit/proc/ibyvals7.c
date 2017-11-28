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

bighole_t iCallFctByVal0000000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
}

bighole_t iCallFctByVal0000001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[6]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0000010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[5]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0000011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[5]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0000100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0000101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0000110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0000111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0001111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0010111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0011111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0100111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0101111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0110111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal0111111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1000111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1001111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1010111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1011111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1100111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1101111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1110111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), iNextPtr(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), iNextPtr(layout, 6)
    );
  }
}

bighole_t iCallFctByVal1111111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4), *(fool1_t *)iNextVal(layout, 5), *(fool1_t *)iNextVal(layout, 6)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4), *(fool2_t *)iNextVal(layout, 5), *(fool2_t *)iNextVal(layout, 6)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4), *(fool3_t *)iNextVal(layout, 5), *(fool3_t *)iNextVal(layout, 6)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4), *(fool4_t *)iNextVal(layout, 5), *(fool4_t *)iNextVal(layout, 6)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4), *(fool5_t *)iNextVal(layout, 5), *(fool5_t *)iNextVal(layout, 6)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4), *(fool6_t *)iNextVal(layout, 5), *(fool6_t *)iNextVal(layout, 6)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4), *(fool7_t *)iNextVal(layout, 5), *(fool7_t *)iNextVal(layout, 6)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4), *(fool8_t *)iNextVal(layout, 5), *(fool8_t *)iNextVal(layout, 6)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4), *(fool9_t *)iNextVal(layout, 5), *(fool9_t *)iNextVal(layout, 6)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4), *(fool10_t *)iNextVal(layout, 5), *(fool10_t *)iNextVal(layout, 6)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4), *(fool11_t *)iNextVal(layout, 5), *(fool11_t *)iNextVal(layout, 6)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4), *(fool12_t *)iNextVal(layout, 5), *(fool12_t *)iNextVal(layout, 6)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4), *(fool13_t *)iNextVal(layout, 5), *(fool13_t *)iNextVal(layout, 6)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4), *(fool14_t *)iNextVal(layout, 5), *(fool14_t *)iNextVal(layout, 6)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4), *(fool15_t *)iNextVal(layout, 5), *(fool15_t *)iNextVal(layout, 6)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4), *(fool16_t *)iNextVal(layout, 5), *(fool16_t *)iNextVal(layout, 6)
    );
  }
}

bighole_t iCallFctByValSub7(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"0000000")) {
    return iCallFctByVal0000000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000001")) {
    return iCallFctByVal0000001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000010")) {
    return iCallFctByVal0000010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000011")) {
    return iCallFctByVal0000011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000100")) {
    return iCallFctByVal0000100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000101")) {
    return iCallFctByVal0000101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000110")) {
    return iCallFctByVal0000110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0000111")) {
    return iCallFctByVal0000111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001000")) {
    return iCallFctByVal0001000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001001")) {
    return iCallFctByVal0001001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001010")) {
    return iCallFctByVal0001010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001011")) {
    return iCallFctByVal0001011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001100")) {
    return iCallFctByVal0001100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001101")) {
    return iCallFctByVal0001101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001110")) {
    return iCallFctByVal0001110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0001111")) {
    return iCallFctByVal0001111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010000")) {
    return iCallFctByVal0010000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010001")) {
    return iCallFctByVal0010001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010010")) {
    return iCallFctByVal0010010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010011")) {
    return iCallFctByVal0010011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010100")) {
    return iCallFctByVal0010100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010101")) {
    return iCallFctByVal0010101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010110")) {
    return iCallFctByVal0010110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0010111")) {
    return iCallFctByVal0010111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011000")) {
    return iCallFctByVal0011000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011001")) {
    return iCallFctByVal0011001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011010")) {
    return iCallFctByVal0011010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011011")) {
    return iCallFctByVal0011011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011100")) {
    return iCallFctByVal0011100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011101")) {
    return iCallFctByVal0011101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011110")) {
    return iCallFctByVal0011110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0011111")) {
    return iCallFctByVal0011111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100000")) {
    return iCallFctByVal0100000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100001")) {
    return iCallFctByVal0100001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100010")) {
    return iCallFctByVal0100010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100011")) {
    return iCallFctByVal0100011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100100")) {
    return iCallFctByVal0100100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100101")) {
    return iCallFctByVal0100101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100110")) {
    return iCallFctByVal0100110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0100111")) {
    return iCallFctByVal0100111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101000")) {
    return iCallFctByVal0101000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101001")) {
    return iCallFctByVal0101001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101010")) {
    return iCallFctByVal0101010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101011")) {
    return iCallFctByVal0101011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101100")) {
    return iCallFctByVal0101100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101101")) {
    return iCallFctByVal0101101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101110")) {
    return iCallFctByVal0101110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0101111")) {
    return iCallFctByVal0101111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110000")) {
    return iCallFctByVal0110000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110001")) {
    return iCallFctByVal0110001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110010")) {
    return iCallFctByVal0110010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110011")) {
    return iCallFctByVal0110011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110100")) {
    return iCallFctByVal0110100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110101")) {
    return iCallFctByVal0110101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110110")) {
    return iCallFctByVal0110110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0110111")) {
    return iCallFctByVal0110111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111000")) {
    return iCallFctByVal0111000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111001")) {
    return iCallFctByVal0111001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111010")) {
    return iCallFctByVal0111010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111011")) {
    return iCallFctByVal0111011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111100")) {
    return iCallFctByVal0111100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111101")) {
    return iCallFctByVal0111101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111110")) {
    return iCallFctByVal0111110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"0111111")) {
    return iCallFctByVal0111111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000000")) {
    return iCallFctByVal1000000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000001")) {
    return iCallFctByVal1000001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000010")) {
    return iCallFctByVal1000010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000011")) {
    return iCallFctByVal1000011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000100")) {
    return iCallFctByVal1000100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000101")) {
    return iCallFctByVal1000101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000110")) {
    return iCallFctByVal1000110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1000111")) {
    return iCallFctByVal1000111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001000")) {
    return iCallFctByVal1001000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001001")) {
    return iCallFctByVal1001001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001010")) {
    return iCallFctByVal1001010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001011")) {
    return iCallFctByVal1001011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001100")) {
    return iCallFctByVal1001100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001101")) {
    return iCallFctByVal1001101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001110")) {
    return iCallFctByVal1001110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1001111")) {
    return iCallFctByVal1001111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010000")) {
    return iCallFctByVal1010000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010001")) {
    return iCallFctByVal1010001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010010")) {
    return iCallFctByVal1010010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010011")) {
    return iCallFctByVal1010011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010100")) {
    return iCallFctByVal1010100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010101")) {
    return iCallFctByVal1010101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010110")) {
    return iCallFctByVal1010110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1010111")) {
    return iCallFctByVal1010111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011000")) {
    return iCallFctByVal1011000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011001")) {
    return iCallFctByVal1011001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011010")) {
    return iCallFctByVal1011010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011011")) {
    return iCallFctByVal1011011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011100")) {
    return iCallFctByVal1011100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011101")) {
    return iCallFctByVal1011101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011110")) {
    return iCallFctByVal1011110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1011111")) {
    return iCallFctByVal1011111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100000")) {
    return iCallFctByVal1100000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100001")) {
    return iCallFctByVal1100001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100010")) {
    return iCallFctByVal1100010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100011")) {
    return iCallFctByVal1100011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100100")) {
    return iCallFctByVal1100100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100101")) {
    return iCallFctByVal1100101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100110")) {
    return iCallFctByVal1100110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1100111")) {
    return iCallFctByVal1100111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101000")) {
    return iCallFctByVal1101000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101001")) {
    return iCallFctByVal1101001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101010")) {
    return iCallFctByVal1101010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101011")) {
    return iCallFctByVal1101011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101100")) {
    return iCallFctByVal1101100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101101")) {
    return iCallFctByVal1101101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101110")) {
    return iCallFctByVal1101110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1101111")) {
    return iCallFctByVal1101111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110000")) {
    return iCallFctByVal1110000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110001")) {
    return iCallFctByVal1110001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110010")) {
    return iCallFctByVal1110010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110011")) {
    return iCallFctByVal1110011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110100")) {
    return iCallFctByVal1110100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110101")) {
    return iCallFctByVal1110101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110110")) {
    return iCallFctByVal1110110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1110111")) {
    return iCallFctByVal1110111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111000")) {
    return iCallFctByVal1111000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111001")) {
    return iCallFctByVal1111001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111010")) {
    return iCallFctByVal1111010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111011")) {
    return iCallFctByVal1111011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111100")) {
    return iCallFctByVal1111100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111101")) {
    return iCallFctByVal1111101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111110")) {
    return iCallFctByVal1111110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"1111111")) {
    return iCallFctByVal1111111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
