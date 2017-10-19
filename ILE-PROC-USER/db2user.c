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
#include "../ILE-PROC/ibyref.h" /* see gen.py */

/*
SRVPGM sample of many different by value arguments with by ref output
Note:
Toolkit only handles pass by value of 'same size' up to 8 paramters.
Toolkit does not handle pass by 'value' of different sizes.
Toolkit does not handle pass by 'value' beyond 8 paramters.

mask
       dcl-pr crazy9;
9         a1 packed(16:2) value;
8         a2 packed(15:2) value;
2         a3 int(5) value;
7         a4 char(7) value;
G         a5 char(16) value;
3         a6 packed(4:2) value;
8         a7 char(8) value;
7         a8 packed(12:2) value;
3         a9 packed(4:2) value;
0         o1 packed(16:2);
0         o2 packed(15:2);
0         o3 int(5);
0         o4 char(7);
0         o5 char(16);
0         o6 packed(4:2);
0         o7 char(8);
0         o8 packed(12:2);
0         o9 packed(4:2);
       end-pr;
*/
bighole_t sample_crazy9(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern, int * isDone)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  *isDone = 1;
  return os_fct_ptr(
    *(fool9_t *)  iNextVal(layout, 0),
    *(fool8_t *)  iNextVal(layout, 1),
    *(fool2_t *)  iNextVal(layout, 2),
    *(fool7_t *)  iNextVal(layout, 3),
    *(fool16_t *) iNextVal(layout, 4),
    *(fool3_t *)  iNextVal(layout, 5),
    *(fool8_t *)  iNextVal(layout, 6),
    *(fool7_t *)  iNextVal(layout, 7),
    *(fool3_t *)  iNextVal(layout, 8),
    iNextPtr(layout, 9),
    iNextPtr(layout, 10),
    iNextPtr(layout, 11),
    iNextPtr(layout, 12),
    iNextPtr(layout, 13),
    iNextPtr(layout, 14),
    iNextPtr(layout, 15),
    iNextPtr(layout, 16),
    iNextPtr(layout, 17)
    );
}

/*
PGM sample of few arguments.
Note: 
Toolkit already handles any PGM by ref call,
this is simple example using db2user.c

       dcl-ds money qualified;
          my varchar(20:2);
          lot packed(5:2);
          sof packed(18:2);
          dough packed(31:2);
       end-ds;

       dcl-ds bio qualified;
          mr varchar(10:2);
          first varchar(15:2);
          last varchar(25:2);
          bank likeds(money) dim(2);
       end-ds;

       dcl-pr Main extpgm;
         maxCount int(10);
         outCount int(10);
         output likeds(bio) dim(10);
       end-pr;
*/
void sample_rainbank(ile_pgm_call_t* layout, char * myPgm, char * myLib, int * isDone)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  *isDone = 1;
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2)
    );
}



bighole_t UserCallSrvPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern, int * isDone)
{
  // SRVPGM add your own custom iCallFctByValxxxxx pattern
  if (!strcmp(myPgm,"RAINSRV") && !strcmp(myFunc,"CRAZY9")) {
    return sample_crazy9(layout, myPgm, myLib, myFunc, lenFunc, pattern, isDone);
  }
  return;
}

void UserCallPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, int * isDone)
{
  // PGM add your own custom iCallPgmByRefxxxxx
  if (!strcmp(myPgm,"RAINBANK")) {
    sample_rainbank(layout, myPgm, myLib, isDone);
    return;
  }
  return;
}

