<?php
    include("auth.php");
    session_start();
    if (isset($_POST['submit']) && $_POST['submit'] === 'OK' && auth($_POST['login'], $_POST['passwd'])) {
        $_SESSION['loggued_on_user'] = $_POST['login'];
?>
    <style>
        body {
            text-align: center;
        }
        p {
            margin: 0;
        }
        iframe {
            border-width: 0;
            width: 800px;
        }
    </style>
    <p>
        <iframe src="chat.php" name="chat" style="height: 550px;"></iframe>
    </p>
    <p>
        <iframe src="speak.php" name="speak" style="height: 50px; top: -1px; position: relative;"></iframe>
    </p>
<?php
    } else {
        $_SESSION['loggued_on_user'] = '';
        echo "ERROR\n";
    }
?>
