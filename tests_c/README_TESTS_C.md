#db2sock/tests_c

==Experimental==

c tests. 

# compile

```
(genmake.py already completed) ...
$ cd db2sock/tests_c
$ python genmake.py

main db2sock/
> ./make_libdb400.sh test
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
> test0000_do_thing_32
> test0000_do_thing_64

```
