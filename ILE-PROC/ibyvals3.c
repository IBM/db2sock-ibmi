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

bighole_t iCallFctByVal000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000_t)();
  os_fct_000_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  return os_fct_ptr(
    ptr0, ptr1, ptr2
    );
}

bighole_t iCallFctByVal001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001_t)();
  os_fct_001_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  fool16_t * val16t2 = NULL;
  fool15_t * val15t2 = NULL;
  fool14_t * val14t2 = NULL;
  fool13_t * val13t2 = NULL;
  fool12_t * val12t2 = NULL;
  fool11_t * val11t2 = NULL;
  fool10_t * val10t2 = NULL;
  fool9_t * val9t2 = NULL;
  fool8_t * val8t2 = NULL;
  fool7_t * val7t2 = NULL;
  fool6_t * val6t2 = NULL;
  fool5_t * val5t2 = NULL;
  fool4_t * val4t2 = NULL;
  fool3_t * val3t2 = NULL;
  fool2_t * val2t2 = NULL;
  fool1_t * val1t2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[2];
  val1t2  = (fool1_t *) ((char *)layout + layout->arg_pos[2]);
  val2t2  = (fool2_t *) val1t2;
  val3t2  = (fool3_t *) val1t2;
  val4t2  = (fool4_t *) val1t2;
  val9t2  = (fool9_t *) val1t2;
  val5t2  = (fool5_t *) val1t2;
  val6t2  = (fool6_t *) val1t2;
  val7t2  = (fool7_t *) val1t2;
  val8t2  = (fool8_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2
    );
  }
}

bighole_t iCallFctByVal010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010_t)();
  os_fct_010_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  fool16_t * val16t1 = NULL;
  fool15_t * val15t1 = NULL;
  fool14_t * val14t1 = NULL;
  fool13_t * val13t1 = NULL;
  fool12_t * val12t1 = NULL;
  fool11_t * val11t1 = NULL;
  fool10_t * val10t1 = NULL;
  fool9_t * val9t1 = NULL;
  fool8_t * val8t1 = NULL;
  fool7_t * val7t1 = NULL;
  fool6_t * val6t1 = NULL;
  fool5_t * val5t1 = NULL;
  fool4_t * val4t1 = NULL;
  fool3_t * val3t1 = NULL;
  fool2_t * val2t1 = NULL;
  fool1_t * val1t1 = NULL;
  char * ptr2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  one_len = layout->arg_len[1];
  val1t1  = (fool1_t *) ((char *)layout + layout->arg_pos[1]);
  val2t1  = (fool2_t *) val1t1;
  val3t1  = (fool3_t *) val1t1;
  val4t1  = (fool4_t *) val1t1;
  val9t1  = (fool9_t *) val1t1;
  val5t1  = (fool5_t *) val1t1;
  val6t1  = (fool6_t *) val1t1;
  val7t1  = (fool7_t *) val1t1;
  val8t1  = (fool8_t *) val1t1;
  val10t1 = (fool10_t *) val1t1;
  val11t1 = (fool11_t *) val1t1;
  val12t1 = (fool12_t *) val1t1;
  val13t1 = (fool13_t *) val1t1;
  val14t1 = (fool14_t *) val1t1;
  val15t1 = (fool15_t *) val1t1;
  val16t1 = (fool16_t *) val1t1;
  ptr2 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2
    );
  }
}

