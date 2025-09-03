<?php
include "../session.php";
include "../connection.php";


if ($_SERVER["REQUEST_METHOD"] == "POST") {
     $uid = $_SESSION['user_id'];
     $date = $_POST['date'];
     $description = $_POST['description'];
     $amount = $_POST['amount'];

     if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
     }

     $sql = "INSERT INTO expense (uid, date, description, amount) 
            VALUES ('$uid', '$date', '$description', '$amount')";

     if ($conn->query($sql) === TRUE) {
          echo "<p>Expense added</p>";
     } else {
          echo "<p> $conn->error </p>";
     }

     $conn->close();
}
?>