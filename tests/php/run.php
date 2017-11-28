<?php
$path = "../json";
foreach (glob($path."/*.json") as $filename) {
  $baseFileName = basename($filename);
  $newFileName = substr($baseFileName, 0 , (strrpos($baseFileName, ".")));
  echo "\n\n***********************************\n";
  echo "ibm_db2 IN/OUT proc" . basename($newFileName) . "\n";
  echo `php test1000_sql400json.php $path/$newFileName`;

  echo "\n\n***********************************\n";
  echo "ibm_db2 RESULT SET proc" . basename($newFileName) . "\n";
  echo `php test2000_sql400json_set.php $path/$newFileName`;

  echo "\n\n***********************************\n";
  echo "odbc RESULT SET proc" . basename($newFileName) . "\n";
  echo `php test3000_sql400json_odbc.php $path/$newFileName`;

  echo "\n\n***********************************\n";
  echo "CGI basic auth" . basename($newFileName) . "\n";
  echo `php test4000_sql400cgi_basic_auth.php $path/$newFileName`;
}
?>
