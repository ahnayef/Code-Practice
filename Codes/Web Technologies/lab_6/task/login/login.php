<?php
include '../connection.php';
include '../session.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $password = $_POST["password"];
    
    $sql = "SELECT * FROM user WHERE username = '$username' AND password = '$password'";
    $result = $conn->query($sql);
    
    if ($result->lengths > 1) {
        $row = $result->fetch_assoc();
        $_SESSION["user_id"] = $row["id"];
        $_SESSION["username"] = $row["username"];
        header("Location: ../index.php");
        exit();
    } else {
        echo "Invalid username or password";
    }
}

$conn->close();
?>