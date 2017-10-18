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

bighole_t iCallFctByVal00000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
}

bighole_t iCallFctByVal00001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[4]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal00010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal00011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal00100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal00101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal00110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal00111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal01111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal10111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), iNextPtr(layout, 4)
    );
  }
}

bighole_t iCallFctByVal11111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3), *(fool1_t *)iNextVal(layout, 4)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3), *(fool2_t *)iNextVal(layout, 4)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3), *(fool3_t *)iNextVal(layout, 4)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3), *(fool4_t *)iNextVal(layout, 4)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3), *(fool5_t *)iNextVal(layout, 4)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3), *(fool6_t *)iNextVal(layout, 4)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3), *(fool7_t *)iNextVal(layout, 4)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3), *(fool8_t *)iNextVal(layout, 4)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3), *(fool9_t *)iNextVal(layout, 4)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3), *(fool10_t *)iNextVal(layout, 4)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3), *(fool11_t *)iNextVal(layout, 4)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3), *(fool12_t *)iNextVal(layout, 4)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3), *(fool13_t *)iNextVal(layout, 4)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3), *(fool14_t *)iNextVal(layout, 4)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3), *(fool15_t *)iNextVal(layout, 4)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3), *(fool16_t *)iNextVal(layout, 4)
    );
  }
}

bighole_t iCallFctByValSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"00000")) {
    return iCallFctByVal00000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00001")) {
    return iCallFctByVal00001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00010")) {
    return iCallFctByVal00010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00011")) {
    return iCallFctByVal00011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00100")) {
    return iCallFctByVal00100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00101")) {
    return iCallFctByVal00101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00110")) {
    return iCallFctByVal00110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00111")) {
    return iCallFctByVal00111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01000")) {
    return iCallFctByVal01000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01001")) {
    return iCallFctByVal01001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01010")) {
    return iCallFctByVal01010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01011")) {
    return iCallFctByVal01011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01100")) {
    return iCallFctByVal01100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01101")) {
    return iCallFctByVal01101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01110")) {
    return iCallFctByVal01110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01111")) {
    return iCallFctByVal01111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10000")) {
    return iCallFctByVal10000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10001")) {
    return iCallFctByVal10001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10010")) {
    return iCallFctByVal10010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10011")) {
    return iCallFctByVal10011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10100")) {
    return iCallFctByVal10100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10101")) {
    return iCallFctByVal10101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10110")) {
    return iCallFctByVal10110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10111")) {
    return iCallFctByVal10111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11000")) {
    return iCallFctByVal11000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11001")) {
    return iCallFctByVal11001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11010")) {
    return iCallFctByVal11010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11011")) {
    return iCallFctByVal11011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11100")) {
    return iCallFctByVal11100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11101")) {
    return iCallFctByVal11101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11110")) {
    return iCallFctByVal11110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11111")) {
    return iCallFctByVal11111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
