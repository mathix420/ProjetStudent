<?php
    $f = fopen("list.csv", 'r');
    flock($f, LOCK_SH);
    $header = fgetcsv($f, 0, ';');
    while ($line = fgetcsv($f, 0, ';')) {
        $id = $line[0];
        $name = $line[1];
        echo "<div id='$id' onclick='del_todo(\"$id\");'>$name</div>";
    }
    flock($f, LOCK_UN);
    fclose($f);
?>
