int pwmPin = 6;

void setup()
{
     pinMode(pwmPin, OUTPUT);
}

void loop()
{
     for (int i = 0; i < 11; i++)
     {
          analogWrite(pwmPin, map(i * 10, 0, 100, 0, 255));
          delay(1000);
     }
}