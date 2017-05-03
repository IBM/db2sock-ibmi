<?php
$url = getenv("SQL_HOST400");                                                                 
$db = getenv("SQL_DB400");                                                                 
$uid = getenv("SQL_UID400");                                                                 
$pwd = getenv("SQL_PWD400");
if (!$url || !$db || !$uid || !$pwd) {
  echo "Test stop. PHP tests are Apache Basic authorization.\n";
  echo "Expect env vars (sample):\n";
  echo "export SQL_HOST400=http://ut28p63/db2/db2json.pgm\n";
  echo "export SQL_DB400=*LOCAL\n";
  echo "export SQL_UID400=username\n";
  echo "export SQL_PWD400=password\n";
  exit();
}
?>
