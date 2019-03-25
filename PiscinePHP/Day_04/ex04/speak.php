<?php
session_start();
setlocale(LC_TIME, "fr_FR");
date_default_timezone_set("Europe/Paris");
if (isset($_POST['submit']) && isset($_SESSION['loggued_on_user']) && $_POST['submit'] === 'SEND') {
    if (!file_exists("../private"))
        mkdir("../private");
    $chat_db = array();
    if (file_exists("../private/chat"))
        $chat_db = unserialize(file_get_contents("../private/chat"));
    $line['login'] = $_SESSION['loggued_on_user'];
    $line['time'] = time();
    $line['msg'] = $_POST['msg'];
    array_push($chat_db, $line);
    $fp = fopen("../private/chat", "w");
    flock($fp,LOCK_EX);
    file_put_contents("../private/chat", serialize($chat_db));
    flock($fp, LOCK_UN);
    fclose($fp);
}
?>
<style>
    html, body {
        margin: 0;
        height: 50px;
    }
</style>
<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
<form action="speak.php" method="post" style="width: 100%; text-align: center; height: 100%; margin: auto;">
    <input type="text" name="msg" style="width: 90%; height: 75%; margin-top: 5px; font-size: 1.3em;"/>
    <input type="submit" value="SEND" name="submit" hidden="true"/>
</form>