/*
 * ILE stored procedure interface PASE libdb400.a->SQL400Json
 */
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

void iCall400(char * blob) 
{
  /* blob -> |4-byte length|pad|data...| */
  ile_pgm_call_t* layout = (ile_pgm_call_t*)blob;
  int argc = 0;
  int parmc = 0;
  int offset = 0;
  int by = 0;
  /* hey adc debug */
  /* sleep(30); */
  /* set ILE addresses based memory spill location offset */
  for (argc=0; argc < layout->argc; argc++) {
    /*  by reference */
    if (layout->argv_parm[argc] > -1) {
      /* ILE address parm location (skip by value slots) */
      parmc = layout->argv_parm[argc];
      offset = layout->arg_pos[parmc];
      /* set ILE address to data */
      layout->argv[argc] = (char *)layout + offset;
      layout->argv[argc+1] = NULL;
    }
  }
}

