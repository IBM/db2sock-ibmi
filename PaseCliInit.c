#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include "PaseCliInit.h"

/* static global resource table
 * Ok, big trick, IBM i db2 resources
 * are unique across all types 
 * henv, hdbc, hstmt, hdesc.
 * Yep-R-Doodle, db2 resources, one big old
 * process resource table with slots (IBMiTable).  
 */
PaseCliResource IBMiTable[PASECLIMAXRESOURCE]; 

/* global data lock (IBM i resources) */
pthread_once_t threadInitObject = PTHREAD_ONCE_INIT;
static pthread_mutex_t threadMutexLock = PTHREAD_MUTEX_INITIALIZER;

/* 
 * dlopen handle of PASE libdb400.a (real driver) 
 */
void *dlhandle = NULL;

/* global table lock
 * This lock is 'lock once'.
 * That is, not PTHREAD_MUTEX_RECURSIVE,
 * therefore do not call twice, will hang.
 */
void init_lock() {
  pthread_mutex_lock(&threadMutexLock);
}

void init_unlock() {
  pthread_mutex_unlock(&threadMutexLock);
}

/* 
 * dlopen handle of PASE libdb400.a,
 * set all symbols for CLI APIs,
 * via load_dlsym (PaseCliAsync_gen.c).
 * Note: dlhandle is checked twice,
 * second under global lock,
 * to avoid race conditions
 * multiple threads starting.
 */
void init_dlsym() {
  char *dlservice = PASECLIDRIVER;
  if (dlhandle  == NULL) {
    init_lock();
    if (dlhandle  == NULL) {
      dlhandle = dlopen(dlservice, RTLD_NOW|RTLD_MEMBER);
      if (dlhandle == NULL)  {
        printf("Service %s Not Found:  %s\n", dlservice, dlerror());
        exit(-1);
      }
      load_dlsym();
    }
    init_unlock();
  }
}

/* caller hold resource level lock
 * init_table_ctor(hdbc,0)     -- opening a hdbc (connection)
 * init_table_ctor(hstmt,hdbc) -- map a stmt to a hdbc (connection)
 * These lock are resource level 'lock multiple', any thread.
 * That is, PTHREAD_MUTEX_RECURSIVE, therefore, same thread, 
 * may lock more than once. Other thread will block.
 * Remember to unlock same number times locked to avoid hangs.
 * (see init_table_lock to understand hstmt to hdbc map locks)
 */
void init_table_ctor(int hstmt, int hdbc) {
  if (!IBMiTable[hstmt].hstmt) {
    pthread_mutexattr_init(&IBMiTable[hstmt].threadMutexAttr);
    pthread_mutexattr_settype(&IBMiTable[hstmt].threadMutexAttr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&IBMiTable[hstmt].threadMutexLock, &IBMiTable[hstmt].threadMutexAttr);
    IBMiTable[hstmt].in_progress = 0;
  }
  IBMiTable[hstmt].hstmt = hstmt;
  IBMiTable[hstmt].hdbc = hdbc;
}
void init_table_dtor(int hstmt) {
  /* do nothing, 
   * statement handles are unique
   * we only want init mutex ctor
   * once done, we have lock scope
   * either statment or connection
   */
}
void * init_table_addr(int hstmt) {
  return (void *) &IBMiTable[hstmt];
}
/* hdbc and/or hstmt scope locks
 * flag = 0 -- lock hdbc (or hstmt, if we ever dare)
 * flag = 1 -- lock hdbc of hstmt (lock parent of statment)
 * 
 * Locking scope hdbc, obvious, aka, lock the connection
 * to one thread at a time usage. Mode typical most database driver 
 * scripting connection pools, aka, one thread<2>one connection (at a time).
 * (... pool says do not share 'resource' across threads)
 *  
 * Locking scope hstmt, currently, flag=1, is recommended
 * for safe hstmt-map2-hdbc connection locks (one statement at time).
 *
 * Future wild, reckless behaviour (Good morning Hal):
 *
 * Nobody (i know), ever tried multiple statement threads 
 * requesting on a single connection at the same time. 
 * However, flag=0, at hstmt level is possible with lock (gulp).
 */
void init_table_lock(int hstmt, int flag) {
  if (flag) {
    pthread_mutex_lock(&IBMiTable[IBMiTable[hstmt].hdbc].threadMutexLock);
    IBMiTable[IBMiTable[hstmt].hdbc].in_progress += 1;
  } else {
    pthread_mutex_lock(&IBMiTable[hstmt].threadMutexLock);
    IBMiTable[hstmt].in_progress += 1;
  }
}
void init_table_unlock(int hstmt,int flag) {
  if (flag) {
    pthread_mutex_unlock(&IBMiTable[IBMiTable[hstmt].hdbc].threadMutexLock);
    if (IBMiTable[hstmt].in_progress > 0) {
      IBMiTable[IBMiTable[hstmt].hdbc].in_progress -= 1;
    }
  } else {
    pthread_mutex_unlock(&IBMiTable[hstmt].threadMutexLock);
    if (IBMiTable[hstmt].in_progress > 0) {
      IBMiTable[hstmt].in_progress -= 1;
    }
  }
}
/* No lock.
 * Used other thread, see if time to join
 * work requested in child thread.
 * This is dicey, but false yes/no is
 * likely ok, when used as 'join'.
 */
int init_table_in_progress(int hstmt,int flag) {
  if (flag) {
    if (IBMiTable[IBMiTable[hstmt].hdbc].in_progress > 0) {
      return 1;
    }
  } else {
    if (IBMiTable[hstmt].in_progress > 0) {
      return 1;
    }
  }
  return 0;
}
/* No lock.
 * Used free resources.
 * This is dicey, but false yes/no is
 * likely ok, when used as 'free'.
 */
int init_table_stmt_2_conn(int hstmt) {
  return IBMiTable[hstmt].hdbc;
}



