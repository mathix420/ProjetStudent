<?php
include("../ft_log.php");
session_start();
if (!file_exists("../private"))
    mkdir("../private");
$users_db = array();
if (file_exists("../private/users"))
    $users_db = array_filter(unserialize(file_get_contents("../private/users")));
if ($users_db[$_SESSION['login']]['rights'] != -2) {
    header("HTTP/1.0 403 Forbidden");
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}
if (isset($_GET['delete'])) {
    unset($users_db[$_GET['delete']]);
    $f = fopen("../private/users", "w");
    flock($f, LOCK_EX);
    file_put_contents("../private/users", serialize(array_filter($users_db)));
    flock($f, LOCK_UN);
    fclose($f);
    header("Location: user.php");
}
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Admin/User</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="../css/admin.css"/>
</head>
<body bgcolor="#2e3131" style="margin: 0;">
<div class="head">
    <a href="/index.php"><h1 class="headtitle">El Marketo</h1></ahref>
    <div class="cont">
        <a href="/admin/index.php">
            <button class="cart">Home admin</button>
        </a>
        <a href="/logout.php">
            <button class="logout">Se déconnecter</button>
        </a>
    </div>
</div>
<div class="admintab">
    <div>
            <h2 class="texte">Supprimez un utilisateurs</h2>
    </div>
</div>
<?php
$users_db = array_filter($users_db, function($R) {return( $R['rights'] !== -2);});
if (count($users_db)) { ?>
<div class="admin-tab-center">
    <table>
        <tbody>
        <?php
        foreach ($users_db as $id => $article) {
            if ($article['rights'] !== -2) { ?>
                <tr>
                    <td class="admintab-texte" align="center"><?= htmlspecialchars($id) ?></td>
                    <td class="admintab-texte" align="center"><a href="/admin/user.php?delete=<?= $id ?>">❌</a></td>
                </tr>
                <?php
            }}
        }
        ?>
        </tbody>
    </table>
</div>
</body>
</html>
