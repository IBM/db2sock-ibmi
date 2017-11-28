<?php
$path = "../json";
foreach (glob($path."/*.json") as $filename) {
  $baseFileName = basename($filename);
  $newFileName = substr($baseFileName, 0 , (strrpos($baseFileName, ".")));
  echo "\n\n***********************************\n";
  echo "rest ILE CGI db2json basic auth" . basename($newFileName) . "\n";
  echo `php test4000_sql400cgi_basic_auth.php $path/$newFileName`;
}
?>
