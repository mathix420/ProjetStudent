<?php
class Jaime {
    function sleepWith ($person) {
        if ($person instanceof Cersei)
            echo "With pleasure, but only in a tower in Winterfell, then.".PHP_EOL;
        elseif ($person instanceof Tyrion)
            echo "Not even if I'm drunk !".PHP_EOL;
        else
            echo "Let's do this.".PHP_EOL;
    }
}
?>