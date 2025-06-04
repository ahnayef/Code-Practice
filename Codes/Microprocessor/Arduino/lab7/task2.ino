int sensorPin = A0;
int sensorValue;
float volt;
float vref = 5;

void setup()
{
     Serial.begin(115200);
}

void loop()
{
     sensorValue = analogRead(sensorPin);
     volt = (vref * (float)sensorValue) / 1023;
     Serial.println(volt);
}
