int sensorPin = A0;
int sensorValue;
float volt;
float vref = 5;
int ledPin = 13;
float threshold = 0.7;

void setup()
{
     pinMode(ledPin, OUTPUT);
     Serial.begin(115200);
}

void loop()
{
     sensorValue = analogRead(sensorPin);
     volt = (vref * (float)sensorValue) / 1023;
     Serial.print(sensorValue);
     Serial.print(" ");
     Serial.println(volt);
     if (volt < threshold)
     {
          digitalWrite(ledPin, HIGH);
          delay(100);
     }
     else
     {
          digitalWrite(ledPin, LOW);
          delay(100);
     }
}
