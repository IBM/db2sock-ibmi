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
this libdb400.a driver may replace PASE version entirely. Possible configuration new/old libdb400.a (see Run below).


#Source
Source links have topical README.md.
```
db2sock               - build source libdb400.a
db2sock/tests         - PASE tests for libdb400.a
db2sock/db2json       - RPG CGI json interface to libdb400.a
db2sock/db2json/tests - tests for RPG CGI json interface
```

#pre-compiled test vesion new libdb400.a
* [YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver)
* (see Run topic for configuration)

#design goals (the list)
- (**available**) No impact - libdb400.a should fit seamless under any existing scripting language db2 extension.
- (**available**) Service driver - provide good PASE side TRACE capabilities for service 
- (**available**) Traditional APIs - provide all current libdb400.a CLI APIs 
- (**available**) Wide APIs (UTF16) - provide all current missing libdb400.a 'wide' CLI APIs 
- (**partial**) Async APIs - high performing async CLI APIs for all new PASE languages, 'callback' (nodejs), and, poll/reap (php).
- (**partial**) Aggregate APIs - SQL400(API) prefix special APIs aggregate common functions/options 
- (**partial**) JSON APIs - enable json only calls REST DB2 called by any language on/off IBM i (db2json - RPG CGI for Apache).
- (**none**) Socket APIs - enable socket based for ideas like 'private' connections
- (**none**) Toolkit APIs - replace xmlservice with consistent 'everything database' matching IBM DB2 current directions with service APIs

#Run (w/LIBPATH)
Place new libdb400.a in some directory (mytest).
Use LIBPATH env var to loader order first the new libdb400.a. 
Do not replace PASE libdb400.a (someday).
```
$ ksh (or bash)
$ ls /mytest/libdb400.a
libdb400.a
$ export LIBPATH=/mytest/lib:/QOpenSys/usr/lib
$ run-my-scripts-or-whatever
```

