#!/usr/bin/php
<?php
    if ($argc == 3) {
        $key_id = -1;
        if (!file_exists($argv[1]))
            exit();
        $fp = fopen($argv[1], "r");
        $header = fgetcsv($fp, 0, ';');
        foreach ($header as $index => $get_key) {
            if ($get_key == $argv[2] && $get_key !== '')
                $key_id = $index;
        }
        if ($key_id == -1) #bad key name
            exit();
        while (($line = fgetcsv($fp, 0, ';')) != '') {
            foreach ($header as $index => $item)
                if ($item !== '')
                    eval ("\$$item" . "['$line[$key_id]'] = \$line[$index];");
        }
        fclose($fp);
        while (true) {
            echo "Entrez votre commande: ";
            $line = trim(fgets(STDIN));
            if ($line == '')
                break;
            eval($line);
        }
        echo "\n";
    }
?>