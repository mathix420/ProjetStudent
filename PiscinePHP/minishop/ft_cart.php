<?php
//fonctions de gestion panier
    function get_cart($users_db) {
        if (isset($_SESSION['login'], $users_db[$_SESSION['login']])) {
            if ($cart = unserialize($users_db[$_SESSION['login']]['cart']))
                return $cart;
            return array();
        }
        elseif (isset($_COOKIE['cart']) && ($cart = unserialize(decrypt_data($_COOKIE['cart']))))
            return $cart;
        else
            return array();
    }
    function save_cart($data, $users_db) {
        if (isset($_SESSION['login'], $users_db[$_SESSION['login']])) {
            $users_db[$_SESSION['login']]['cart'] = serialize($data);
            file_put_contents("private/users", serialize(array_filter($users_db)), LOCK_EX);
        }
        else
            setcookie('cart', encrypt_data(serialize($data)));
    }
?>