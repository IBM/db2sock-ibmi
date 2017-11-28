<?php
$path = "../json";
foreach (glob($path."/*.json") as $filename) {
  $baseFileName = basename($filename);
  $newFileName = substr($baseFileName, 0 , (strrpos($baseFileName, ".")));
  echo "\n\n***********************************\n";
  echo "ibm_db2 RESULT SET proc" . basename($newFileName) . "\n";
  echo `php test2000_sql400json_set.php $path/$newFileName`;
}
?>