bighole_t iCallFctByVal011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011_t)();
  os_fct_011_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  fool16_t * val16t1 = NULL;
  fool15_t * val15t1 = NULL;
  fool14_t * val14t1 = NULL;
  fool13_t * val13t1 = NULL;
  fool12_t * val12t1 = NULL;
  fool11_t * val11t1 = NULL;
  fool10_t * val10t1 = NULL;
  fool9_t * val9t1 = NULL;
  fool8_t * val8t1 = NULL;
  fool7_t * val7t1 = NULL;
  fool6_t * val6t1 = NULL;
  fool5_t * val5t1 = NULL;
  fool4_t * val4t1 = NULL;
  fool3_t * val3t1 = NULL;
  fool2_t * val2t1 = NULL;
  fool1_t * val1t1 = NULL;
  fool16_t * val16t2 = NULL;
  fool15_t * val15t2 = NULL;
  fool14_t * val14t2 = NULL;
  fool13_t * val13t2 = NULL;
  fool12_t * val12t2 = NULL;
  fool11_t * val11t2 = NULL;
  fool10_t * val10t2 = NULL;
  fool9_t * val9t2 = NULL;
  fool8_t * val8t2 = NULL;
  fool7_t * val7t2 = NULL;
  fool6_t * val6t2 = NULL;
  fool5_t * val5t2 = NULL;
  fool4_t * val4t2 = NULL;
  fool3_t * val3t2 = NULL;
  fool2_t * val2t2 = NULL;
  fool1_t * val1t2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  one_len = layout->arg_len[1];
  val1t1  = (fool1_t *) ((char *)layout + layout->arg_pos[1]);
  val2t1  = (fool2_t *) val1t1;
  val3t1  = (fool3_t *) val1t1;
  val4t1  = (fool4_t *) val1t1;
  val9t1  = (fool9_t *) val1t1;
  val5t1  = (fool5_t *) val1t1;
  val6t1  = (fool6_t *) val1t1;
  val7t1  = (fool7_t *) val1t1;
  val8t1  = (fool8_t *) val1t1;
  val10t1 = (fool10_t *) val1t1;
  val11t1 = (fool11_t *) val1t1;
  val12t1 = (fool12_t *) val1t1;
  val13t1 = (fool13_t *) val1t1;
  val14t1 = (fool14_t *) val1t1;
  val15t1 = (fool15_t *) val1t1;
  val16t1 = (fool16_t *) val1t1;
  one_len = layout->arg_len[2];
  val1t2  = (fool1_t *) ((char *)layout + layout->arg_pos[2]);
  val2t2  = (fool2_t *) val1t2;
  val3t2  = (fool3_t *) val1t2;
  val4t2  = (fool4_t *) val1t2;
  val9t2  = (fool9_t *) val1t2;
  val5t2  = (fool5_t *) val1t2;
  val6t2  = (fool6_t *) val1t2;
  val7t2  = (fool7_t *) val1t2;
  val8t2  = (fool8_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2
    );
  }
}

bighole_t iCallFctByVal100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100_t)();
  os_fct_100_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  fool16_t * val16t0 = NULL;
  fool15_t * val15t0 = NULL;
  fool14_t * val14t0 = NULL;
  fool13_t * val13t0 = NULL;
  fool12_t * val12t0 = NULL;
  fool11_t * val11t0 = NULL;
  fool10_t * val10t0 = NULL;
  fool9_t * val9t0 = NULL;
  fool8_t * val8t0 = NULL;
  fool7_t * val7t0 = NULL;
  fool6_t * val6t0 = NULL;
  fool5_t * val5t0 = NULL;
  fool4_t * val4t0 = NULL;
  fool3_t * val3t0 = NULL;
  fool2_t * val2t0 = NULL;
  fool1_t * val1t0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  one_len = layout->arg_len[0];
  val1t0  = (fool1_t *) ((char *)layout + layout->arg_pos[0]);
  val2t0  = (fool2_t *) val1t0;
  val3t0  = (fool3_t *) val1t0;
  val4t0  = (fool4_t *) val1t0;
  val9t0  = (fool9_t *) val1t0;
  val5t0  = (fool5_t *) val1t0;
  val6t0  = (fool6_t *) val1t0;
  val7t0  = (fool7_t *) val1t0;
  val8t0  = (fool8_t *) val1t0;
  val10t0 = (fool10_t *) val1t0;
  val11t0 = (fool11_t *) val1t0;
  val12t0 = (fool12_t *) val1t0;
  val13t0 = (fool13_t *) val1t0;
  val14t0 = (fool14_t *) val1t0;
  val15t0 = (fool15_t *) val1t0;
  val16t0 = (fool16_t *) val1t0;
  ptr1 = layout->argv[iNextArgv(layout, 0)];
  ptr2 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2
    );
  }
}

