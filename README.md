#------IMPORTANT WARNING -------
This project is under construction. APIs are changing daily, therefore, you should not use for ANY production purpose. 
When this warning disappears, APIs will be considered stable.


#db2sock

Welcome to the db2sock project. Goal is PASE DB2 CLI asynchronous API driver (libdb400.a).

A vast number of features have been added to new libdb400.a, async CLI, ILE direct CLI APIs, 
Unicode CLI "Unix" API (UTF-8), Unicode CLI "wide" APIs (UTF-16), and more.
These additions should make language extension writing easier.
CCSID topic describes new libdb400.a mode settings via SQLOverrideCCSID400(ccsid).

Run time, libdb400.a should fit seamless under any existing scripting language db2 extension. 
That is to say, exports everything old PASE libdb400.a, while providing advanced functions.
You do NOT have to recompile your language extension, simply set PASE LIBPATH for new libdb400.a.

Compile time, if you wish to exploit new features use the new header file PaseCliAsync.h.
After compiling with new features, you are runtime dependent on new libdb400.a.
Therefore, you will need to ship a copy of this shared library with your product.
If you do not wish to exploit new features, continue compiling with ILE sqlcli.h.

This project originated because of a need to create async DB2 requests for Node.js on IBM i, 
but it isn't just for Node.js and can instead be applied to all PASE langs (PHP, Ruby, Python, etc).

#Future
Many more features are planned, such as, tracing CLI APIs, debug message to joblog, socket based db2,
web based db2, json based db2, etc. Wildly imagined, if custom interfaces test well, one could
imagine gutting all languages extension to bare minimum script language interaction, leaving all
the real DB2 work to this driver (aka, new SQL400Connection(W) with attributes). For example, flight of
fancy, one could imagine, PHP mysql extension talking directly to this driver, wherein, any old 
PHP+mysql application would be instant DB2 (no port). Ok, no promise, but, you get the idea.

Author two cents, when stable, start using this driver, 
you will grow function by leaps with very little effort.


#CCSID
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


##Usage:

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
SQLRETURN libdb400_SQLExecDirect(..);
SQLRETURN libdb400_SQLExecDirectW(..); (*)

=== bypass all, call ILE directly (not recommended) ===
SQLRETURN ILE_SQLExecDirect(..);
SQLRETURN ILE_SQLExecDirectW(..);

```
SQLExecDirect is only an example,
see libdb400.exp for all exported APIs.

(*) PASE libdb400.a does not support wide CLI APIs.
Therefore, this libdb400.a simply calls ILE.


## Advanced features
Experimental advanced features, large, complex operations in one async call.

```
Convert:
SQL400ToUtf8
SQL400ToUtf8Async
SQL400ToUtf8Join
SQL400FromUtf8
SQL400FromUtf8Async
SQL400FromUtf8Join
SQL400ToUtf16
SQL400ToUtf16Async
SQL400ToUtf16Join
SQL400FromUtf16
SQL400FromUtf16Async
SQL400FromUtf16Join

Connect:
SQL400Connect
SQL400ConnectAsync
SQL400ConnectJoin
SQL400ConnectW
SQL400ConnectWAsync
SQL400ConnectWJoin
SQL400pConnect
SQL400pConnectAsync
SQL400pConnectJoin
SQL400pConnectW
SQL400pConnectWAsync
SQL400pConnectWJoin
SQL400Close
SQL400CloseAsync
SQL400CloseJoin
SQL400pClose
SQL400pCloseAsync
SQL400pCloseJoin

Command:
SQL400Cmd
SQL400CmdAsync
SQL400CmdJoin
SQL400ChgLibl
SQL400ChgLiblAsync
SQL400ChgLiblJoin
SQL400ChgCurLib
SQL400ChgCurLibAsync
SQL400ChgCurLibJoin

Fetch:
SQL400Fetch
SQL400FetchAsync
SQL400FetchJoin
SQL400FetchArray
SQL400FetchArrayAsync
SQL400FetchArrayJoin
SQL400FetchArrayW
SQL400FetchArrayWAsync
SQL400FetchArrayWJoin
SQL400FetchArrayFree
SQL400FetchArrayFreeAsync
SQL400FetchArrayFreeJoin

... many more ...
```

## JSON based web socket
```
assumes basic authorization (httpd.conf)

<Directory />       
   AuthType Basic
   AuthName "IBMi OS User Profile"
   Require valid-user
   PasswdFile %%SYSTEM%%
   Order Deny,Allow 
   Deny From all     
</Directory>
ScriptAlias /db2/ /QSYS.LIB/DB2JSON.LIB/
<Directory /QSYS.LIB/DB2JSON.LIB/>
  AllowOverride None
  order allow,deny
  allow from all
  SetHandler cgi-script
  Options +ExecCGI
  CGIConvMode BINARY
</Directory>

set test authorization (shell)
> export SQL_HOST400=lp0364d
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD

== node test db2 json 
> node nodejsrest.js

== curl test db2 json
> ./curltest.sh
> ./curltestnull.sh
```


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
Alternative pre-compiled Yips binary

* http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver 
* (test only, not production)


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
- PaseCliJson.h          -- db2 json interface (experimental)
- PaseCliJson.c          -- db2 json interface (experimental)

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

##Note:

Only compiled with xlc using -qldbl128 -qalign=natural. 
Missing these options will result in ILE DB2 call failures.
if curious, see /usr/include/as400_types.h, type ILEpointer -- quadword align compiler issues.
BTW -- i have no idea if gcc can be made to provide proper alignment (tbd).

#License
BSD

