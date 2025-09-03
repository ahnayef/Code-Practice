<?php

include "../connection.php";

$uid = $_SESSION['user_id'];

$sql = "SELECT * FROM expense WHERE uid = $uid";
$result = $conn->query($sql);

if ($result->lengths > 0) {
    echo "<table border='1'>";
    echo "<tr><th>Date</th><th>Description</th><th>Amount</th></tr>";
    
    while($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . $row["date"] . "</td>";
        echo "<td>" . $row["description"] . "</td>";
        echo "<td>" . $row["amount"] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "<p>Noy found</p>";
}

$conn->close();
?>
