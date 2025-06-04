#include <Servo.h>

Servo servo1;
int servo1pin = 9;
int value;

void setup()
{
     servo1.attach(servo1pin);
     Serial.begin(115200);
}

void loop()
{
     if (Serial.available() > 0)
     {
          value = Serial.read(); // Expecting value of 0 - 9
          value = value - 48;
          if (value <= 9 && value >= 0)
          {
               value = value * 20;
               servo1.write(value);
               Serial.print("Angle is ");
               Serial.println(value);
          }
          else
          {
               Serial.println("Angle out of bound");
          }
     }
}