#Run (w/o LIBPATH)
Possible 'no LIBPATH' configuration (my machine and chroots). 
This enables every PASE language on the machine to start using the new driver.
```
===
both libdb400.a drivers on machine (my machine)
===
> cp libdb400.a /QOpenSys/usr/lib/libdb400.a
/QOpenSys/usr/lib/libdb400.a                          (new driver)
> ln -sf /QOpenSys/usr/lib/libdb400.a /usr/lib/libdb400.a
/usr/lib/libdb400.a -> /QOpenSys/usr/lib/libdb400.a   (new driver symbolic link)
== no change (PASE original) ===
/QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a     (orignal PASE driver - do not alter)

Note: PASE PTFs may revert back to original old driver (re-do).

===
problems (change back to original)?
===
> cd /QOpenSys/usr/lib
> ln -sf ../../QIBM/ProdData/OS400/PASE/lib/libdb400.a libdb400.a

Note: 'Change back' (above), assumes symbolic /usr/lib PASE as shipped. Please verify.
bash-4.3$ ls -l /usr/lib
lrwxrwxrwx    1 qsys     0                34 Dec 22 2015  /usr/lib -> /QOpenSys/usr/lib
bash-4.3$ ls -l /QOpenSys/usr/lib/libdb400.a
lrwxrwxrwx    1 qsys     0                90 Dec 22 2015  /QOpenSys/usr/lib/libdb400.a -> ../../QIBM/ProdData/OS400/PASE/lib/libdb400.a
bash-4.3$ ls -l /usr/lib/libdb400.a
lrwxrwxrwx    1 qsys     0                90 Dec 22 2015  /usr/lib/libdb400.a -> ../../QIBM/ProdData/OS400/PASE/lib/libdb400.a
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

#Future
Many more features are planned, such as, tracing CLI APIs, debug message to joblog, socket based db2,
web based db2, json based db2, etc. Perhaps replace existing PASE language 'drivers' with consistent
versions that support all the APIs, async, wide, json, socket, etc. 

## DB2 async (future)
Basic 'async' poll/reap vs. callback (not actual):
At times simple example is best. These are not actual APIs, 
but demonstrate idea 'async' in languages that may not have
callback.

'async' poll/reap example (not actual):
```
// request did NOT halt did NOT halt PHP
$poll = db2_async_query_fetch('select * from lib/file');
// check $result did NOT halt PHP
while(!($result = db2_result_poll($poll))) {
  // do something else with php
  $clean = check_laundry('home');
  if (!$clean) send_laundry('home');
}
// query result available now
foreach ($result as $row) {
  foreach ($row as $key => $value) {
    print("data: $key,$value");
  }
}
```

'async' callback example (not actual):
```
// request did NOT halt node
db2_async_query_fetch('select * from lib/file', function(result) {
  for (var i = 0; i < result.length; i++) {
    var row = result[i];
    for (var j = 0; j < rows.length; j++) {
      var col = rows[j];
      console.log("data: " + col.key + "," + col.value);
    }
  }
}
// do something else with node
check_laundry('home', function(clean) {
  if (!clean) { send_laundry('home'); }
}
```
## DB2 REST kerberos/EIM (future)
Perhaps json interface completely
http REST request configured as PASE fastcgi or ILE cgi. 
(see source db2json)
```
php, node, ruby, python <-json-Apache/ngix-> db2 libdb400 JSON server
Note: 
- Enables DB2 kerberos automatically, because Apache provides (free).
- Enables any version of EIM style DB2 profile switch, again because Apache provides (free).
```  

## DB2 map other databases (future)
Imagination run wild, db2 socket interface 
'map' other socket based database requests into db2.
```
php, node, ruby, python mysql/maria client <-port 3306-> db2 libdb400 socket server
```

## Disclaimer future
Ok, no promise, but, you get the idea. A basic design change is needed to PASE libdb400.a to enable a better future.
We would like to do this publicly so ALL may clearly understand libdb400.a technology, and, possibly contribute.
Author two cents, when stable, start using this driver, you will grow function by leaps with very little effort.

###Notes
Clarification to avoid conspiracy.

To be clear, new libdb400.a synchronous driver CLI APIs are the same (today APIs).
That is, new libdb400.a under most PASE languages will run exactly same code path. In fact, at present new libdb400.a 
will run 'original APIs' by calling old driver (/QOpenSys/QIBM/ProdData/OS400/PASE/lib/libdb400.a).

Specifically 'new' changes to old driver, original UTF-8 (1208) and new UTF-16 (1200 - wide) APIs take 
alternate short path directly call ILE API database (no PASE iconv). 
Current technical theory is all UTF-8/16 DB2 CLI APIs should work without old PASE libdb400.a iconv 'assistance'.
In unlikely event UTF-8/16 fast path proves untrue (not work), 
some new CLI APIs may return back to PASE iconv like current libdb400.a (old driver). 

All asynchronous APIs with suffix 'Async/Thread' are new. Also, all aggregate APIs with prefix 'SQL400' are new (mutiple call task APIs).  

**Current node.js issues are old driver.** The current async DB2 interfaces for Node.js on 
IBM i do NOT use this new driver. Specifically, any current issues or performance problems with 
node db2a having NOTHING to do with this new project (see future). 

To be clear, 'async' APIs are NOT just for Node.js, but can instead be applied to all PASE langs (PHP, Ruby, Python, etc).
Some languages will use the 'async' pool (reap), others use async 'callback' (nodejs). The goal
is APIs for any language (see sample following).

Most of this code is generated by python gen.py. This is not frivolous programmer play time. 
Script generation allows for very rapid enhancement or change of underlying technology. 
All but ends programmer finger checks present in repeated monotony of code duplication (bored programmer asleep at desk). 
The basic calls through CLI are trivial (as intended), therefore very well suited to script generation. 
Due simple CLI interfaces we can add extended calls like 'Async' with high level of confidence in quality. 
Basically, have a thought, day later have a new API.

Experts. Yes. The driver has mutex locking at the connection level for most CLI APIs. 
This means only one operation will be running against a given QSQSRVR job at a time. 
However, as normal, any given client may have many QSQSRVR jobs executing at the same relative time using different connection 
(same profile, many profiles). Ignoring politics, DB2 is not completely thread safe, therefore libdb400.a 
connection mutex is required to avoid language driver builders going crazy adding ton of exception code 
(aka, language driver builders going crazy means ... run this API, then this, then this, but not this, 
or that, put your left foot in, pull your left foot out, do the hokey pokey and turn yourself about 
... threaded DB2 API works).  

#Contributors
- Tony Cairns, IBM
- Aaron Bartell, Krengel Technology, Inc.
- You can help test new libdb400.a driver to make sure there are no surprises (volunteers welcome).

#Follow Along
We will be discussing things in the [Issues](http://bit.ly/db2sock-issues) section of this repo.  

#License
MIT

#Service (export TRACE=on/off)
Driver service information moved to README_TRACE.md [see source](https://bitbucket.org/litmis/db2sock/src)

#Build
Build information has been moved to README_BUILD.md [see source](https://bitbucket.org/litmis/db2sock/src)

#ChangeLog
See progress [YIPS test version binary](http://yips.idevcloud.com/wiki/index.php/Databases/SuperDriver):



