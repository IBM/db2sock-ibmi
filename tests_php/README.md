#db2sock/tests_php

==Experimental==

php tests.

# run
```
> export PHP_DB=MYIBMI (*LOCAL)
> export PHP_UID=MYUID
> export PHP_PWD=MYPWD

Run all tests_json ...
> php run.php

Run driver tests_json ...
> php run_ibm_db2_set.php
> php run_ibm_db2_io.php
> php run_odbc.php

One at a time ...
> php test0000_do_thing32
```

