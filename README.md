#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.


#db2sock

Welcome to db2sock project. Goal is PASE DB2 CLI asynchronous API driver and more (libdb400.a).

A vast number of features have been added to new libdb400.a, async CLI, ILE direct CLI APIs, 
Unicode CLI "Unix" API (UTF-8), Unicode CLI "wide" APIs (UTF-16), and more.
These additions should make language extension writing easier.
CCSID topic describes new libdb400.a mode settings via SQLOverrideCCSID400(ccsid).

Run time, libdb400.a should fit seamless under any existing scripting language db2 extension. 
That is to say, exports everything old PASE libdb400.a, while providing advanced functions.
You do NOT have to recompile your language extension, simply set PASE LIBPATH for new libdb400.a.

At this time, this additional libdb400.a driver is designed to augment current PASE
libdb400.a. Therefore both must be on the machine. However, eventually
this libdb400.a driver may replace PASE version entirely.

NOTE: The current async DB2 requests for Node.js on IBM i do NOT use this driver, so current issues or
performance with node db2a having NOTHING to do with this new project (see future). We should be clear,
'async' APIs are NOT just for Node.js, but can instead be applied to all PASE langs (PHP, Ruby, Python, etc).
Some languages will use the 'async' pool (reap), others use async 'callback' (nodejs). The goal
is APIs for any language.

#design goals (the list)
- No impact - libdb400.a should fit seamless under any existing scripting language db2 extension.
- Service driver - provide good PASE side TRACE capabilities for service
- Traditional APIs - provide all current libdb400.a CLI APIs
- Wide APIs (UTF16) - provide all current missing libdb400.a 'wide' CLI APIs
- Aggregate APIs - SQL400(API) prefix special APIs aggregate common functions/options (factor common code all PASE lang drivers)
- Async APIs - high performing async CLI APIs for all new PASE languages (including Aggregate API interfaces). 
The async API interfaces should handle both 'callback' (nodejs), and, poll/reap (php).
- JSON APIs - enable json only calls (JSON Aggregate API interface). Allows future REST DB2 called by any language on/off IBM i
- Socket APIs - enable socket based for ideas like 'private' connections (private db2 serving)
- Toolkit APIs - replace xmlservice with consistent 'everything database' matching IBM DB2 current directions with service APIs

#Future
Many more features are planned, such as, tracing CLI APIs, debug message to joblog, socket based db2,
web based db2, json based db2, etc. Perhaps replace existing PASE language 'drivers' with consistent
versions that support all the APIs, async, wide, json, socket, etc.
Ok, no promise, but, you get the idea. Author two cents, when stable, start using this driver, 
you will grow function by leaps with very little effort.

#Run
Place new libdb400.a in some directory (mytest). 
Do not replace PASE /usr/lib/libdb400.a (someday).
```
$ export PATH=/mytest:$PATH
$ export LIBPATH=.:/mytest/lib:/usr/lib
$ run-my-scripts-or-whatever
```

This project gcc compiles are NOT using gcc runtime, aka,
not using perzl.org runtime elements, therefore 
do not put /opt/freeware front of LIBPATH (bad /opt/freeware).
```
bash-4.3$ echo $LIBPATH
.:/opt/freeware/lib:/usr/lib
bash-4.3$ test0003_async_callback_connect_64
Could not load program test0003_async_callback_connect_64:
Could not load module /home/monoroot/libdb400/tests/./libdb400.a(shr_64.o).
        Dependent module /opt/freeware/lib/libiconv.a(shr4_64.o) could not be loaded.
```

#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.

