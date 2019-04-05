<?php
    if (isset($_POST['id'])) {
        $csv = file_get_contents("list.csv");
        print_r(explode(PHP_EOL, $csv));
        $lines = array_filter(explode(PHP_EOL, $csv), function($data) {
            return (!preg_match("/^".$_POST['id'].";.*/", $data));
        });
        file_put_contents("list.csv", join(PHP_EOL, $lines), LOCK_EX);
    }
?>