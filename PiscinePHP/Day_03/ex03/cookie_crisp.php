<?php
    if (!isset($_GET['action']) || !isset($_GET['name']))
        exit();
    switch ($_GET['action']) {
        case "set":
            setcookie($_GET['name'], $_GET['value']);
            break;
        case "get":
            echo $_COOKIE[$_GET['name']];
            break;
        case "del":
            setcookie($_GET['name'], '');
            break;
    }
?>