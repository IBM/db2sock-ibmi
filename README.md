#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock

Welcome to db2sock project. Goal is PASE DB2 CLI asynchronous API driver and more (libdb400.a).

A vast number of features have been added to new libdb400.a, async CLI, ILE direct CLI APIs, 
Unicode CLI "Unix" API (UTF-8), Unicode CLI "wide" APIs (UTF-16), and more.
These additions should make DB2 language extension writing easier.

Run time, libdb400.a should fit seamless under any existing scripting language db2 extension. 
That is to say, new libdb400.a exports everything old PASE libdb400.a, same synchronous CLI APIs,
but providing new advanced functions (above). At this time, new libdb400.a driver is designed to 
augment current PASE libdb400.a, therefore both must be on the machine. However, eventually new 
libdb400.a driver may replace PASE version entirely.  You do NOT have to recompile your language extension, 
simply set PASE LIBPATH for new libdb400.a. Possible configuration new/old libdb400.a (see Run below)

##design goals (the list)
- (**available**) No impact - libdb400.a should fit seamless under any existing scripting language db2 extension.
- (**available**) Service driver - provide good PASE side TRACE capabilities for service 
- (**available**) Traditional APIs - provide all current libdb400.a CLI APIs 
- (**available**) Wide APIs (UTF16) - provide all current missing libdb400.a 'wide' CLI APIs 
- (**available**) Async APIs - high performing async CLI APIs for all new PASE languages, 'callback' (nodejs), and, poll/reap (php).
- (**few**) Aggregate APIs - SQL400(API) prefix special APIs aggregate common functions/options 
- (**few**) JSON APIs - enable json only calls REST DB2 called by any language on/off IBM i (db2json - ILE CGI for Apache).
- (**none**) Socket APIs - enable socket based for ideas like 'private' connections
- (**none**) Toolkit APIs - replace xmlservice with consistent 'everything database' matching IBM DB2 current directions with service APIs


##Trace
The driver will trace CLI calls with env var TRACE (latest only).
TRACE supports a very high speed stack walk of function calls.
Recommend service and support people use TRACE for any new PASE language DB2 issue (much easier).
```
== file options /tmp/libdb400_trace_(pid) ==
export TRACE=on (file)
export TRACE=off

== output terminal ==
export TRACE=ws (console)

== trace file with coredump, read with dbx -W ==
export TRACE=stop (file + stop coredump)
```

#Build
Source links have topical README.md.
```
db2sock                      - libdb400.a - db2 driver source
db2sock/fastcgi              - db2jsonfcgi - fastcgi rest interface source (optional)
db2sock/ILE-CGI              - db2json.pgm - ILE CGI rest interface source (optional)
db2sock/toolkit-base         - libtkit400.a - toolkit base driver source (optional)
db2sock/toolkit-parser-json  - libjson400.a - toolkit json parser driver source (optional)
db2sock/tests_c              - c tests (optional)
db2sock/tests_php            - php tests (optional)
```

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

== libdb400.a ===
> cd db2sock
> make tgt32 tgt64 install

== libtkit400.a (optional) ===
> cd db2sock/toolkit-base
> make tgt32 tgt64 install

== libjson400.a (optional) ===
> cd db2sock/toolkit-parser-json
> make tgt32 tgt64 install

== db2jsonfcgi (optional) ===
> cd db2sock/fastcgi
> make tgt32 tgt64 install

== db2json.pgm (optional) ===
> export CHROOT=/path/chroot
> cd db2sock/ILE-CGI
> make cgi
```
Note: db2json.pgm requires borgi project (https://bitbucket.org/litmis/borgi)


##YIPS pre-compiled test vesion
* [YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver)

Install 'no LIBPATH' configuration (my machine and chroots). 
This enables every PASE language on the machine to start using new driver.
```
===
chroot only (ignore in root)
===
> mkdir -p /QOpenSys/QIBM/ProdData/OS400/PASE/lib
> cp /QOpenSys/usr/lib/libdb400.a /QOpenSys/QIBM/ProdData/OS400/PASE/lib/.
Note: 
- manditory save PASE libdb400.a (first time only)
- new driver uses PASE libdb400.a (above location)

