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

bighole_t iCallFctByVal000000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000000_t)();
  os_fct_000000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  ptr4 = layout->argv[iNextArgv(layout, 4)];
  ptr5 = layout->argv[iNextArgv(layout, 5)];
  return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
}

bighole_t iCallFctByVal000001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000001_t)();
  os_fct_000001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  ptr4 = layout->argv[iNextArgv(layout, 4)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal000010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000010_t)();
  os_fct_000010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal000011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000011_t)();
  os_fct_000011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal000100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000100_t)();
  os_fct_000100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  ptr5 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal000101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000101_t)();
  os_fct_000101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal000110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000110_t)();
  os_fct_000110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal000111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_000111_t)();
  os_fct_000111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal001000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001000_t)();
  os_fct_001000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  ptr5 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal001001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001001_t)();
  os_fct_001001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 2)];
  ptr4 = layout->argv[iNextArgv(layout, 3)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal001010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001010_t)();
  os_fct_001010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal001011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001011_t)();
  os_fct_001011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal001100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001100_t)();
  os_fct_001100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal001101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001101_t)();
  os_fct_001101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal001110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001110_t)();
  os_fct_001110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal001111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001111_t)();
  os_fct_001111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal010000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010000_t)();
  os_fct_010000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  ptr5 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal010001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010001_t)();
  os_fct_010001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal010010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010010_t)();
  os_fct_010010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal010011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010011_t)();
  os_fct_010011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal010100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010100_t)();
  os_fct_010100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal010101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010101_t)();
  os_fct_010101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal010110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010110_t)();
  os_fct_010110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal010111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_010111_t)();
  os_fct_010111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal011000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011000_t)();
  os_fct_011000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal011001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011001_t)();
  os_fct_011001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal011010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011010_t)();
  os_fct_011010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal011011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011011_t)();
  os_fct_011011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal011100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011100_t)();
  os_fct_011100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal011101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011101_t)();
  os_fct_011101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal011110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011110_t)();
  os_fct_011110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal011111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_011111_t)();
  os_fct_011111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal100000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100000_t)();
  os_fct_100000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  ptr5 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal100001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100001_t)();
  os_fct_100001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal100010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100010_t)();
  os_fct_100010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal100011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100011_t)();
  os_fct_100011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal100100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100100_t)();
  os_fct_100100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal100101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100101_t)();
  os_fct_100101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal100110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100110_t)();
  os_fct_100110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal100111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_100111_t)();
  os_fct_100111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal101000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101000_t)();
  os_fct_101000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal101001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101001_t)();
  os_fct_101001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 1)];
  ptr4 = layout->argv[iNextArgv(layout, 2)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal101010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101010_t)();
  os_fct_101010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal101011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101011_t)();
  os_fct_101011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal101100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101100_t)();
  os_fct_101100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal101101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101101_t)();
  os_fct_101101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal101110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101110_t)();
  os_fct_101110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal101111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_101111_t)();
  os_fct_101111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal110000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110000_t)();
  os_fct_110000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  ptr5 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal110001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110001_t)();
  os_fct_110001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal110010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110010_t)();
  os_fct_110010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal110011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110011_t)();
  os_fct_110011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal110100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110100_t)();
  os_fct_110100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal110101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110101_t)();
  os_fct_110101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal110110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110110_t)();
  os_fct_110110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal110111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_110111_t)();
  os_fct_110111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal111000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111000_t)();
  os_fct_111000_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 0)];
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  ptr5 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal111001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111001_t)();
  os_fct_111001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
  val10t2 = (fool10_t *) val1t2;
  val11t2 = (fool11_t *) val1t2;
  val12t2 = (fool12_t *) val1t2;
  val13t2 = (fool13_t *) val1t2;
  val14t2 = (fool14_t *) val1t2;
  val15t2 = (fool15_t *) val1t2;
  val16t2 = (fool16_t *) val1t2;
  ptr3 = layout->argv[iNextArgv(layout, 0)];
  ptr4 = layout->argv[iNextArgv(layout, 1)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal111010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111010_t)();
  os_fct_111010_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal111011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111011_t)();
  os_fct_111011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByVal111100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111100_t)();
  os_fct_111100_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 0)];
  ptr5 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4, ptr5
    );
  }
}

bighole_t iCallFctByVal111101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111101_t)();
  os_fct_111101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
  val10t3 = (fool10_t *) val1t3;
  val11t3 = (fool11_t *) val1t3;
  val12t3 = (fool12_t *) val1t3;
  val13t3 = (fool13_t *) val1t3;
  val14t3 = (fool14_t *) val1t3;
  val15t3 = (fool15_t *) val1t3;
  val16t3 = (fool16_t *) val1t3;
  ptr4 = layout->argv[iNextArgv(layout, 0)];
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4, *val16t5
    );
  }
}

bighole_t iCallFctByVal111110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111110_t)();
  os_fct_111110_t *os_fct_ptr = NULL;
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
  char * ptr5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  ptr5 = layout->argv[iNextArgv(layout, 0)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4, ptr5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4, ptr5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4, ptr5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4, ptr5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4, ptr5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4, ptr5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4, ptr5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4, ptr5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4, ptr5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4, ptr5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4, ptr5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4, ptr5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4, ptr5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4, ptr5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4, ptr5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4, ptr5
    );
  }
}

