#!/usr/bin/php
<?php
while (true) {
    echo "Entrez un nombre: ";
    $line = fgets(STDIN);
    if ($line == '')
        break;
    $line = trim($line);
    if (is_numeric($line)) {
        if (intval(substr($line, -1)) % 2 === 0)
            echo "Le chiffre $line est Pair\n";
        else
            echo "Le chiffre $line est Impair\n";
    } else
        echo "'$line' nest pas un chiffre\n";
}
echo "\n";
?>