#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sqlcli1.h>
#include "PaseCliInit.h"
#include "PaseCliPrintf.h"
#include "PaseCliDevFile.h"


/* Thread specific data key */
pthread_key_t printDataKey = NULL;

#define uint16 unsigned short
#define uint32 unsigned int
#define uint64 unsigned long long
#ifdef TGT64
#define Address unsigned long long
typedef struct TiaStackFrame {
  uint64 backChain;
  uint32 savedCR;
  uint32 resvd;
  uint64 savedLR;
  uint64 resrv1;
  uint64 resrv2;
  uint64 toc;
  uint64 parmRegs[8];
} TiaStackFrameStruct;
#else
#define Address unsigned int
typedef struct TiaStackFrame {
  uint32 backChain;
  uint32 savedCR;
  uint32 savedLR;
  uint32 resrv1;
  uint32 resrv2;
  uint32 toc;
  uint32 parmRegs[8];
  uint32 pad[2];
} TiaStackFrameStruct;
#endif

typedef struct FN_NAME
{
    uint16 nameLen;
    char name[1];
} FN_NAME_STRUCT;
typedef struct tbtable_short
{
    uint32 zeroAnchor;		/* include this in to make things simpler */
    uint32 version:8;		/* traceback format version               */
    uint32 lang:8;          /* See language values below              */
    uint32 globallink:1;	/* Set if routine is global linkage 	  */
    uint32 is_eprol:1;		/* Set if is out-of-line epilog/prologue  */
    uint32 has_tboff:1;		/* Set if offset from start of proc stored */
    uint32 int_proc:1;		/* Set if routine is internal		  */
    uint32 has_ctl:1;		/* Set if routine involves controlled storage */
    uint32 tocless:1;		/* Set if routine contains no TOC 	  */
    uint32 fp_present:1;	/* Set if routine performs FP operations  */
    uint32 log_abort:1;		/* Set if routine logs or aborts FP ops   */
    uint32 int_hndl:1;		/* Set if routine is interrupt handler    */
    uint32 name_present:1;	/* Set if name is present in proc table */
    uint32 uses_alloca:1;	/* Set if alloca used to allocate storage */
    uint32 cl_dis_inv:3;	/* On-condition directives, see below */
    uint32 saves_cr:1;		/* Set if procedure saves the condition reg */
    uint32 saves_lr:1;		/* Set if procedure saves the link reg */
    uint32 stores_bc:1;		/* Set if procedure stores the backchain */
    uint32 fixup:1;         /* Set if code is generated fixup code. */
    uint32 fpr_saved:6;		/* Number of FPRs saved, max of 32 */
    uint32 spare3:2;		/* Spare bits */
    uint32 gpr_saved:6;		/* Number of GPRs saved, max of 32 */
    uint32 fixedparms:8;	/* Number of fixed point parameters */
    uint32 floatparms:7;	/* Number of floating point parameters */
    uint32 parmsonstk:1;	/* Set if all parameters placed on stack */
} tbtable_short_struct;

static int printf_include_cnt;
static int printf_exclude_cnt;
static char * printf_include_data[PRINTF_SCAN_MAX];
static char * printf_exclude_data[PRINTF_SCAN_MAX];

#ifdef XLC
Address pase_GPR1();
#pragma mc_func pase_GPR1 { "38610000" }
#else
void check_GCC(Address stk) {
  if (stk == 0) {
     printf_format("---bad stack---\n---%p---\n",stk);
  }
}
Address pase_GPR1() {
  Address stk = 42;
#ifdef TGT64
  asm volatile ("addi 9,1,0\t\n": "=r"(stk));
#else
  asm volatile ("addi 9,1,0\t\n": "=r"(stk));
#endif
  check_GCC(stk);
  return stk;
}
#endif

