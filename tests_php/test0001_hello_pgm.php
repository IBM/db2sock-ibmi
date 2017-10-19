<?php
$database   = getenv("PHP_DB");
$user       = getenv("PHP_UID");
$password   = getenv("PHP_PWD");
/* $blob = file_get_contents ("../tests_c/j0001_pgm_hello.json"); */
$blob =
'{"pgm":[{"name":"HELLO",  "lib":"DB2JSON"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}';
print("Input:\n");
var_dump($blob);
print("Output:\n");
$conn = db2_connect($database,$user,$password);
if (!$conn) die("Bad connect: $database,$user\n");
$stmt = db2_prepare($conn, "call DB2JSON.DB2PROCJ(?)");
if (!$stmt) die("Bad prepare: ".db2_stmt_errormsg());
$ret=db2_bind_param($stmt, 1, "blob", DB2_PARAM_INOUT);
$ret=db2_execute($stmt);
if (!$ret) die("Bad execute: ".db2_stmt_errormsg()."\n");
var_dump($blob);
?>
