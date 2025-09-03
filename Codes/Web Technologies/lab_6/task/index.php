<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Expense</title>
</head>
<body>
    <p>Hi, <?php echo $_SESSION["username"]; ?></p>
    <div>
        <ul>
            <li><a href="expense/index.php">Add New Expense</a></li>
            <li><a href="display/index.php">View All Expenses</a></li>
            <li><a href="logout.php">Logout</a></li>
        </ul>
    </div>
</body>
</html>