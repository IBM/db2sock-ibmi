#ifndef _I_BY_REF_H
#define _I_BY_REF_H
#include "../toolkit-base/PaseToIle.h"
#define ICALL_MAX_RETURN 2000000
typedef struct bighole_struct {
  char hole[ICALL_MAX_RETURN];
} bighole_t;
#pragma datamodel(p128)
typedef void (os_pgm_pattern_t)();
#pragma linkage(os_pgm_pattern_t,OS)
#pragma datamodel(pop)
void iCallPgmByRefSub1(ile_pgm_call_t* layout, char * myPgm, char * myLib);
void iCallPgmByRefSub2(ile_pgm_call_t* layout, char * myPgm, char * myLib);
void iCallPgmByRefSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib);
void iCallPgmByRefSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib);
void iCallPgmByRefSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib);
bighole_t iCallFctByRefSub1(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc);
bighole_t iCallFctByRefSub2(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc);
bighole_t iCallFctByRefSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc);
bighole_t iCallFctByRefSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc);
bighole_t iCallFctByRefSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc);
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
static char * iNextVal(ile_pgm_call_t* layout, int argc)
{
  return (char *)layout + layout->arg_pos[argc];
}
static char * iNextPtr(ile_pgm_call_t* layout, int argc)
{
  int i = 0;
  for (i=0; i < ILE_PGM_MAX_ARGS; i++) {
    if (layout->argv_parm[i] == argc) {
      return layout->argv[i];
    }
  }
  return NULL;
}
typedef bighole_t (os_fct_pattern_t)();
static os_fct_pattern_t * iNextFunc(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  void *os_pfct_ptr = NULL;
  os_fct_pattern_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);
  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);
  return os_fct_ptr;
}
static os_pgm_pattern_t * iNextPgm(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  return os_pfct_ptr;
}
bighole_t iCallFctByValSub1(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub2(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub6(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub7(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
bighole_t iCallFctByValSub8(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);
#endif /*_I_BY_REF_H*/
