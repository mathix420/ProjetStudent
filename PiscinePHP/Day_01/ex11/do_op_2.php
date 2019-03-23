#!/usr/bin/php
<?php
function do_op($val1, $val2, $op) {
    if ($val1 === "" || $val2 === "")
        exit("Syntax Error\n");
    switch ($op) {
        case '+':
            echo intval(trim($val1)) + intval(trim($val2)), "\n";
            break;
        case '-':
            echo intval(trim($val1)) - intval(trim($val2)), "\n";
            break;
        case '/':
            if (intval(trim($val2) == 0))
                exit("Error : Division by zero\n");
            echo intval(trim($val1)) / intval(trim($val2)), "\n";
            break;
        case '%':
            if (intval(trim($val2) == 0))
                exit("Error : Modulo by zero\n");
            echo intval(trim($val1)) % intval(trim($val2)), "\n";
            break;
        case '*':
            echo intval(trim($val1)) * intval(trim($val2)), "\n";
            break;
    }
}

if ($argc !== 2)
    exit("Incorrect Parameters\n");
$ops = array('+', '-', '*', '/%');
$str = trim($argv[1]);
$array = array();
while ((is_numeric(ltrim(join("", $array))) || !strlen(ltrim(join("", $array)))
        || in_array(ltrim(join("", $array)), array('+', '-'))) && $i < strlen($str)) {
    array_push($array, $str[$i++]);
}
$i--;
array_pop($array);
$val1 = trim(join("", $array));
while (ctype_space($str[$i]))
    $i++;
$op = $str[$i++];
$array = array();
while ((is_numeric(ltrim(join("", $array))) || !strlen(ltrim(join("", $array)))
        || in_array(ltrim(join("", $array)), array('+', '-'))) && $i < strlen($str)) {
    array_push($array, $str[$i++]);
}
$val2 = trim(join("", $array));
if ($i !== strlen($str))
    exit("Syntax Error\n");
do_op($val1, $val2, $op);
?>