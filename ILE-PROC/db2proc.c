/*
 * ILE stored procedure interface PASE libdb400.a->SQL400Json
 */
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
#include "ibyref.h" /* see gen.py */

void iCall400(char * blob) 
{
  /* blob -> |4-byte length|pad|data...| */
  ile_pgm_call_t* layout = (ile_pgm_call_t*)blob;
  int argc = 0;
  int parmc = 0;
  int offset = 0;
  int by = 0;
  int lenPgm = 0;
  int lenLib = 0;
  int lenFunc = 0;
  int lenRet = 0;
  char * myPgm = NULL;
  char * myLib = NULL;
  char * myFunc = NULL;
  char * myLibl = "*LIBL";
  char * myRet = NULL;
  bighole_t bighole;

  /* hey adc debug */
  /* sleep(30); */
  layout->step = 1;

  /* set ILE addresses based memory spill location offset */
  for (argc=0; argc < ILE_PGM_MAX_ARGS; argc++) {
    if (argc < layout->argc) {
      /*  by reference */
      if (layout->argv_parm[argc] > -1) {
        /* ILE address parm location (skip by value slots) */
        parmc = layout->argv_parm[argc];
        offset = layout->arg_pos[parmc];
        /* set ILE address to data */
        layout->argv[argc] = (char *)layout + offset;
      }
    } else {
      layout->argv[argc] = NULL;
    }
  }
  layout->step = 2;

  /* resolve call  */
  myPgm = layout->pgm;
  myLib = layout->lib;
  myFunc = layout->func;
  lenPgm = strlen(myPgm);
  lenLib = strlen(myLib);
  if (!lenLib) {
    myLib = myLibl;
    lenLib = 5;
  }
  lenFunc = strlen(myFunc);
  layout->step = 3;

  if (!lenFunc) {
    /* call by ref */
    if (layout->argc == layout->parmc) {
      if (layout->argc < 32) {
        iCallPgmByRefSub1(layout, myPgm, myLib);
      } else if (layout->argc < 64) {
        iCallPgmByRefSub2(layout, myPgm, myLib);
      } else if (layout->argc < 96) {
        iCallPgmByRefSub3(layout, myPgm, myLib);
      } else if (layout->argc < 128) {
        iCallPgmByRefSub4(layout, myPgm, myLib);
      } else if (layout->argc < 160) {
        iCallPgmByRefSub5(layout, myPgm, myLib);
      }
    } else {
      /* next work */
    }
  } else {
    /* call by ref */
    if (layout->argc == layout->parmc) {
      if (layout->argc < 32) {
        bighole = iCallFctByRefSub1(layout, myPgm, myLib, myFunc, lenFunc);
      } else if (layout->argc < 64) {
        bighole = iCallFctByRefSub2(layout, myPgm, myLib, myFunc, lenFunc);
      } else if (layout->argc < 96) {
        bighole = iCallFctByRefSub3(layout, myPgm, myLib, myFunc, lenFunc);
      } else if (layout->argc < 128) {
        bighole = iCallFctByRefSub4(layout, myPgm, myLib, myFunc, lenFunc);
      } else if (layout->argc < 160) {
        bighole = iCallFctByRefSub5(layout, myPgm, myLib, myFunc, lenFunc);
      }
    } else {
      /* next work */
    }
  }
  layout->step = 4;

  /* return aggregate? */
  if (layout->return_start && layout->return_start < layout->return_end) {
    myRet = (char *)layout + layout->return_start;
    lenRet = layout->return_end - layout->return_start;
    memcpy(myRet,(char *)&bighole,lenRet);
  }
  layout->step = 5;

}

