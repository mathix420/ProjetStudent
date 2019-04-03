<?php

class NightsWatch {
    private $tab = array();
    public function recruit($recruit) {
        array_push($this->tab, $recruit);
    }
    public function fight() {
        foreach ($this->tab as $fighter) {
            if (method_exists($fighter, 'fight'))
                $fighter->fight();
        }
    }
}

?>