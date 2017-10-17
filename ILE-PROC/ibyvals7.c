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

bighole_t iCallFctByVal0000000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000000_t)();
  os_fct_0000000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  ptr4 = layout->argv[iNextArgv(layout, 4)];
  ptr5 = layout->argv[iNextArgv(layout, 5)];
  ptr6 = layout->argv[iNextArgv(layout, 6)];
  return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
}

bighole_t iCallFctByVal0000001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000001_t)();
  os_fct_0000001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  ptr4 = layout->argv[iNextArgv(layout, 4)];
  ptr5 = layout->argv[iNextArgv(layout, 5)];
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0000010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000010_t)();
  os_fct_0000010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 5)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0000011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000011_t)();
  os_fct_0000011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0000100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000100_t)();
  os_fct_0000100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 5)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0000101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000101_t)();
  os_fct_0000101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0000110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000110_t)();
  os_fct_0000110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0000111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000111_t)();
  os_fct_0000111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0001000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001000_t)();
  os_fct_0001000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 5)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0001001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001001_t)();
  os_fct_0001001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0001010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001010_t)();
  os_fct_0001010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0001011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001011_t)();
  os_fct_0001011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0001100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001100_t)();
  os_fct_0001100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0001101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001101_t)();
  os_fct_0001101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0001110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001110_t)();
  os_fct_0001110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0001111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001111_t)();
  os_fct_0001111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0010000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010000_t)();
  os_fct_0010000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 5)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0010001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010001_t)();
  os_fct_0010001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0010010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010010_t)();
  os_fct_0010010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0010011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010011_t)();
  os_fct_0010011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0010100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010100_t)();
  os_fct_0010100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0010101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010101_t)();
  os_fct_0010101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0010110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010110_t)();
  os_fct_0010110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0010111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010111_t)();
  os_fct_0010111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0011000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011000_t)();
  os_fct_0011000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0011001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011001_t)();
  os_fct_0011001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0011010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011010_t)();
  os_fct_0011010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0011011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011011_t)();
  os_fct_0011011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0011100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011100_t)();
  os_fct_0011100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0011101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011101_t)();
  os_fct_0011101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0011110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011110_t)();
  os_fct_0011110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0011111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011111_t)();
  os_fct_0011111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0100000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100000_t)();
  os_fct_0100000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 5)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0100001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100001_t)();
  os_fct_0100001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0100010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100010_t)();
  os_fct_0100010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0100011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100011_t)();
  os_fct_0100011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0100100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100100_t)();
  os_fct_0100100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0100101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100101_t)();
  os_fct_0100101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0100110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100110_t)();
  os_fct_0100110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0100111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100111_t)();
  os_fct_0100111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0101000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101000_t)();
  os_fct_0101000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0101001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101001_t)();
  os_fct_0101001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0101010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101010_t)();
  os_fct_0101010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0101011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101011_t)();
  os_fct_0101011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0101100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101100_t)();
  os_fct_0101100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0101101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101101_t)();
  os_fct_0101101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0101110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101110_t)();
  os_fct_0101110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0101111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101111_t)();
  os_fct_0101111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0110000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110000_t)();
  os_fct_0110000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0110001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110001_t)();
  os_fct_0110001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0110010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110010_t)();
  os_fct_0110010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0110011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110011_t)();
  os_fct_0110011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0110100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110100_t)();
  os_fct_0110100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0110101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110101_t)();
  os_fct_0110101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0110110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110110_t)();
  os_fct_0110110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0110111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110111_t)();
  os_fct_0110111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0111000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111000_t)();
  os_fct_0111000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0111001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111001_t)();
  os_fct_0111001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0111010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111010_t)();
  os_fct_0111010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0111011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111011_t)();
  os_fct_0111011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0111100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111100_t)();
  os_fct_0111100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal0111101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111101_t)();
  os_fct_0111101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal0111110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111110_t)();
  os_fct_0111110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal0111111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111111_t)();
  os_fct_0111111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1000000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000000_t)();
  os_fct_1000000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 5)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1000001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000001_t)();
  os_fct_1000001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1000010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000010_t)();
  os_fct_1000010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1000011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000011_t)();
  os_fct_1000011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1000100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000100_t)();
  os_fct_1000100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1000101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000101_t)();
  os_fct_1000101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1000110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000110_t)();
  os_fct_1000110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1000111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000111_t)();
  os_fct_1000111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1001000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001000_t)();
  os_fct_1001000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1001001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001001_t)();
  os_fct_1001001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1001010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001010_t)();
  os_fct_1001010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1001011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001011_t)();
  os_fct_1001011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1001100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001100_t)();
  os_fct_1001100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1001101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001101_t)();
  os_fct_1001101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1001110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001110_t)();
  os_fct_1001110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1001111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001111_t)();
  os_fct_1001111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1010000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010000_t)();
  os_fct_1010000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1010001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010001_t)();
  os_fct_1010001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1010010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010010_t)();
  os_fct_1010010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1010011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010011_t)();
  os_fct_1010011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1010100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010100_t)();
  os_fct_1010100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1010101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010101_t)();
  os_fct_1010101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1010110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010110_t)();
  os_fct_1010110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1010111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010111_t)();
  os_fct_1010111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1011000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011000_t)();
  os_fct_1011000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1011001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011001_t)();
  os_fct_1011001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1011010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011010_t)();
  os_fct_1011010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1011011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011011_t)();
  os_fct_1011011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1011100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011100_t)();
  os_fct_1011100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1011101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011101_t)();
  os_fct_1011101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1011110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011110_t)();
  os_fct_1011110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1011111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011111_t)();
  os_fct_1011111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1100000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100000_t)();
  os_fct_1100000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 4)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1100001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100001_t)();
  os_fct_1100001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1100010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100010_t)();
  os_fct_1100010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1100011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100011_t)();
  os_fct_1100011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1100100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100100_t)();
  os_fct_1100100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1100101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100101_t)();
  os_fct_1100101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1100110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100110_t)();
  os_fct_1100110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1100111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100111_t)();
  os_fct_1100111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1101000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101000_t)();
  os_fct_1101000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1101001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101001_t)();
  os_fct_1101001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1101010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101010_t)();
  os_fct_1101010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1101011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101011_t)();
  os_fct_1101011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1101100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101100_t)();
  os_fct_1101100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1101101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101101_t)();
  os_fct_1101101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1101110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101110_t)();
  os_fct_1101110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1101111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101111_t)();
  os_fct_1101111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1110000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110000_t)();
  os_fct_1110000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 3)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1110001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110001_t)();
  os_fct_1110001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1110010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110010_t)();
  os_fct_1110010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1110011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110011_t)();
  os_fct_1110011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1110100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110100_t)();
  os_fct_1110100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1110101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110101_t)();
  os_fct_1110101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1110110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110110_t)();
  os_fct_1110110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1110111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110111_t)();
  os_fct_1110111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1111000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111000_t)();
  os_fct_1111000_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 2)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1111001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111001_t)();
  os_fct_1111001_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1111010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111010_t)();
  os_fct_1111010_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1111011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111011_t)();
  os_fct_1111011_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, ptr4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, ptr4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, ptr4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, ptr4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, ptr4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, ptr4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, ptr4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, ptr4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, ptr4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, ptr4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, ptr4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, ptr4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, ptr4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, ptr4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, ptr4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, ptr4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1111100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111100_t)();
  os_fct_1111100_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 1)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4, ptr5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4, ptr5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4, ptr5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4, ptr5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4, ptr5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4, ptr5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4, ptr5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4, ptr5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4, ptr5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4, ptr5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4, ptr5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4, ptr5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4, ptr5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4, ptr5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4, ptr5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4, ptr5, ptr6
    );
  }
}

