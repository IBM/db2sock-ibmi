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

bighole_t iCallFctByRef0(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    );
}

bighole_t iCallFctByRef1(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0)
    );
}

bighole_t iCallFctByRef2(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1)
    );
}

bighole_t iCallFctByRef3(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
}

bighole_t iCallFctByRef4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
}

bighole_t iCallFctByRef5(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
}

bighole_t iCallFctByRef6(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
}

bighole_t iCallFctByRef7(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
}

bighole_t iCallFctByRef8(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7)
    );
}

bighole_t iCallFctByRef9(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8)
    );
}

bighole_t iCallFctByRef10(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9)
    );
}

bighole_t iCallFctByRef11(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10)
    );
}

bighole_t iCallFctByRef12(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11)
    );
}

bighole_t iCallFctByRef13(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12)
    );
}

bighole_t iCallFctByRef14(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13)
    );
}

bighole_t iCallFctByRef15(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14)
    );
}

bighole_t iCallFctByRef16(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15)
    );
}

bighole_t iCallFctByRef17(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16)
    );
}

bighole_t iCallFctByRef18(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17)
    );
}

bighole_t iCallFctByRef19(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18)
    );
}

bighole_t iCallFctByRef20(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19)
    );
}

bighole_t iCallFctByRef21(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20)
    );
}

bighole_t iCallFctByRef22(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21)
    );
}

bighole_t iCallFctByRef23(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22)
    );
}

bighole_t iCallFctByRef24(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23)
    );
}

bighole_t iCallFctByRef25(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24)
    );
}

bighole_t iCallFctByRef26(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25)
    );
}

bighole_t iCallFctByRef27(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26)
    );
}

bighole_t iCallFctByRef28(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27)
    );
}

bighole_t iCallFctByRef29(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28)
    );
}

bighole_t iCallFctByRef30(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29)
    );
}

bighole_t iCallFctByRef31(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30)
    );
}

bighole_t iCallFctByRefSub1(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  switch(layout->argc) {
  case 0:
    return iCallFctByRef0(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 1:
    return iCallFctByRef1(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 2:
    return iCallFctByRef2(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 3:
    return iCallFctByRef3(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 4:
    return iCallFctByRef4(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 5:
    return iCallFctByRef5(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 6:
    return iCallFctByRef6(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 7:
    return iCallFctByRef7(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 8:
    return iCallFctByRef8(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 9:
    return iCallFctByRef9(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 10:
    return iCallFctByRef10(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 11:
    return iCallFctByRef11(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 12:
    return iCallFctByRef12(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 13:
    return iCallFctByRef13(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 14:
    return iCallFctByRef14(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 15:
    return iCallFctByRef15(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 16:
    return iCallFctByRef16(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 17:
    return iCallFctByRef17(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 18:
    return iCallFctByRef18(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 19:
    return iCallFctByRef19(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 20:
    return iCallFctByRef20(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 21:
    return iCallFctByRef21(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 22:
    return iCallFctByRef22(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 23:
    return iCallFctByRef23(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 24:
    return iCallFctByRef24(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 25:
    return iCallFctByRef25(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 26:
    return iCallFctByRef26(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 27:
    return iCallFctByRef27(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 28:
    return iCallFctByRef28(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 29:
    return iCallFctByRef29(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 30:
    return iCallFctByRef30(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 31:
    return iCallFctByRef31(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  default:
    break;
  }
}