bighole_t iCallFctByVal111111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_111111_t)();
  os_fct_111111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t5 = NULL;
  fool15_t * val15t5 = NULL;
  fool14_t * val14t5 = NULL;
  fool13_t * val13t5 = NULL;
  fool12_t * val12t5 = NULL;
  fool11_t * val11t5 = NULL;
  fool10_t * val10t5 = NULL;
  fool9_t * val9t5 = NULL;
  fool8_t * val8t5 = NULL;
  fool7_t * val7t5 = NULL;
  fool6_t * val6t5 = NULL;
  fool5_t * val5t5 = NULL;
  fool4_t * val4t5 = NULL;
  fool3_t * val3t5 = NULL;
  fool2_t * val2t5 = NULL;
  fool1_t * val1t5 = NULL;
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
  val9t0  = (fool9_t *) val1t0;
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
  val9t1  = (fool9_t *) val1t1;
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
  val9t2  = (fool9_t *) val1t2;
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
  val9t3  = (fool9_t *) val1t3;
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
  val9t4  = (fool9_t *) val1t4;
  val10t4 = (fool10_t *) val1t4;
  val11t4 = (fool11_t *) val1t4;
  val12t4 = (fool12_t *) val1t4;
  val13t4 = (fool13_t *) val1t4;
  val14t4 = (fool14_t *) val1t4;
  val15t4 = (fool15_t *) val1t4;
  val16t4 = (fool16_t *) val1t4;
  one_len = layout->arg_len[5];
  val1t5  = (fool1_t *) ((char *)layout + layout->arg_pos[5]);
  val2t5  = (fool2_t *) val1t5;
  val3t5  = (fool3_t *) val1t5;
  val4t5  = (fool4_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val5t5  = (fool5_t *) val1t5;
  val6t5  = (fool6_t *) val1t5;
  val7t5  = (fool7_t *) val1t5;
  val8t5  = (fool8_t *) val1t5;
  val9t5  = (fool9_t *) val1t5;
  val10t5 = (fool10_t *) val1t5;
  val11t5 = (fool11_t *) val1t5;
  val12t5 = (fool12_t *) val1t5;
  val13t5 = (fool13_t *) val1t5;
  val14t5 = (fool14_t *) val1t5;
  val15t5 = (fool15_t *) val1t5;
  val16t5 = (fool16_t *) val1t5;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4, *val1t5
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4, *val2t5
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4, *val3t5
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4, *val4t5
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4, *val5t5
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4, *val6t5
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4, *val7t5
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4, *val8t5
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4, *val9t5
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4, *val10t5
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4, *val11t5
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4, *val12t5
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4, *val13t5
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4, *val14t5
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4, *val15t5
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4, *val16t5
    );
  }
}

bighole_t iCallFctByValSub6(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"000000")) {
    return iCallFctByVal000000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000001")) {
    return iCallFctByVal000001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000010")) {
    return iCallFctByVal000010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000011")) {
    return iCallFctByVal000011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000100")) {
    return iCallFctByVal000100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000101")) {
    return iCallFctByVal000101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000110")) {
    return iCallFctByVal000110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"000111")) {
    return iCallFctByVal000111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001000")) {
    return iCallFctByVal001000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001001")) {
    return iCallFctByVal001001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001010")) {
    return iCallFctByVal001010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001011")) {
    return iCallFctByVal001011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001100")) {
    return iCallFctByVal001100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001101")) {
    return iCallFctByVal001101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001110")) {
    return iCallFctByVal001110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"001111")) {
    return iCallFctByVal001111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010000")) {
    return iCallFctByVal010000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010001")) {
    return iCallFctByVal010001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010010")) {
    return iCallFctByVal010010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010011")) {
    return iCallFctByVal010011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010100")) {
    return iCallFctByVal010100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010101")) {
    return iCallFctByVal010101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010110")) {
    return iCallFctByVal010110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"010111")) {
    return iCallFctByVal010111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011000")) {
    return iCallFctByVal011000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011001")) {
    return iCallFctByVal011001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011010")) {
    return iCallFctByVal011010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011011")) {
    return iCallFctByVal011011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011100")) {
    return iCallFctByVal011100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011101")) {
    return iCallFctByVal011101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011110")) {
    return iCallFctByVal011110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"011111")) {
    return iCallFctByVal011111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100000")) {
    return iCallFctByVal100000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100001")) {
    return iCallFctByVal100001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100010")) {
    return iCallFctByVal100010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100011")) {
    return iCallFctByVal100011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100100")) {
    return iCallFctByVal100100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100101")) {
    return iCallFctByVal100101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100110")) {
    return iCallFctByVal100110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"100111")) {
    return iCallFctByVal100111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101000")) {
    return iCallFctByVal101000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101001")) {
    return iCallFctByVal101001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101010")) {
    return iCallFctByVal101010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101011")) {
    return iCallFctByVal101011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101100")) {
    return iCallFctByVal101100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101101")) {
    return iCallFctByVal101101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101110")) {
    return iCallFctByVal101110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"101111")) {
    return iCallFctByVal101111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110000")) {
    return iCallFctByVal110000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110001")) {
    return iCallFctByVal110001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110010")) {
    return iCallFctByVal110010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110011")) {
    return iCallFctByVal110011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110100")) {
    return iCallFctByVal110100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110101")) {
    return iCallFctByVal110101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110110")) {
    return iCallFctByVal110110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"110111")) {
    return iCallFctByVal110111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111000")) {
    return iCallFctByVal111000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111001")) {
    return iCallFctByVal111001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111010")) {
    return iCallFctByVal111010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111011")) {
    return iCallFctByVal111011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111100")) {
    return iCallFctByVal111100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111101")) {
    return iCallFctByVal111101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111110")) {
    return iCallFctByVal111110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"111111")) {
    return iCallFctByVal111111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
