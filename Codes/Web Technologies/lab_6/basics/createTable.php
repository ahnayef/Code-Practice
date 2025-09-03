<?php

$sql = 'CREATE TABLE student(
     id INT AUTO_INCREMENT PRIMARY KEY,
     name VARCHAR(50),
     email VARCHAR(50)
)';

if ($conn->query($sql) === TRUE) {
     echo "Table created successfully";
} else {
     echo "Error creating table: " . $conn->error;
}

$conn->close();

?>