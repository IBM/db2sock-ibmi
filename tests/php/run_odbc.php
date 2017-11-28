<?php
$path = "../json";
foreach (glob($path."/*.json") as $filename) {
  $baseFileName = basename($filename);
  $newFileName = substr($baseFileName, 0 , (strrpos($baseFileName, ".")));
  echo "\n\n***********************************\n";
  echo "odbc RESULT SET proc" . basename($newFileName) . "\n";
  echo `php test3000_sql400json_odbc.php $path/$newFileName`;
}
?>
