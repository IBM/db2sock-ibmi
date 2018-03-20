#db2sock build notes

##make (see Yips pre-compile to skip) 
Please read DRIVER BUILDER SECTION before compile.
```
===
chroot only (ignore in root)
===
> mkdir -p /QOpenSys/QIBM/ProdData/OS400/PASE/lib
> cp /QOpenSys/usr/lib/libdb400.a /QOpenSys/QIBM/ProdData/OS400/PASE/lib/.
Note: 
- manditory save PASE libdb400.a (first time only)
- new driver uses PASE libdb400.a (above location)

== chroot path (ILE compiles) ===
> export CHROOT=/path/chroot

=== build everything ===
> ./makeall.sh
> ./makeclean.sh
(see make file for individual compiles)
```
Notes: 

- requires borgi project (https://bitbucket.org/litmis/borgi)

- libjson400.a json toolkit parser is optionally dynamically loaded via SQL400Json API. 
This default parser may be replaced by any Open Source json parser (DIY enabled).

- libtkit400.a toolkit runner is dynamically loaded via SQL400Json API with libjson400.a.
This object provides toolkit functions similar to XMLSERVICE (db2proc.srvpgm).
You must build db2proc.srvpgm db2 procedure before libtkit400.a to create proc/iconf.h.
At runtime you may override db2 procedure library location with env var TOOLLIB (optional).


#DRIVER BUILDER SECTION
For driver builders.

1) Need to copy ILE CLI headers to PASE.
```
> ./db2sock/pase_includes/cpysqlincludes.sh 
> cp db2sock/pase_includes/sqlcli1.h /QOpenSys/usr/include/.
```

2) edit PASE header to force gcc align quadword (aligned(16)).
```
===
IMPORTANT: as400_types.h must have force gcc align quadword (see edit above) 
===
> grep gcc /usr/include/as400*       
/usr/include/as400_types.h:    long double      align __attribute__((aligned(16))); /* force gcc align quadword */

=== edit this file ===
/usr/include/as400_types.h:
/*
 * Quadword (aligned) area for a tagged ILE pointer
 */
typedef union _ILEpointer {
#if !(defined(_AIX) || defined(KERNEL))
#pragma pack(1,16,_ILEpointer)	/* Force sCC quadword alignment */
#endif
/* CAUTION: Some compilers only provide 64-bits for long double */
/*========================GCC CHANGE =================================*/
#if defined( __GNUC__ )
    long double	align __attribute__((aligned(16))); /* force gcc align quadword */
#else
    long double align;	/* Force xlc quadword alignment (with -qldbl128 -qalign=natural) */
#endif
/*========================GCC CHANGE =================================*/
#ifndef _AIX
    void		*openPtr; /* MI open pointer (tagged quadword) */
#endif
    struct {
	char		filler[16-sizeof(uint64)];
	address64_t	addr;	/* (PASE) memory address */
    } s;
} ILEpointer;
```
Note:
If you miss aligned(16) step, all will compile, but NOTHING will run (DB2 fails).

##gen.py creates (do not edit): 
- PaseCliAsync.h         -- header asynchronous extensions (php, node, ...)
- PaseCliAsync_gen.c     -- asynchronous driver APIs
- PaseCliILE_gen.c       -- direct ILE call APIs (exported)
- PaseCliLibDB400_gen.c  -- PASE libdb400.a override dlsyms (replace someday)
- PaseCliDump_gen.c      -- TRACE each CLI API with full stack walk (cool)
- libdb400.exp           -- all CLI export APIs

#DRIVER BUILDER TOOLS
How i set-up my tools. I used either GNU gmake or PASE make (gmake shown below).

```
====
outside chroot -- *SECOFR
====
qcmd:
> CRTLIB LIB(DB2JSON) TEXT('super driver')
> CHGUSRPRF USRPRF(DB2SOCK) LOCALE(*NONE) HOMEDIR('/QOpenSys/db2sock/./home/db2sock')

=> copy ILE DB2 headers into root /usr/include (before chroot)<=
bash-4.3$ ./db2sock/pase_includes/cpysqlincludes.sh 
bash-4.3$ cp db2sock/pase_includes/sqlcli1.h /QOpenSys/usr/include/.
===
IMPORTANT: as400_types.h must have force gcc align quadword (see edit above) 
===
bash-4.3$ grep gcc /usr/include/as400*       
/usr/include/as400_types.h:    long double      align __attribute__((aligned(16))); /* force gcc align quadword */

=> following run using *SECOFR profile (not user profile db2sock) <=
bash-4.3$ ./chroot_setup.sh chroot_minimal.lst /QOpenSys/db2sock
bash-4.3$ ./chroot_setup.sh chroot_includes.lst /QOpenSys/db2sock
bash-4.3$ ./chroot_setup.sh chroot_nls.lst /QOpenSys/db2sock
bash-4.3$ ./chroot_setup.sh chroot_OPS_GCC.lst /QOpenSys/db2sock
bash-4.3$ mkdir -p /QOpenSys/db2sock/home/db2sock
bash-4.3$ ./chroot_chown.sh db2sock


====
enter chroot 
db2sock auto-login from my laptop over ssh (http://www.rebol.com/docs/ssh-auto-login.html)
====
ssh -X db2sock@ut28p63
$ ksh
$ cd /QOpenSys/QIBM/ProdData/OPS/GCC/pkg
$ ./pkg_setup.sh pkg_perzl_bash-4.3.lst
$ export PATH=/opt/freeware/bin:/QOpenSys/usr/bin
$ bash
bash-4.3$ ./pkg_setup.sh pkg_perzl_gcc-4.8.3.lst
====
IMPORTANT: copy PASE libdb400.a to orignal location (one time only)
====
mkdir -p /QOpenSys/QIBM/ProdData/OS400/PASE/lib
bash-4.3$ cp /QOpenSys/usr/lib/libdb400.a /QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a
===
try make
===
bash-4.3$ gmake tgt32 tgt64 install 
make: *** virtual memory exhausted.  Stop.
====
i needed new gmake (and m4)
http://yips.idevcloud.com/wiki/index.php/PASE/OpenSourceBinaries
====
bash-4.3$ wget400 http://yips.idevcloud.com/wiki/uploads/PASE/gmake-4.2.zip
bash-4.3$ wget400 http://yips.idevcloud.com/wiki/uploads/PASE/m4-1.4.17.zip
bash-4.3$ unzip gmake-4.2.zip 
bash-4.3$ unzip m4-1.4.17.zip
bash-4.3$ cp gmake /opt/freeware/bin/gmake 
bash-4.3$ cp m4 /opt/freeware/bin/m4       
===
re-try make
===
bash-4.3$ gmake tgt32 tgt64 install 

```

