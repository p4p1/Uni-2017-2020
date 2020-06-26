<?php
function inverse($x) {
    if (!$x) {
        throw new Exception("Division by zero");
    }
    return 1/$x;
}

try {
    echo inverse(5) . "\n";
} catch (Exception $e) {
    echo "OMG ERROR: ", $e->getMessage(), "\n";
}

/* -------------------------------------*/


function add($num1, $num2) {
    test_number($num1);
    test_number($num2);
    return ($num1 + $num2);
}


function main() {
    while (1) {
        $num1 = readline("Number 1: ");
        $num2 = readline("Number 2: ");
        try {
            $solution = add($num1, $num2);
        } catch (Exception $e) {
            echo $e->getMessage();
            continue;
        }

        echo "The Solution is: " . $solution . "\n";
    }
}

main();
?>
