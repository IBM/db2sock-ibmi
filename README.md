#IMPORTANT WARNING -------------------------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.


#db2sock
Welcome to the db2sock project.  

Goal is PASE DB2 CLI asynchronous API driver (libdb400.a).
This new libdb400.a is replacement for PASE libdb400.a (default).
Replacement was done to add missing wide APIs to PASE driver.
Also, old driver was less than optimal dealing with CCSID.
However, compile chicken switch exists in generated code to use old libdb400.a (not recommended).
Follow on project maybe socket based driver (tbd).

This project originated because of a need to create async DB2 requests for Node.js on IBM i, 
but it isn't just for Node.js and can instead be applied to all PASE langs (PHP, Ruby, Python, etc).

##Usage:

Only compiled with xlc using -qldbl128 -qalign=natural. 
Missing these options will result in ILE DB2 call failures.
if curious, see /usr/include/as400_types.h, type ILEpointer -- quadword align compiler issues.
BTW -- i have no idea if gcc can be made to provide proper alignment (tbd).

In general, use CLI APIs, which, enable correct locking for async and non-async db2 operations.
However, feel free to use new direct call ILE DB2 APIs (ILE_SQLxxx). 
```
example:
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
SQLRETURN libdb400_SQLExecDirect(..); (no wide interfaces)

=== bypass all, call ILE directly (not recommended) ===
SQLRETURN ILE_SQLExecDirect(..);
SQLRETURN ILE_SQLExecDirectW(..);

```
SQLExecDirect is only an example,
see libdb400.exp for all exported APIs.

#CCSID
You should call SQLOverrideCCSID400(ccsid), before any other SQL activity (see tests).
Environment setting SQLOverrideCCSID400 defines how this libdb400.a operates.
```
=== UTF-8 mode, most popular AIX/PASE/Linux ===
SQLOverrideCCSID400(1208) -- UTF-8 mode, CLI normal/async direct ILE call
-->SQLExecDirect(Async)-->ILE_SQLExecDirect-->DB2
-->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2

=== UTF-8 mode, most popular Windows/Java ===
SQLOverrideCCSID400(1200) -- UTF-16 mode, CLI normal/async direct ILE call
-->SQLExecDirect(Async)-->ILE_SQLExecDirectW-->DB2
-->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2

=== PASE default (original libdb400.a) ===
SQLOverrideCCSID400(other) -- PASE ccsid, CLI API calls PASE libdb400.a
-->SQLExecDirect(Async)-->PASE libdb400.a(SQLExecDirect)-->DB2
-->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2 (*)

```
(*) PASE libdb400.a does not support wide CLI APIs.
Therefore, this libdb400.a simply calls ILE.


#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.

#Follow Along
We will be discussing things in the [Issues](http://bit.ly/db2sock-issues) section of this repo.  

# build
```
> python gen.py
> ./xlcmakeall
```

##gen.py creates: 
- PaseCliAsync.h         -- header asynchronous extensions (php, node, ...)
- PaseCliAsync_gen.c     -- asynchronous driver APIs
- PaseCliILE_gen.c       -- direct ILE call APIs (exported)
- PaseCliLibDB400_gen.c  -- PASE libdb400.a override dlsyms
- libdb400.exp           -- all CLI export APIs

##human coding:
- PaseCliCustom.c        -- 'big function' APIs (experimental)
- PaseCliInit.c          -- db2 resource table manager (read)
- PaseCliInit.h          -- db2 resource table header

##examples
```
build
> cd tests
> python genmake.py
> ./xlcmakeall

optional set user profile
> export SQL_DB400="*LOCAL"
> export SQL_UID400="UID"
> export SQL_PWD400="PWD"

run 32-bit or 64-bit
> testnnnn_32
> testnnnn_64
```
Note: APIs are changing daily, therefore, tests may change significantly.


#License
BSD

