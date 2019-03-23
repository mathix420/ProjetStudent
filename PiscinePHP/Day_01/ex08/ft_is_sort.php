<?php
function ft_is_sort($tab) {
    $sorted = $tab;
    sort($sorted);
    return ($tab === $sorted);
}
?>