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

bighole_t iCallFctByVal00000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00000_t)();
  os_fct_00000_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  char * ptr3 = NULL;
  char * ptr4 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  ptr4 = layout->argv[iNextArgv(layout, 4)];
  return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4
    );
}

bighole_t iCallFctByVal00001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00001_t)();
  os_fct_00001_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal00010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00010_t)();
  os_fct_00010_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal00011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00011_t)();
  os_fct_00011_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal00100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00100_t)();
  os_fct_00100_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal00101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00101_t)();
  os_fct_00101_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal00110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00110_t)();
  os_fct_00110_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal00111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_00111_t)();
  os_fct_00111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal01000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01000_t)();
  os_fct_01000_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal01001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01001_t)();
  os_fct_01001_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal01010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01010_t)();
  os_fct_01010_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal01011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01011_t)();
  os_fct_01011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal01100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01100_t)();
  os_fct_01100_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal01101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01101_t)();
  os_fct_01101_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal01110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01110_t)();
  os_fct_01110_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal01111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_01111_t)();
  os_fct_01111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal10000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10000_t)();
  os_fct_10000_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal10001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10001_t)();
  os_fct_10001_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal10010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10010_t)();
  os_fct_10010_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal10011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10011_t)();
  os_fct_10011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal10100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10100_t)();
  os_fct_10100_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal10101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10101_t)();
  os_fct_10101_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal10110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10110_t)();
  os_fct_10110_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal10111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_10111_t)();
  os_fct_10111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal11000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11000_t)();
  os_fct_11000_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal11001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11001_t)();
  os_fct_11001_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal11010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11010_t)();
  os_fct_11010_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal11011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11011_t)();
  os_fct_11011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByVal11100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11100_t)();
  os_fct_11100_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  char * ptr4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 0)];
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4
    );
  }
}

bighole_t iCallFctByVal11101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11101_t)();
  os_fct_11101_t *os_fct_ptr = NULL;
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
  char * ptr3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  ptr3 = layout->argv[iNextArgv(layout, 0)];
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4
    );
  }
}

bighole_t iCallFctByVal11110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11110_t)();
  os_fct_11110_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  char * ptr4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 0)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4
    );
  }
}

bighole_t iCallFctByVal11111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_11111_t)();
  os_fct_11111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t3 = NULL;
  fool15_t * val15t3 = NULL;
  fool14_t * val14t3 = NULL;
  fool13_t * val13t3 = NULL;
  fool12_t * val12t3 = NULL;
  fool11_t * val11t3 = NULL;
  fool10_t * val10t3 = NULL;
  fool9_t * val9t3 = NULL;
  fool8_t * val8t3 = NULL;
  fool7_t * val7t3 = NULL;
  fool6_t * val6t3 = NULL;
  fool5_t * val5t3 = NULL;
  fool4_t * val4t3 = NULL;
  fool3_t * val3t3 = NULL;
  fool2_t * val2t3 = NULL;
  fool1_t * val1t3 = NULL;
  fool16_t * val16t4 = NULL;
  fool15_t * val15t4 = NULL;
  fool14_t * val14t4 = NULL;
  fool13_t * val13t4 = NULL;
  fool12_t * val12t4 = NULL;
  fool11_t * val11t4 = NULL;
  fool10_t * val10t4 = NULL;
  fool9_t * val9t4 = NULL;
  fool8_t * val8t4 = NULL;
  fool7_t * val7t4 = NULL;
  fool6_t * val6t4 = NULL;
  fool5_t * val5t4 = NULL;
  fool4_t * val4t4 = NULL;
  fool3_t * val3t4 = NULL;
  fool2_t * val2t4 = NULL;
  fool1_t * val1t4 = NULL;
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
  one_len = layout->arg_len[3];
  val1t3  = (fool1_t *) ((char *)layout + layout->arg_pos[3]);
  val2t3  = (fool2_t *) val1t3;
  val3t3  = (fool3_t *) val1t3;
  val4t3  = (fool4_t *) val1t3;
  val9t3  = (fool9_t *) val1t3;
  val5t3  = (fool5_t *) val1t3;
  val6t3  = (fool6_t *) val1t3;
  val7t3  = (fool7_t *) val1t3;
  val8t3  = (fool8_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  one_len = layout->arg_len[4];
  val1t4  = (fool1_t *) ((char *)layout + layout->arg_pos[4]);
  val2t4  = (fool2_t *) val1t4;
  val3t4  = (fool3_t *) val1t4;
  val4t4  = (fool4_t *) val1t4;
  val9t4  = (fool9_t *) val1t4;
  val5t4  = (fool5_t *) val1t4;
  val6t4  = (fool6_t *) val1t4;
  val7t4  = (fool7_t *) val1t4;
  val8t4  = (fool8_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4
    );
  }
}

bighole_t iCallFctByValSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"00000")) {
    return iCallFctByVal00000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00001")) {
    return iCallFctByVal00001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00010")) {
    return iCallFctByVal00010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00011")) {
    return iCallFctByVal00011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00100")) {
    return iCallFctByVal00100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00101")) {
    return iCallFctByVal00101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00110")) {
    return iCallFctByVal00110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"00111")) {
    return iCallFctByVal00111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01000")) {
    return iCallFctByVal01000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01001")) {
    return iCallFctByVal01001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01010")) {
    return iCallFctByVal01010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01011")) {
    return iCallFctByVal01011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01100")) {
    return iCallFctByVal01100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01101")) {
    return iCallFctByVal01101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01110")) {
    return iCallFctByVal01110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"01111")) {
    return iCallFctByVal01111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10000")) {
    return iCallFctByVal10000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10001")) {
    return iCallFctByVal10001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10010")) {
    return iCallFctByVal10010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10011")) {
    return iCallFctByVal10011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10100")) {
    return iCallFctByVal10100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10101")) {
    return iCallFctByVal10101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10110")) {
    return iCallFctByVal10110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"10111")) {
    return iCallFctByVal10111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11000")) {
    return iCallFctByVal11000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11001")) {
    return iCallFctByVal11001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11010")) {
    return iCallFctByVal11010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11011")) {
    return iCallFctByVal11011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11100")) {
    return iCallFctByVal11100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11101")) {
    return iCallFctByVal11101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11110")) {
    return iCallFctByVal11110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"11111")) {
    return iCallFctByVal11111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
