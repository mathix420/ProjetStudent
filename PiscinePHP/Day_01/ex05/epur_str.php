#!/usr/bin/php
<?php
    if (count($argv) < 2)
        exit();
    $string = trim($argv[1]);
    $string = preg_replace("/\s+/", " ", $string);
    echo $string."\n";
?>