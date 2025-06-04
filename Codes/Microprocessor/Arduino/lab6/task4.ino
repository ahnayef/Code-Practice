int pwmPin = 6;

void setup()
{
     pinMode(pwmPin, OUTPUT);
}

void loop()
{
     analogWrite(pwmPin, 127);
     delay(1000);

     analogWrite(pwmPin, 255);
     delay(1000);

     analogWrite(pwmPin, 0);
     delay(1000);
}