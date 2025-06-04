#define BUTTON 2
#define OUT 13 
#define REACTION_TIME 10000  // 10 seconds

unsigned long doorOpenTime = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(OUT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  if (buttonState == LOW) {  // Button pressed (door closed)
    doorOpenTime = millis();  // Reset timer when door is closed
    digitalWrite(OUT, LOW);
  } else {  // Button released (door open)
    // Check if door has been open longer than the reaction time
    if (millis() - doorOpenTime > REACTION_TIME) {
      digitalWrite(OUT, HIGH);
    }
  }
}