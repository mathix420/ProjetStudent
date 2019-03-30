<?php
    if (isset($_POST['submit']) && $_POST['submit'] === "OK" && $_POST['passwd'] !== '') {
        if (!file_exists("../private"))
            mkdir("../private");
        $fake_db = array();
        if (file_exists("../private/passwd")) {
            $fake_db = unserialize(file_get_contents("../private/passwd"));
        }
        foreach ($fake_db as $user_data)
            if (in_array($_POST['login'], $user_data)) {
                echo "ERROR\n";
                return ;
            }
        $user_credential['login'] = $_POST['login'];
        $user_credential['passwd'] =  hash("sha512", $_POST['passwd']);
        array_push($fake_db, $user_credential);
        file_put_contents("../private/passwd", serialize($fake_db), LOCK_EX);
        echo "OK\n";
    } else {
        echo "ERROR\n";
    }
?>