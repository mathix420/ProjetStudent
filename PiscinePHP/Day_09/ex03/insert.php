<?php
    if (isset($_POST['id'], $_POST['text'])) {
        echo $_POST['id'] . $_POST['text'];
        $data[0] = "".$_POST['id'];
        $data[1] = base64_encode($_POST['text']);
        $f = fopen("list.csv", 'a+');
        flock($f, LOCK_EX);
        fputcsv($f, $data, ';', '"');
        flock($f, LOCK_UN);
        fclose($f);
    }
?>
