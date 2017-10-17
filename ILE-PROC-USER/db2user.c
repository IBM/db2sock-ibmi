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

typedef struct fool16 {char hole[16]; } fool16_t;
typedef struct fool15 {char hole[15]; } fool15_t;
typedef struct fool14 {char hole[14]; } fool14_t;
typedef struct fool13 {char hole[13]; } fool13_t;
typedef struct fool12 {char hole[12]; } fool12_t;
typedef struct fool11 {char hole[11]; } fool11_t;
typedef struct fool10 {char hole[10]; } fool10_t;
typedef struct fool9 {char hole[9]; } fool9_t;
typedef struct fool8 {char hole[8]; } fool8_t;
typedef struct fool7 {char hole[7]; } fool7_t;
typedef struct fool6 {char hole[6]; } fool6_t;
typedef struct fool5 {char hole[5]; } fool5_t;
typedef struct fool4 {char hole[4]; } fool4_t;
typedef struct fool3 {char hole[3]; } fool3_t;
typedef struct fool2 {char hole[2]; } fool2_t;
typedef struct fool1 {char hole[1]; } fool1_t;
static int iNextArgv(ile_pgm_call_t* layout, int argc)
{
  int i = 0;
  int j = 0;
  for (i=0; i < ILE_PGM_MAX_ARGS; i++) {
    if (layout->argv[i]) {
      if (j == argc) {
        return i;
      }
      j++;
    }
  }
  return 0;
}

bighole_t UserCallSrvPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern, int * isDone)
{
  // add your own custom iCallFctByValxxxxx pattern
  return;
}

void UserCallPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, int * isDone)
{
  // add your own custom iCallPgmByRefxxxxx
  return;
}

