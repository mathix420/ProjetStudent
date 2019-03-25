#!/usr/bin/php
<?php
    $array = array();
    foreach ($argv as $index => $value) {
        if ($index) {
            $filtered = preg_replace("/\s+/", " ", trim($value));
            $array = array_merge($array, explode(" ", $filtered));
        }
    }
    sort($array);
    foreach ($array as $value)
        echo $value."\n";
?>
