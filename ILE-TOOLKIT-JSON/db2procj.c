/*
 * ILE stored procedure interface db2procj(ILE)->libdb400.a->SQL400Json->...
 */
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <qp2user.h>
/* Use EBCDIC default job CCSID in Qp2dlopen and Qp2dlsym calls */
#define JOB_CCSID 0
#include <qmhsndm.h>

#define blobMax 15000000

#ifndef int16
#define int16 short
#endif
#ifndef uint16
#define uint16 unsigned short
#endif
#ifndef int32
#define int32 int
#endif
#ifndef uint32
#define uint32 unsigned int
#endif
#ifndef int64
#define int64 long long
#endif
#ifndef uint64
#define uint64 unsigned long long
#endif

#define OCCURS_MAX_ROWS 1000

void iJson400_Pase(char * blob, int rset) 
{
  /* blob -> |4-byte length|pad|data...| */
  char *blobData = NULL;
  int blobLen = 0;
  int rc = 0;
  int i = 0;
  char *start64Path="/QOpenSys/usr/lib/start32";
  char *arg_list[2];
  QP2_ptr64_t id = 0;
  void * symbol = NULL;
  int * paseErrno = 0;
  char *start64LibPath="LIBPATH=/QOpenSys/db2sock/QOpenSys/usr/lib:/QOpenSys/usr/lib";
  char *env_list[2];
  char *lib64Name= "libdb400.a(shr.o)";
  char *func64Name= "SQL400Json";
  const QP2_arg_type_t signature[] = {QP2_ARG_WORD, QP2_ARG_PTR32, QP2_ARG_WORD, QP2_ARG_PTR32, QP2_ARG_WORD, QP2_ARG_END};
  uint64 newPasePtr = 0;
  struct {
  int32 inhdbc;  /* Qp2CallPase - arglist */
  uint32 injson; 
  int32 inlen; 
  uint32 outjson;
  int32 outlen;
  } paseFunctionArglist;
  char * inputILEPtr = NULL;
  char * outputILEPtr = NULL;
  int sqlrc = 0;

  typedef struct occurs_t
  {
    char Out151[3000];
  } occurs_t;

  int Occurs151 = OCCURS_MAX_ROWS;
  occurs_t Output151[OCCURS_MAX_ROWS];

  /* debug me */
  /* sleep(30); */

  blobData = (char *) blob + 4;
  for (i=blobMax; i>=0; i--) {
    if (blobData[i] == 0x20 || !blobData[i]) {
       blobData[i] = 0x0;
    } else {
      break;
    }
  }
  blobLen = strlen(blobData);

  arg_list[0] = start64Path;
  arg_list[1] = NULL;
  env_list[0] = start64LibPath;
  env_list[1] = NULL;
  Qp2RunPase(start64Path,
             NULL,
             NULL,
             0,
             819,
             (char**)&arg_list,
             (char**)&env_list);

  id = Qp2dlopen(lib64Name,
                 (QP2_RTLD_NOW | QP2_RTLD_MEMBER ),
                 JOB_CCSID);

  symbol = Qp2dlsym(id, func64Name, JOB_CCSID, NULL);

  /* debug me */
  /* sleep(30); */

  paseFunctionArglist.inhdbc = 0;

  inputILEPtr = Qp2malloc(blobLen + 1, &newPasePtr);
  memset(inputILEPtr,0,blobLen + 1);
  memcpy(inputILEPtr,blobData,blobLen);
  paseFunctionArglist.injson = newPasePtr;
  paseFunctionArglist.inlen = blobLen;

  outputILEPtr = Qp2malloc(blobMax, &newPasePtr);
  memset(outputILEPtr,0,blobMax);
  paseFunctionArglist.outjson = newPasePtr;
  paseFunctionArglist.outlen = blobMax;

  rc = Qp2CallPase(symbol,
                &paseFunctionArglist,
                signature,
                QP2_RESULT_WORD,
                &sqlrc);
/*
  if (rset > 0) {
    exec sql
      Set Result Sets Array :Output151 For :Occurs151 Rows;
  } else {
    strcpy(blobData, outputILEPtr);
  }
*/
  strcpy(blobData, outputILEPtr);

  Qp2free(inputILEPtr);
  Qp2free(outputILEPtr);

  Qp2dlclose(id);
  Qp2EndPase();
}

void iJson400(char * blob) {
  iJson400_Pase(blob, 0);
} 
void iJson400R(char * blob) {
  iJson400_Pase(blob, 1);
} 


