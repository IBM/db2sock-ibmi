#db2sock/tests

==Experimental==

c tests. 

# compile

```
optional (git) ...
$ cd db2sock/tests
$ python genmake.py

gcc compile ...
$ cd db2sock/tests
$ ./make_tests.sh
```

# run
```
> export SQL_HOST400=myibmi
> export SQL_DB400=*LOCAL
> export SQL_UID400=MYUID
> export SQL_PWD400=MYPWD


One at a time ...
> test0004_async_callback_query_32
> test0004_async_callback_query_64

Run all ...
> python run.py

```

# note
Your LIBPATH should NOT be set /opt/freeware first (below).
However, when compiling i often set /opt/freeware first.
So i usually use two ssh sessions (one compile, one test).

Makefiles removed /opt/freeware binaries (see Makefile).
At runtime (test time), we want only PASE binaries and new libdb400.a.

```
bash-4.3$ cd tests

== bad libpath runtime ===

bash-4.3$ echo $LIBPATH
.:/opt/freeware/lib:/usr/lib

bash-4.3$ test0003_async_callback_connect_64
Could not load program test0003_async_callback_connect_64:
Could not load module /home/monoroot/libdb400/tests/./libdb400.a(shr_64.o).
        Dependent module /opt/freeware/lib/libiconv.a(shr4_64.o) could not be loaded.
        Member shr4_64.o is not found in archive 
Could not load module st0003_async_callback_connect_64.
        Dependent module /home/monoroot/libdb400/tests/./libdb400.a(shr_64.o) could not be loaded.
Could not load module .

== good LIBPATH set ===

bash-4.3$ export LIBPATH=.:/QOpenSys/usr/lib:/opt/freeware
bash-4.3$ test0003_async_callback_connect_64              
SQL400ConnectAsync (thread 258): connect running
SQL400ConnectAsync (thread 1): hi there from main thread
SUCCESS: tid valid) expect=1 actual=258
SQL400ConnectCallback (thread 258): hi there from callback thread
SQL400ConnectCallback (thread 258): complete: sqlrc=0, henv=1, db= uid= pwd=xxxx *ohnd=2 options=1800015a0 callback=180001248
SQL400ConnectCallback (thread 258): leaving
SUCCESS: operation complete) expect=1 actual=1

== good PASE default ==

bash-4.3$ unset LIBPATH
bash-4.3$ echo $LIBPATH

bash-4.3$ test0003_async_callback_connect_64
SQL400ConnectAsync (thread 258): connect running
SQL400ConnectAsync (thread 1): hi there from main thread
SUCCESS: tid valid) expect=1 actual=258
SQL400ConnectCallback (thread 258): hi there from callback thread
SQL400ConnectCallback (thread 258): complete: sqlrc=0, henv=1, db= uid= pwd=xxxx *ohnd=2 options=1800015a0 callback=180001248
SQL400ConnectCallback (thread 258): leaving
SUCCESS: operation complete) expect=1 actual=1


```


