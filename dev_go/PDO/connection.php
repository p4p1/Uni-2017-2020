<?php
$servername = "localhost";
$username = "root";
$password = "";


try {

  $conn = new PDO("mysql:host=$servername;dbname=coding", $username, $password);

  // set the PDO error mode to exception
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

  echo "Connected successfully";

  $return_value = $conn->query("SHOW DATABASES;");
    $sql = "CREATE TABLE MyGuests (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(30) NOT NULL,
    lastname VARCHAR(30) NOT NULL,
    email VARCHAR(50),
    reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
    )";
    $nb = $return_value->rowCount();
    echo $nb;


} catch(PDOException $e) {
  echo "Connection failed: " . $e->getMessage();
}

?>