void printf_force_SIGQUIT(char *mykey) {
  int i = 0; 
  int stop = 0; 
  char dbxexe[1024];
  char dbxnest[32];
  char dbxattach[32];
  char ** dbxsrc;
  char dbxdirs[32][1024];
  char * arg[128];
  pid_t a = 0;
  pid_t p = 0;
  stop = init_cli_trace(); 
  switch (stop) { 
  case DB2CLITRACE_FILE_DBX:
    printf_format("%s.stop ---force dbx---\n", mykey);
    dev_dump();
    a = getpid();
    memset(dbxexe,0,sizeof(dbxexe));
    memset(dbxnest,0,sizeof(dbxnest));
    memset(dbxattach,0,sizeof(dbxattach));
    sprintf(dbxexe,"/QOpenSys/usr/bin/dbx");
    sprintf(dbxnest,"-d 100");
    sprintf(dbxattach,"-a %d", a);
    dbxsrc = (char **) init_cli_dbx();
    p = fork();
    if (p == 0) {
      arg[0] = (char *)&dbxexe;
      arg[1] = (char *)&dbxnest;
      arg[2] = (char *)&dbxattach;
      printf("0 %s\n",(char *)arg[0]);
      printf("1 %s\n",(char *)arg[1]);
      printf("2 %s\n",(char *)arg[2]);
      for (i=3;dbxsrc[i-3];i++) {
        sprintf(dbxdirs[i],"-I %s",dbxsrc[i-3]);
        arg[i] = (char *)&dbxdirs[i];
        printf("%d %s\n", i, (char *)arg[i]);
      }
      arg[i] = (char *)NULL;
      execv(arg[0], arg);
    } else { 
      sleep(20); 
    } 
    break;
  case DB2CLITRACE_FILE_STOP: 
    printf_format("%s.stop ---force coredump---\n", mykey);
    dev_dump();
    raise (SIGQUIT); 
    break;
  default: 
    break;
  } 
}


void printf_sqlrc_status(char *mykey, SQLRETURN sqlrc) { 
  switch(sqlrc) { 
  case SQL_SUCCESS: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_SUCCESS");
    break;
  case SQL_SUCCESS_WITH_INFO: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_SUCCESS_WITH_INFO");
    break;
  case SQL_NO_DATA_FOUND: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_NO_DATA_FOUND");
    break;
  case SQL_NEED_DATA: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_NEED_DATA");
    break;
  case SQL_ERROR: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_ERROR");
    break;
  case SQL_INVALID_HANDLE: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_INVALID_HANDLE (SQL_ERROR)");
    break;
  case SQL_STILL_EXECUTING: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_STILL_EXECUTING (SQL_ERROR)");
    break;
  default: 
    printf_format("%s.retn %s %s 0x%p (%d) %s\n",mykey,"SQLRETURN","sqlrc",sqlrc,sqlrc,"SQL_RC_UKNOWN (SQL_ERROR)");
    break;
  }
}


void printf_sqlrc_head_foot(char *mykey, SQLRETURN sqlrc, int beg) { 
  if (sqlrc > SQL_ERROR) { 
    if (beg) { 
      printf_format("%s.tbeg +++success+++\n",mykey);
    } else { 
      printf_format("%s.tend +++success+++\n",mykey);
    } 
  } else { 
    if (beg) { 
      printf_format("%s.tbeg ---error---\n", mykey);
    } else { 
      printf_format("%s.tend ---error---\n", mykey);
      printf_force_SIGQUIT(mykey); 
    } 
  } 
}


void printf_key(char *mykey, char *text) {
  struct timeval mytv;
  int tid; /* tid_t */
  pthread_t self;

  gettimeofday(&mytv,NULL);

  self = pthread_self();
  pthread_getunique_np(&self, &tid);

  sprintf_format(mykey,"%s.%d.%d.%d",text,getpid(),(int)mytv.tv_sec,tid);
}

void * printf_buff() {
  void *dataPtr;
  if ((dataPtr=(void *)pthread_getspecific(printDataKey))==NULL)
  {
    dataPtr = malloc(PRINTF_BUFFER_MAX);
    (void)pthread_setspecific(printDataKey, (const void *)dataPtr);
  }
  return dataPtr;
}

