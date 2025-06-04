int ledPin = 13;
int switchPin = 4;
int switchStatus = 0;
int lastSwitchStatus = 1;
int currentSwitchStatus = 1;
bool ledStatus = false;

unsigned long debounceDelay = 100;
unsigned long lastDebounceTime = 0;

void setup()
{
     pinMode(ledPin, OUTPUT);
     pinMode(switchPin, INPUT);
     Serial.begin(115200);
}

void loop()
{
     switchStatus = digitalRead(switchPin);
     Serial.println(switchStatus);

     if (switchStatus != lastSwitchStatus)
     {
          lastDebounceTime = millis();
     }

     if ((millis() - lastDebounceTime) > debounceDelay)
     {
          Serial.println(lastDebounceTime);
          if (switchStatus != currentSwitchStatus)
          {
               currentSwitchStatus = switchStatus;

               if (currentSwitchStatus == HIGH)
               {
                    ledStatus = !ledStatus;
               }
          }
     }

     digitalWrite(ledPin, ledStatus);
     lastSwitchStatus = switchStatus;
     // delay(100); This delay ruins debounce
}
