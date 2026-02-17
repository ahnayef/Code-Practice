# NEUB CSE-06133216 Fall 2025 Lab 4

In this lab we discuss JavaScript. The topics include
* Web storage API
    * localStorage
    * sessionStorage
* IndexedDB

## Class Code
```html
<html>
    <head>
        <title>CSE-06133216 Fall 2025 Lab 4 - Web Storage and IndexedDB usage</title>
    </head>
    <body>
        <h1>This is a demo page showing webstorage</h1>
        <input type="text" id="inputName">
        <button onclick="saveName()">Save</button>
        <button onclick="loadName()">Load</button>
        <button onclick="clearName()">Clear</button>
        <h3 id="nameDisplay"></h3>
    </body>
    <script>
        //Basic usage of localStorage
        // localStorage.setItem("username", "Shahadat");
        // let name=localStorage.getItem("username");
        // console.log(name);

        function saveName()
        {
            let name=document.getElementById("inputName").value;
            localStorage.setItem("userName", name);
            alert("User Saved");
        }

        function loadName()
        {
            let name=localStorage.getItem("userName");
            if(!name){
                document.getElementById("nameDisplay").innerText='No user saved';
            }
            else{
                document.getElementById("nameDisplay").innerText=`Hello ${name}`;
            }
            
        }

        function clearName()
        {
            localStorage.removeItem("userName");
            alert("User Name Cleared")
        }

        //WebSQL
        //Cromium does not support it now so no need to check this
        // var db = openDatabase ('mydb', '1.0', 'Test DB', 2*1024*1024);
        // Where,
        //      mydb - Database name
        //      1.0 - Version number
        //      Test DB - Text description
        //      2*1024*1024 -  Size of database
        //      Creation callback – called if the database is created. Even if this feature is not available the database will be still created.

        // db.transaction(function (tx) {
        //     tx.executeSql(
        //     "CREATE TABLE users (id INTEGER PRIMARY KEY, name TEXT, email TEXT)"
        //     );
        // });

        //IndexedDB
        if (!window.indexedDB) {
        alert("Sorry! Your browser does not support IndexedDB");
        }

        let db;
        let request=window.indexedDB.open("myDB", 1);
        request.onupgradeneeded=function(e){
            db=e.target.result;
            let store=db.createObjectStore("users", {keyPath: "id", autoIncrement: true});
            store.createIndex("firstName", "name", {unique: false});
            store.createIndex("lastName", "name", {unique: false});
            console.log("Database Created");            
        }

        request.onsuccess =function(e){
            db=e.target.result;
            console.log("Database Opened")
        }

        request.onerror =function(e){
            console.error("Error opening databse:", r.target.errorCode)
        }

        //Adding Data to database

        function addUser(firstName, lastName){
            if (!db) {
                console.error("Database is not ready yet.");
                return;
            }
            let tx = db.transaction("users", "readwrite");
            let store=tx.objectStore("users");
            store.add({firstName: firstName, lastName:lastName});
            tx.oncomplete=()=>console.log("User Added");
        }

        //addUser("Shahadat", "Hussain");

        //Reading Data
        function getUsers(){
            let tx = db.transaction("users", "readwrite");
            let store=tx.objectStore("users");
            let allUsers=store.getAll();
            allUsers.onsuccess=()=> console.log(allUsers.result);
        }

        //Updating
        function updateUser(id, firstName, lastName){
            let tx = db.transaction("users", "readwrite");
            let store=tx.objectStore("users");
            store.put({id: id, firstName: firstName, lastName:lastName});
        }

        //updateUser(1,"Shahadat Hussain","Parvez")

        //Deleting Data
        function deleteUser(id){
            let tx = db.transaction("users", "readwrite");
            let store=tx.objectStore("users");
            store.delete(id);
            console.log("User Deleted");
        }


    </script>
</html>
```

Here is and example of maintaing user database using indexedDB
```html
<!DOCTYPE html>
<html>
<head>
    <title>CSE-06133216 Fall 2025 Lab 4 - IndexedDB example</title>
</head>
<body>
    <h1>Using IndexedDB Add, View, and Delete Users</h1>

    <form id="userForm">
        <label>Name: <input type="text" id="name" required></label><br>
        <label>Email: <input type="email" id="email" required></label><br>
        <button type="submit">Add User</button>
    </form>

    <h2>All Users</h2>
    <ul id="userList"></ul>

    <script>
        let db;

        // Open database
        let request = indexedDB.open("UserDB", 1);

        // Create object store if not already created
        request.onupgradeneeded = function(event) {
            db = event.target.result;
            let store = db.createObjectStore("users", { keyPath: "id", autoIncrement: true });
            store.createIndex("name", "name", { unique: false });
            store.createIndex("email", "email", { unique: true });
            console.log("Object store created");
        };

        
        request.onsuccess = function(event) {
            db = event.target.result;
            console.log("Database opened successfully");
            displayUsers(); // Show any existing users
        };

        request.onerror = function(event) {
            console.error("Database error:", event.target.errorCode);
        };

        // Add user
        function addUser(user) {
            if (!db) {
                console.error("Database not ready yet");
                return;
            }
            let transaction = db.transaction(["users"], "readwrite");
            let store = transaction.objectStore("users");
            let request = store.add(user);

            request.onsuccess = function() {
                console.log("User added successfully");
                displayUsers(); 
            };
            request.onerror = function() {
                console.error("Error adding user");
            };
        }

        //Show all users
        function displayUsers() {
            let list = document.getElementById("userList");
            list.innerHTML = "";

            let transaction = db.transaction("users", "readonly");
            let store = transaction.objectStore("users");
            let request = store.openCursor();

            request.onsuccess = function(event) {
                let user = event.target.result;
                if (user) {
                    let li = document.createElement("li");
                    li.textContent = `ID: ${user.value.id} | Name: ${user.value.name} | Email: ${user.value.email}`;
                    
                    //Adding a Delete button
                    let deleteBtn = document.createElement("button");
                    deleteBtn.textContent = "X";
                    deleteBtn.style.marginLeft = "10px";
                    deleteBtn.onclick = function() {
                        deleteUser(user.value.id);
                    };

                    li.appendChild(deleteBtn);
                    list.appendChild(li);
                    user.continue();
                }
            };
        }

        // Delete user by id
        function deleteUser(id) {
            let transaction = db.transaction("users", "readwrite");
            let store = transaction.objectStore("users");
            let request = store.delete(id);

            request.onsuccess = function() {
                console.log("User deleted:", id);
                displayUsers(); 
            };

            request.onerror = function() {
                console.error("Delete failed for user:", id);
            };
        }

        //Handle form submission
        document.getElementById("userForm").addEventListener("submit", function(e) {
            e.preventDefault();
            let name = document.getElementById("name").value.trim();
            let email = document.getElementById("email").value.trim();
            if (name && email) {
                addUser({ name: name, email: email });
                this.reset();
            }
        });
    </script>
</body>
</html>

```


## Class Task

Create a TODO app in html with data stored in the browser. You can use either Web Storage indexedDB.