char * printf_buffer() {
  return (char *)printf_buff();
}
void printf_clear() {
  memset(printf_buffer(),0,PRINTF_BUFFER_MAX + 1);
}
void printf_fifo(char * bigbuff) {
  int have, want, remain, need;
  char tmp[PRINTF_BUFFER_MAX+1];
  want = strlen(bigbuff);
  have = strlen(printf_buffer());
  remain = PRINTF_BUFFER_MAX-have;
  if (remain < want) {
    need = want - remain;
    memset(tmp,0,PRINTF_BUFFER_MAX);
    strcpy(tmp,&printf_buffer()[need]);
    memset(printf_buffer(),0,PRINTF_BUFFER_MAX+1);
    strcpy(printf_buffer(),tmp);
  }
  strcat(printf_buffer(),bigbuff);
  printf_buffer()[PRINTF_BUFFER_MAX] = '\0';
}
void printf_format(const char * format, ...) {
    char bigbuff[PRINTF_BUFFER_MAX];
    char *p = (char *) &bigbuff; 
    FILE * pFile;

    va_list args;
    va_start(args, format);
    vsprintf(p, format, args);
    va_end(args);

    printf_fifo(bigbuff);
}
void sprintf_format(char *buff, const char * format, ...) {
    char bigbuff[PRINTF_BUFFER_MAX];
    char *p = (char *) &bigbuff; 
    FILE * pFile;

    va_list args;
    va_start(args, format);
    vsprintf(p, format, args);
    va_end(args);

    strcpy(buff,bigbuff);
}
void printf_hexdump(char * prefix, void *string, unsigned int len) {
  char	charbuf[17];
  char	c0, c1;
  char	*p = (char*)string;
  char	*end;
  unsigned int i=0, j=0;

  /* protect my self */
#ifdef TGT64
  if ((char *)string < (char *)0x100000000) return;
#else
  if ((char *)string < (char *)0x10000000) return;
#endif

  /* not too much data */
  if (len > PRINTF_HEXDUMP_MAX) len = PRINTF_HEXDUMP_MAX;
  /* but just enough */
  while ((len % 16)) len++;
  end = p + len;
  for (i = 0, j = 0; p < end ; ++p, ++i, j++) {
    if (j == 16) {
      printf_format(" ");
      charbuf[16] = 0;
      printf_format(">%s<\n", charbuf);
      j = 0;
	}
    if (j == 0) printf_format("%s.phex %16p : ", prefix, p);
    charbuf[i & 15] = (isgraph(*p)? *p: '.');
    if (*p == ' ') charbuf[i & 15] = ' ';
    c0 = '0' + ((unsigned char)*p >> 4);
    if (c0 > '9') c0 = c0 - '9' + 'a' - 1;
    c1 = '0' + (*p & 0x0f);
    if (c1 > '9') c1 = c1 - '9' + 'a' - 1;
    printf_format("%c%c", c0, c1);
  }
  if (j) {
    printf_format(" ");
    charbuf[16] = 0;
    printf_format(">%s<\n", charbuf);
  }
}

void printf_stack_internal(char * prefix) {
  Address stk = pase_GPR1();
  Address backchain = 0;
  Address goforth;
  char myname[512];
  struct TiaStackFrame *frame;
  struct tbtable_short *tb;
  enum { FNOFFSET_INVALID = -1 }; /* any odd number would do */

  /* don't want first frame printf_stack_internal */
  stk = *(Address *)stk;
  frame = (struct TiaStackFrame *) stk;
  stk = *(Address *)stk;
  /* loop stack backchain */
  while (stk) {
    memset(myname,0,512);
    /* looking for zero word tbtable start */
    goforth = frame->savedLR;
    while (*(uint32 *)goforth) {
      goforth += sizeof(uint32);
    }
    tb = (struct tbtable_short *) goforth;
    if (tb->name_present) {
      Address nameOffset;
      Address fnOffset;
      uint32 numCtl;
      struct FN_NAME *fn;
      uint32 tb_len = 256;

      nameOffset = sizeof(*tb);
      if ((tb->fixedparms + tb->floatparms) > 0) nameOffset += sizeof(uint32);
      fnOffset = FNOFFSET_INVALID; 
      if (tb->has_tboff) {
	    fnOffset = *(uint32*)((char*)tb + nameOffset);
	    nameOffset += sizeof(uint32);
      }
      if (tb->int_hndl) nameOffset += sizeof(uint32);
      if (tb->has_ctl) {
	    numCtl = *(uint32*)((char*)tb + nameOffset);
	    nameOffset += (sizeof(numCtl) + (numCtl * sizeof(uint32)));
      }
      if (nameOffset < (tb_len - sizeof(uint16))) {
	    fn = (struct FN_NAME*)((char*)tb + nameOffset);
	    if (fn->nameLen && ((nameOffset + fn->nameLen) <= (tb_len - sizeof(uint16)))) {
          strncpy(myname,fn->name,fn->nameLen);
        }
      }
    } else {
      sprintf(myname,"missing");
    }
    frame = (struct TiaStackFrame *) stk;
    if (stk == backchain) {
      if (tb->parmsonstk) {
        switch (tb->fixedparms + tb->floatparms) {
          case 0:
            printf_format("%s.walk %s (void)\n",
            prefix,
            myname
            );
            break;
          case 1:
            printf_format("%s.walk %s (%p)\n",
            prefix,
            myname,
            frame->parmRegs[0]
            );
            break;
          case 2:
            printf_format("%s.walk %s (%p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1]
            );
            break;
          case 3:
            printf_format("%s.walk %s (%p %p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1],
            frame->parmRegs[2]
            );
            break;
          case 4:
            printf_format("%s.walk %s (%p %p %p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1],
            frame->parmRegs[2],
            frame->parmRegs[3]
            );
            break;
          case 5:
            printf_format("%s.walk %s (%p %p %p %p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1],
            frame->parmRegs[2],
            frame->parmRegs[3],
            frame->parmRegs[4]
            );
            break;
          case 6:
            printf_format("%s.walk %s (%p %p %p %p %p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1],
            frame->parmRegs[2],
            frame->parmRegs[3],
            frame->parmRegs[4],
            frame->parmRegs[5]
            );
            break;
          case 7:
            printf_format("%s.walk %s (%p %p %p %p %p %p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1],
            frame->parmRegs[2],
            frame->parmRegs[3],
            frame->parmRegs[4],
            frame->parmRegs[5],
            frame->parmRegs[6]
            );
            break;
          default:
            printf_format("%s.walk %s (%p %p %p %p %p %p %p %p)\n",
            prefix,
            myname,
            frame->parmRegs[0],
            frame->parmRegs[1],
            frame->parmRegs[2],
            frame->parmRegs[3],
            frame->parmRegs[4],
            frame->parmRegs[5],
            frame->parmRegs[6],
            frame->parmRegs[7]
            );
            break;
        }
      } else {
        printf_format("%s.walk %s (?)\n",
        prefix,
        myname
        );
      }
    }
    backchain = *(Address *)stk;
    stk = backchain;
  } /* while backchain */
}

