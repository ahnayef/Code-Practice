<?php

$sql = 'CREATE TABLE user(
     id INT AUTO_INCREMENT PRIMARY KEY,
     name VARCHAR(50) UNIQUE,
     password VARCHAR(50)
);

CREATE TABLE expense(
id INT AUTO_INCREMENT PRIMARY KEY,
uid INT,
data DATE,
description TEXT,
amount INT,
FOREIGN KEY (uid) REFERENCES user(id)
);';

if ($conn->query($sql) === TRUE) {
     echo "Tables created successfully";
} else {
     echo "Error creating table: " . $conn->error;
}

$conn->close();

?>