#!/usr/bin/php
<?php
    $file = file_get_contents($argv[1]);
    echo preg_replace_callback(
            "/(?<=<a)((?!<\/a>)(\n|.))*(?=<\/a>)/",
            function ($matches) {
                $regex = '((?<=title=")((?!").)*(?="))|((?<=>)((?!<).)*(?=(<|$)))';
                return preg_replace_callback(
                        "/$regex/",
                        function ($matches) {
                            return strtoupper($matches[0]);
                        },
                        $matches[0]
                );
            },
            $file
    );
?>