void printf_stack(char * prefix) {
  printf_stack_internal(prefix);
}

/* TBD -- filter */
int printf_get_trace_script() {
  return 1;;
}


void printf_script( char * pmsg )
{
  int i = 0, print_ok = 1;
  char mykey[256];
  char * msg = NULL;
  char * fmsg = NULL;

  if (printf_get_trace_script()) {
    if (pmsg) {
      /* include only */
      if (printf_include_cnt) {
        print_ok = 0;
        for (i=0; i < printf_include_cnt; i++) {
          msg = printf_include_data[i];
          fmsg = strstr(pmsg,msg);
          if (fmsg != NULL) {
            print_ok = 1;
            break;
          }
        }
      }
      /* exclude any */
      if (printf_exclude_cnt) {
        for (i=0; i < printf_exclude_cnt; i++) {
          msg = printf_exclude_data[i];
          fmsg = strstr(pmsg,msg);
          if (fmsg != NULL) {
            print_ok = 0;
            break;
          }
        }
      }
      if (print_ok) {
        printf_key(mykey,"script");
        printf_format("%s.run %s\n",mykey,pmsg);
      } 
    } 
  }
}

void printf_script_include( char * pmsg )
{
  int i=0, len1 = 0, len2 = 0, fnd=0, include_ok = 0;
  char *msg = NULL;
  if (printf_get_trace_script()) {
    if (printf_include_cnt < PRINTF_SCAN_MAX && pmsg && strlen(pmsg)) {
      include_ok = 1;
      len1 = strlen(pmsg);
      for (i=0; i < printf_include_cnt; i++) {
        msg = printf_include_data[i];
        len2 = strlen(msg);
        if (len1 == len2) {
          fnd = memcmp(pmsg, msg, len2);
          if (fnd == 0) {
            include_ok = 0;
            break;
          }
        }
      }
      if (include_ok) {
        msg = (char *) malloc(len1 + 1);
        strcpy(msg,pmsg);
        printf_include_data[printf_include_cnt] = msg;
        printf_include_cnt++;
      }
    }
  }
}

void printf_script_exclude( char * pmsg )
{
  int i=0, len1 = 0, len2 = 0, fnd=0, exclude_ok = 0;
  char *msg = NULL;
  if (printf_get_trace_script()) {
    if (printf_exclude_cnt < PRINTF_SCAN_MAX && pmsg && strlen(pmsg)) {
      exclude_ok = 1;
      len1 = strlen(pmsg);
      for (i=0; i < printf_exclude_cnt; i++) {
        msg = printf_exclude_data[i];
        len2 = strlen(msg);
        if (len1 == len2) {
          fnd = memcmp(pmsg, msg, len2);
          if (fnd == 0) {
            exclude_ok = 0;
            break;
          }
        }
      }
      if (exclude_ok) {
        msg = (char *) malloc(len1 + 1);
        strcpy(msg,pmsg);
        printf_exclude_data[printf_exclude_cnt] = msg;
        printf_exclude_cnt++;
      }
    }
  }
}

void printf_script_clear()
{
  int i = 0;
  char *msg = NULL;
  if (printf_get_trace_script()) {
    for (i=0; i < printf_include_cnt; i++) {
      msg = printf_include_data[i];
      free(msg);
    }
    for (i=0; i < printf_exclude_cnt; i++) {
      msg = printf_exclude_data[i];
      free(msg);
    }
    printf_include_cnt = 0;
    printf_exclude_cnt = 0;
  }
}


