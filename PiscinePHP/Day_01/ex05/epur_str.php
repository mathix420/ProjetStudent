<?php
    if (count($argv) > 2)
        exit("To many parameters!\n");
    else if (count($argv) < 2)
        exit("Not enough parameters!\n");
    $string = trim($argv[1]);
    $string = preg_replace("/\s+/", " ", $string);
    echo $string."\n";
?>