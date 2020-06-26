
<!DOCTYPE html>
<html>
    <head>
        <title>C'est vraiment trop drole!!!!</title>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
<style>
body {
    background-color: pink;
}
.container {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    text-align: center;
    min-height: 100vh;
}

.appear {
    color: pink;
    background-color: pink;
}

.diseapear:hover {
    color: black;
    cursor: default;
}

</style>
    </head>
    <body>
        <div class="container">
<?php

    if ((strcmp($_GET["token1"], "lapremiereblage") == 0) && (strcmp($_GET["token2"], "pangolin") == 0) && (strcmp($_GET["token3"], "YESLETSGO") == 0)) {
        echo "<h1>You win!!!!!!!!</h1>";
    } else {
        echo '<form id="theFORM" action="win.php" method="GET" /><p>First : </p><input id="input_token" type="text" name="token1" /><p>Second : </p><input id="input_token" type="text" name="token2" /><p> Third : </p><input id="input_token" type="text" name="token3" /><input type="submit" name="submit" /></form>';
    }

?>
        </div>
        <div class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="..">Restart</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav mr-auto">
                    <li class="nav-item active">
                        <a class="nav-link" href="#">Previous</a>
                    </li>
                    <li class="nav-item active">
                        <a class="nav-link" href="second.php">Next</a>
                    </li>
                </ul>
            </div>
        </div>
    </body>
</html>
