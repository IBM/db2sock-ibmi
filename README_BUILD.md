#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#DRIVER BUILDER SECTION
For driver builders of scripting extensions (php ibm_db2, ruby ibm_db, etc.).
The idea with this 'super driver' is many tasks repeated over and over in each
language driver could be moved into the lowest CLI driver (libdb400.a).
Also adding features to each language, such as asynchronous calls, CLI tracing, etc,
will be much easier.

## build
Need to copy ILE CLI headers to PASE.
```
> ./cpysqlincludes.sh 
```

All make files have been converted to gcc compiles.
```
optional (git already completed) ...
> python gen.py

compiles ...
# examples:
# 1) compile from chroot
#   > export INICHROOT=/QOpenSys/zend7
#   > export INILIB=DB2JSON
#   > export INITARGET=/QOpenSys/usr/lib
#   > ./make_libdb400.sh
# 2) compile from root
#   > export INILIB=DB2JSON
#   > export INITARGET=/QOpenSys/usr/lib
#   > ./make_libdb400.sh
# Subset compile:
#   > ./make_libdb400.sh ile 400 test
#   > ./make_libdb400.sh ile 400
#   > ./make_libdb400.sh test
```
Note:

- PASE include change gcc compiles will not run unless you take force gcc align quadword action in notes for PASE /usr/include/as400_types.h.

- PASE gmake Makefile compiles RPG programs (see utilities system400, CRTPGM, CRTRPGMOD).

- PASE system400 new 'chroot' system utility. Created by Makefile (no action required). Technical: Uses QSQSRVR job via db2 libdb400.a.

- PASE Makefile utilities CRTPGM, CRTRPGMOD use new system400 utility for ILE/RPG builds. Must export INICHROOT (above).