bighole_t iCallFctByVal1111101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111101_t)();
  os_fct_1111101_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4, ptr5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4, ptr5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4, ptr5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4, ptr5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4, ptr5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4, ptr5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4, ptr5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4, ptr5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4, ptr5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4, ptr5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4, ptr5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4, ptr5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4, ptr5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4, ptr5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4, ptr5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4, ptr5, *val16t6
    );
  }
}

bighole_t iCallFctByVal1111110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111110_t)();
  os_fct_1111110_t *os_fct_ptr = NULL;
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
  char * ptr6 = NULL;
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
  ptr6 = layout->argv[iNextArgv(layout, 0)];
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4, *val1t5, ptr6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4, *val2t5, ptr6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4, *val3t5, ptr6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4, *val4t5, ptr6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4, *val5t5, ptr6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4, *val6t5, ptr6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4, *val7t5, ptr6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4, *val8t5, ptr6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4, *val9t5, ptr6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4, *val10t5, ptr6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4, *val11t5, ptr6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4, *val12t5, ptr6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4, *val13t5, ptr6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4, *val14t5, ptr6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4, *val15t5, ptr6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4, *val16t5, ptr6
    );
  }
}

bighole_t iCallFctByVal1111111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111111_t)();
  os_fct_1111111_t *os_fct_ptr = NULL;
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
  fool16_t * val16t6 = NULL;
  fool15_t * val15t6 = NULL;
  fool14_t * val14t6 = NULL;
  fool13_t * val13t6 = NULL;
  fool12_t * val12t6 = NULL;
  fool11_t * val11t6 = NULL;
  fool10_t * val10t6 = NULL;
  fool9_t * val9t6 = NULL;
  fool8_t * val8t6 = NULL;
  fool7_t * val7t6 = NULL;
  fool6_t * val6t6 = NULL;
  fool5_t * val5t6 = NULL;
  fool4_t * val4t6 = NULL;
  fool3_t * val3t6 = NULL;
  fool2_t * val2t6 = NULL;
  fool1_t * val1t6 = NULL;
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
  one_len = layout->arg_len[6];
  val1t6  = (fool1_t *) ((char *)layout + layout->arg_pos[6]);
  val2t6  = (fool2_t *) val1t6;
  val3t6  = (fool3_t *) val1t6;
  val4t6  = (fool4_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val5t6  = (fool5_t *) val1t6;
  val6t6  = (fool6_t *) val1t6;
  val7t6  = (fool7_t *) val1t6;
  val8t6  = (fool8_t *) val1t6;
  val9t6  = (fool9_t *) val1t6;
  val10t6 = (fool10_t *) val1t6;
  val11t6 = (fool11_t *) val1t6;
  val12t6 = (fool12_t *) val1t6;
  val13t6 = (fool13_t *) val1t6;
  val14t6 = (fool14_t *) val1t6;
  val15t6 = (fool15_t *) val1t6;
  val16t6 = (fool16_t *) val1t6;
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3, *val1t4, *val1t5, *val1t6
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3, *val2t4, *val2t5, *val2t6
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3, *val3t4, *val3t5, *val3t6
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3, *val4t4, *val4t5, *val4t6
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3, *val5t4, *val5t5, *val5t6
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3, *val6t4, *val6t5, *val6t6
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3, *val7t4, *val7t5, *val7t6
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3, *val8t4, *val8t5, *val8t6
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3, *val9t4, *val9t5, *val9t6
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3, *val10t4, *val10t5, *val10t6
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3, *val11t4, *val11t5, *val11t6
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3, *val12t4, *val12t5, *val12t6
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3, *val13t4, *val13t5, *val13t6
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3, *val14t4, *val14t5, *val14t6
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3, *val15t4, *val15t5, *val15t6
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3, *val16t4, *val16t5, *val16t6
    );
  }
}

