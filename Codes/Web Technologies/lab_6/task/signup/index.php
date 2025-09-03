<!DOCTYPE html>
<html lang="en">
<head>
     <meta charset="UTF-8">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <title>Sign Up</title>
</head>
<body>
     <h2>Sign Up</h2>
     <form action="signup.php" method="POST">
          <div>
               <label for="username">Username:</label>
               <input type="text" id="username" name="username" required>
          </div>
          <div>
               <label for="password">Password:</label>
               <input type="password" id="password" name="password" required>
          </div>
          <div>
               <label for="confirm_password">Confirm Password:</label>
               <input type="password" id="confirm_password" name="confirm_password" required>
          </div>
          <div>
               <input type="submit" value="Sign Up">
          </div>
     </form>
     <p>Already have an account? <a href="../login/index.php">Login here</a></p>
</body>
</html>