<?php
$fp = fopen("/etc/passwd","r");
if($fp)
{
echo 'ok!';
$result = fread($fp,
8192);
return $result;
echo $result;
}
else
{
echo 'no!';
}
?>