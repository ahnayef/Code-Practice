<?php
$servername = "localhost";
$username = "test";
$password = "123456";
$dbname = "expenditure";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>