===
install yips download pre-compile
===
> cp libdb400.a /QOpenSys/usr/lib/.
> cp libtkit400.a /QOpenSys/usr/lib/.
> cp libjson400.a /QOpenSys/usr/lib/.
```

#Run ILE CGI (optional)
REST json to libdb400.a [Source -> ILE-CGI/README.md](https://bitbucket.org/litmis/db2sock/src)

#Run PASE fastcgi (optional)
REST json to libdb400.a [Source -> fastcgi/README.md](https://bitbucket.org/litmis/db2sock/src)

#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.
- You can help test new libdb400.a driver to make sure there are no surprises (volunteers welcome).

#License
MIT


#DRIVER BUILDER SECTION
For driver builders.

1) Need to copy ILE CLI headers to PASE.
```
> cd pase_includes
> ./cpysqlincludes.sh 
> cp sqlcli1.h /QOpenSys/usr/include/.
```

2) edit PASE header to force gcc align quadword (aligned(16)).
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
qcmd:
> CRTLIB LIB(DB2JSON) TEXT('super driver')
> CHGUSRPRF USRPRF(DB2SOCK) LOCALE(*NONE) HOMEDIR('/QOpenSys/db2sock/./home/db2sock')

=> copy ILE DB2 headers into root /usr/include (before chroot)<=
bash-4.3$ cpysqlincludes.sh 

=> following run using *SECOFR profile (not user profile db2sock) <=
bash-4.3$ ./chroot_setup.sh chroot_minimal.lst /QOpenSys/db2sock
bash-4.3$ ./chroot_setup.sh chroot_includes.lst /QOpenSys/db2sock
bash-4.3$ ./chroot_setup.sh chroot_nls.lst /QOpenSys/db2sock
bash-4.3$ ./chroot_setup.sh chroot_OPS_GCC.lst /QOpenSys/db2sock
bash-4.3$ mkdir -p /QOpenSys/db2sock/home/db2sock
bash-4.3$ ./chroot_chown.sh db2sock
====
i set up auto-login from my laptop over ssh (http://www.rebol.com/docs/ssh-auto-login.html)
====
ssh -X db2sock@ut28p63
$ ksh
$ cd /QOpenSys/QIBM/ProdData/OPS/GCC/pkg
$ ./pkg_setup.sh pkg_perzl_bash-4.3.lst
$ export PATH=/opt/freeware/bin:/QOpenSys/usr/bin
$ bash
bash-4.3$ ./pkg_setup.sh pkg_perzl_gcc-4.8.3.lst
====
IMPORTANT: copy PASE libdb400.a to orignal location
====
mkdir -p /QOpenSys/QIBM/ProdData/OS400/PASE/lib
bash-4.3$ cp /QOpenSys/usr/lib/libdb400.a /QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a
===
IMPORTANT: as400_types.h must have force gcc align quadword  
===
bash-4.3$ cp pase_includes/* /QOpenSys/usr/include/
bash-4.3$ grep gcc /usr/include/as400*       
/usr/include/as400_types.h:    long double      align __attribute__((aligned(16))); /* force gcc align quadword */
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

#Author Notes

To be clear, **new libdb400.a synchronous driver CLI APIs are the same (today APIs).**
That is, new libdb400.a under most PASE languages will run exactly same code path. In fact, at present new libdb400.a 
will run 'original APIs' by calling old driver (/QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a).
You really should be able to slip this driver under your current PASE favorite script language and keep running (i am).

Specifically 'new' changes to old driver, **original UTF-8 (1208) and new UTF-16 (1200 - wide) APIs take 
alternate short path directly call ILE API database (no PASE iconv).** 
Current technical theory is all UTF-8/16 DB2 CLI APIs should work without old PASE libdb400.a iconv 'assistance'.
In unlikely event UTF-8/16 fast path proves untrue (not work), 
some new CLI APIs may return back to PASE iconv like current libdb400.a (old driver). 

All asynchronous APIs with suffix **'Async/Thread'** are new. 
Also, all aggregate APIs with prefix **'SQL400'** are new (mutiple call task APIs).  

**Current node.js issues are old driver.** The current async DB2 interfaces for Node.js on 
IBM i do NOT use this new driver. Specifically, any current issues or performance problems with 
node db2a having NOTHING to do with this new project (see future). 

**The goal is new APIs for any language.** To be clear, 'async' APIs are NOT just for 'async' Node.js, 
but can instead be applied to all PASE langs (PHP, Ruby, Python, etc).
Some languages will use 'async' poll/reap (php), others use async 'callback' (nodejs).

**Most of this code is generated by python gen.py.** This is not frivolous. 
Script generation allows for very rapid enhancement or change of underlying technology. 
All but ends programmer finger checks present in repeated monotony of code duplication (bored programmer). 
The basic calls through CLI are trivial (as intended), therefore very well suited to script generation. 
Due simple CLI interfaces we can add extended calls like 'Async' with high level of confidence in quality. 
Basically, have a thought, day later have a new API.

**The driver has thread mutex locking at the connection level for most CLI APIs.** 
DB2 is not completely thread safe. Simply stated, client PASE language side, do not share DB2 resources 
across threads (connections/statements). To this end, new libdb400.a driver uses a connection/thread-mutex. 
This means only one operation/statement will be running against a given QSQSRVR job at a time. Also, 
any single connection will not be used across multiple threads at the same time 
(mutex at connection level). However, any given client may have many threads each with a connection, 
running many QSQSRVR jobs executing same relative time profile indifferent.
(If you have difficulty understanding threads and mutexes, ignore, mutex will only confuse you. 
New libdb400.a just works fast enough 'async'.).

**On demand dynamic symbol resolution** is used for both up calls to ILE DB2 and old calls to PASE libdb400.a. 
A good thing! This will work fine without performance impact, because only APIs 'used' will be 'resolved' on first touch API. 
To wit, consider 98% of PASE applications are running as demons (php, node, ruby, etc.), and, use task repeatable CLI APIs 
(aka, connect, prepare/execute or query, fetch, related APIs), wherein, technically, repeatable tasks will 
'dynamic resolve' to ILE/PASE API 'first touch API' and re-use forever subsequent calls to API (once and done).  

**Open Source libdb400.a driver** does not mean poor quality. In fact, experts (me) are working on the new driver. 
This project is open because we want complete transparency on how your PASE new scripting language DB2 driver works. 
No more mystery, look at the source (and help). When available for production (notice removed top project), 
we will try to be very careful not to damage anything currently running. However, new people can have new ideas, 
so the new exotic 'non-architecture' APIs like 'Async' or 'SQL400' may change over time. 
Also, any new driver may introduce some behavior issues. If you have a recommendation, problem, so on, 
please feel free to use issues on git project (click 'Issues' left panel).



