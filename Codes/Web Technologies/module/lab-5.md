# NEUB CSE-06133216 Fall 2025 Lab 5

In this lab we discuss PHP. The topics include basic php structure, loops, and form handling.


## Class Codes
### Creating basic HTML structure using php
```php
<?php
//echo "Hello World";
echo "<html><head></head><body>";
echo "<h1>Hello World</h1>";

echo "</body>";

?>
```

### PHP Syntax and usage
```php
<html>
    <head>

    </head>
    <body>
        <?php 
        $username="Kushal";
        $isStudent=true;
        $studentId="0562310005101015";
        $firstName="Kushal";
        $lastName="Panthadas";
        $fullName=$firstName." ".$lastName;
        //$cgpa=3.86;

        //Comment
        # Comment
        /*
            This is a 
            multiline comment

            PHP is case sensitive so BE CAREFUL:
        */
        ?>
        <h1><?php echo "Hello ".$username ;?></h1>
        <p>
            <?php 
            echo "Name: <b>".$fullName."</b><br>" ;
            if($isStudent)
            {
                echo "Reg: <b>".$studentId."</b><br>" ;
            }

            //Array
            //Indexed Array
            $subjects= array("Machine Learning","Computer Security", "Computer Architecture", "Economics", "Project II", "Web TEchnologies", "Technical Writing and Research Methodology");
            
            //echo  $subjects[1];
            for($i=0;$i<=5;$i++){
                echo  "<br>".$subjects[$i];
            }

            echo "<br><br>";
            foreach($subjects as $subject){
                echo $subject."<br>";
            }

            $counter=1;
            while($counter<=10){
                echo "Count: $counter <br>";
                $counter++;
            }

            do{
                echo "Count: $counter <br>";
                $counter--;
            }while($counter>0);

            //Declaring indexed array using shortcut syntax
            $marks=[75, 78, 68, 90, 55, 88, 40];
            $totalMarks=array_sum($marks);
            $averageMarks=$totalMarks/count($marks);
            echo "<br> $averageMarks";

            //Associative Array
            $courses = array(
                "Machine Learning" => 75,
                "Computer Security" =>65, 
                "Computer Architecture" => 90, "Economics" => 68, 
                "Project II" => 88, 
                "Web Technologies" => 55, 
                "Technical Writing and Research Methodology" => 70
            );

            echo "<br> Marks of each subjects<br>";
            foreach($courses as $course => $cmark){
                echo "$course: $cmark <br>";
            }

            echo "<br>2<br>";
            $courseList=array_keys($courses);
            for($i=0;$i<count($courseList);$i++){
                $course=$courseList[$i];
                $cmark=$courses[$course];
                echo "$course: $cmark <br>";
            }

            //Declaring constants in PHP
            define("siteName", "TEST PHP SITE");
            const pi = 3.14159;

            echo "<br>";
            echo siteName;
            echo pi;

            //PHP also supports break and continue statement


            ?>
        </p>
    </body>
</html>
```

### GET method usage
```php
<?php
if(isset($_GET['u'])){
    $userName=$_GET['n'];
    //Find user details from database
    echo "ECHO USER DETAILS HERE";
}
?>
```
### POST method usage
form.php
```php
<html>
    <head>

    </head>
    <body>
    <form action="process.php" method="POST">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
        
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required>

        <input type="submit" value="Submit">
    </form>        
    </body>
</html>
```

process.php
```php
<?php
if($_POST){
    // //Form Handling without validation
    // $name=$_POST['name'];
    // $email=$_POST['email'];
    // echo "Name: ".htmlspecialchars($name)."<br>";
    // echo "Name: ".htmlspecialchars($email)."<br>";

    if(empty($_POST['name'])){
        $errors[]="Name is required";
    } elseif (strlen($_POST['name'])<5){
        $errors[] = "Name must be at least 5 characters long";
    }
    if(empty($_POST['email'])){
        $errors[]="Email is required";
    } elseif(!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)){
        $errors[] = "Invalid email format";
    }

    if(empty($errors)){
        //Do SQL query
        echo "Form submitter successfully";
    }
    else{
        foreach($errors as $error){
            echo $error;
        }
    }
}
else{
    header("Location: form.php");
    ?>
<!-- <html>
    <head>

    </head>
    <body>
    <form action="process.php" method="POST">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
        
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required>

        <input type="submit" value="Submit">
    </form>        
    </body>
</html> -->
    <?php
}

?>
```