bighole_t iCallFctByVal101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101_t)();
  os_fct_101_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  fool16_t * val16t0 = NULL;
  fool15_t * val15t0 = NULL;
  fool14_t * val14t0 = NULL;
  fool13_t * val13t0 = NULL;
  fool12_t * val12t0 = NULL;
  fool11_t * val11t0 = NULL;
  fool10_t * val10t0 = NULL;
  fool9_t * val9t0 = NULL;
  fool8_t * val8t0 = NULL;
  fool7_t * val7t0 = NULL;
  fool6_t * val6t0 = NULL;
  fool5_t * val5t0 = NULL;
  fool4_t * val4t0 = NULL;
  fool3_t * val3t0 = NULL;
  fool2_t * val2t0 = NULL;
  fool1_t * val1t0 = NULL;
  char * ptr1 = NULL;
  fool16_t * val16t2 = NULL;
  fool15_t * val15t2 = NULL;
  fool14_t * val14t2 = NULL;
  fool13_t * val13t2 = NULL;
  fool12_t * val12t2 = NULL;
  fool11_t * val11t2 = NULL;
  fool10_t * val10t2 = NULL;
  fool9_t * val9t2 = NULL;
  fool8_t * val8t2 = NULL;
  fool7_t * val7t2 = NULL;
  fool6_t * val6t2 = NULL;
  fool5_t * val5t2 = NULL;
  fool4_t * val4t2 = NULL;
  fool3_t * val3t2 = NULL;
  fool2_t * val2t2 = NULL;
  fool1_t * val1t2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  one_len = layout->arg_len[0];
  val1t0  = (fool1_t *) ((char *)layout + layout->arg_pos[0]);
  val2t0  = (fool2_t *) val1t0;
  val3t0  = (fool3_t *) val1t0;
  val4t0  = (fool4_t *) val1t0;
  val9t0  = (fool9_t *) val1t0;
  val5t0  = (fool5_t *) val1t0;
  val6t0  = (fool6_t *) val1t0;
  val7t0  = (fool7_t *) val1t0;
  val8t0  = (fool8_t *) val1t0;
  val10t0 = (fool10_t *) val1t0;
  val11t0 = (fool11_t *) val1t0;
  val12t0 = (fool12_t *) val1t0;
  val13t0 = (fool13_t *) val1t0;
  val14t0 = (fool14_t *) val1t0;
  val15t0 = (fool15_t *) val1t0;
  val16t0 = (fool16_t *) val1t0;
  ptr1 = layout->argv[iNextArgv(layout, 0)];
  one_len = layout->arg_len[2];
  val1t2  = (fool1_t *) ((char *)layout + layout->arg_pos[2]);
  val2t2  = (fool2_t *) val1t2;
  val3t2  = (fool3_t *) val1t2;
  val4t2  = (fool4_t *) val1t2;
  val9t2  = (fool9_t *) val1t2;
  val5t2  = (fool5_t *) val1t2;
  val6t2  = (fool6_t *) val1t2;
  val7t2  = (fool7_t *) val1t2;
  val8t2  = (fool8_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2
    );
  }
}

