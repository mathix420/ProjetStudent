#!/usr/bin/php
<?php
    if ($argc >= 2) {
        echo preg_replace("/[ \t]+/", " ", $argv[1]);
    }
?>