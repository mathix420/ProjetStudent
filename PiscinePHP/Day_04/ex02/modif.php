<?php
    if (isset($_POST['submit']) && $_POST['submit'] === "OK" && $_POST['newpw'] !== '') {
        if (!file_exists("../private/passwd")) {
            echo "ERROR\n";
            return;
        }
        $fake_db = unserialize(file_get_contents("../private/passwd"));
        foreach ($fake_db as &$user_data)
            if (in_array($_POST['login'], $user_data)) {
                if ($user_data['passwd'] === hash('sha512', $_POST['oldpw']))
                    $user_data['passwd'] = hash("sha512", $_POST['newpw']);
                else {
                    echo "ERROR\n";
                    return;
                }
            }
        file_put_contents("../private/passwd", serialize($fake_db), LOCK_EX);
        echo "OK\n";
    } else {
        echo "ERROR\n";
    }
?>
