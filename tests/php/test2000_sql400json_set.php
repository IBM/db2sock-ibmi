<?php
$database   = getenv("PHP_DB");
$user       = getenv("PHP_UID");
$password   = getenv("PHP_PWD");

function help() {
  die("Syntax: php test2000_sql400json_set.php ../json/j0001_pgm_hello");
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
$stmt = db2_prepare($conn, "call DB2JSON.DB2PROCJR(?)");
if (!$stmt) die("Bad prepare: ".db2_stmt_errormsg());
$ret=db2_execute($stmt, array($clob));
if (!$ret) die("Bad execute: ".db2_stmt_errormsg());
$clob = "";
while ($row = db2_fetch_array($stmt)){
  $clob .= $row[0];
}
$clob = trim($clob);
print("Output:\n");
var_dump($clob);

$sqlrc = 0;
$tok = strtok($clobexp, "\n");
while ($tok !== false) {
  $pos = strpos($clob,$tok);
  if ($pos === false) {
    print("fail missing ". $tok . "\n");
    $sqlrc = -1;
    break;
  } else {
    $sqlrc = 0;
  }
  $tok = strtok("\n");
}

if (!$sqlrc) {
  print("success (". $sqlrc . ")\n");
} else {
  print("fail (". $sqlrc . ")\n");
}

?>