bighole_t iCallFctByVal110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110_t)();
  os_fct_110_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  fool16_t * val16t0 = NULL;
  fool15_t * val15t0 = NULL;
  fool14_t * val14t0 = NULL;
  fool13_t * val13t0 = NULL;
  fool12_t * val12t0 = NULL;
  fool11_t * val11t0 = NULL;
  fool10_t * val10t0 = NULL;
  fool9_t * val9t0 = NULL;
  fool8_t * val8t0 = NULL;
  fool7_t * val7t0 = NULL;
  fool6_t * val6t0 = NULL;
  fool5_t * val5t0 = NULL;
  fool4_t * val4t0 = NULL;
  fool3_t * val3t0 = NULL;
  fool2_t * val2t0 = NULL;
  fool1_t * val1t0 = NULL;
  fool16_t * val16t1 = NULL;
  fool15_t * val15t1 = NULL;
  fool14_t * val14t1 = NULL;
  fool13_t * val13t1 = NULL;
  fool12_t * val12t1 = NULL;
  fool11_t * val11t1 = NULL;
  fool10_t * val10t1 = NULL;
  fool9_t * val9t1 = NULL;
  fool8_t * val8t1 = NULL;
  fool7_t * val7t1 = NULL;
  fool6_t * val6t1 = NULL;
  fool5_t * val5t1 = NULL;
  fool4_t * val4t1 = NULL;
  fool3_t * val3t1 = NULL;
  fool2_t * val2t1 = NULL;
  fool1_t * val1t1 = NULL;
  char * ptr2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  one_len = layout->arg_len[0];
  val1t0  = (fool1_t *) ((char *)layout + layout->arg_pos[0]);
  val2t0  = (fool2_t *) val1t0;
  val3t0  = (fool3_t *) val1t0;
  val4t0  = (fool4_t *) val1t0;
  val9t0  = (fool9_t *) val1t0;
  val5t0  = (fool5_t *) val1t0;
  val6t0  = (fool6_t *) val1t0;
  val7t0  = (fool7_t *) val1t0;
  val8t0  = (fool8_t *) val1t0;
  val10t0 = (fool10_t *) val1t0;
  val11t0 = (fool11_t *) val1t0;
  val12t0 = (fool12_t *) val1t0;
  val13t0 = (fool13_t *) val1t0;
  val14t0 = (fool14_t *) val1t0;
  val15t0 = (fool15_t *) val1t0;
  val16t0 = (fool16_t *) val1t0;
  one_len = layout->arg_len[1];
  val1t1  = (fool1_t *) ((char *)layout + layout->arg_pos[1]);
  val2t1  = (fool2_t *) val1t1;
  val3t1  = (fool3_t *) val1t1;
  val4t1  = (fool4_t *) val1t1;
  val9t1  = (fool9_t *) val1t1;
  val5t1  = (fool5_t *) val1t1;
  val6t1  = (fool6_t *) val1t1;
  val7t1  = (fool7_t *) val1t1;
  val8t1  = (fool8_t *) val1t1;
  val10t1 = (fool10_t *) val1t1;
  val11t1 = (fool11_t *) val1t1;
  val12t1 = (fool12_t *) val1t1;
  val13t1 = (fool13_t *) val1t1;
  val14t1 = (fool14_t *) val1t1;
  val15t1 = (fool15_t *) val1t1;
  val16t1 = (fool16_t *) val1t1;
  ptr2 = layout->argv[iNextArgv(layout, 0)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2
    );
  }
}

