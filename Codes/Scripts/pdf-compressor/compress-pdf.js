const fs = require("fs");
const path = require("path");
const { exec } = require("child_process");

const inputDir = path.join(__dirname, "input");
const outputDir = path.join(__dirname, "output");

// Create output directory if it doesn't exist
if (!fs.existsSync(outputDir)) {
  fs.mkdirSync(outputDir);
}

// Compression quality options
// screen  -> lowest size, lowest quality
// ebook   -> good balance (recommended)
// printer -> higher quality
// prepress -> highest quality
const PDF_QUALITY = "/ebook";

fs.readdir(inputDir, (err, files) => {
  if (err) {
    console.error("Error reading input directory:", err);
    return;
  }

  const pdfFiles = files.filter(file => file.toLowerCase().endsWith(".pdf"));

  if (pdfFiles.length === 0) {
    console.log("No PDF files found in input directory.");
    return;
  }

  pdfFiles.forEach(file => {
    const inputPath = path.join(inputDir, file);
    const outputPath = path.join(outputDir, file);

    const command = `
      gs -sDEVICE=pdfwrite \
         -dCompatibilityLevel=1.4 \
         -dPDFSETTINGS=${PDF_QUALITY} \
         -dNOPAUSE -dQUIET -dBATCH \
         -sOutputFile="${outputPath}" \
         "${inputPath}"
    `;

    exec(command, (error) => {
      if (error) {
        console.error(`❌ Failed to compress ${file}`);
      } else {
        console.log(`✅ Compressed: ${file}`);
      }
    });
  });
});
