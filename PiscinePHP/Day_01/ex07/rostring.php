#!/usr/bin/php
<?php
    if (count($argv) < 2)
        exit();
    $string = preg_replace("/\s+/", " ", trim($argv[1]));
    $array = explode(" ", $string);
    foreach ($array as $index => $value){
        if ($index)
            echo $value." ";
    }
    echo $array[0]."\n";
?>