bighole_t iCallFctByVal111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111_t)();
  os_fct_111_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  fool16_t * val16t0 = NULL;
  fool15_t * val15t0 = NULL;
  fool14_t * val14t0 = NULL;
  fool13_t * val13t0 = NULL;
  fool12_t * val12t0 = NULL;
  fool11_t * val11t0 = NULL;
  fool10_t * val10t0 = NULL;
  fool9_t * val9t0 = NULL;
  fool8_t * val8t0 = NULL;
  fool7_t * val7t0 = NULL;
  fool6_t * val6t0 = NULL;
  fool5_t * val5t0 = NULL;
  fool4_t * val4t0 = NULL;
  fool3_t * val3t0 = NULL;
  fool2_t * val2t0 = NULL;
  fool1_t * val1t0 = NULL;
  fool16_t * val16t1 = NULL;
  fool15_t * val15t1 = NULL;
  fool14_t * val14t1 = NULL;
  fool13_t * val13t1 = NULL;
  fool12_t * val12t1 = NULL;
  fool11_t * val11t1 = NULL;
  fool10_t * val10t1 = NULL;
  fool9_t * val9t1 = NULL;
  fool8_t * val8t1 = NULL;
  fool7_t * val7t1 = NULL;
  fool6_t * val6t1 = NULL;
  fool5_t * val5t1 = NULL;
  fool4_t * val4t1 = NULL;
  fool3_t * val3t1 = NULL;
  fool2_t * val2t1 = NULL;
  fool1_t * val1t1 = NULL;
  fool16_t * val16t2 = NULL;
  fool15_t * val15t2 = NULL;
  fool14_t * val14t2 = NULL;
  fool13_t * val13t2 = NULL;
  fool12_t * val12t2 = NULL;
  fool11_t * val11t2 = NULL;
  fool10_t * val10t2 = NULL;
  fool9_t * val9t2 = NULL;
  fool8_t * val8t2 = NULL;
  fool7_t * val7t2 = NULL;
  fool6_t * val6t2 = NULL;
  fool5_t * val5t2 = NULL;
  fool4_t * val4t2 = NULL;
  fool3_t * val3t2 = NULL;
  fool2_t * val2t2 = NULL;
  fool1_t * val1t2 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  one_len = layout->arg_len[0];
  val1t0  = (fool1_t *) ((char *)layout + layout->arg_pos[0]);
  val2t0  = (fool2_t *) val1t0;
  val3t0  = (fool3_t *) val1t0;
  val4t0  = (fool4_t *) val1t0;
  val9t0  = (fool9_t *) val1t0;
  val5t0  = (fool5_t *) val1t0;
  val6t0  = (fool6_t *) val1t0;
  val7t0  = (fool7_t *) val1t0;
  val8t0  = (fool8_t *) val1t0;
  val10t0 = (fool10_t *) val1t0;
  val11t0 = (fool11_t *) val1t0;
  val12t0 = (fool12_t *) val1t0;
  val13t0 = (fool13_t *) val1t0;
  val14t0 = (fool14_t *) val1t0;
  val15t0 = (fool15_t *) val1t0;
  val16t0 = (fool16_t *) val1t0;
  one_len = layout->arg_len[1];
  val1t1  = (fool1_t *) ((char *)layout + layout->arg_pos[1]);
  val2t1  = (fool2_t *) val1t1;
  val3t1  = (fool3_t *) val1t1;
  val4t1  = (fool4_t *) val1t1;
  val9t1  = (fool9_t *) val1t1;
  val5t1  = (fool5_t *) val1t1;
  val6t1  = (fool6_t *) val1t1;
  val7t1  = (fool7_t *) val1t1;
  val8t1  = (fool8_t *) val1t1;
  val10t1 = (fool10_t *) val1t1;
  val11t1 = (fool11_t *) val1t1;
  val12t1 = (fool12_t *) val1t1;
  val13t1 = (fool13_t *) val1t1;
  val14t1 = (fool14_t *) val1t1;
  val15t1 = (fool15_t *) val1t1;
  val16t1 = (fool16_t *) val1t1;
  one_len = layout->arg_len[2];
  val1t2  = (fool1_t *) ((char *)layout + layout->arg_pos[2]);
  val2t2  = (fool2_t *) val1t2;
  val3t2  = (fool3_t *) val1t2;
  val4t2  = (fool4_t *) val1t2;
  val9t2  = (fool9_t *) val1t2;
  val5t2  = (fool5_t *) val1t2;
  val6t2  = (fool6_t *) val1t2;
  val7t2  = (fool7_t *) val1t2;
  val8t2  = (fool8_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2
    );
  }
}

bighole_t iCallFctByValSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"000")) {
    return iCallFctByVal000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001")) {
    return iCallFctByVal001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010")) {
    return iCallFctByVal010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011")) {
    return iCallFctByVal011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100")) {
    return iCallFctByVal100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101")) {
    return iCallFctByVal101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110")) {
    return iCallFctByVal110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111")) {
    return iCallFctByVal111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
