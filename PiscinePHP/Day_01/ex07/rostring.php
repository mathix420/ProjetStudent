<?php
    if (count($argv) < 2)
        exit("Not enough parameters!\n");
    $string = preg_replace("/\s+/", " ", trim($argv[1]));
    $array = explode(" ", $string);
    foreach ($array as $index => $value){
        if ($index)
            echo $value." ";
    }
    echo $array[0]."\n";
?>