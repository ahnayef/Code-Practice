const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');
const util = require('util');

const execPromise = util.promisify(exec);

// Input and output directory configuration
// You may want to customize these paths
const inputDir = './input'; // Directory containing videos with audio
const outputDir = './output'; // Directory where videos without audio will be saved

// Create output directory if it doesn't exist
if (!fs.existsSync(outputDir)) {
  fs.mkdirSync(outputDir, { recursive: true });
}

// Get all files from input directory
const processDirectory = async () => {
  try {
    const files = fs.readdirSync(inputDir);

    // Filter for video files (you can add more extensions if needed)
    const videoExtensions = ['.mp4', '.mov', '.avi', '.mkv', '.webm', '.flv'];
    const videoFiles = files.filter(file =>
      videoExtensions.includes(path.extname(file).toLowerCase())
    );

    console.log(`Found ${videoFiles.length} video files to process`);

    // Process each video file
    for (const file of videoFiles) {
      const inputPath = path.join(inputDir, file);
      const outputPath = path.join(outputDir, file);

      console.log(`Processing: ${file}`);

      // Use ffmpeg to remove audio (-an flag)
      await execPromise(`ffmpeg -i "${inputPath}" -c:v copy -an "${outputPath}"`);

      console.log(`Completed: ${file} -> Audio removed`);
    }

    console.log('All videos processed successfully!');
  } catch (error) {
    console.error('Error processing videos:', error);
  }
};

// Execute the function
processDirectory();
