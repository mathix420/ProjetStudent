<?php
    session_start();
    if ($_GET['submit'] === "OK") {
        $_SESSION['login'] = $_GET['login'];
        $_SESSION['passwd'] = $_GET['passwd'];
    }
?>
<form action="index.php" method="get">
    <p>Identifiant: <input type="text" name="login" value="<?= $_SESSION['login'] ?>"/></p>
    <p>Mot de passe: <input type="text" name="passwd" value="<?= $_SESSION['passwd'] ?>"/></p>
    <p><input type="submit" value="OK" name="submit"></p>
</form>
