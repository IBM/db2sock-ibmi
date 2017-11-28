<?php
$database   = getenv("PHP_DB");
$user       = getenv("PHP_UID");
$password   = getenv("PHP_PWD");

if (!extension_loaded('odbc')) {
    die('odbc not loaded');
}

function help() {
  die("Syntax: php test3000_sql400json_odbc.php ../json/j0001_pgm_hello");
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

$conn = odbc_connect($database,$user,$password);
if (!$conn) die("Bad connect: $database,$user");
$stmt = odbc_prepare($conn, "call DB2JSON.DB2PROCJH(?)");
if (!$stmt) die("Bad prepare: ".odbc_errormsg());
$ret=odbc_execute($stmt,array($clob));
if (!$ret) die("Bad execute: ".odbc_errormsg());
$clob = "";
while(odbc_fetch_row($stmt)) {
  $row = odbc_result($stmt,1);
  $chunk = explode("DEADBEEF", $row);
  $clob .= $chunk[0];
}
$clob = trim($clob);
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
