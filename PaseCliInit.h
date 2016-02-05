#ifndef _PASECLIINIT_H
#define _PASECLIINIT_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <as400_types.h>
#include <as400_protos.h>

#ifdef __64BIT__
#define PASECLIDRIVER "/QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a(shr_64.o)"
#else
#define PASECLIDRIVER "/QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a(shr.o)"
#endif

#define DB2CLISRVPGM "QSYS/QSQCLI"

#define PASECLIMAXRESOURCE 33000
typedef struct PaseCliResource {
  int hstmt;                       /* index hstmt or hdbc */
  int hdbc;                        /* index to hdc (above) */ 
  pthread_mutex_t threadMutexLock; /* lock hdbc or hstmt */
  pthread_mutexattr_t threadMutexAttr;
  int in_progress;
  char *hKey;
} PaseCliResource;
extern PaseCliResource IBMiTable[PASECLIMAXRESOURCE];
extern void init_table_ctor(int hstmt, int hdbc);
extern void init_table_dtor(int hstmt);
extern void init_table_lock(int hstmt,int flag);
extern void init_table_unlock(int hstmt,int flag);
extern int init_table_in_progress(int hstmt,int flag);
extern int init_table_stmt_2_conn(int hstmt);
extern void init_table_add_hash(int hstmt, char * db, char * uid, char * pwd, char * qual, int flag);
extern int init_table_hash_2_conn(char * db, char * uid, char * pwd, char * qual);
extern void init_table_add_hash_W(int hstmt, unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual, int flag);
extern int init_table_hash_2_conn_W(unsigned int * db, unsigned int * uid, unsigned int * pwd, unsigned int * qual);

extern void * init_cli_dlsym();
extern int init_cli_srvpgm();
extern int init_CCSID400( int newCCSID );

extern int custom_strlen_utf16(unsigned int * src);
extern void * custom_alloc_zero(int sz);


#endif /* _PASECLIINIT_H */

