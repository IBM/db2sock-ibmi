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

bighole_t iCallFctByVal0(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0)
    );
}

bighole_t iCallFctByVal1(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  int one_len = layout->arg_len[0]; /* all value elements must be same size (yuck) */
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  switch(one_len) {
  case 1: return os_fct_ptr(
    *(fool1_t *)iNextVal(layout, 0)
    );
  case 2: return os_fct_ptr(
    *(fool2_t *)iNextVal(layout, 0)
    );
  case 3: return os_fct_ptr(
    *(fool3_t *)iNextVal(layout, 0)
    );
  case 4: return os_fct_ptr(
    *(fool4_t *)iNextVal(layout, 0)
    );
  case 5: return os_fct_ptr(
    *(fool5_t *)iNextVal(layout, 0)
    );
  case 6: return os_fct_ptr(
    *(fool6_t *)iNextVal(layout, 0)
    );
  case 7: return os_fct_ptr(
    *(fool7_t *)iNextVal(layout, 0)
    );
  case 8: return os_fct_ptr(
    *(fool8_t *)iNextVal(layout, 0)
    );
  case 9: return os_fct_ptr(
    *(fool9_t *)iNextVal(layout, 0)
    );
  case 10: return os_fct_ptr(
    *(fool10_t *)iNextVal(layout, 0)
    );
  case 11: return os_fct_ptr(
    *(fool11_t *)iNextVal(layout, 0)
    );
  case 12: return os_fct_ptr(
    *(fool12_t *)iNextVal(layout, 0)
    );
  case 13: return os_fct_ptr(
    *(fool13_t *)iNextVal(layout, 0)
    );
  case 14: return os_fct_ptr(
    *(fool14_t *)iNextVal(layout, 0)
    );
  case 15: return os_fct_ptr(
    *(fool15_t *)iNextVal(layout, 0)
    );
  case 16: return os_fct_ptr(
    *(fool16_t *)iNextVal(layout, 0)
    );
  }
}

bighole_t iCallFctByValSub1(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"0")) {
    return iCallFctByVal0(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1")) {
    return iCallFctByVal1(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
