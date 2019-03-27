<?php
    function log_user($user) {
        session_start();
        if (isset($_SESSION['login']) && $_SESSION['login'] === $user)
            return True;
        $_SESSION['login'] = $user;
        return True;
    }
?>