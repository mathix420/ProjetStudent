#!/usr/bin/php
<?php
    if ($argv[1] == "mais pourquoi cette demo ?")
        echo "Tout simplement pour quen feuilletant le sujet\non ne sapercoive pas de la nature de lexo\n";
    elseif ($argv[1] == "mais pourquoi cette chanson ?")
        echo "Parce que Kwame a des enfants\n";
    elseif ($argv[1] == "vraiment ?")
        if (rand(0, 1))
            echo "Oui il a vraiment des enfants\n";
        else
            echo "Nan cest parce que cest le premier avril\n";
?>