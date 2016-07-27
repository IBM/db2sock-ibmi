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
Your LIBPATH should not be set /opt/freeware first (below).
However, when compiling i often set /opt/freeware first.
So i usually use two ssh sessions (one compile, one test).

Makefiles removed /opt/freeware binaries (see Makefile).
At runtime (test time), we want only PASE binaries and new libdb400.a.

```
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

```


