<?php
    setlocale(LC_TIME, "fr_FR");
    date_default_timezone_set("Europe/Paris");
    if (!file_exists("../private/chat"))
        exit();
    $tab = unserialize(file_get_contents("../private/chat"));
    foreach ($tab as $key => $content) { ?>
        [ <?= date("G:i", $content['time']) ?> ] <b> <?= $content['login'] ?> </b>: <?= htmlspecialchars($content['msg']) ?> <br>
<?php } ?>