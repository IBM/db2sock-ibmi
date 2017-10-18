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

void iCallPgmByRef0(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    );
}

void iCallPgmByRef1(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0)
    );
}

void iCallPgmByRef2(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1)
    );
}

void iCallPgmByRef3(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
}

void iCallPgmByRef4(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3)
    );
}

void iCallPgmByRef5(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4)
    );
}

void iCallPgmByRef6(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5)
    );
}

void iCallPgmByRef7(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6)
    );
}

void iCallPgmByRef8(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7)
    );
}

void iCallPgmByRef9(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8)
    );
}

void iCallPgmByRef10(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9)
    );
}

void iCallPgmByRef11(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10)
    );
}

void iCallPgmByRef12(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11)
    );
}

void iCallPgmByRef13(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12)
    );
}

void iCallPgmByRef14(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13)
    );
}

void iCallPgmByRef15(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14)
    );
}

void iCallPgmByRef16(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15)
    );
}

void iCallPgmByRef17(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16)
    );
}

void iCallPgmByRef18(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17)
    );
}

void iCallPgmByRef19(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18)
    );
}

void iCallPgmByRef20(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19)
    );
}

void iCallPgmByRef21(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20)
    );
}

void iCallPgmByRef22(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21)
    );
}

void iCallPgmByRef23(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22)
    );
}

void iCallPgmByRef24(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23)
    );
}

void iCallPgmByRef25(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24)
    );
}

void iCallPgmByRef26(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25)
    );
}

void iCallPgmByRef27(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26)
    );
}

void iCallPgmByRef28(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27)
    );
}

void iCallPgmByRef29(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28)
    );
}

void iCallPgmByRef30(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29)
    );
}

void iCallPgmByRef31(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30)
    );
}

void iCallPgmByRefSub1(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  switch(layout->argc) {
  case 0:
    iCallPgmByRef0(layout, myPgm, myLib);
    break;
  case 1:
    iCallPgmByRef1(layout, myPgm, myLib);
    break;
  case 2:
    iCallPgmByRef2(layout, myPgm, myLib);
    break;
  case 3:
    iCallPgmByRef3(layout, myPgm, myLib);
    break;
  case 4:
    iCallPgmByRef4(layout, myPgm, myLib);
    break;
  case 5:
    iCallPgmByRef5(layout, myPgm, myLib);
    break;
  case 6:
    iCallPgmByRef6(layout, myPgm, myLib);
    break;
  case 7:
    iCallPgmByRef7(layout, myPgm, myLib);
    break;
  case 8:
    iCallPgmByRef8(layout, myPgm, myLib);
    break;
  case 9:
    iCallPgmByRef9(layout, myPgm, myLib);
    break;
  case 10:
    iCallPgmByRef10(layout, myPgm, myLib);
    break;
  case 11:
    iCallPgmByRef11(layout, myPgm, myLib);
    break;
  case 12:
    iCallPgmByRef12(layout, myPgm, myLib);
    break;
  case 13:
    iCallPgmByRef13(layout, myPgm, myLib);
    break;
  case 14:
    iCallPgmByRef14(layout, myPgm, myLib);
    break;
  case 15:
    iCallPgmByRef15(layout, myPgm, myLib);
    break;
  case 16:
    iCallPgmByRef16(layout, myPgm, myLib);
    break;
  case 17:
    iCallPgmByRef17(layout, myPgm, myLib);
    break;
  case 18:
    iCallPgmByRef18(layout, myPgm, myLib);
    break;
  case 19:
    iCallPgmByRef19(layout, myPgm, myLib);
    break;
  case 20:
    iCallPgmByRef20(layout, myPgm, myLib);
    break;
  case 21:
    iCallPgmByRef21(layout, myPgm, myLib);
    break;
  case 22:
    iCallPgmByRef22(layout, myPgm, myLib);
    break;
  case 23:
    iCallPgmByRef23(layout, myPgm, myLib);
    break;
  case 24:
    iCallPgmByRef24(layout, myPgm, myLib);
    break;
  case 25:
    iCallPgmByRef25(layout, myPgm, myLib);
    break;
  case 26:
    iCallPgmByRef26(layout, myPgm, myLib);
    break;
  case 27:
    iCallPgmByRef27(layout, myPgm, myLib);
    break;
  case 28:
    iCallPgmByRef28(layout, myPgm, myLib);
    break;
  case 29:
    iCallPgmByRef29(layout, myPgm, myLib);
    break;
  case 30:
    iCallPgmByRef30(layout, myPgm, myLib);
    break;
  case 31:
    iCallPgmByRef31(layout, myPgm, myLib);
    break;
  default:
    break;
  }
}
