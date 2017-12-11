#db2sock/tests_php

==Experimental==

php tests.

# run
```
> export PHP_URL=http://ut28p63/db2/db2json.pgm  (ILE-CGI - works partial)
> export PHP_URL=http://myibmi/db2json.db2  (fastcgi- apache or nginx - works good)
--- optional ---
> export PHP_DB=MYIBMI (*LOCAL)
> export PHP_UID=MYUID
> export PHP_PWD=MYPWD

Run all tests_json ...
> php run.php

Run driver tests_json ...
> cd db2sock/tests/php
> php run_ibm_db2_set.php
> php run_ibm_db2_io.php
> php run_odbc.php
> php run_odbc.php
> php test4000_sql400cgi_basic_auth.php

Note: Basic auth is ignored by nginx (do not have to change).


One at a time ...
> php test0000_do_thing32
```

