int sensorPin = A0;
int sensorValue;
int ledPin = 13;

void setup()
{
     pinMode(ledPin, OUTPUT);
     Serial.begin(115200);
}

void loop()
{
     sensorValue = analogRead(sensorPin);
     Serial.println(sensorValue);

     // Turning LED on and off with delay equal to sensorValue
     digitalWrite(ledPin, HIGH);
     delay(sensorValue);
     digitalWrite(ledPin, LOW);
     delay(sensorValue);
}
