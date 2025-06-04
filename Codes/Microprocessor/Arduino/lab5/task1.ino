int ledPin=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(1000);
  Serial.println("LED ON");
  digitalWrite(ledPin, LOW);
  delay(500);
  Serial.println("LED OFF");
}
