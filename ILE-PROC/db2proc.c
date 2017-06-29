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

#pragma datamodel(p128)
typedef void (os_pgm_128_t) 
(
char * p001,char * p002,char * p003,char * p004,char * p005,
char * p006,char * p007,char * p008,char * p009,char * p010,
char * p011,char * p012,char * p013,char * p014,char * p015,
char * p016,char * p017,char * p018,char * p019,char * p020,
char * p021,char * p022,char * p023,char * p024,char * p025,
char * p026,char * p027,char * p028,char * p029,char * p030,
char * p031,char * p032,char * p033,char * p034,char * p035,
char * p036,char * p037,char * p038,char * p039,char * p040,
char * p041,char * p042,char * p043,char * p044,char * p045,
char * p046,char * p047,char * p048,char * p049,char * p050,
char * p051,char * p052,char * p053,char * p054,char * p055,
char * p056,char * p057,char * p058,char * p059,char * p060,
char * p061,char * p062,char * p063,char * p064,char * p065,
char * p066,char * p067,char * p068,char * p069,char * p070,
char * p071,char * p072,char * p073,char * p074,char * p075,
char * p076,char * p077,char * p078,char * p079,char * p080,
char * p081,char * p082,char * p083,char * p084,char * p085,
char * p086,char * p087,char * p088,char * p089,char * p090,
char * p091,char * p092,char * p093,char * p094,char * p095,
char * p096,char * p097,char * p098,char * p099,char * p100,
char * p101,char * p102,char * p103,char * p104,char * p105,
char * p106,char * p107,char * p108,char * p109,char * p110,
char * p111,char * p112,char * p113,char * p114,char * p115,
char * p116,char * p117,char * p118,char * p119,char * p120,
char * p121,char * p122,char * p123,char * p124,char * p125,
char * p126,char * p127,char * p128
);
#pragma linkage(os_pgm_128_t,OS)
#pragma datamodel(pop)

#define ICALL_MAX_RETURN 5000000
typedef struct bighole_struct {
  char hole[ICALL_MAX_RETURN];
} bighole_t;

typedef bighole_t (os_fct_128_t) 
(
char * p001,char * p002,char * p003,char * p004,char * p005,
char * p006,char * p007,char * p008,char * p009,char * p010,
char * p011,char * p012,char * p013,char * p014,char * p015,
char * p016,char * p017,char * p018,char * p019,char * p020,
char * p021,char * p022,char * p023,char * p024,char * p025,
char * p026,char * p027,char * p028,char * p029,char * p030,
char * p031,char * p032,char * p033,char * p034,char * p035,
char * p036,char * p037,char * p038,char * p039,char * p040,
char * p041,char * p042,char * p043,char * p044,char * p045,
char * p046,char * p047,char * p048,char * p049,char * p050,
char * p051,char * p052,char * p053,char * p054,char * p055,
char * p056,char * p057,char * p058,char * p059,char * p060,
char * p061,char * p062,char * p063,char * p064,char * p065,
char * p066,char * p067,char * p068,char * p069,char * p070,
char * p071,char * p072,char * p073,char * p074,char * p075,
char * p076,char * p077,char * p078,char * p079,char * p080,
char * p081,char * p082,char * p083,char * p084,char * p085,
char * p086,char * p087,char * p088,char * p089,char * p090,
char * p091,char * p092,char * p093,char * p094,char * p095,
char * p096,char * p097,char * p098,char * p099,char * p100,
char * p101,char * p102,char * p103,char * p104,char * p105,
char * p106,char * p107,char * p108,char * p109,char * p110,
char * p111,char * p112,char * p113,char * p114,char * p115,
char * p116,char * p117,char * p118,char * p119,char * p120,
char * p121,char * p122,char * p123,char * p124,char * p125,
char * p126,char * p127,char * p128
);

void iCallPgm128 (os_pgm_128_t *os_fct_ptr, ile_pgm_call_t* layout) 
{
  os_fct_ptr(
   layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4],
   layout->argv[5], layout->argv[6], layout->argv[7], layout->argv[8], layout->argv[9],
   layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], layout->argv[14],
   layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19],
   layout->argv[20], layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24],
   layout->argv[25], layout->argv[26], layout->argv[27], layout->argv[28], layout->argv[29],
   layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34],
   layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39],
   layout->argv[40], layout->argv[41], layout->argv[42], layout->argv[43], layout->argv[44],
   layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], layout->argv[49],
   layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54],
   layout->argv[55], layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59],
   layout->argv[60], layout->argv[61], layout->argv[62], layout->argv[63], layout->argv[64],
   layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69],
   layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74],
   layout->argv[75], layout->argv[76], layout->argv[77], layout->argv[78], layout->argv[79],
   layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], layout->argv[84],
   layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89],
   layout->argv[90], layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94],
   layout->argv[95], layout->argv[96], layout->argv[97], layout->argv[98], layout->argv[99],
   layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104],
   layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109],
   layout->argv[110], layout->argv[111], layout->argv[112], layout->argv[113], layout->argv[114],
   layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], layout->argv[119],
   layout->argv[120], layout->argv[121], layout->argv[122], layout->argv[123], layout->argv[124],
   layout->argv[125], layout->argv[126], layout->argv[127]
   );
}