bighole_t iCallFctByValSub7(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"0000000")) {
    return iCallFctByVal0000000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000001")) {
    return iCallFctByVal0000001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000010")) {
    return iCallFctByVal0000010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000011")) {
    return iCallFctByVal0000011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000100")) {
    return iCallFctByVal0000100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000101")) {
    return iCallFctByVal0000101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000110")) {
    return iCallFctByVal0000110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0000111")) {
    return iCallFctByVal0000111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001000")) {
    return iCallFctByVal0001000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001001")) {
    return iCallFctByVal0001001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001010")) {
    return iCallFctByVal0001010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001011")) {
    return iCallFctByVal0001011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001100")) {
    return iCallFctByVal0001100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001101")) {
    return iCallFctByVal0001101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001110")) {
    return iCallFctByVal0001110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001111")) {
    return iCallFctByVal0001111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010000")) {
    return iCallFctByVal0010000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010001")) {
    return iCallFctByVal0010001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010010")) {
    return iCallFctByVal0010010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010011")) {
    return iCallFctByVal0010011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010100")) {
    return iCallFctByVal0010100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010101")) {
    return iCallFctByVal0010101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010110")) {
    return iCallFctByVal0010110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010111")) {
    return iCallFctByVal0010111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011000")) {
    return iCallFctByVal0011000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011001")) {
    return iCallFctByVal0011001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011010")) {
    return iCallFctByVal0011010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011011")) {
    return iCallFctByVal0011011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011100")) {
    return iCallFctByVal0011100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011101")) {
    return iCallFctByVal0011101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011110")) {
    return iCallFctByVal0011110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011111")) {
    return iCallFctByVal0011111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100000")) {
    return iCallFctByVal0100000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100001")) {
    return iCallFctByVal0100001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100010")) {
    return iCallFctByVal0100010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100011")) {
    return iCallFctByVal0100011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100100")) {
    return iCallFctByVal0100100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100101")) {
    return iCallFctByVal0100101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100110")) {
    return iCallFctByVal0100110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100111")) {
    return iCallFctByVal0100111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101000")) {
    return iCallFctByVal0101000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101001")) {
    return iCallFctByVal0101001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101010")) {
    return iCallFctByVal0101010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101011")) {
    return iCallFctByVal0101011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101100")) {
    return iCallFctByVal0101100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101101")) {
    return iCallFctByVal0101101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101110")) {
    return iCallFctByVal0101110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101111")) {
    return iCallFctByVal0101111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110000")) {
    return iCallFctByVal0110000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110001")) {
    return iCallFctByVal0110001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110010")) {
    return iCallFctByVal0110010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110011")) {
    return iCallFctByVal0110011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110100")) {
    return iCallFctByVal0110100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110101")) {
    return iCallFctByVal0110101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110110")) {
    return iCallFctByVal0110110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110111")) {
    return iCallFctByVal0110111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111000")) {
    return iCallFctByVal0111000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111001")) {
    return iCallFctByVal0111001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111010")) {
    return iCallFctByVal0111010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111011")) {
    return iCallFctByVal0111011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111100")) {
    return iCallFctByVal0111100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111101")) {
    return iCallFctByVal0111101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111110")) {
    return iCallFctByVal0111110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111111")) {
    return iCallFctByVal0111111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000000")) {
    return iCallFctByVal1000000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000001")) {
    return iCallFctByVal1000001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000010")) {
    return iCallFctByVal1000010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000011")) {
    return iCallFctByVal1000011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000100")) {
    return iCallFctByVal1000100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000101")) {
    return iCallFctByVal1000101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000110")) {
    return iCallFctByVal1000110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000111")) {
    return iCallFctByVal1000111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001000")) {
    return iCallFctByVal1001000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001001")) {
    return iCallFctByVal1001001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001010")) {
    return iCallFctByVal1001010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001011")) {
    return iCallFctByVal1001011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001100")) {
    return iCallFctByVal1001100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001101")) {
    return iCallFctByVal1001101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001110")) {
    return iCallFctByVal1001110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001111")) {
    return iCallFctByVal1001111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010000")) {
    return iCallFctByVal1010000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010001")) {
    return iCallFctByVal1010001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010010")) {
    return iCallFctByVal1010010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010011")) {
    return iCallFctByVal1010011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010100")) {
    return iCallFctByVal1010100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010101")) {
    return iCallFctByVal1010101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010110")) {
    return iCallFctByVal1010110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010111")) {
    return iCallFctByVal1010111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011000")) {
    return iCallFctByVal1011000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011001")) {
    return iCallFctByVal1011001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011010")) {
    return iCallFctByVal1011010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011011")) {
    return iCallFctByVal1011011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011100")) {
    return iCallFctByVal1011100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011101")) {
    return iCallFctByVal1011101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011110")) {
    return iCallFctByVal1011110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011111")) {
    return iCallFctByVal1011111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100000")) {
    return iCallFctByVal1100000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100001")) {
    return iCallFctByVal1100001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100010")) {
    return iCallFctByVal1100010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100011")) {
    return iCallFctByVal1100011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100100")) {
    return iCallFctByVal1100100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100101")) {
    return iCallFctByVal1100101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100110")) {
    return iCallFctByVal1100110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100111")) {
    return iCallFctByVal1100111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101000")) {
    return iCallFctByVal1101000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101001")) {
    return iCallFctByVal1101001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101010")) {
    return iCallFctByVal1101010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101011")) {
    return iCallFctByVal1101011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101100")) {
    return iCallFctByVal1101100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101101")) {
    return iCallFctByVal1101101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101110")) {
    return iCallFctByVal1101110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101111")) {
    return iCallFctByVal1101111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110000")) {
    return iCallFctByVal1110000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110001")) {
    return iCallFctByVal1110001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110010")) {
    return iCallFctByVal1110010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110011")) {
    return iCallFctByVal1110011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110100")) {
    return iCallFctByVal1110100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110101")) {
    return iCallFctByVal1110101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110110")) {
    return iCallFctByVal1110110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110111")) {
    return iCallFctByVal1110111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111000")) {
    return iCallFctByVal1111000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111001")) {
    return iCallFctByVal1111001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111010")) {
    return iCallFctByVal1111010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111011")) {
    return iCallFctByVal1111011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111100")) {
    return iCallFctByVal1111100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111101")) {
    return iCallFctByVal1111101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111110")) {
    return iCallFctByVal1111110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111111")) {
    return iCallFctByVal1111111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
