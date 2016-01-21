#ifndef _PASECLIINIT_H
#define _PASECLIINIT_H

#ifdef __64BIT__
#define PASECLIDRIVER "/QOpenSys/usr/lib/libdb400.a(shr_64.o)"
#else
#define PASECLIDRIVER "/QOpenSys/usr/lib/libdb400.a(shr.o)"
#endif

#define PASECLIMAXRESOURCE 33000
typedef struct PaseCliResource {
  int hstmt;                       /* index hstmt or hdbc */
  int hdbc;                        /* index to hdc (above) */ 
  pthread_mutex_t threadMutexLock; /* lock hdbc or hstmt */
  pthread_mutexattr_t threadMutexAttr;
  int in_progress;
} PaseCliResource;
extern PaseCliResource IBMiTable[PASECLIMAXRESOURCE];
extern void init_table_ctor(int hstmt, int hdbc);
extern void init_table_dtor(int hstmt);
extern void init_table_lock(int hstmt,int flag);
extern void init_table_unlock(int hstmt,int flag);
extern int init_table_in_progress(int hstmt,int flag);
extern int init_table_stmt_2_conn(int hstmt);

extern void *dlhandle;
extern void init_dlsym();
extern void init_lock();
extern void init_unlock();


#endif /* _PASECLIINIT_H */

