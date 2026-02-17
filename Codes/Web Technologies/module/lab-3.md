# NEUB CSE-06133216 Fall 2025 Lab 3

In this lab we discuss JavaScript. The topics include
* JSON Data storage
* Loading data Asynchronously

## Class Code
```html
<html>
    <head>
        <style>
            table tr td{
                border: 1px;
                border-style: solid;
                border-color: black;
            }
        </style>

    </head>
    <body>
        <div>
            <table id="userTable">
                <tr>
                    <th>Registration Number</th>
                    <th>Name</th>
                </tr>

            </table>
        </div>
    </body>
    <script>
        //Fetching JSON
        async function fetchUser(){
            try{
                const response = await fetch('studentList.json');
                // console.log(response);
                
                if(!response.ok)
                {
                    throw new Error(`HTTP ERROR. Status:${response.status}`)
                }
                const users=await response.json();

                // users.forEach(element => {
                //     console.log(`<tr><td>${element.Reg}</td><td>${element.Name}</td></tr>`);
                //     document.getElementById("userTable").innerHTML+=`<tr><td>${element.Reg}</td><td>${element.Name}</td></tr>`;
                // });

                return users                
            }
            catch(error){
                console.log(error.message);
            }
        }

        // let users=Promise.resolve(fetchUser);
        // users.array.forEach(element => {
        //             console.log(`<tr><td>${element.Reg}</td><td>${element.Name}</td></tr>`);
        //             document.getElementById("userTable").innerHTML+=`<tr><td>${element.Reg}</td><td>${element.Name}</td></tr>`;
        //         });

        async function displayData(){
            const users= await fetchUser();
            users.forEach(element => {
                    console.log(`<tr><td>${element.Reg}</td><td>${element.Name}</td></tr>`);
                    document.getElementById("userTable").innerHTML+=`<tr><td>${element.Reg}</td><td>${element.Name}</td></tr>`;
                });
        } 

        //fetchUser();
        displayData();


        // POST request
        async function createUser(userData){
            try{
                const response = await fetch('pageName',{
                    method: 'POST',
                    header:{

                    },
                    body: JSON.stringify(userData)
                });

                if (!response.ok){
                    throw new Error(`HTTP ERROR. Status: ${response.status}`);
                }
                //Resonse to user
            } 
            catch(error){
                conssole.log(`ERROR creating user: ${error.message}`);
            }
            

        }

        createUser({
            name: 'TEst Name',
            reg: '0562310005101060'
        });

    </script>
</html>
```
Sample JSON Data
```Javascript
[
  {
    "Reg": "0562310005101001",
    "Name": "Amir Hamza"
  },
  {
    "Reg": "0562310005101002",
    "Name": "Shimu Begum"
  },
  {
    "Reg": "0562310005101003",
    "Name": "Md.Masum Prodhania "
  },
  {
    "Reg": "0562310005101004",
    "Name": "Abu Bokor"
  },
  {
    "Reg": "0562310005101005",
    "Name": "Priya Das"
  },
  {
    "Reg": "0562310005101006",
    "Name": "Md.Muradul Islam Polash"
  },
  {
    "Reg": "0562310005101007",
    "Name": "Rayhan Aziz Chowdhury Shafi"
  },
  {
    "Reg": "0562310005101008",
    "Name": "Sanjida Khanom"
  },
  {
    "Reg": "0562310005101009",
    "Name": "Jahid Uddin"
  },
  {
    "Reg": "0562310005101010",
    "Name": "Jannatul Bushra Moni"
  },
  {
    "Reg": "0562310005101011",
    "Name": "Tanjina Akter"
  },
  {
    "Reg": "0562310005101012",
    "Name": "Hrithik Dev Nath"
  },
  {
    "Reg": "0562310005101013",
    "Name": "Rumi Begum"
  },
  {
    "Reg": "0562310005101014",
    "Name": "Zahidul Islam Khan"
  },
  {
    "Reg": "0562310005101015",
    "Name": "kushal Pantha Das"
  },
  {
    "Reg": "0562310005101016",
    "Name": "Lutfa Nawar Ena"
  },
  {
    "Reg": "0562310005101017",
    "Name": "Hasin Rayhan Sami"
  },
  {
    "Reg": "0562310005101018",
    "Name": "Dulon Akhter Sathee"
  },
  {
    "Reg": "0562310005101019",
    "Name": "Oli Ahmed"
  },
  {
    "Reg": "0562310005101020",
    "Name": "Md.Mokbul Miah"
  },
  {
    "Reg": "0562310005101021",
    "Name": "Md.Maruf Talukdar"
  },
  {
    "Reg": "0562310005101022",
    "Name": "Jannatul Ferdues Kely"
  },
  {
    "Reg": "0562310005101023",
    "Name": "Md.Shakib Uddin"
  },
  {
    "Reg": "0562310005101024",
    "Name": "Jubayer Ahmed"
  },
  {
    "Reg": "0562310005101025",
    "Name": "Srijon Talukdar"
  },
  {
    "Reg": "0562310005101026",
    "Name": "Atqiya Anjum"
  },
  {
    "Reg": "0562310005101027",
    "Name": "Ahsan Habib Nayef"
  },
  {
    "Reg": "0562310005101028",
    "Name": "Arnob Das"
  },
  {
    "Reg": "0562310005101029",
    "Name": "Halima Sadia Tabassum"
  },
  {
    "Reg": "0562310005101030",
    "Name": "Shorifur Rashid"
  },
  {
    "Reg": "0562310005101031",
    "Name": "Jakaria Chowdhury Tajwone"
  },
  {
    "Reg": "0562310005101032",
    "Name": "Fatematuj Johura Mim"
  },
  {
    "Reg": "0562310005101033",
    "Name": "Nazir Hossain Sahinur"
  },
  {
    "Reg": "0562310005101034",
    "Name": "Md. Nasir Uddin"
  },
  {
    "Reg": "0562310005101035",
    "Name": "Mirza Anjuman Ara Juman"
  },
  {
    "Reg": "0562310005101036",
    "Name": "Avishek Das Adhikari"
  },
  {
    "Reg": "0562310005101037",
    "Name": "Md. Rana Mia"
  },
  {
    "Reg": "0562310005101038",
    "Name": "Tahmina Akter Tanni"
  },
  {
    "Reg": "0562310005101039",
    "Name": "Nabila Jannat"
  },
  {
    "Reg": "0562310005101040",
    "Name": "Snehasish Saha Roy Akash"
  },
  {
    "Reg": "0562310005101041",
    "Name": "Hussain Ahmed"
  },
  {
    "Reg": "0562310005101042",
    "Name": "Md.Lal Chan"
  },
  {
    "Reg": "0562310005101043",
    "Name": "Fahima Haque Talukder"
  },
  {
    "Reg": "0562310005101044",
    "Name": "Sadia Mahjabin Mim"
  },
  {
    "Reg": "0562310005101201",
    "Name": "Sanjida Akter"
  },
  {
    "Reg": "0562310005101045",
    "Name": "Mst. Fahimajjaman Jaina"
  },
  {
    "Reg": "0562310005101046",
    "Name": "Shah Shafiul Alam"
  },
  {
    "Reg": "0562310005101047",
    "Name": "Abdul Wahid Umayer"
  },
  {
    "Reg": "0562310005101048",
    "Name": "Chironto Rudra Paul"
  },
  {
    "Reg": "0562310005101049",
    "Name": "Yahiya"
  },
  {
    "Reg": "0562310005101050",
    "Name": "Ishtiaq Mahmood"
  },
  {
    "Reg": "0562310005101051",
    "Name": "Md.Foysal Ahmed"
  },
  {
    "Reg": "0562310005101052",
    "Name": "Shakil Muhammad Shahriar"
  },
  {
    "Reg": "0562310005101053",
    "Name": "Redwan Hussain"
  },
  {
    "Reg": "0562310005101054",
    "Name": "Md. Miftahul Hasan Mehedi"
  }
]
```


## Class Task

Create page to show result of yours in a page.
* The results should be stored in a JSON file
* In the result view show result of individual course separated into semesters
* For each semester show the CGPA