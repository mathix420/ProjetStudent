<?php
    function auth($login, $passwd) {
        if (!file_exists("../private/passwd"))
            return False;
        $fake_db = unserialize(file_get_contents("../private/passwd"));
        foreach ($fake_db as $user_data)
            if (in_array($login, $user_data))
                if ($user_data['passwd'] === hash("sha512", $passwd))
                    return True;
        return False;
    }