bighole_t iCallFct128 (os_fct_128_t *os_fct_ptr, ile_pgm_call_t* layout) 
{
  return os_fct_ptr(
   layout->argv[0], layout->argv[1], layout->argv[2], layout->argv[3], layout->argv[4],
   layout->argv[5], layout->argv[6], layout->argv[7], layout->argv[8], layout->argv[9],
   layout->argv[10], layout->argv[11], layout->argv[12], layout->argv[13], layout->argv[14],
   layout->argv[15], layout->argv[16], layout->argv[17], layout->argv[18], layout->argv[19],
   layout->argv[20], layout->argv[21], layout->argv[22], layout->argv[23], layout->argv[24],
   layout->argv[25], layout->argv[26], layout->argv[27], layout->argv[28], layout->argv[29],
   layout->argv[30], layout->argv[31], layout->argv[32], layout->argv[33], layout->argv[34],
   layout->argv[35], layout->argv[36], layout->argv[37], layout->argv[38], layout->argv[39],
   layout->argv[40], layout->argv[41], layout->argv[42], layout->argv[43], layout->argv[44],
   layout->argv[45], layout->argv[46], layout->argv[47], layout->argv[48], layout->argv[49],
   layout->argv[50], layout->argv[51], layout->argv[52], layout->argv[53], layout->argv[54],
   layout->argv[55], layout->argv[56], layout->argv[57], layout->argv[58], layout->argv[59],
   layout->argv[60], layout->argv[61], layout->argv[62], layout->argv[63], layout->argv[64],
   layout->argv[65], layout->argv[66], layout->argv[67], layout->argv[68], layout->argv[69],
   layout->argv[70], layout->argv[71], layout->argv[72], layout->argv[73], layout->argv[74],
   layout->argv[75], layout->argv[76], layout->argv[77], layout->argv[78], layout->argv[79],
   layout->argv[80], layout->argv[81], layout->argv[82], layout->argv[83], layout->argv[84],
   layout->argv[85], layout->argv[86], layout->argv[87], layout->argv[88], layout->argv[89],
   layout->argv[90], layout->argv[91], layout->argv[92], layout->argv[93], layout->argv[94],
   layout->argv[95], layout->argv[96], layout->argv[97], layout->argv[98], layout->argv[99],
   layout->argv[100], layout->argv[101], layout->argv[102], layout->argv[103], layout->argv[104],
   layout->argv[105], layout->argv[106], layout->argv[107], layout->argv[108], layout->argv[109],
   layout->argv[110], layout->argv[111], layout->argv[112], layout->argv[113], layout->argv[114],
   layout->argv[115], layout->argv[116], layout->argv[117], layout->argv[118], layout->argv[119],
   layout->argv[120], layout->argv[121], layout->argv[122], layout->argv[123], layout->argv[124],
   layout->argv[125], layout->argv[126], layout->argv[127]
   );
}


void iCall400(char * blob) 
{
  /* blob -> |4-byte length|pad|data...| */
  ile_pgm_call_t* layout = (ile_pgm_call_t*)blob;
  int argc = 0;
  int parmc = 0;
  int offset = 0;
  int by = 0;
  int lenPgm = 0;
  int lenLib = 0;
  int lenFunc = 0;
  int lenRet = 0;
  char * myPgm = NULL;
  char * myLib = NULL;
  char * myFunc = NULL;
  char * myLibl = "*LIBL";
  char * myRet = NULL;
  os_pgm_128_t *os_pfct_ptr = NULL;
  os_fct_128_t *os_fct_ptr = NULL;
  _SYSPTR os_pgm_ptr = NULL;
  unsigned long long os_act_mark = 0;
  int os_obj_type = 0;
  bighole_t bighole;

  /* hey adc debug */
  /* sleep(30); */

  /* resolve call  */
  myPgm = layout->pgm;
  myLib = layout->lib;
  myFunc = layout->func;
  lenPgm = strlen(myPgm);
  lenLib = strlen(myLib);
  if (!lenLib) {
    myLib = myLibl;
    lenLib = 5;
  }
  lenFunc = strlen(myFunc);
  if (!lenFunc) {
    /* resolve pgm */
    os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);
  } else {
    /* resolve srvpgm */
    os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);
    os_act_mark = QleActBndPgmLong(& os_pgm_ptr, NULL, NULL, NULL, NULL);
    os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL); 
  }

  /* set ILE addresses based memory spill location offset */
  for (argc=0; argc < ILE_PGM_MAX_ARGS; argc++) {
    if (argc < layout->argc) {
      /*  by reference */
      if (layout->argv_parm[argc] > -1) {
        /* ILE address parm location (skip by value slots) */
        parmc = layout->argv_parm[argc];
        offset = layout->arg_pos[parmc];
        /* set ILE address to data */
        layout->argv[argc] = (char *)layout + offset;
      }
    } else {
      layout->argv[argc] = NULL;
    }
  }

  /* call by ref */
  if (layout->argc == layout->parmc) {
    if (!lenFunc) {
      iCallPgm128(os_pfct_ptr, layout);
    } else {
      bighole = iCallFct128(os_fct_ptr, layout);
    }
  /* call mix by ref/val */
  } else {
    /* next work */
  }

  /* return aggregate? */
  if (layout->return_start && layout->return_start < layout->return_end) {
    myRet = (char *)layout + layout->return_start;
    lenRet = layout->return_end - layout->return_start;
    memcpy(myRet,(char *)&bighole,lenRet);
  }

}

