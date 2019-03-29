<?php
    if (!isset($_SERVER['PHP_AUTH_USER'])) {
        header('WWW-Authenticate: Basic realm="\'Espace membres\'"');
        header('HTTP/1.0 401 Unauthorized');
        echo "Cette zone est accessible uniquement aux membres du site";
        exit;
    } elseif ($_SERVER['PHP_AUTH_USER'] === "zaz" && $_SERVER['PHP_AUTH_PW'] === "jaimelespetitsponeys"){
        $encoded_data = base64_encode(file_get_contents("../img/42.png"));
		echo "<body><html>\n";
        echo "Bonjour Zaz<br>\n";
        echo "<img src='data:image/png;base64,$encoded_data'>\n";
		echo "</body></html>\n";
    } else {
        $_SERVER['PHP_AUTH_USER'] = '';
        header('HTTP/1.0 401 Unauthorized');
        echo "<body><html>Cette zone est accessible uniquement aux membres du site</body></html>\n";
    }
?>
