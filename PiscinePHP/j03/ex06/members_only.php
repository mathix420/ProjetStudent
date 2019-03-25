<?php
    if (!isset($_SERVER['PHP_AUTH_USER'])) {
        header('WWW-Authenticate: Basic realm="\'Espace membres\'"');
        header('HTTP/1.0 401 Unauthorized');
        echo "Cette zone est accessible uniquement aux membres du site";
        exit;
    } elseif ($_SERVER['PHP_AUTH_USER'] === "zaz" && $_SERVER['PHP_AUTH_PW'] === "jaimelespetitsponeys"){
        $encoded_data = base64_encode(file_get_contents("../img/42.png"));
        echo "Bonjour Zaz<br>";
        echo "<img src='data:image/png;base64,$encoded_data'>";
    } else {
        $_SERVER['PHP_AUTH_USER'] = '';
        header('HTTP/1.0 401 Unauthorized');
        echo "Cette zone est accessible uniquement aux membres du site";
    }
?>