#Follow Along
We will be discussing things in the [Issues](http://bit.ly/db2sock-issues) section of this repo.  

#License
MIT

# pre-compiled Yips binary (test only, not production)
* http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver


#------ DRIVER CLI TRACE -------
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

== trace file with dbx 'live' stop kinda works (*expert*) ==
export TRACE=dbx (file + stop in dbx)
export DBXSRC="/home/srcdir1:/home/srcdir1:... "
(*) dbx 'live' stop
-- recommend using 'stop' coredump (works with less odd dbx stuff)
-- 32bit run execute complete leaves dbx job stuck, quit ok (ps -ef, kill -9 pid)
-- 64 bit hopeless (use 'stop' coredump option)
-- (dbx -W libdbx special flag DBX_SILENT=y -- see Yips site)
```

Example: Trace to file
```
bash-4.3$ export TRACE=on
bash-4.3$ ls /tmp
bash-4.3$ ./test0054_async_callback_query_fetch_array_64                    
main_environ (thread 1): starting
main_environ (thread 1): leaving
SQL400EnvironmentCallback (thread 258): starting
SQL400EnvironmentCallback (thread 258): complete: sqlrc=0, *ohnd=1 options=180001538 callback=180000d38
main_connect (thread 258): starting
:
bash-4.3$ ls /tmp/
libdb400_trace_129505
bash-4.3$ cat /tmp/libdb400_trace_129505 
SQLAllocHandle.129505.1492615392.1.tbeg +++success+++
SQLAllocHandle.129505.1492615392.1.walk printf_stack (ffffffffffff7a0)
SQLAllocHandle.129505.1492615392.1.walk dump_SQLAllocHandle (fffff950 10001a04e4298 a5f1bb7c 9001000a5f1bb7c)
SQLAllocHandle.129505.1492615392.1.walk SQLAllocHandle (104b8e0ddf00d a045a9a0 9001000a5f1bb7c)
SQLAllocHandle.129505.1492615392.1.walk custom_SQLOverrideCCSID400 (4b8a0449ab0)
:
```

Example: Trace to file, coredump when CLI sqlrc = SQL_ERROR
(use dbx -W with libdbx special flag DBX_SILENT=y -- see Yips site) 
```
bash-4.3$ export DBX_SILENT=y
bash-4.3$ export TRACE=stop             
bash-4.3$ ./test0001_theory_db2_error_32
Quit (core dumped)

bash-4.3$ tail /tmp/libdb400_trace_166187
SQLSetConnectAttr.166187.1492708424.1.walk dump_SQLSetConnectAttr (fffffffe 0 2713 0 0)
SQLSetConnectAttr.166187.1492708424.1.walk SQLSetConnectAttr (0 2713 0 0)
SQLSetConnectAttr.166187.1492708424.1.walk main (1 2ff22d1c)
SQLSetConnectAttr.166187.1492708424.1.retn SQLRETURN sqlrc 0xfffffffe (-2) SQL_INVALID_HANDLE (SQL_ERROR)
SQLSetConnectAttr.166187.1492708424.1.parm SQLHDBC hdbc 0x0 (0)
SQLSetConnectAttr.166187.1492708424.1.parm SQLINTEGER attrib 0x2713 (10003)
SQLSetConnectAttr.166187.1492708424.1.parm SQLPOINTER vParam 0x0 (0)
SQLSetConnectAttr.166187.1492708424.1.parm SQLINTEGER inlen 0x0 (0)
SQLSetConnectAttr.166187.1492708424.1.tend ---error---
SQLSetConnectAttr.166187.1492708424.1.stop ---force coredump---

bash-4.3$ dbx -W                        
Type 'help' for help.
[using memory image in core]
reading symbolic information ...
Quit in pthread_kill at 0xd6bf67fc ($t1)
0xd6bf67fc (pthread_kill+0x9c) 48000805          bl   0xd6bf7000 (thread_kill)    
(dbx) where
pthread_kill(??, ??) at 0xd6bf67fc
_p_raise(??) at 0xd6bf5c68
dump_force_SIGQUIT(mykey = "SQLSetConnectAttr.166187.1492708424.1"), line 19 in "PaseCliDump_gen.c"
dump_sqlrc_head_foot(mykey = "SQLSetConnectAttr.166187.1492708424.1", sqlrc = -2, beg = 0), line 62 in "PaseCliDump_gen.c"
dump_SQLSetConnectAttr(sqlrc = -2, hdbc = 0, attrib = 10003, vParam = (nil), inlen = 0), line 1985 in "PaseCliDump_gen.c"
SQLSetConnectAttr(hdbc = 0, attrib = 10003, vParam = (nil), inlen = 0), line 6766 in "PaseCliAsync_gen.c"
main(argc = 1, argv = 0x2ff22d1c), line 34 in "test0001_theory_db2_error.c"
(dbx) 

```

#------ DRIVER BUILDER SECTION -------
Build information has been moved to README_BUILD.md

