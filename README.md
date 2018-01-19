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
but providing new advanced functions (above). At this time, new libdb400.a driver is designed to 
augment current PASE libdb400.a, therefore both must be on the machine. However, eventually new 
libdb400.a driver may replace PASE version entirely.  You do NOT have to recompile your language extension, 
simply set PASE LIBPATH for new libdb400.a. Possible configuration new/old libdb400.a (see Run below)

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
db2sock/db2                  - libdb400.a - db2 driver source
db2sock/toolkit              - libtkit400.a - toolkit base driver source (optional)
                             - tkit400.srvpgm - ILE toolkit base driver source (remote)
db2sock/toolkit/fastcgi      - db2jsonfcgi - fastcgi rest interface source (optional)
                             - db2jsonngix - fastcgi cgi starter rest interface source (optional)
db2sock/toolkit/cgi          - db2json.pgm - ILE CGI rest interface source (optional)
db2sock/toolkit/proc         - db2proc.srvpgm - ILE toolkit service interface iCall400 source (optional)
db2sock/toolkit/proc-user    - db2user.srvpgm - ILE toolkit user special custom toolkit call enabler (optional)
db2sock/toolkit/procj        - db2procj, db2procjr, db2procjh - ILE stored procedures to call toolkit (remote) 
db2sock/toolkit/parser-json  - libjson400.a - toolkit json parser driver source (optional)
                             - json400.srvpgm - ILE toolkit json parser driver source (remote)
db2sock/tests/rpg            - RPG tests for tests_json (optional)
db2sock/tests/json           - json tests (optional)
db2sock/tests/c              - c tests (optional)
db2sock/tests/php            - php tests (optional)
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
```

#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.
- You can help test new libdb400.a driver to make sure there are no surprises (volunteers welcome).

#License
MIT


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

# A debate faster vs security

The following security discussion in-memory _PGMCALL/_ILECALL calling is for geeks only. 
This project is NOT (repeat NOT), implementing in-memory calling of ILE PGMS/SRVPGMs. 
Aka, safe toolkit as can be expected.

**The debate. Faster is not better. In fact, just plain unsafe (my argument).**

Everybody feels allure of 'going faster', toolkit calls no different. 
However recent events publicly indicated, 'faster' is not always 'better' (Specter and Meltdown).

**To point.**

A fork of this project is experimenting with in-memory calling of ILE PGMS/SRVPGMs for faster performance. 
The fork project uses faster in-memory toolkit calls with _PGMCALL/_ILECALL, aka, calling your RPG in-memory scripting. 
However, security side affects of in-memory calling in web scripting languages are substantial.

Why? All fast web servers supporting scripting languages use an idea of 'daemon' scripting jobs.
That is, scripting language stays active in a job(s) handling requests. 
Obviously, be careful what 'company data' we leave hanging around live in-memory in scripting language jobs. 
To wit, any company data still live in a script job can be hacked. 
Herein lies a major design flaw in faster fork copy of db2sock (my warning).

Note: Php is example, but applies to all scripting languages.

1) Company data live in php process is bad.

The fork project in-memory calls in a scripting job leaves company data active forever (easily hacked). 

Each time your script uses toolkit call a PGM/SRVPGM, the program is activated in the toolkit job. 
In fact, anything your srvpgm/pgm ran in job is 'live' in activated memory. 
Activation of your pgm/srvpgm is for life of the process. 
This also means any in-memory calls you made have data also 'live' for the life of the process.  
Scripting language jobs stay alive forever, therefore using in-memory calling (fork project), 
your company data is available for hacking. To hack, simple script recall last pgm/srvpgm anytime 
and get the last social security number (whatever laying around). Very unsafe (but fast).


2) QTEMP data left live php process is bad.

The fork project in-memory calls in a scripting language leaves QTEMP data active forever (easily hacked).

Many RPG programs use QTEMP 'work files' to hold intermediate results of complex operations. 
QTEMP is scoped to current process, therefore, when job ends all company 'work file' data disappears. 
Only rarely do RPG programs go out of the way to delete QTEMP company data. Like previous case (forked project), 
in-memory call QTEMP stays alive forever in the scripting language job. 
To hack, simple script read QTEMP in scripting language job. Very unsafe (but fast).

**easily hack (in-memory calls editorial)**

Basically fork project faster in-memory call is it's own worst enemy. 
That is, _PGMCALL/_ILECALL in-memory call 'good', can be used for in-memory call 'bad'. 

There are so many hack 'in-memory' state examples, a complete listing is impossible. 

Example (simple): Your 'good' script faster in-memory calls RPG program uses QTEMP file of credit card numbers. 
Great! However RPG program does not delete QTEMP files (oh oh). Hours later, a 'bad' hacker script uses 'faster' 
in-memory calls to read QTEMP using native file IO (open, read, close). Nasty! You've been hacked by in-memory 
leaving QTEMP hanging around with active data. 

Aka, 'faster' in-memory call is it's own worst enemy. 

There is no 'faster' free lunch with forked project db2sock. In fact, whole idea is likely bad for IBM i. 
I am not being evil. On contrary, fork project in-memory idea is clever(ish). I am simply trying to help avoid weeks of 
effort that will most likely ultimately be scraped.

BTW – PASE community suggestion of porting fflib to wrapper _PGMCALL/_ILECALL has been heralded as replacement for toolkits. 
Unfortunately this has same 'bad' in-memory hack consequences for web sites discussed. 
 

**You decide, speed vs secure**

To date, fork project author and myself have not been able to come to agreement on the risk.
I felt the issues are sever enough to warrent comment (sorry).

The main db2sock project uses QSQSRVR proxy jobs (db2 connect),
therefore company data is NOT live in any web server daemon job. In fact,  
most use 'stateless' QSQSRVR jobs, which is zero'd between uses (detach QSQSRVR job processing). 
Aka, safe toolkit as can be expected. 

You have facts, and, decide for yourself.

