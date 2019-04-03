<?php
class Lannister {
    function sleepWith ($person) {
        if ($person instanceof Jaime || $person instanceof Cersei)
            echo "Not even if I'm drunk !".PHP_EOL;
        else
            echo "Let's do this.".PHP_EOL;
    }
}
?>