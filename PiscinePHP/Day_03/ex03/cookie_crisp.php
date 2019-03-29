<?php
    if (!isset($_GET['action']) || !isset($_GET['name']))
        exit();
    switch ($_GET['action']) {
        case "set":
            setcookie($_GET['name'], $_GET['value']);
            break;
        case "get":
			if ($_COOKIE[$_GET['name']])
				echo $_COOKIE[$_GET['name']]."\n";
            break;
        case "del":
            setcookie($_GET['name'], '');
            break;
    }
?>