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

bighole_t iCallFctByVal0000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0000_t)();
  os_fct_0000_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  int argc = 0;
  int one_len = 0; /* all value elements must be same size (yuck) */
  char * ptr0 = NULL;
  char * ptr1 = NULL;
  char * ptr2 = NULL;
  char * ptr3 = NULL;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  ptr0 = layout->argv[iNextArgv(layout, 0)];
  ptr1 = layout->argv[iNextArgv(layout, 1)];
  ptr2 = layout->argv[iNextArgv(layout, 2)];
  ptr3 = layout->argv[iNextArgv(layout, 3)];
  return os_fct_ptr(
    ptr0, ptr1, ptr2, ptr3
    );
}

bighole_t iCallFctByVal0001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0001_t)();
  os_fct_0001_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val1t3
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val2t3
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val3t3
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val4t3
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val5t3
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val6t3
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val7t3
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val8t3
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val9t3
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val10t3
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val11t3
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val12t3
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val13t3
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val14t3
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val15t3
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, ptr2, *val16t3
    );
  }
}

bighole_t iCallFctByVal0010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0010_t)();
  os_fct_0010_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, ptr3
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, ptr3
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, ptr3
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, ptr3
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, ptr3
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, ptr3
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, ptr3
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, ptr3
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, ptr3
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, ptr3
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, ptr3
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, ptr3
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, ptr3
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, ptr3
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, ptr3
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, ptr3
    );
  }
}

bighole_t iCallFctByVal0011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0011_t)();
  os_fct_0011_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, ptr1, *val1t2, *val1t3
    );
  case 2: return os_fct_ptr(
    ptr0, ptr1, *val2t2, *val2t3
    );
  case 3: return os_fct_ptr(
    ptr0, ptr1, *val3t2, *val3t3
    );
  case 4: return os_fct_ptr(
    ptr0, ptr1, *val4t2, *val4t3
    );
  case 5: return os_fct_ptr(
    ptr0, ptr1, *val5t2, *val5t3
    );
  case 6: return os_fct_ptr(
    ptr0, ptr1, *val6t2, *val6t3
    );
  case 7: return os_fct_ptr(
    ptr0, ptr1, *val7t2, *val7t3
    );
  case 8: return os_fct_ptr(
    ptr0, ptr1, *val8t2, *val8t3
    );
  case 9: return os_fct_ptr(
    ptr0, ptr1, *val9t2, *val9t3
    );
  case 10: return os_fct_ptr(
    ptr0, ptr1, *val10t2, *val10t3
    );
  case 11: return os_fct_ptr(
    ptr0, ptr1, *val11t2, *val11t3
    );
  case 12: return os_fct_ptr(
    ptr0, ptr1, *val12t2, *val12t3
    );
  case 13: return os_fct_ptr(
    ptr0, ptr1, *val13t2, *val13t3
    );
  case 14: return os_fct_ptr(
    ptr0, ptr1, *val14t2, *val14t3
    );
  case 15: return os_fct_ptr(
    ptr0, ptr1, *val15t2, *val15t3
    );
  case 16: return os_fct_ptr(
    ptr0, ptr1, *val16t2, *val16t3
    );
  }
}

bighole_t iCallFctByVal0100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0100_t)();
  os_fct_0100_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, ptr3
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, ptr3
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, ptr3
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, ptr3
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, ptr3
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, ptr3
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, ptr3
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, ptr3
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, ptr3
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, ptr3
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, ptr3
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, ptr3
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, ptr3
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, ptr3
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, ptr3
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, ptr3
    );
  }
}

bighole_t iCallFctByVal0101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0101_t)();
  os_fct_0101_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, ptr2, *val1t3
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, ptr2, *val2t3
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, ptr2, *val3t3
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, ptr2, *val4t3
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, ptr2, *val5t3
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, ptr2, *val6t3
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, ptr2, *val7t3
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, ptr2, *val8t3
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, ptr2, *val9t3
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, ptr2, *val10t3
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, ptr2, *val11t3
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, ptr2, *val12t3
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, ptr2, *val13t3
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, ptr2, *val14t3
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, ptr2, *val15t3
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, ptr2, *val16t3
    );
  }
}

bighole_t iCallFctByVal0110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0110_t)();
  os_fct_0110_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, ptr3
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, ptr3
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, ptr3
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, ptr3
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, ptr3
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, ptr3
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, ptr3
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, ptr3
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, ptr3
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, ptr3
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, ptr3
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, ptr3
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, ptr3
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, ptr3
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, ptr3
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, ptr3
    );
  }
}

