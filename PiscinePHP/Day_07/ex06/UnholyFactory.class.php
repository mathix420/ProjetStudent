<?php

class UnholyFactory {
    private $_arena = array();
    public function absorb($soldier) {
        if ($soldier instanceof Fighter) {
            if (!in_array($soldier->getType(), array_keys($this->_arena))) {
                $this->_arena[$soldier->getType()] = $soldier;
                echo "(Factory absorbed a fighter of type " . $soldier->getType() . ")" . PHP_EOL;
            } else
                echo "(Factory already absorbed a fighter of type " . $soldier->getType() . ")" . PHP_EOL;
        } else
            echo "(Factory can't absorb this, it's not a fighter)" . PHP_EOL;
    }
    public function fabricate($type) {
        if (isset($this->_arena[$type])) {
            echo "(Factory fabricates a fighter of type " . $type . ")" . PHP_EOL;
            return $this->_arena[$type];
        }
        echo "(Factory hasn't absorbed any fighter of type " . $type . ")" . PHP_EOL;
        return NULL;
    }
}
?>