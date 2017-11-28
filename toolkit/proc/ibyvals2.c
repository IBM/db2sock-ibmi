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

bighole_t iCallFctByVal00(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1)
    );
}

bighole_t iCallFctByVal01(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[1]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool1_t *)iNextVal(layout, 1)
    );
  case 2: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool2_t *)iNextVal(layout, 1)
    );
  case 3: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool3_t *)iNextVal(layout, 1)
    );
  case 4: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool4_t *)iNextVal(layout, 1)
    );
  case 5: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool5_t *)iNextVal(layout, 1)
    );
  case 6: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool6_t *)iNextVal(layout, 1)
    );
  case 7: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool7_t *)iNextVal(layout, 1)
    );
  case 8: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool8_t *)iNextVal(layout, 1)
    );
  case 9: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool9_t *)iNextVal(layout, 1)
    );
  case 10: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool10_t *)iNextVal(layout, 1)
    );
  case 11: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool11_t *)iNextVal(layout, 1)
    );
  case 12: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool12_t *)iNextVal(layout, 1)
    );
  case 13: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool13_t *)iNextVal(layout, 1)
    );
  case 14: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool14_t *)iNextVal(layout, 1)
    );
  case 15: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool15_t *)iNextVal(layout, 1)
    );
  case 16: return os_fct_ptr(
    iNextPtr(layout, 0), *(fool16_t *)iNextVal(layout, 1)
    );
  }
}

bighole_t iCallFctByVal10(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), iNextPtr(layout, 1)
    );
  }
}

bighole_t iCallFctByVal11(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0), *(fool1_t *)iNextVal(layout, 1)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0), *(fool2_t *)iNextVal(layout, 1)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0), *(fool3_t *)iNextVal(layout, 1)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0), *(fool4_t *)iNextVal(layout, 1)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0), *(fool5_t *)iNextVal(layout, 1)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0), *(fool6_t *)iNextVal(layout, 1)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0), *(fool7_t *)iNextVal(layout, 1)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0), *(fool8_t *)iNextVal(layout, 1)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0), *(fool9_t *)iNextVal(layout, 1)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0), *(fool10_t *)iNextVal(layout, 1)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0), *(fool11_t *)iNextVal(layout, 1)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0), *(fool12_t *)iNextVal(layout, 1)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0), *(fool13_t *)iNextVal(layout, 1)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0), *(fool14_t *)iNextVal(layout, 1)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0), *(fool15_t *)iNextVal(layout, 1)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0), *(fool16_t *)iNextVal(layout, 1)
    );
  }
}

bighole_t iCallFctByValSub2(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"00")) {
    return iCallFctByVal00(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"01")) {
    return iCallFctByVal01(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"10")) {
    return iCallFctByVal10(layout, myPgm, myLib, myFunc, lenFunc);
  }
  else if (!strcmp(pattern,"11")) {
    return iCallFctByVal11(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
