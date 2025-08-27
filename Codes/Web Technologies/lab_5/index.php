<!DOCTYPE html>
<html lang="en">

<head>
     <meta charset="UTF-8">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <title>Document</title>
</head>

<body>
     <?php

     const pi = 3.14159; //Ideal for numerical
     define("SITE_NAME", "Test php site"); //Ideal for string
     
     $username = "AHN";
     $isStudent = true;
     $id = "0562310005101027";
     $cgpa = 3.80;
     //Array
     $subjects = array("Computer Security", "Machine Learning", "Computer Architecture", "Web Technologies", "Technical Writing & Research Methodology", "Project Work II", "Principles of Economics");

     $marks = [80, 85, 90, 95, 82, 87, 97];

     $totalMarks = array_sum($marks);

     $avarageMarks = $totalMarks / count($subjects);

     $subjectMarks = ["Computer Security" => 80, "Machine Learning" => 85, "Computer Architecture" => 90, "Web Technologies" => 95, "Technical Writing & Research Methodology" => 82, "Project Work II" => 87, "Principles of Economics" => 97];

     $coursesList = array_keys($subjectMarks);

     ?>
     <h1>Hello
          <?php echo $username; ?>
     </h1>

     <p>
          <?php

          echo SITE_NAME;
          echo "<br>";
          echo pi;
          echo "<br>";

          echo "Name : <b>$username</b><br>";

          if ($isStudent) {
               echo "Reg: $id";
          }
          ;
          echo "<ul>";
          for ($i = 0; $i <= 5; $i++) {
               echo "<li> $subjects[$i] </li>";
          }
          echo "</ul>";

          echo "<ul>";
          foreach ($subjectMarks as $key => $value) {
               echo "<li>$key : $value</li>";
          }
          ;

          echo "<br>";

          for ($i = 0; $i < count($coursesList); $i++) {
               $course = $coursesList[$i];
               $mark = $subjectMarks[$course];

               echo "<li>$course : $marks</li>";
          }
          echo "</ul>";

          echo "<h3>Avarage: $avarageMarks</h3>";


          ?>
     </p>

</body>

</html>