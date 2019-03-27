<?php
include("check_log.php");
$articles_db = array();
if (file_exists("private/articles"))
    $articles_db = array_filter(unserialize(file_get_contents("private/articles")));
if (!check_log())
    header("Location: login.html");
if (!empty($_POST))
    header("Location: index.php");
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>El Marketo</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Quicksand:300" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/log.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="/css/button.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="/css/article.css"/>
</head>
<body bgcolor="#2e3131" style="margin: 0;">
    <div class="head">
        <a href="index.php"><h1 class="headtitle">El Marketo</h1></ahref>
        <div class="cont">
        <div class="dropdown">
            <button class="dropbtn">Catégories</button>
            <div class="dropdown-content">
                <a href="#">Sol</a>
                <a href="#">Air</a>
                <a href="#">Mer</a>
            </div>
        </div>
        <a><button class="cart">Panier</button></a>
        <a href="/logout.php"><button class="logout">Se déconnecter</button></a>
        </div>
    </div>
    <div class="boutique">
        <?php foreach ($articles_db as $index => $article) { ?>
            <div class="card">
                <div class="article-card price-div">
                    <h1><?= htmlspecialchars($article['price']) ?>€</h1>
                    <form action="cart.php" method="post">
                        <input type="hidden" name="article_id" value="<?= $index ?>"/>
                        <p><button type="submit" value="OK" name="submit">Acheter</button></p>
                    </form>
                </div>
                <div class="article-card">
                    <div class="img-cont"><img src="<?= $article['image'] ?>" alt="image"></div>
                    <p><?= htmlspecialchars($article['name']) ?></p>
                    <p><?= htmlspecialchars($article['description']) ?></p>
                </div>
            </div>
        <?php } ?>
    </div>
</body>
</html>