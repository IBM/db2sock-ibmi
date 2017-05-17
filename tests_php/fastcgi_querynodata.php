<?php
require "connection.inc";
$json = json_encode(
  array(
    "query" => "select * from QIWS.QCUSTCDT where LSTNAM='Not' or LSTNAM='Here'",
    "fetch" => "*ALL"
  )
);
$context = stream_context_create(
  array(
    'http' => array(
       'method'  => 'POST',
       'header'  => 
          "Content-Type: Content-Type: application/json\r\n".
          "Authorization: Basic " . base64_encode("$uid:$pwd"),
       'content' => $json
    )
  )
);
echo "url:$urlf\nrequest:$json\n";
$ret = file_get_contents($urlf, false, $context);
echo "response:\n";
if ($ret) {
  $result = json_decode($ret);
  var_dump($result);
} else {
  echo "Failed:\n";
  var_dump($ret);
}
?>
