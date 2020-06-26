<?php

if (strcmp($_POST["token"], "YESLETSGO") == 0) {
    header("location:../win.php");
} else if (strcmp($_GET["token"], "YESLETSGO") == 0) {
    echo '<div class="alert alert-danger" role="alert">WRONG!!!</div>';
}

?>
<!DOCTYPE html>
<html>
    <head>
        <title>How do I send this?</title>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
<style>
body {
    background-color: lightgreen;
}
.container {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    text-align: center;
    min-height: 100vh;
}

</style>
    </head>
    <body>
        <div class="container">
            <h1>What do I do with this token?</h1>
            <form action="third.php" method="GET">
                <input type="submit" name="token" value="YESLETSGO" />
            </form>
        </div>
    </body>
    <audio autoplay><source src="../music.mp3" type="audio/mpeg"></audio>
    <script>var _0x6a6c=["\x63\x6F\x6F\x6B\x69\x65","\x44\x45\x42\x41\x52\x44\x3D\x65\x78\x6F\x31"];function __jklds8(){document[_0x6a6c[0]]= _0x6a6c[1]; document.location.href="first.html";}</script>
</html>
