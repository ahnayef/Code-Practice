// generate-qrs.js
const QRCode = require("qrcode");
const fs = require("fs");
const path = require("path");

const BASE_URL = "https://fest.neubcse.org/volunteers/";
const OUTPUT_DIR = "./qrcodes";

// Ensure output directory exists
if (!fs.existsSync(OUTPUT_DIR)) {
     fs.mkdirSync(OUTPUT_DIR);
}

const entries = [
     { name: "Md Ali Ahmed Farhan", id: "05625205101012" },
     { name: "Rysa Hoque Chowdhury", id: "01624205101018" },
     { name: "Md Ajharul Islam", id: "05624205101055" },
     { name: "Joyashis Das", id: "0562410005101003" },
     { name: "Md. Jakir Hussain", id: "05624205101022" },
     { name: "Mst Hajera Begum Shimla", id: "0562220005101044" },
     { name: "SANDIP PAUL", id: "05624205101063" },
     { name: "Maymuna Marjan", id: "0562210005101014" },
     { name: "Abhijit Kar Bappi", id: "05624205101029" },
     { name: "Md. Ruhan Hussain", id: "0562410005101038" },
     { name: "Anik Chowdhury", id: "0562220005101049" },
     { name: "Inaya Madiha Islam", id: "05625205101008" },
     { name: "Tanjeda Tanha Sumaiya", id: "0562410005101001" },
     { name: "Priya Das", id: "0562310005101005" },
     { name: "Jadab Lal Sarkar", id: "0562410005101022" },
     { name: "MD Khalid Hasan", id: "05625105101036" },
     { name: "Fabiha Bushra Chowdhury", id: "0562220005101016" },
     { name: "Md. Murad Ahmed Tahmim", id: "0562410005101034" },
     { name: "Hridoy Paul", id: "05624205101062" },
     { name: "Farhana Akter Dina", id: "0562220005101031" },
     { name: "Md. Iktiyad Ahmed Sabit", id: "05625205101042" },
     { name: "Shahlin Fatema Chowdhury Shakifa", id: "05625105101022" },
     { name: "Tahmid Zaman Nabil", id: "05625205101007" },
     { name: "Jakaria Chowdhury Tajwone", id: "0562310005101031" },
     { name: "Syed Salman Sami", id: "0562210005101007" },
     { name: "Md Tanvir Hasan Chowdhury", id: "05624205101037" },
     { name: "Md. Wahidul Auwal Sany", id: "0562320005101063" },
     { name: "MST. FAHIMAJJAMAN JAINA", id: "0562310005101045" },
     { name: "Zarin Tasnim Uddin Jeba", id: "0562320005101060" },
     { name: "Oly Ahmed", id: "0562510005101017" },
     { name: "Saykat Dev Shaon", id: "0562320005101007" },
     { name: "Mst Tajmin Akter", id: "05624205101026" },
     { name: "Pritha Rani Mojumder", id: "0562410005101045" },
     { name: "Suborna Jahan Sumona", id: "0562320005101203" },
     { name: "Shormi Rani Deb", id: "05625205101039" },
     { name: "Sudip Paul", id: "05624205101061" },
     { name: "Redwan Hussan", id: "0562410005101028" },
     { name: "Fouzia Nusrath Chowdhury", id: "0562210005101032" },
     { name: "MD AL MAMUN", id: "05625205101009" },
     { name: "Nazmin Ara Asha", id: "0562410005101031" },
     { name: "Mst. Rafia Khatun", id: "0562320005101055" },
     { name: "Md. Muslim Hussain", id: "05625205101031" },
     { name: "Mahbubur Rahman Rahi", id: "0562410005101046" },
     { name: "Sumaiya Jannat", id: "0562320005101030" },
     { name: "MD.Lal Chan", id: "0562310005101042" },
     { name: "Rubia Jannat Suchi", id: "05624205101015" },
     { name: "Hrithik Dev Nath", id: "0562310005101012" },
     { name: "Fatematuj Johura Mim", id: "0562310005101032" },
     { name: "Tasfia Mostofa Shatu", id: "0562220005101023" },
     { name: "Sraboni Akter Tasnur", id: "0562410005101027" },
     { name: "Ahsan Habib Nayef", id: "0562310005101027" },
];

function safeSlug(value) {
     return value
          .toLowerCase()
          .replace(/[^a-z0-9]+/g, "-")
          .replace(/^-+|-+$/g, "");
}

async function generateQRCodes() {
     for (const { name, id } of entries) {
          const url = `${BASE_URL}${id}`;
          const suffix = name ? `${safeSlug(name)}-` : "";
          const fileName = `${suffix}${id}.png`;
          const filePath = path.join(OUTPUT_DIR, fileName);

          await QRCode.toFile(filePath, url, {
               type: "png",
               width: 1000,
               margin: 1,
               color: {
                    dark: "#000000",       // black QR
                    light: "#00000000",    // transparent background
               },
          });

          console.log(`Generated: ${fileName}`);
     }
}

generateQRCodes().then(() => {
     console.log("✅ All QR codes generated!");
});
