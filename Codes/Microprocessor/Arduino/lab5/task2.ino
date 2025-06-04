int ledPin=12;
int switchPin=4;
int switchStatus=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin,INPUT);
  Serial.begin(115200);

}

void loop() {
  switchStatus=digitalRead(switchPin);
  digitalWrite(ledPin,switchStatus);
  delay(100);  
}