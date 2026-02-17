# NEUB CSE-06133216 Fall 2025 Lab 6

In this lab we discuss database usage in PHP. Topics include Connect, Create DB/Table, Insert, Retrieve, Update, Delete, Join.


## Class Codes
## MySQLi
Here are some of the examples shown for MySQLi.
### Connecting to Database
```php
<?php
$servername = "localhost";
$username   = "root";
$password   = "";
$dbname     = "school";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
```
### Creating Database
```php
<?php
$conn = new mysqli('localhost', 'root', '');
$sql = 'CREATE DATABASE school';
if ($conn->query($sql) === TRUE) {
    echo 'Database created successfully';
} else {
    echo 'Error: ' . $conn->error;
}
$conn->close();
?>
```
### Creating Table
```php
<?php
$sql = 'CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(50)
)';
if ($conn->query($sql) === TRUE) {
    echo 'Table created';
}
?>
```

### Insert Data from Form - form.php
```php
<form method='post' action='insert.php'>
    Name: <input type='text' name='name'><br>
    Email: <input type='email' name='email'><br>
    <input type='submit' value='Save'>
</form>
```

### Insert Data from Form - insert.php
```php
<?php
include 'db.php';
$name  = $_POST['name'];
$email = $_POST['email'];
$sql = "INSERT INTO students (name, email) VALUES ('$name', '$email')";
if ($conn->query($sql)) 
    echo 'Inserted successfully';
include 'close.php'
?>
```
db.php
```php
<?php
$servername = "localhost";
$username   = "root";
$password   = "";
$dbname     = "school";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";
?>
```
close.php
```php
<?php
$conn->close();
?>
```

### Retrieve Data
```php
<?php
$stmnt='SELECT * FROM students'
$result = $conn->query($stmnt);
while ($row = $result->fetch_assoc()) {
    echo $row['id'] . ' - ' . $row['name'] . '<br>';
}
?>
```

### Retrieve limited amount of Data
```php
<?php
$stmnt='SELECT * FROM students LIMIT [10,] 20'
$result = $conn->query($stmnt);
while ($row = $result->fetch_assoc()) {
    echo $row['id'] . ' - ' . $row['name'] . '<br>';
}
?>
```

### Update Data
```php
<?php
$sql = "UPDATE students SET email='new@mail.com' WHERE id=1";
$conn->query($sql);
?>
```
if userid is available through global variables like these\
```
$uid;
$uname
$uemail
```
we can use the following structure of codes

```php
<?php
$sql = "UPDATE students SET email='new@mail.com' WHERE id=$uid";
$conn->query($sql);
?>
```

### Delete Data
```php
<?php
$sql = "DELETE FROM students WHERE id=1";
$conn->query($sql);
?>
```

### Sorting Data
```php
$sql = "SELECT * FROM students ORDER BY name ASC";
// ASC = ascending (default), DESC = descending
$result = $conn->query($sql);
while ($row = $result->fetch_assoc()) {
    echo $row['id'] . " - " . $row['name'] . "<br>";
}
```

### Grouping Data
```php
$sql = "SELECT COUNT(id) AS total_students, email
        FROM students
        GROUP BY email";
$result = $conn->query($sql);
while ($row = $result->fetch_assoc()) {
    echo $row['email'] . ": " . $row['total_students'] . "<br>";
}
```

### Aggregate Functions
* Common MySQL Aggregate Functions:
    * COUNT(column) – Counts rows
    * SUM(column) – Adds all values
    * AVG(column) – Calculates average
    * MIN(column) – Finds smallest value
    * MAX(column) – Finds largest value

```php
$sql = "SELECT COUNT(id) AS total, AVG(age) AS avg_age
        FROM students";
$result = $conn->query($sql);
$row = $result->fetch_assoc();
echo "Total: " . $row['total'] . "<br>";
echo "Average Age: " . $row['avg_age'];
```

### Joining Tables
```php
$sql = "SELECT students.name, courses.course_name
        FROM students
        INNER JOIN courses ON students.id = courses.student_id";
$result = $conn->query($sql);
```

## PDO
* PDO = PHP Data Objects
* A database access layer providing a uniform way to connect to many databases
* Supports multiple DB types: MySQL, PostgreSQL, SQLite, etc.
* More secure with prepared statements
* Cleaner and more flexible than MySQLi

Here are some examples of Database using with PDO.

### Connecting to Database with PDO
```php
<?php
$dsn = "mysql:host=localhost;dbname=school";
$username = "root";
$password = "";

try {
    $pdo = new PDO($dsn, $username, $password);
    // Set error mode to exception
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    echo "Connected successfully";
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>
```

### Insert Data with PDO
```php
<?php
$sql = "INSERT INTO students (name, email) VALUES (:name, :email)";
$stmt = $pdo->prepare($sql);
$stmt->execute([
    ':name' => "John Doe",
    ':email' => "john@example.com"
]);
echo "Record inserted successfully";
?>
```

### Retrieve Data with PDO
```php
<?php
$sql = "SELECT * FROM students";
$stmt = $pdo->query($sql);

while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
    echo $row['id'] . " - " . $row['name'] . "<br>";
}
?>
```

### Update & Delete with PDO
```php
// Update
$sql = "UPDATE students SET email=:email WHERE id=:id";
$stmt = $pdo->prepare($sql);
$stmt->execute([':email' => "new@mail.com", ':id' => 1]);

// Delete
$sql = "DELETE FROM students WHERE id=:id";
$stmt = $pdo->prepare($sql);
$stmt->execute([':id' => 1]);
```

## PHP Session
* A way to store user information across multiple pages
* Data stored on the server (unlike cookies)
* Each visitor gets a unique session ID
* Common uses:
    * Login systems
    * Shopping carts
    * Saving temporary form data

### Starting a Session
```php
<?php
session_start(); // Must be called before any output

$_SESSION['uid'] = 50;
$_SESSION['username'] = "JohnDoe";
echo "Session started, username saved.";
?>
```

### Accessing Session Data
```php
<?php
session_start();
echo "Welcome " . $_SESSION['username'].;
echo “Your User ID is " . $_SESSION['uid'].;
?>
```

### Removing Session Data
```php
<?php
session_start();
unset($_SESSION['username']); // Remove one variable
session_destroy(); // Destroy entire session
?>
```

### Session Example
login.php
```php
<?php
session_start();
$_SESSION['loggedin'] = true;
header("Location: dashboard.php");
?>
```

dashboard.php
```php
<?php
session_start();
if ($_SESSION['loggedin']) {
    echo "Welcome to your dashboard!";
} else {
    echo "Please log in first.";
}
?>
```


## Class Task
* Create a database expenditure
* Create user table: (id, username, password)
* Create expense table: (id, uid, date, description, amount)
* Create a user registration and login page
* Create a form to insert expense records
* Display all expense for logged in user
* Create a summary page to show expense summary by all user

_Submit your task through pendrive in the class_
