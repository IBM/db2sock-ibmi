<?php
$url = getenv("SQL_HOST400");                                                                 
$db = getenv("SQL_DB400");                                                                 
$uid = getenv("SQL_UID400");                                                                 
$pwd = getenv("SQL_PWD400");
if (!$url) {
  $url = "http://ut28p63/db2/db2json.pgm";
}
$postdata = http_build_query(
array (
"json" => "{\"query\":\"select * from QIWS/QCUSTCDT where LSTNAM='Jones' or LSTNAM='Vine'\",\"fetch\":\"*ALL\"}"
)
);
$context = stream_context_create(
array(
    'http' => array(
        'header'  => "Authorization: Basic " . base64_encode("$uid:$pwd"),
        'method'  => 'POST',
        'content' => $postdata
    )
));
$ret = file_get_contents($url, false, $context);
var_dump($ret);
?>
