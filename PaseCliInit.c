#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include "PaseCliInit.h"

extern void load_dlsym();

void *dlhandle = NULL;

/* Thread specific data key */
pthread_key_t threadDataKey = NULL;
pthread_once_t threadInitObject = PTHREAD_ONCE_INIT;
static pthread_mutex_t threadMutexLock = PTHREAD_MUTEX_INITIALIZER;

/* static global resource table */
PaseCliResource IBMiTable[PASECLIMAXRESOURCE]; 


void init_dtor(void *threadKeyData)
{
  void *dataPtr = (void *)threadKeyData;
  free(dataPtr);
}

void init_ctor(void)
{
  (void)pthread_key_create(&threadDataKey,(void (*)(void *))init_dtor);
  sync();
}

void * init_buff() {
  void *dataPtr;
  if ((dataPtr=(void *)pthread_getspecific(threadDataKey))==NULL)
  {
    dataPtr = malloc(64);
    memset(dataPtr,0,64);
    (void)pthread_setspecific(threadDataKey, (const void *)dataPtr);
  }
  return dataPtr;
}

void init_lock() {
  pthread_mutex_lock(&threadMutexLock);
}

void init_unlock() {
  pthread_mutex_unlock(&threadMutexLock);
}

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
      (void)pthread_once(&threadInitObject, (void (*)(void))init_ctor);
    }
    init_unlock();
  }
}

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


int init_table_stmt_2_conn(int hstmt) {
  return IBMiTable[hstmt].hdbc;
}



