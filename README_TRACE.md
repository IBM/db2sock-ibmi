#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.

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

