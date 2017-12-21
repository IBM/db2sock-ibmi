<?php
$url        = getenv("PHP_URL"); // export PHP_URL=http://ut28p63/db2/db2json.pgm  (ILE-CGI - works partial)
                                 // export PHP_URL=http://ut28p63/db2json.db2  (fastcgi-PASE - works good)
$user       = getenv("PHP_UID"); // export PHP_UID=MYID
$password   = getenv("PHP_PWD"); // export PHP_MYPWD

$handle = 0;
for ($i=0;$i<2;$i++) {
  if ($i == 0) {
    $clob = myjson1();
  }
  else {
    $clob = myjson2($handle);
  }
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
  // poor mans json parsing (just for test)
  // "{"script":[{"query":[{"handle":3},...
  if ($i == 0) {
    $b1 = str_replace(array('[', '{', '}', ']', ',', "\n", ' ', ':'), "", $ret);
    $b2 = str_replace(array('"'), ":", $b1);
    $b3 = str_replace(array("::"), ":", $b2);
    $b4 = str_replace(array("::"), ":", $b3);
    $arr = explode(':',$b4);
    $handle = $arr[4];
    print("Handle:$handle\n");
  }
} 

function myjson1() {
$clob =
'{"connect":[
  {"qual":"fred"},
  {"query":[{"stmt":"select * from QIWS/QCUSTCDT"}, 
            {"fetch":[{"rec":2}]},
            {"fetch":[{"rec":2}]}
           ]}
]}
';
return $clob;
}
function myjson2($handle) {
$clob =
'{"connect":[
  {"qual":"fred"},
  {"query":[{"handle":'.$handle.'},
            {"fetch":[{"rec":"all"}]}
           ]}
]}
';
return $clob;
}


?>
