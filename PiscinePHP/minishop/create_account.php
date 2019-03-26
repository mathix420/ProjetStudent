<?php
include('ft_log.php');
$error_image = "respond.jpg";
if (isset($_POST['login'], $_POST['passwd'], $_POST['rpasswd'], $_POST['submit'])) {
    if ($_POST['rpasswd'] !== $_POST['passwd'] || $_POST['submit'] !== 'OK') {
        $error_message = ($_POST['submit'] !== 'OK') ? "Mauvaise requette !" : "Mot de passes non identiques !";
        $error_image = ($_POST['submit'] !== 'OK') ? "respond.jpg" : "brain_not_found.jpg";
    }
    else if ($_POST['passwd'] === '' || $_POST['login'] === '') {
        $error_message = "Le mot de passe et le login ne peuvent pas être vides !";
        $error_image = "empty_pass.jpg";
    }
    else {
        if (!file_exists("private"))
            mkdir("private");
        $fake_db = array();
        if (file_exists("private/users"))
            $fake_db = unserialize(file_get_contents("private/users"));
        foreach ($fake_db as $user_data) {
            if ($_POST['login'] == $user_data['login']) {
                $error_message = "Le pseudo existe déjà !";
                $error_image = "Baby-Clone.jpg";
                break;
            }
        }
        if ($error_message == '') {
            $user_credential['login'] = $_POST['login'];
            $user_credential['passwd'] = password_hash($_POST['passwd'], PASSWORD_DEFAULT);
            $user_credential['rights'] = -1;
            array_push($fake_db, $user_credential);
            file_put_contents("private/users", serialize($fake_db));
            log_user($_POST['login']);
            header("Location: index.php");
        }
    }
}
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Erreur</title>
</head>
<body bgcolor="#2A363B" style="color: white;">
    <h1 align='center'><?= $error_message ?></h1>
    <p align='center'><img src='img/<?= $error_image ?>' alt="error"></p>
</body>
</html>
