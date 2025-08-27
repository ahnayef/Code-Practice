<!DOCTYPE html>
<html lang="en">

<head>
     <meta charset="UTF-8">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <title>PHP Form</title>
</head>

<body>

     <form action="process.php" method="post">

          <label for="name">Name</label>
          <input type="text" placeholder="Inter your name" name="name" id="name">
          <br>

          <label for="email">Email</label>
          <input type="email" placeholder="Inter your email" name="email" id="email">

          <br>
          <button type="submit">Submit</button>

     </form>

</body>

</html>