#include <EEPROM.h>

const int ledPins[8] = {A0, A1, A2, A3, A4, A5, 2, 3};

void setup()
{

     Serial.begin(115200);

     for (int i = 0; i < 8; i++)
     {
          pinMode(ledPins[i], OUTPUT);
     }

     for (int i = 0; i < 16; i++)
     {
          EEPROM.write(i, i);
          delay(100);
     }

     for (int i = 0; i < 16; i++)
     {
          byte value = EEPROM.read(i);
          displayByteOnLED(value);
          Serial.println(value);
          delay(1000);
     }
}

void loop()
{
     // Nothing
     Serial.println("Entered void loop");
     delay(10000);
}

void displayByteOnLED(byte value)
{
     for (int i = 0; i < 8; i++)
     {
          digitalWrite(ledPins[i], value >> i & 1);
     }
}
