<?php
    function ft_split($string) {
        $split = explode(" ", trim(preg_replace("/ +/", ' ', $string)));
        sort($split);
        return ($split);
    };
?>