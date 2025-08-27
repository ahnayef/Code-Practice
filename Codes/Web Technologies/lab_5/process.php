<?php
if ($_POST) {
     $name = $_POST['name'];
     $email = $_POST['email'];


     if (empty($name)) {
          $errors[] = "Name is required";
     } elseif (strlen($name) < 5) {
          $errors[] = "Name must be at least 5 character long";
     }

     if (empty($email)) {
          $errors[] = "Email is required";
     } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
          $errors[] = "Invalid email format";

     }


     if (empty($errors)) {
          echo "Name:" . htmlspecialchars($name) . " <br> Email:" . htmlspecialchars($name);
     } else {
          foreach ($errors as $error) {
               echo "<h1 style='color:red'>$error</h1><br>";
          }
     }

} else {
     header("Location: form.php");
}
?>