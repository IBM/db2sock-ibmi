#!/bin/sh
MYCONN="myconn"
SQL="{\"sql\":"\
"{\"connect\":"\
"{\"database\":\""\
$SQL_DB400\
"\",\"user\":\""\
$SQL_UID400\
"\",\"password\":\""\
$SQL_PWD400\
"\",\"qualify\":\""\
$MYCONN\
"\"},"\
"\"prepare\":\"select * from qiws.qcustcdt\","\
"\"execute\":null,"\
"\"fetch\":\"*\"}}"
echo "================="
echo "$SQL"
echo "================="

curl -u "$SQL_UID400:$SQL_PWD400" \
-G "http://lp0364d/db2/db2json.pgm" \
--data-urlencode "$SQL"

echo "\n"

