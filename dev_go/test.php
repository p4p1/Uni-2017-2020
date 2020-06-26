<?php


function fun($arg) {
    while ($arg) {
        query->("SELECT * FROM $arg[0]")
    }
}

?>
