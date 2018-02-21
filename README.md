#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

#db2sock

Welcome to db2sock project. Goal is PASE DB2 CLI asynchronous API driver and more (libdb400.a).

A vast number of features have been added to new libdb400.a, async CLI, ILE direct CLI APIs, 
Unicode CLI "Unix" API (UTF-8), Unicode CLI "wide" APIs (UTF-16), and more.
These additions should make DB2 language extension writing easier.

## IBM i script language writers (DB2 extensions)

If you are attempting to build a new  IBM i language db2 driver (nodejs example), please consider contacting db2sock project issues.
That is, together, we should be able to add new APIs to db2sock (libdb400.a) to 'remedy' any db2 language coding difficult 
in your new language driver. I suggest we need only achieve a right balance of 'Aggregate APIs' in db2sock to fit real 
world of scripting language DB2 driver demands.

## features

Run time, libdb400.a should fit seamless under any existing scripting language db2 extension. 
That is to say, new libdb400.a exports everything old PASE libdb400.a, same synchronous CLI APIs,
but providing new advanced functions (above).

##design goals (the list)
- (**available**) No impact - libdb400.a should fit seamless under any existing scripting language db2 extension.
- (**available**) Service driver - provide good PASE side TRACE capabilities for service 
- (**available**) Traditional APIs - provide all current libdb400.a CLI APIs 
- (**available**) Wide APIs (UTF16) - provide all current missing libdb400.a 'wide' CLI APIs 
- (**available**) Async APIs - high performing async CLI APIs for all new PASE languages.
- (**few**) Aggregate APIs - SQL400(API) aggregate common functions/options (db2 extension writers) 
- (**none**) Socket APIs - enable socket based for ideas like 'private' connections (daemons like MySql) 
- (**partial**) Toolkit APIs - replace xmlservice (see JSON APIs, XML APIs, etc.)
- (**partial**) Toolkit JSON APIs - enable json only calls by any language on/off IBM i.
- (**none**) Toolkit XML APIs - enable json only calls by any language on/off IBM i.
- (**none**) LUW match libdb2.a - enable LUW DB2 source compiles without ifdef PASE 

# README.md (sub-directories).
```
/db2                  - libdb400.a - db2 driver source
/toolkit              - libtkit400.a - toolkit base driver source (optional)
                      - tkit400.srvpgm - ILE toolkit base driver source (remote)
/toolkit/fastcgi      - db2jsonfcgi - fastcgi rest interface source (optional)
                      - db2jsonngix - fastcgi cgi starter rest interface source (optional)
/toolkit/cgi          - db2json.pgm - ILE CGI rest interface source (optional)
/toolkit/proc         - db2proc.srvpgm - ILE toolkit service interface iCall400 source (optional)
/toolkit/proc-user    - db2user.srvpgm - ILE toolkit user special custom toolkit call enabler (optional)
/toolkit/procj        - db2procj, db2procjr, db2procjh - ILE clob/char stored procedures to call toolkit (remote) 
                      - db2procb, db2procbr            - ILE blob/bin stored procedures to call toolkit (remote) 
/toolkit/parser-json  - libjson400.a - toolkit json parser driver source (optional)
                      - json400.srvpgm - ILE toolkit json parser driver source (remote)
/tests/rpg            - RPG tests for tests_json (optional)
/tests/json           - json tests (optional)
/tests/c              - c tests (optional)
/tests/php            - php tests (optional)
```

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

##YIPS pre-compiled test vesion
* [YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver)

Install 'no LIBPATH' configuration (my machine and chroots). 
This enables every PASE language on the machine to start using new driver.
Any version 1.1.4-sg1(+) no longer require old shipped PASE libdb400.a.

```
===
install yips download pre-compile
===
call qp2term
== replace symbolic link with new libdb400.a (db2sock) ===
> ls -l /QOpenSys/usr/lib/libdb400.a
lrwxrwxrwx /QOpenSys/usr/lib/libdb400.a -> ../../QIBM/ProdData/OS400/PASE/lib/libdb400.a
> cp /QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a /QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a-save
> rm /QOpenSys/usr/lib/libdb400.a
> cp libdb400.a /QOpenSys/usr/lib/.
> cp /QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a-save /QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a
== additional toolkit modules ===
> cp libtkit400.a /QOpenSys/usr/lib/. (optional toolkit)
> cp libjson400.a /QOpenSys/usr/lib/. (optional json parser toolkit)
> cp db2jsonfcgi /QOpenSys/usr/lib/. (optional toolkit fastcgi 32 bit)
> cp db2jsonfcgi_64 /QOpenSys/usr/lib/. (optional toolkit fastcgi 64 bit)
> cp db2jsonngix /QOpenSys/usr/lib/. (optional toolkit fastcgi 32 bit)
> cp db2jsonngix_64 /QOpenSys/usr/lib/. (optional toolkit fastcgi 64 bit)
== ILE modules ==
qcmd (proc for toolkit + RPG tests)
RSTLIB SAVLIB(DB2JSON) DEV(*SAVF) SAVF(QGPL/DB2JSON)
===
reset original libdb400.a (when done new db2sock version ... or never ...)
===
> cd /QOpenSys/usr/lib
> ln -sf ../../QIBM/ProdData/OS400/PASE/lib/libdb400.a libdb400.a



## Obsolete 1.1.4-sg1(-)

The following instructions are for older db2sock drivers only prior 1.1.4-sg1.

Obsolete - At this time, new libdb400.a driver is designed to 
augment current PASE libdb400.a, therefore both must be on the machine. However, eventually new 
libdb400.a driver may replace PASE version entirely.  You do NOT have to recompile your language extension, 
simply set PASE LIBPATH for new libdb400.a. Possible configuration new/old libdb400.a (see Run below)


```
===
chroot only (ignore in root)
===
> mkdir -p /QOpenSys/QIBM/ProdData/OS400/PASE/lib
> cp /QOpenSys/usr/lib/libdb400.a /QOpenSys/QIBM/ProdData/OS400/PASE/lib/.
Note: 
- manditory save PASE libdb400.a (first time only)
- new driver uses PASE libdb400.a (above location)
```

#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.
- You can help test new libdb400.a driver to make sure there are no surprises (volunteers welcome).

#License
MIT


#Author Notes

To be clear, **new libdb400.a synchronous driver CLI APIs are the same (today APIs).**
That is, new libdb400.a under most PASE languages will run exactly same code path.
You really should be able to slip this driver under your current PASE favorite script language and keep running (i am).

Specifically 'new' changes to old driver, **original UTF-8 (1208) and new UTF-16 (1200 - wide) APIs take 
alternate short path directly call ILE API database (no PASE iconv).** 
Current technical theory is all UTF-8/16 DB2 CLI APIs should work without old PASE libdb400.a iconv 'assistance'.
In unlikely event UTF-8/16 fast path proves untrue (not work), 
some new CLI APIs may return back to PASE iconv similar current libdb400.a (old driver). 

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


