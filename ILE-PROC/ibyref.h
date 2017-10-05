#ifndef _I_BY_REF_H
#define _I_BY_REF_H
#define ICALL_MAX_RETURN 3000000
typedef struct bighole_struct {
  char hole[ICALL_MAX_RETURN];
} bighole_t;
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
#endif /*_I_BY_REF_H*/
