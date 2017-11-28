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
$stmt = db2_prepare($conn, "call DB2JSON.DB2PROCJ(?)");
if (!$stmt) die("Bad prepare: ".db2_stmt_errormsg());
$ret=db2_bind_param($stmt, 1, "clob", DB2_PARAM_INOUT);

$clob = myjson();
$ret=db2_execute($stmt);
if (!$ret) die("Bad execute: ".db2_stmt_errormsg()."\n");
var_dump($clob);

function myjson() {
$clob =
'{"pgm":[{"name":"HELLO",  "lib":"DB2JSON", "debugpgm":"stop pgm HELLO"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}';
return $clob;
}


?>
