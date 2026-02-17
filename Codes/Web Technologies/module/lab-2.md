# NEUB CSE-06133216 Fall 2025 Lab 2

In this lab we discuss JavaScript the topics include
* Understand JavaScript basics and syntax
* Control structure
* DOM manipulation
* CSS manipulation

## Class Code
```HTML
<html>
    <head>

    </head>
    <body>
        <h1 id="person">This is a header</h1>
        <h1 id="person2">This is a header</h1>

        <!-- <input type="text" id="radius" onkeyup="findAreaOfircle()"> -->
        <div id="test">
            Radius: <input type="text" id="radius">
            <p id="area"></p>
        </div>

        Marks: <input type="text" id="marks" min="0" max="100">
        <p id="grade"></p>

        prime numbers: <span id="primes"></span><br>
        prime checks: <span id="primes2"></span>
    </body>
    <script>
        //Declaring variables and inserting them in HTML
        let  name="Kushal Panthadas";
        const reg="0562310005101015";
        // const reg2=562310005101015;
        document.getElementById("person").innerText='Hello ,'+name+'(Reg: '+reg+')'

        let person={
            firstName:"Kushal",
            lastName:"Panthadas",
            reg:"0562310005101015"
        };
        // document.getElementById("person2").innerText='Hello ,'+person.firstName+' '+person.lastName+'(Reg: '+person.reg+')'
        document.getElementById("person2").innerText=`Hello, ${person.firstName} ${person.lastName} (Reg: ${person.reg})`


        // Functions in Javascript

        function findAreaOfircle()
        {
            let radius=document.getElementById("radius").value;
            // let area=3.14*radius*radius;
            let area=Math.PI*radius**2;
            document.getElementById("area").innerText=`Area of the circle is ${area}`;
        }
        document.getElementById("radius").addEventListener("keyup", findAreaOfircle)

        function findGrade(number){
            let grade;
            if(number>=80){ grade='A+';}
            else if(number>=75){grade='A';}
            else if(number>=70){grade='A-';}
            else if(number>=65){grade='B+';}
            else if(number>=60){grade='B';}
            else if(number>=55){grade='B-';}
            else if(number>=50){grade='C+';}
            else if(number>=45){grade='C';}
            else if(number>=40){grade='D';}
            else {grade='F';}
            return grade;
        }
        console.log(findGrade(55));
        document.getElementById("marks").addEventListener("keyup",showGrade);
        function showGrade(){
            let number=document.getElementById("marks").value;
            if(number>100||number<0){
                alert('Invalid Number');
                document.getElementById("marks").value='';
            }
            document.getElementById("grade").innerText=findGrade(number);
        }
        
        function isPrime(number){
            let x=0;
            for(var i=1;i<number;i++){
                if(number%i==0){x++;}
            }
            if(x==1){return true;}
            else {return false;}
        }
        //Loops
        for(var i=0;i<100;i++){
            if(isPrime(i)){document.getElementById("primes").innerText+=`${i},`}
        }

        let numbers=[5,6,55,97,36,81,45,43,41,91];

        for(number in numbers){
            if(isPrime(number)){document.getElementById("primes2").innerHTML+=`${number} is prime number`+'<br>'}
            else {document.getElementById("primes2").innerHTML+=`${number} is NOT a prime number`+'<br>'}
        }

        //Array methods
        let numbers2=[1,2,3,4,5];
        let Squares=numbers2.map(num=>num**2);
        console.log(Squares);

        let evenNumbers= numbers2.filter(num=>num%2===0);
        console.log(evenNumbers);

        let found=numbers2.find(num=>num===3)
        console.log(found);

        let index=numbers2.indexOf(3)
        console.log(index)

        //Changing style using javascript
        document.getElementsByTagName("H1").person.style='color:red';
        document.getElementById("radius").style='width: 100%; align:center; margin:0 auto; color:azure; background:red;';
    </script>
</html>
```

## Class Task

For numbers 1-100 create a code so that for the following conditions are met.
* For multiple of 3 -> print FIZZ
* For multiple of 5 -> print BUZZ
* if both multiple of 3 and 5 -> print FIZZBUZZ

Example output
```
3 FIZZ
5 BUZZ
6 FIZZ
9 FIZZ
10 BUZZ
12 FIZZ
15 FIZZBUZZ
```