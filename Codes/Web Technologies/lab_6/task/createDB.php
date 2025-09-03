<?php
$conn = new mysqli("localhost", "test", "123456", "webTech");

$sql = 'CREATE DATABASE expenditure';

if ($conn->query($sql) === TRUE) {
     echo "Database created successfully";
} else {
     echo "Error creating database: " . $conn->error;
}

$conn->close();
?>