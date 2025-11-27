import { exec } from "child_process";
import path from "path";

const inputVideo = "input.mp4";
const outputVideo = "output_cut.mp4";

// Start and end times
const startTime = "00:15:00";  // 15 min
const endTime = "01:20:00";    // 1:20 h

// Duration = end - start (1h20m - 15m = 1h5m = 3900 seconds)
const durationSeconds = 3900;

const command = `ffmpeg -i "${inputVideo}" -ss ${startTime} -t ${durationSeconds} -c copy "${outputVideo}"`;

console.log("⏳ Cutting video...");
exec(command, (error, stdout, stderr) => {
  if (error) {
    console.error("❌ Error:", error.message);
    return;
  }
  console.log("Video cut complete ^_^");
  console.log(`Saved as: ${path.resolve(outputVideo)}`);
});
