#!/usr/bin/php
<?php
    if ($argc != 4 || !is_numeric(trim($argv[1])) || !is_numeric(trim($argv[3])))
        exit("Incorrect Parameters\n");
    switch ($argv[2][0]) {
        case '+':
            echo intval(trim($argv[1])) + intval(trim($argv[3])), "\n";
            break;
        case '-':
            echo intval(trim($argv[1])) - intval(trim($argv[3])), "\n";
            break;
        case '/':
            if (intval(trim($argv[3]) == 0))
                exit("Error : Division by zero\n");
            echo intval(trim($argv[1])) / intval(trim($argv[3])), "\n";
            break;
        case '%':
            if (intval(trim($argv[3]) == 0))
                exit("Error : Modulo by zero\n");
            echo intval(trim($argv[1])) % intval(trim($argv[3])), "\n";
            break;
        case '*':
            echo intval(trim($argv[1])) * intval(trim($argv[3])), "\n";
            break;
        default:
            exit("Incorrect Parameters\n");
    }
 ?>