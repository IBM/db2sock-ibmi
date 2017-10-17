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
Sample of many different by value arguments with by ref output

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
  void *os_pfct_ptr = NULL;
  typedef bighole_t (os_fct_001_t)();
  os_fct_001_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  /* "9827G3873000000000" - pattern */
  fool9_t  * a1 = (fool9_t *) ((char *)layout + layout->arg_pos[0]);
  fool8_t  * a2 = (fool8_t *) ((char *)layout + layout->arg_pos[1]);
  fool2_t  * a3 = (fool2_t *) ((char *)layout + layout->arg_pos[2]);
  fool7_t  * a4 = (fool7_t *) ((char *)layout + layout->arg_pos[3]);
  fool16_t * a5 = (fool16_t *)((char *)layout + layout->arg_pos[4]);
  fool3_t  * a6 = (fool3_t *) ((char *)layout + layout->arg_pos[5]);
  fool8_t  * a7 = (fool8_t *) ((char *)layout + layout->arg_pos[6]);
  fool7_t  * a8 = (fool7_t *) ((char *)layout + layout->arg_pos[7]);
  fool3_t  * a9 = (fool3_t *) ((char *)layout + layout->arg_pos[8]);
  char * o1 = layout->argv[iNextArgv(layout, 0)];
  char * o2 = layout->argv[iNextArgv(layout, 1)];
  char * o3 = layout->argv[iNextArgv(layout, 2)];
  char * o4 = layout->argv[iNextArgv(layout, 3)];
  char * o5 = layout->argv[iNextArgv(layout, 4)];
  char * o6 = layout->argv[iNextArgv(layout, 5)];
  char * o7 = layout->argv[iNextArgv(layout, 6)];
  char * o8 = layout->argv[iNextArgv(layout, 7)];
  char * o9 = layout->argv[iNextArgv(layout, 8)];
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr(*a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8, *a9, o1, o2, o3, o4, o5, o6, o7, o8, o9);
}


bighole_t UserCallSrvPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern, int * isDone)
{
  // add your own custom iCallFctByValxxxxx pattern
  if (!strcmp(myPgm,"RAINSRV") && !strcmp(myFunc,"CRAZY9")) {
    return sample_crazy9(layout, myPgm, myLib, myFunc, lenFunc, pattern, isDone);
  }
  return;
}

void UserCallPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib, int * isDone)
{
  // add your own custom iCallPgmByRefxxxxx
  return;
}

