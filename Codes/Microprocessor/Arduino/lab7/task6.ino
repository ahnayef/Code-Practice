int switchPin = 2;
int ledPin = 13;
bool ledStatus = false;

void setup()
{
     pinMode(ledPin, OUTPUT);
     pinMode(switchPin, INPUT);
     Serial.begin(115200);
     attachInterrupt(0, ledToggle, FALLING);
}

void loop()
{
}

void ledToggle()
{
     ledStatus = !ledStatus;
     digitalWrite(ledPin, ledStatus);
}