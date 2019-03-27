#!/usr/bin/php
<?php
    function get_all_moy($data) {
        $data_moy = array();
        foreach ($data as $name => $grades) {
            foreach ($grades as $grade) {
                $data_moy[$name] += intval($grade);
            }
            $data_moy[$name] /= count($grades);
        }
        ksort($data_moy);
        return ($data_moy);
    }
    function sum_moy($data) {
        $moy = 0;
        $count = 0;
        foreach ($data as $name => $grades)
            foreach ($grades as $grade) {
                $count++;
                $moy += intval($grade);
            }
        return ($moy / $count);
    }
    function get_gap($mouli_data, $data_moy) {
        $out = array();
        ksort($mouli_data);
        foreach ($mouli_data as $name => $mouligrade) {
            $out[$name] = $data_moy[$name] - $mouligrade;
        }
        return ($out);
    }
    function print_keyarray($array) {
        foreach ($array as $name => $value) {
            echo $name.":".$value."\n";
        }
    }
    $data = array();
    $mouli_data = array();
    fgetcsv(STDIN, 0, ";");
    while ($line = fgetcsv(STDIN, 0, ";")) {
        $line[0] = trim($line[0]);
        $line[1] = trim($line[1]);
        if ($line[1] != '' && $line[2] != "moulinette") {
            if (!array_key_exists($line[0], $data))
                $data[$line[0]] = array($line[1]);
            else
                array_push($data[$line[0]], $line[1]);
        }
        elseif ($line[1] != '') {
            if (!array_key_exists($line[0], $mouli_data))
                $mouli_data[$line[0]] = $line[1];
        }
    }
    switch ($argv[1]) {
        case "moyenne":
            echo sum_moy($data)."\n";
            break;
        case "moyenne_user":
            print_keyarray(get_all_moy($data));
            break;
        case "ecart_moulinette":
            $moy = get_all_moy($data);
            print_keyarray(get_gap($mouli_data, $moy));
            break;
    }
?>