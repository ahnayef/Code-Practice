int pwmPin = 7;

void setup()
{
     pinMode(pwmPin, OUTPUT);
}

void loop()
{
     pwm(pwmPin, 20);
}

void pwm(int pin, int duty)
{
     int t_on = 5;
     float x = ((t_on * 100) / duty) - t_on;
     int t_off = (int)x;
     digitalWrite(pin, HIGH);
     delay(t_on);
     digitalWrite(pin, LOW);
     delay(t_off);
}