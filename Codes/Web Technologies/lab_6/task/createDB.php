<?php
$conn = new mysqli("localhost", "test", "123456", "expenditure");

// $sql = 'CREATE DATABASE IF NOT EXISTS expenditure';

if ($conn) {

     $sql_user = "CREATE TABLE IF NOT EXISTS user(
          id INT AUTO_INCREMENT PRIMARY KEY,
          username VARCHAR(50) UNIQUE,
          password VARCHAR(50)
     )";

     if ($conn->query($sql_user) === TRUE) {
          echo "User created successfully<br>";
     } else {
          echo "Error creating user.: " . $conn->error . "<br>";
     }

     $sql_exp = "CREATE TABLE IF NOT EXISTS expense(
          id INT AUTO_INCREMENT PRIMARY KEY,
          uid INT,
          date DATE,
          description TEXT,
          amount INT,
          FOREIGN KEY (uid) REFERENCES user(id)
     )";

     if ($conn->query($sql_exp) === TRUE) {
          echo "Expense created successfully<br>";
     } else {
          echo "Error creating expense: " . $conn->error . "<br>";
     }

} else {
     echo "Error creating database: " . $conn->error;
}

$conn->close();
?>