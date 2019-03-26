<?php
session_start();
if (!isset($_SESSION['login']))
    header("Location: login.html");
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>El Marketo</title>
    <link href="https://fonts.googleapis.com/css?family=Abel" rel="stylesheet">
    <link rel="stylesheet" type="text/css" media="screen" href="css/log.css"/>
    <link rel="stylesheet" type="text/css" media="screen" href="css/button.css"/>
</head>
<body bgcolor="#2A363B" style="margin: 0;">
<div class="head">
    <h1 align="center" class="headtitle">El Marketo</h1>
    <div class="dropdown">
        <button class="dropbtn">Catégories</button>
        <div class="dropdown-content">
            <a href="#">Sol</a>
            <a href="#">Air</a>
            <a href="#">Mer</a>
        </div>
    </div>
    <a><button class="logout">Se déconnecter</button></a>
    <a><button class="cart">Panier</button></a>
</div>
</body>
</html>