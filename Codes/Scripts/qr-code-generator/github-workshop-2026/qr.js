// generate-qrs.js
const QRCode = require("qrcode");
const fs = require("fs");
const path = require("path");

const BASE_URL = "http://society.neubcse.org/event/participants/";
const OUTPUT_DIR = path.join(__dirname, "qrcodes");

// Ensure output directory exists
if (!fs.existsSync(OUTPUT_DIR)) {
     fs.mkdirSync(OUTPUT_DIR);
}

const entries = [
     { name: "Md. Murad Ahmed Tahmim ", id: "0562410005101034" },
     { name: "Hridoy Paul ", id: "05624205101062" },
     { name: "SANDIP PAUL", id: "05624205101063" },
     { name: "Sudip Paul", id: "05624205101061" },
     { name: "Prodipta Shakar Das Akash", id: "05624205101051" },
     { name: "Mst Tajmin Akter", id: "05624205101026" },
     { name: "Shahriar Hussain ", id: "0562410005101008" },
     { name: "Mahbubur Rahman Rahi", id: "0562410005101046" },
     { name: "Md Hossain Shihab ", id: "05624205101065" },
     { name: "Redwan Hussan", id: "0562410005101028" },
     { name: "Abhijit Kar Bappi ", id: "05624205101029" },
     { name: "Mohua Tajrin Chowdhury ", id: "0562410005101010" },
     { name: "Md. Wahidul Auwal Sany ", id: "562320005101063" },
     { name: "Oly Ahmed", id: "0562410005101017" },
     { name: "Md Tanvir Hasan Chowdhury ", id: "05624205101037" },
     { name: "Jadab Lal Sarkar ", id: "0562410005101022" },
     { name: "Saiful Alom Saif", id: "05625105101032" },
]

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
                    dark: "#9334FF",       // white QR
                    light: "#FFF",    // transparent background
               },
          });

          console.log(`Generated: ${fileName}`);
     }
}

generateQRCodes().then(() => {
     console.log("✅ All QR codes generated!");
});
