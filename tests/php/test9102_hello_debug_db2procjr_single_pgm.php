<?php
$database   = getenv("PHP_DB");
$user       = getenv("PHP_UID");
$password   = getenv("PHP_PWD");

$clob = myjson();
print("Input:\n");
var_dump($clob);
print("Output:\n");

print("Waiting with debug message on *QSYSOPR ...\n");

$conn = db2_connect($database,$user,$password);
if (!$conn) die("Bad connect: $database,$user\n");

$stmt = db2_prepare($conn, "call DB2JSON.DB2PROCJR(?)");
if (!$stmt) die("Bad prepare: ".db2_stmt_errormsg());
$ret=db2_execute($stmt, array($clob));
if (!$ret) die("Bad execute: ".db2_stmt_errormsg());
$clobOut = "";
while ($row = db2_fetch_array($stmt)){
  $clobOut .= $row[0];
}
$clobOut = trim($clobOut);
var_dump($clobOut);

function myjson() {
$clob =
'{"pgm":[{"name":"HELLO",  "lib":"DB2JSON", "debugpgm":"stop pgm HELLO"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}';
return $clob;
}


?>
