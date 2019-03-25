<?php
    setlocale(LC_TIME, "fr_FR");
    date_default_timezone_set("Europe/Paris");
    if (file_exists("../private/chat"))
        $tab = unserialize(file_get_contents("../private/chat"));
    else
        exit();
    foreach ($tab as $key => $content) {
        echo "[" . date("G:i", $content['time']) . "] <b>" . htmlspecialchars($content['login']) . "</b>: " . htmlspecialchars($content['msg']) . "<br>\n";
    }
?>