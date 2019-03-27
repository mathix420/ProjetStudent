<?php
include("../ft_log.php");
session_start();
if (!file_exists("../private"))
    mkdir("../private");
$fake_db = array();
if (file_exists("../private/users"))
    $fake_db = array_filter(unserialize(file_get_contents("../private/users")));
if ($fake_db[$_SESSION['login']]['rights'] != -2) {
    header("HTTP/1.0 403 Forbidden");
    exit("<h1 align='center'>403 FORBIDDEN</h1>");
}
$articles_db = array();
if (file_exists("../private/articles"))
    $articles_db = array_filter(unserialize(file_get_contents("../private/articles")));
if (isset($_GET['delete'])) {
    unlink($articles_db[$_GET['delete']]['image']);
    unset($articles_db[$_GET['delete']]);
    array_push($articles_db, $tab);
    $f = fopen("../private/articles", "w");
    flock($f, LOCK_EX);
    file_put_contents("../private/articles", serialize(array_filter($articles_db)));
    flock($f, LOCK_UN);
    fclose($f);
    header("Location: index.php");
} elseif (isset($_FILES['image'], $_POST['price'], $_POST['description'], $_POST['name'], $_POST['categorie'])
    && $_POST['submit'] == "OK") {
    $tab['name'] = substr($_POST['name'], 0, 30);
    $tab['price'] = substr($_POST['price'], 0, 7);
    $tab['description'] = substr($_POST['description'], 0, 100);
    $tab['categorie'] = $_POST['categorie'];
    //FILE UPLOAD
    if (!file_exists("../img/article"))
        mkdir("../img/article");
    $target_dir = "../img/article/";
    $target_file = $target_dir . basename($_FILES["image"]["name"]);
    $i = 1;
    while (file_exists($target_file)) {
        $split = explode(".", basename($_FILES["image"]["name"]));
        $extension = array_pop($split);
        $target_file = $target_dir . join(".", $split) . $i++ . ".$extension";
    }
    $imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
    if (!getimagesize($_FILES["image"]["tmp_name"]))
        exit ("<h1 align='center'>Désolé, une erreur est survenue pendant le téléchargement.</h1>");
    if ($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
        && $imageFileType != "gif") {
        echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
        $uploadOk = 0;
    }
    if (move_uploaded_file($_FILES["image"]["tmp_name"], $target_file)) {
        $tab['image'] = $target_file;
    } else {
        exit ("<h1 align='center'>Désolé, une erreur est survenue pendant le téléchargement.</h1>");
    }
    /////
    array_push($articles_db, $tab);
    $f = fopen("../private/articles", "w");
    flock($f, LOCK_EX);
    file_put_contents("../private/articles", serialize($articles_db));
    flock($f, LOCK_UN);
    fclose($f);
    header("Location: index.php");
} else if (!isset($_POST['image'], $_POST['price'], $_POST['description'], $_POST['name'], $_POST['categorie'])) {
    $error_message = "Tout les champs doivent êtres remplis !";
    $error_image = "respond.jpg";
}
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Admin</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="../css/header.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="../css/admin.css"/>
</head>
<body bgcolor="#2e3131" style="margin: 0;">
<div class="head">
    <a href="/index.php"><h1 class="headtitle">El Marketo</h1></a>
    <div class="cont">
        <a href="/admin/user.php">
            <button class="cart">Users menu</button>
        </a>
        <a href="/logout.php">
            <button class="logout">Se déconnecter</button>
        </a>
    </div>
</div>
<div class="admintab">
    <div>
        <form method="post" action="../admin/index.php" enctype="multipart/form-data">
            <h2 class="texte">Ajoutez un article</h2>
            <input placeholder="name" type="text" name="name" size="27" class="info" maxlength="30">
            <input placeholder="description" type="text" name="description" size="27" class="info" maxlength="100">
            <input placeholder="price" type="number" name="price" size="27" class="info" min="0.00" max="99999.99" step="0.01">
            <section>
                <div class="select-group">
                    <select name="categorie">
                        <option>Avions</option>
                        <option>Bateaux</option>
                        <option>Voitures</option>
                    </select>
                    <div class="arrow">▼</div>
                </div>
            </section>
            <input type="file" name="image" size="27" class="info" id="image">
            <button type="submit" value="OK" name="submit" class="post">Créer</button>
        </form>
    </div>
</div>
<?php
if (count($articles_db)) { ?>
<div class="admin-tab-center">
    <table>
        <tbody>
        <?php
        foreach ($articles_db as $id => $article) { ?>
            <tr>
                <td class="admintab-texte" align="center"><?= htmlspecialchars($article['name']) ?></td>
                <td class="admintab-texte" align="center"><?= htmlspecialchars($article['description']) ?></td>
                <td class="admintab-texte" align="center"><?= htmlspecialchars($article['price']) ?>€</td>
                <td class="admintab-texte" align="center"><?= htmlspecialchars($article['categorie']) ?></td>
                <td class="admintab-texte" align="center"><img src="<?= htmlspecialchars($article['image']) ?>"></td>
                <td class="admintab-texte" align="center"><a href="/admin/index.php?delete=<?= $id ?>">❌</a></td>
            </tr>
            <?php
        }
        }
        ?>
        </tbody>
    </table>
</div>
</body>
</html>