bighole_t iCallFctByVal0111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_0111_t)();
  os_fct_0111_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    ptr0, *val1t1, *val1t2, *val1t3
    );
  case 2: return os_fct_ptr(
    ptr0, *val2t1, *val2t2, *val2t3
    );
  case 3: return os_fct_ptr(
    ptr0, *val3t1, *val3t2, *val3t3
    );
  case 4: return os_fct_ptr(
    ptr0, *val4t1, *val4t2, *val4t3
    );
  case 5: return os_fct_ptr(
    ptr0, *val5t1, *val5t2, *val5t3
    );
  case 6: return os_fct_ptr(
    ptr0, *val6t1, *val6t2, *val6t3
    );
  case 7: return os_fct_ptr(
    ptr0, *val7t1, *val7t2, *val7t3
    );
  case 8: return os_fct_ptr(
    ptr0, *val8t1, *val8t2, *val8t3
    );
  case 9: return os_fct_ptr(
    ptr0, *val9t1, *val9t2, *val9t3
    );
  case 10: return os_fct_ptr(
    ptr0, *val10t1, *val10t2, *val10t3
    );
  case 11: return os_fct_ptr(
    ptr0, *val11t1, *val11t2, *val11t3
    );
  case 12: return os_fct_ptr(
    ptr0, *val12t1, *val12t2, *val12t3
    );
  case 13: return os_fct_ptr(
    ptr0, *val13t1, *val13t2, *val13t3
    );
  case 14: return os_fct_ptr(
    ptr0, *val14t1, *val14t2, *val14t3
    );
  case 15: return os_fct_ptr(
    ptr0, *val15t1, *val15t2, *val15t3
    );
  case 16: return os_fct_ptr(
    ptr0, *val16t1, *val16t2, *val16t3
    );
  }
}

bighole_t iCallFctByVal1000(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1000_t)();
  os_fct_1000_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, ptr3
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, ptr3
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, ptr3
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, ptr3
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, ptr3
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, ptr3
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, ptr3
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, ptr3
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, ptr3
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, ptr3
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, ptr3
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, ptr3
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, ptr3
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, ptr3
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, ptr3
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, ptr3
    );
  }
}

bighole_t iCallFctByVal1001(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1001_t)();
  os_fct_1001_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, ptr2, *val1t3
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, ptr2, *val2t3
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, ptr2, *val3t3
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, ptr2, *val4t3
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, ptr2, *val5t3
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, ptr2, *val6t3
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, ptr2, *val7t3
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, ptr2, *val8t3
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, ptr2, *val9t3
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, ptr2, *val10t3
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, ptr2, *val11t3
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, ptr2, *val12t3
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, ptr2, *val13t3
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, ptr2, *val14t3
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, ptr2, *val15t3
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, ptr2, *val16t3
    );
  }
}

bighole_t iCallFctByVal1010(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1010_t)();
  os_fct_1010_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, ptr3
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, ptr3
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, ptr3
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, ptr3
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, ptr3
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, ptr3
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, ptr3
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, ptr3
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, ptr3
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, ptr3
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, ptr3
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, ptr3
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, ptr3
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, ptr3
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, ptr3
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, ptr3
    );
  }
}

bighole_t iCallFctByVal1011(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1011_t)();
  os_fct_1011_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, ptr1, *val1t2, *val1t3
    );
  case 2: return os_fct_ptr(
    *val2t0, ptr1, *val2t2, *val2t3
    );
  case 3: return os_fct_ptr(
    *val3t0, ptr1, *val3t2, *val3t3
    );
  case 4: return os_fct_ptr(
    *val4t0, ptr1, *val4t2, *val4t3
    );
  case 5: return os_fct_ptr(
    *val5t0, ptr1, *val5t2, *val5t3
    );
  case 6: return os_fct_ptr(
    *val6t0, ptr1, *val6t2, *val6t3
    );
  case 7: return os_fct_ptr(
    *val7t0, ptr1, *val7t2, *val7t3
    );
  case 8: return os_fct_ptr(
    *val8t0, ptr1, *val8t2, *val8t3
    );
  case 9: return os_fct_ptr(
    *val9t0, ptr1, *val9t2, *val9t3
    );
  case 10: return os_fct_ptr(
    *val10t0, ptr1, *val10t2, *val10t3
    );
  case 11: return os_fct_ptr(
    *val11t0, ptr1, *val11t2, *val11t3
    );
  case 12: return os_fct_ptr(
    *val12t0, ptr1, *val12t2, *val12t3
    );
  case 13: return os_fct_ptr(
    *val13t0, ptr1, *val13t2, *val13t3
    );
  case 14: return os_fct_ptr(
    *val14t0, ptr1, *val14t2, *val14t3
    );
  case 15: return os_fct_ptr(
    *val15t0, ptr1, *val15t2, *val15t3
    );
  case 16: return os_fct_ptr(
    *val16t0, ptr1, *val16t2, *val16t3
    );
  }
}

