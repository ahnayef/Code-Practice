#include <EEPROM.h>

const int ledPins[8] = {A0, A1, A2, A3, A4, A5, 2, 3};

byte ledStates[8] = {1, 3, 7, 15, 7, 3, 1, 0};

void setup()
{

     Serial.begin(115200);

     for (int i = 0; i < 8; i++)
     {
          pinMode(ledPins[i], OUTPUT);
     }

     for (int i = 0; i < 8; i++)
     {
          EEPROM.write(i, ledStates[i]);
     }
}

void loop()
{
     for (int i = 0; i < 8; i++)
     {
          byte value = EEPROM.read(i);
          displayByteOnLED(value);
          Serial.println(value);
          delay(1000);
     }
}

void displayByteOnLED(byte value)
{
     for (int i = 0; i < 8; i++)
     {
          digitalWrite(ledPins[i], value >> i & 1);
     }
}