I am using a chroot with following packages from [ibmichroot](https://bitbucket.org/litmis/ibmichroot). 
```
> pkg_setup.sh pkg_perzl_gcc-4.8.3.lst
```
I needed a new gmake, you can find these on [yips Open Source](http://yips.idevcloud.com/wiki/index.php/PASE/OpenSourceBinaries)
```
Binary fixes (GCC OPS):
    Attach:gmake-4.2.zip — newer version
    Attach:m4-1.4.17.zip — newer version
        copy to directory /opt/freeware/bin 
```

##gen.py creates: 
- PaseCliAsync.h         -- header asynchronous extensions (php, node, ...)
- PaseCliAsync_gen.c     -- asynchronous driver APIs
- PaseCliILE_gen.c       -- direct ILE call APIs (exported)
- PaseCliLibDB400_gen.c  -- PASE libdb400.a override dlsyms (replace someday)
- PaseCliDump_gen.c      -- TRACE each CLI API with full stack walk (cool)
- libdb400.exp           -- all CLI export APIs

##human coding:
- sqlcli1.h              -- match LUW header convention
- PaseCliLic.h           -- compiled license into binary
- PaseCliCustom.c        -- 'big function' APIs (experimental)
- PaseCliPrintf.c        -- TRACE printf to device
- PaseCliPrintf.h        -- TRACE printf header
- PaseCliDev.c           -- TRACE device file or console (more later)
- PaseCliDev.h           -- TRACE device header
- PaseCliDevConsole.c    -- TRACE console
- PaseCliDevConsole.h    -- TRACE console header
- PaseCliDevFile.c       -- TRACE file (/tmp/libdb400_trace_(pid))
- PaseCliDevFile.h       -- TRACE file header
- PaseCliInit.c          -- db2 resource table manager (read)
- PaseCliInit.h          -- db2 resource table header

##human ILE c coding (see README_CGI for configuration):
- db2json.c              -- ILE Apache CGI JSON interface to libdb400.a


##examples
```
build
> python genmake.py (already complete)
> ./make_libdb400.sh test

set user profile (optional)
> cd tests
> export SQL_DB400="*LOCAL"
> export SQL_UID400="UID"
> export SQL_PWD400="PWD"

run 32-bit or 64-bit
> testnnnn_32
> testnnnn_64
```

# Internal information (optional read)
Test cases are best source for information on how to use. These are a few notes.

##set CCSID first (tests)
You should call SQLOverrideCCSID400(ccsid), before any other SQL activity (see tests).
Environment setting SQLOverrideCCSID400 defines how this libdb400.a operates.
```
=== UTF-8 ccsid, normal Unix mode (direct ILE call) ===
SQLOverrideCCSID400(1208)
-->SQLExecDirect(Async)-->ILE_SQLExecDirect-->DB2

=== UTF-16 ccsid, 'W'ide interfaces (direct ILE call) ===
SQLOverrideCCSID400(1200)
-->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2

=== PASE ccsid, original mode (call original libdb400.a) ===
SQLOverrideCCSID400(0) -- job ccsid, best guess
SQLOverrideCCSID400(pase_ccsid)
-->SQLExecDirect(Async)-->PASE libdb400.a(SQLExecDirect)-->DB2 (*)
```
(*) Calling old libdb400.a less desirable, so may change over time.


##Usage CLI APIs

In general, use CLI APIs, which, enable correct locking for async and non-async db2 operations.
However, feel free to use new direct call ILE DB2 APIs (ILE_SQLxxx). 
```
=== CLI APIs UTF-8 or APIWs UTF-16  ===
=== choose async and/or normal wait === 
SQLRETURN SQLExecDirect(..);
SQLRETURN SQLExecDirectW(..);

== callback or reap/join with async ===
pthread_t SQLExecDirectAsync(..);
pthread_t SQLExecDirectWAsync(..);
void SQLExecDirectCallback(SQLExecDirectStruct* );
SQLExecDirectStruct * SQLExecDirectJoin (pthread_t tid, SQLINTEGER flag);
void SQLExecDirectWCallback(SQLExecDirectWStruct* );
SQLExecDirectWStruct * SQLExecDirectWJoin (pthread_t tid, SQLINTEGER flag);

=== bypass all, call PASE libdb400.a directly  (not recommended) ===
SQLRETURN libdb400_SQLExecDirect(..);
SQLRETURN libdb400_SQLExecDirectW(..); (*)

=== bypass all, call ILE directly (not recommended) ===
SQLRETURN ILE_SQLExecDirect(..);
SQLRETURN ILE_SQLExecDirectW(..);

```

## Advanced features
Experimental advanced features, large, complex operations in one async call.

```
TBD - re-work 400 custom APIs in progress
```

##Note:
All make files have been converted to gcc compiles. 

In switching to gcc, you have to edit PASE header to force gcc align quadword.
If you miss this edit header step, all will compile, but NOTHING will run.

```
/usr/include/as400_types.h:
/*
 * Quadword (aligned) area for a tagged ILE pointer
 */
typedef union _ILEpointer {
#if !(defined(_AIX) || defined(KERNEL))
#pragma pack(1,16,_ILEpointer)	/* Force sCC quadword alignment */
#endif
/* CAUTION: Some compilers only provide 64-bits for long double */
#if defined( __GNUC__ )
    long double	align __attribute__((aligned(16))); /* force gcc align quadword */
#else
    long double align;	/* Force xlc quadword alignment (with -qldbl128 -qalign=natural) */
#endif
#ifndef _AIX
    void		*openPtr; /* MI open pointer (tagged quadword) */
#endif
    struct {
	char		filler[16-sizeof(uint64)];
	address64_t	addr;	/* (PASE) memory address */
    } s;
} ILEpointer;
```

gcc options in Makefile ...
```
### gmake
### gmake TGT64=64
### gcc options
### -v            - verbose compile
### -Wl,-bnoquiet - verbose linker
### -shared       - shared object
### -maix64       - 64bit
### -isystem      - compile PASE system headers
### -nostdlib     - remove libgcc_s.a and crtcxa_s.o

gcc code tip unsigned long long ...

gcc bug cast to unsigned long long not work (bad sign extend), 
therefore we also need cast ulong to match size of pointer 32/64 
   arglist->ohnd.s.addr = (ulong) ohnd; /* silly gcc compiler */
```

xlc no longer supported ...
```
When using xlc, use options -qldbl128 -qalign=natural. 
Missing these options will result in ILE DB2 call failures.
See /usr/include/as400_types.h, type ILEpointer (quadword align compiler issues).
```

