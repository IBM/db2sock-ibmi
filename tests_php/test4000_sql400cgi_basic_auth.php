<?php
$url        = getenv("PHP_URL"); // export PHP_URL=http://ut28p63/db2/db2json.pgm
$user       = getenv("PHP_UID"); // export PHP_UID=MYID
$password   = getenv("PHP_PWD"); // export PHP_MYPWD

function help() {
  die("Syntax: php test4000_sql400cgi_basic_auth.php ../tests_json/j0001_pgm_hello");
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
$clob = file_get_contents($url, false, $context);
print("Output:\n");
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
