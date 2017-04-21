#db2sock/tests

==Experimental==

c tests. 

# compile

```
optional (git already completed) ...
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

