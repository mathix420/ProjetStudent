#!/usr/bin/php
<?php
function cmp_mod($str1, $str2) {
    $new_ascii = array_merge(
        range(ord('a'), ord('z')),
        range(ord('0'), ord('9')),
        range(ord("\0"), ord('/')),
        range(ord(':'), ord('@')),
        range(ord('['), ord('`')),
        range(ord('{'), 127)
    );
    $index = 0;
    while ($index <= count($str1) + 1 && $index <= count($str2) + 1) {
        $val1 = array_search(ord(strtolower($str1)[$index]), $new_ascii);
        $val2 = array_search(ord(strtolower($str2)[$index]), $new_ascii);
        if ($val1 != $val2)
            break;
        $index++;
    }
    return ($val1 - $val2);
}

$array = array();
foreach ($argv as $index => $value) {
    if ($index) {
        $filtered = preg_replace("/\s+/", " ", trim($value));
        $array = array_merge($array, explode(" ", $filtered));
    }
}
usort($array, "cmp_mod");
foreach ($array as $value)
    echo $value . "\n";
?>
