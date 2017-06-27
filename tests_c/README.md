#db2sock/tests_c

==Experimental==

c tests. 

# compile

```
$ make tgt32 tgt64
```

# run
```
(optional missing env will work many cases)
> export SQL_HOST400=myibmi
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD

Tests expect TRACE ...
> export TRACE=stop (coredumps expected where test stated)
-- or --
> export TRACE=on

Run all ...
> python run.py


One at a time ...
> test0000_do_thing32
> test0000_do_thing64
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
