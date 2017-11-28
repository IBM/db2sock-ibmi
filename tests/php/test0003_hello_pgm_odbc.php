<?php
$database   = getenv("PHP_DB");
$user       = getenv("PHP_UID");
$password   = getenv("PHP_PWD");

if (!extension_loaded('odbc')) {
    die('odbc not loaded');
}


$clob = myjson();
print("Input:\n");
var_dump($clob);
print("Output:\n");

$conn = odbc_connect($database,$user,$password);
if (!$conn) die("Bad connect: $database,$user");
$stmt = odbc_prepare($conn, "call DB2JSON.DB2PROCJH(?)");
if (!$stmt) die("Bad prepare: ".odbc_errormsg());
$ret=odbc_execute($stmt,array($clob));
if (!$ret) die("Bad execute: ".odbc_errormsg());
$clobOut = "";
while(odbc_fetch_row($stmt)) {
  $row = odbc_result($stmt,1);
  $chunk = explode("DEADBEEF", $row);
  $clobOut .= $chunk[0];
}
$clobOut = trim($clobOut);
var_dump($clobOut);

function myjson() {
$clob =
'{"pgm":[{"name":"HELLO",  "lib":"DB2JSON"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}';
return $clob;
}


?>
