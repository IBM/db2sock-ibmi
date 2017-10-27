<?php
$path = "../tests_c";
foreach (glob($path."/*.json") as $filename) {
  $baseFileName = basename($filename);
  $newFileName = substr($baseFileName, 0 , (strrpos($baseFileName, ".")));
  echo "\n\n***********************************\n";
  echo "IN/OUT proc" . basename($newFileName) . "\n";
  echo `php test1000_sql400json.php $path/$newFileName`;
  echo "\n\n***********************************\n";
  echo "RESULT SET proc" . basename($newFileName) . "\n";
  echo `php test2000_sql400json_set.php $path/$newFileName`;
}
?>
