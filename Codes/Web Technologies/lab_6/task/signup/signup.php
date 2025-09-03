<?php
include '../connection.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $password = $_POST["password"];
    $confirm_password = $_POST["confirm_password"];
    
    if ($password !== $confirm_password) {
        echo "Passwords do not match. <a href='index.php'>Try again</a>";
        exit();
    }
    
    $sql = "INSERT INTO user (username, password) VALUES ('$username', '$password')";
    
    if ($conn->query($sql) === TRUE) {
        echo "Registered!";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

$conn->close();
?>