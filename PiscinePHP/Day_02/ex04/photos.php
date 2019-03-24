#!/usr/bin/php
<?php
    if ($argc == 2) {
        $file = file_get_contents($argv[1]);
        $split = parse_url($argv[1]);
        if (file_exists($split['host']))
            exit("Directory already exists!\n");
        preg_match_all("/(?<=<img)((?!>).)*(?=>)/", $file, $images);
        mkdir($split['host']);
        foreach ($images[0] as $image) {
            preg_match_all("/(?<=src=\")((?!\").)*(?=\")/", $image, $urls);
            foreach ($urls[0] as $url) {
                if (!preg_match("/^https?:\/\//", $url))
                    $url = join("/", array(trim($argv[1], '/'), trim($url, '/')));
                $infos = pathinfo(parse_url($url)['path']);
                while (file_exists($split['host']."/".$infos['basename']))
                    $infos['basename'] = $infos['filename'] . $i++ . "." . $infos['extension'];
                $image = copy($url, $split['host']."/".$infos['basename']);
            }
        }
    }
?>