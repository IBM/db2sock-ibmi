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

Run all ...
> python run.py


One at a time ...
> test0000_do_thing32
> test0000_do_thing64
```

