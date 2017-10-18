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

bighole_t iCallFctByVal0000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
}

bighole_t iCallFctByVal0001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[3]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal0010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal0011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[2]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal0100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal0101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal0110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal0111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), iNextPtr(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), iNextPtr(layout, 3)
    );
  }
}

bighole_t iCallFctByVal1111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1), *(fool1_t *)iNextVal(layout, 2), *(fool1_t *)iNextVal(layout, 3)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1), *(fool2_t *)iNextVal(layout, 2), *(fool2_t *)iNextVal(layout, 3)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1), *(fool3_t *)iNextVal(layout, 2), *(fool3_t *)iNextVal(layout, 3)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1), *(fool4_t *)iNextVal(layout, 2), *(fool4_t *)iNextVal(layout, 3)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1), *(fool5_t *)iNextVal(layout, 2), *(fool5_t *)iNextVal(layout, 3)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1), *(fool6_t *)iNextVal(layout, 2), *(fool6_t *)iNextVal(layout, 3)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1), *(fool7_t *)iNextVal(layout, 2), *(fool7_t *)iNextVal(layout, 3)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1), *(fool8_t *)iNextVal(layout, 2), *(fool8_t *)iNextVal(layout, 3)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1), *(fool9_t *)iNextVal(layout, 2), *(fool9_t *)iNextVal(layout, 3)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1), *(fool10_t *)iNextVal(layout, 2), *(fool10_t *)iNextVal(layout, 3)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1), *(fool11_t *)iNextVal(layout, 2), *(fool11_t *)iNextVal(layout, 3)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1), *(fool12_t *)iNextVal(layout, 2), *(fool12_t *)iNextVal(layout, 3)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1), *(fool13_t *)iNextVal(layout, 2), *(fool13_t *)iNextVal(layout, 3)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1), *(fool14_t *)iNextVal(layout, 2), *(fool14_t *)iNextVal(layout, 3)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1), *(fool15_t *)iNextVal(layout, 2), *(fool15_t *)iNextVal(layout, 3)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1), *(fool16_t *)iNextVal(layout, 2), *(fool16_t *)iNextVal(layout, 3)
    );
  }
}

bighole_t iCallFctByValSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"0000")) {
    return iCallFctByVal0000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001")) {
    return iCallFctByVal0001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010")) {
    return iCallFctByVal0010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011")) {
    return iCallFctByVal0011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100")) {
    return iCallFctByVal0100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101")) {
    return iCallFctByVal0101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110")) {
    return iCallFctByVal0110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111")) {
    return iCallFctByVal0111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000")) {
    return iCallFctByVal1000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001")) {
    return iCallFctByVal1001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010")) {
    return iCallFctByVal1010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011")) {
    return iCallFctByVal1011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100")) {
    return iCallFctByVal1100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101")) {
    return iCallFctByVal1101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110")) {
    return iCallFctByVal1110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111")) {
    return iCallFctByVal1111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