bighole_t iCallFctByVal1100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1100_t)();
  os_fct_1100_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, ptr3
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, ptr3
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, ptr3
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, ptr3
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, ptr3
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, ptr3
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, ptr3
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, ptr3
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, ptr3
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, ptr3
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, ptr3
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, ptr3
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, ptr3
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, ptr3
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, ptr3
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, ptr3
    );
  }
}

bighole_t iCallFctByVal1101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1101_t)();
  os_fct_1101_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, ptr2, *val1t3
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, ptr2, *val2t3
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, ptr2, *val3t3
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, ptr2, *val4t3
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, ptr2, *val5t3
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, ptr2, *val6t3
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, ptr2, *val7t3
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, ptr2, *val8t3
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, ptr2, *val9t3
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, ptr2, *val10t3
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, ptr2, *val11t3
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, ptr2, *val12t3
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, ptr2, *val13t3
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, ptr2, *val14t3
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, ptr2, *val15t3
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, ptr2, *val16t3
    );
  }
}

bighole_t iCallFctByVal1110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1110_t)();
  os_fct_1110_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, ptr3
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, ptr3
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, ptr3
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, ptr3
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, ptr3
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, ptr3
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, ptr3
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, ptr3
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, ptr3
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, ptr3
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, ptr3
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, ptr3
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, ptr3
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, ptr3
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, ptr3
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, ptr3
    );
  }
}

bighole_t iCallFctByVal1111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_1111_t)();
  os_fct_1111_t *os_fct_ptr = NULL;
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
  switch(one_len) {
  case 1: return os_fct_ptr(
    *val1t0, *val1t1, *val1t2, *val1t3
    );
  case 2: return os_fct_ptr(
    *val2t0, *val2t1, *val2t2, *val2t3
    );
  case 3: return os_fct_ptr(
    *val3t0, *val3t1, *val3t2, *val3t3
    );
  case 4: return os_fct_ptr(
    *val4t0, *val4t1, *val4t2, *val4t3
    );
  case 5: return os_fct_ptr(
    *val5t0, *val5t1, *val5t2, *val5t3
    );
  case 6: return os_fct_ptr(
    *val6t0, *val6t1, *val6t2, *val6t3
    );
  case 7: return os_fct_ptr(
    *val7t0, *val7t1, *val7t2, *val7t3
    );
  case 8: return os_fct_ptr(
    *val8t0, *val8t1, *val8t2, *val8t3
    );
  case 9: return os_fct_ptr(
    *val9t0, *val9t1, *val9t2, *val9t3
    );
  case 10: return os_fct_ptr(
    *val10t0, *val10t1, *val10t2, *val10t3
    );
  case 11: return os_fct_ptr(
    *val11t0, *val11t1, *val11t2, *val11t3
    );
  case 12: return os_fct_ptr(
    *val12t0, *val12t1, *val12t2, *val12t3
    );
  case 13: return os_fct_ptr(
    *val13t0, *val13t1, *val13t2, *val13t3
    );
  case 14: return os_fct_ptr(
    *val14t0, *val14t1, *val14t2, *val14t3
    );
  case 15: return os_fct_ptr(
    *val15t0, *val15t1, *val15t2, *val15t3
    );
  case 16: return os_fct_ptr(
    *val16t0, *val16t1, *val16t2, *val16t3
    );
  }
}

bighole_t iCallFctByValSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)
{
  if (!strcmp(pattern,"0000")) {
    return iCallFctByVal0000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0001")) {
    return iCallFctByVal0001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0010")) {
    return iCallFctByVal0010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0011")) {
    return iCallFctByVal0011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0100")) {
    return iCallFctByVal0100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0101")) {
    return iCallFctByVal0101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0110")) {
    return iCallFctByVal0110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"0111")) {
    return iCallFctByVal0111(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1000")) {
    return iCallFctByVal1000(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1001")) {
    return iCallFctByVal1001(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1010")) {
    return iCallFctByVal1010(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1011")) {
    return iCallFctByVal1011(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1100")) {
    return iCallFctByVal1100(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1101")) {
    return iCallFctByVal1101(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1110")) {
    return iCallFctByVal1110(layout, myPgm, myLib, myFunc, lenFunc);
  }
  if (!strcmp(pattern,"1111")) {
    return iCallFctByVal1111(layout, myPgm, myLib, myFunc, lenFunc);
  }
}
