<?php
$path = "../tests_json";
foreach (glob($path."/*.json") as $filename) {
  $baseFileName = basename($filename);
  $newFileName = substr($baseFileName, 0 , (strrpos($baseFileName, ".")));
  echo "\n\n***********************************\n";
  echo "ibm_db2 IN/OUT proc" . basename($newFileName) . "\n";
  echo `php test1000_sql400json.php $path/$newFileName`;
}
?>
