<?php
    $f = fopen("list.csv", 'r');
    flock($f, LOCK_SH);
    $header = fgetcsv($f, 0, ';');
    while ($line = fgetcsv($f, 0, ';')) {
        $id = $line[0];
        $name = htmlspecialchars(base64_decode($line[1]));
        echo "<li id='$id' onclick='del_todo(\"$id\");'>$name</li>";
    }
    flock($f, LOCK_UN);
    fclose($f);
?>
