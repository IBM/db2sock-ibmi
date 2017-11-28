<?php
$url        = getenv("PHP_URL"); // export PHP_URL=http://ut28p63/db2/db2json.pgm  (ILE-CGI - works partial)
                                 // export PHP_URL=http://ut28p63/db2json.db2  (fastcgi-PASE - works good)
$user       = getenv("PHP_UID"); // export PHP_UID=MYID
$password   = getenv("PHP_PWD"); // export PHP_MYPWD

$clob = myjson();
print("Input:\n");
var_dump($clob);
print("Output:\n");


$context  = stream_context_create(
  array('http' =>
    array(
      'method'  => 'POST',
      'header'  => "Content-type: application/x-www-form-urlencoded\r\n".
                   "Authorization: Basic " . base64_encode("$user:$password"),
      'content' => $clob
    )
  )
);
$ret = file_get_contents($url, false, $context);
var_dump($ret);

function myjson() {
$clob =
'{"pgm":[{"name":"HELLO",  "lib":"DB2JSON"},
        {"s":{"name":"char", "type":"128a", "value":"Hi there"}}
       ]}';
return $clob;
}


?>
