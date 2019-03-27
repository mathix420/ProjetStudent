<?php
    include("check_log.php");
    if (!check_log())
        header("Location: login.html");
    session_start();
    $articles_db = array();
    if (file_exists("private/articles"))
        $articles_db = unserialize(file_get_contents("private/articles"));
    if (isset($_POST['article_id']) && !empty($_POST['submit']) && $_POST['submit'] === 'OK') {
        if (!($cart = unserialize($_SESSION['cart'])))
            $cart = array();
        if (!isset($cart[$_POST['article_id']])) {
            $article = $articles_db[$_POST['article_id']];
            $article['qte'] = 1;
            array_push($cart, $article);
        } else
            $cart[$_POST['article_id']]['qte']++;
        $_SESSION['cart'] = serialize($cart);
        header("Location: cart.php");
    } elseif (isset($_GET['del']) && isset($articles_db[$_GET['del']])) {
        if (!($cart = unserialize($_SESSION['cart'])))
            $cart = array();
        unset($cart[$_GET['del']]);
        $_SESSION['cart'] = serialize($cart);
    }
    $cart = unserialize($_SESSION['cart']);
    // if (!empty($_POST))
    //     header("Location: index.php");
?>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <title>Admin</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/header.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="/css/cart.css"/>
</head>

<body bgcolor="#2e3131" style="margin: 0;">
    <div class="head">
        <a href="/index.php">
            <h1 class="headtitle">El Marketo</h1>
            </ahref>
            <div class="cont">
                <a href="/logout.php">
                    <button class="logout">Se déconnecter</button>
                </a>
            </div>
    </div>
    <div id="shopping-cart">
        <h1>Shopping Cart</h1>
        <a id="btnEmpty" href="index.php?action=empty">Empty Cart</a>
        <table class="tbl-cart" cellpadding="10" cellspacing="1">
            <tbody>
                <tr>
                    <th style="text-align:left;">Nom</th>
                    <th style="text-align:left;">Description</th>
                    <th style="text-align:right;" width="5%">Qte.</th>
                    <th style="text-align:right;" width="10%">Prix<br>( in €)</th>
                    <th style="text-align:right;" width="10%">Total<br>( in €)</th>
                    <th style="text-align:center;" width="5%">Supprimer</th>
                </tr>
            <?php foreach ($cart as $index => $value) {?>
                <tr>
                    <td><img src="<?= $value['image'] ?>" class="cart-item-image"><?= htmlspecialchars($value['name']) ?></td>
                    <td><?= htmlspecialchars($value['description']) ?></td>
                    <td style="text-align:right;"><?= $value['qte'] ?></td>
                    <td style="text-align:right;"><?= number_format($value['price'], 2) ?></td>
                    <td style="text-align:right;"><?= number_format($value['price']*$value['qte'], 2) ?></td>
                    <td style="text-align:center;">
                        <a href="cart.php?del=<?= $index ?>" class="btnRemoveAction">❌</a>
                    </td>
                </tr>
            <?php } ?>
                <tr>
                    <td colspan="2" align="right">Total:</td>
                    <td align="right"><?= 1==1 ?></td>
                    <td align="right" colspan="2"><strong><?= 1==1 ?></strong></td>
                    <td></td>
                </tr>
            </tbody>
        </table>
    </div>
</body>

</html>