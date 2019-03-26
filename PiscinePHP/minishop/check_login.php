<?php
function check_pair($login, $passwd) {
    if (!file_exists("private/users"))
        return False;
    $fake_db = unserialize(file_get_contents("private/users"));
    foreach ($fake_db as $user_data)
        if (in_array($login, $user_data))
            if (password_verify($passwd, $user_data['passwd']))
                return True;
    return False;
}