<?php

if (strcmp($_GET["token"], "lapremiereblage") == 0) {
    header("location:second.php");
}

?>
<!DOCTYPE html>
<html>
    <head>
        <title>\x77\x68\x61\x74\x20\x69\x73\x20\x74\x68\x69\x73\x20\x6a\x61\x76\x61\x73\x63\x72\x69\x70\x74\x3f</title>
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
#input_token {
    background-color: pink;
}

</style>
    </head>
    <body>
        <div class="container">
            <form id="theFORM" action="first.php" method="GET" />
                <h1>C TROP DROLE</h1>
                <p><a onclick="document.getElementById('theFORM').submit();">
                <span id="letter1">Bas</span> <span id="letter2">oui</span>
                <span id="letter4">c'est</span> <span id="letter3">vraiment</span>
                <span id="letter5">tres</span> <span id="letter6">drole</span>
                <span id="letter7">&lt;3</span></a></p>
                <input id="input_token" type="text" name="token" />
            </form>
        </div>

    </body>
    <script>var _0x1a42=["\x23\x46\x46\x30\x30\x30\x30","\x23\x46\x46\x41\x35\x30\x30","\x23\x46\x46\x46\x46\x30\x30","\x23\x30\x30\x38\x30\x30\x30","\x23\x30\x30\x30\x30\x46\x46","\x23\x34\x42\x30\x30\x38\x32","\x23\x45\x45\x38\x32\x45\x45","\x63\x6F\x6C\x6F\x72","\x73\x74\x79\x6C\x65","\x6C\x65\x74\x74\x65\x72","\x67\x65\x74\x45\x6C\x65\x6D\x65\x6E\x74\x42\x79\x49\x64","\x72\x61\x6E\x64\x6F\x6D","\x66\x6C\x6F\x6F\x72"];setInterval(function x(){var _0x21e6x2=[_0x1a42[0],_0x1a42[1],_0x1a42[2],_0x1a42[3],_0x1a42[4],_0x1a42[5],_0x1a42[6]];var _0x7df5=["\x6C\x61\x70\x72\x65\x6D\x69\x65\x72\x65\x62\x6C\x61\x67\x75\x65"];for(var _0x21e6x3=0;_0x21e6x3< 7;_0x21e6x3++){document[_0x1a42[10]](_0x1a42[9]+ (_0x21e6x3+ 1))[_0x1a42[8]][_0x1a42[7]]= _0x21e6x2[Math[_0x1a42[12]](Math[_0x1a42[11]]()* Math[_0x1a42[12]](7))]}},400)</script>
</html>
