<?php
$database   = getenv("PHP_DB");
$user       = getenv("PHP_UID");
$password   = getenv("PHP_PWD");

function help() {
  die("Syntax: php test1000_sql400json.php ../json/j0001_pgm_hello");
}

if (!isset($argv) || !isset($argv[1])) {
  help();
}
$filepath = $argv[1];
$clobjson = file_get_contents ($filepath . ".json");
$clobexp = file_get_contents ($filepath . ".exp");
if (!$clobjson || !$clobexp) {
  help();
}


print("\n====================================\n");
print($filepath . "\n");
$clob = $clobjson;
print("Input:\n");
var_dump($clob);

$conn = db2_connect($database,$user,$password);
if (!$conn) die("fail connect: $database,$user\n");
$stmt = db2_prepare($conn, "call DB2JSON.DB2PROCJ(?)");
if (!$stmt) die("fail prepare: ".db2_stmt_errormsg());
$ret=db2_bind_param($stmt, 1, "clob", DB2_PARAM_INOUT);
$ret=db2_execute($stmt);
if (!$ret) die("fail execute: ".db2_stmt_errormsg()."\n"); 
print("Output:\n");
var_dump($clob);

$sqlrc = 0;
$tok = strtok($string, "\n");
while ($tok !== false) {
  if (!strpos($clob,$tok)) {
    print("fail missing ". $tok . "\n");
    $sqlrc = 0;
    break;
  }
  $tok = strtok("\n");
}

if (!$sqlrc) {
  print("success (". $sqlrc . ")\n");
} else {
  print("fail (". $sqlrc . ")\n");
}

?>
