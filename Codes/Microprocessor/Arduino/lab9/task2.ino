int mls1 = 3;
int mls2 = 4;
int mrs1 = 7;
int mrs2 = 8;
int mlen = 5;
int mren = 9;

void setup()
{
     pinMode(mls1, OUTPUT);
     pinMode(mls2, OUTPUT);
     pinMode(mrs1, OUTPUT);
     pinMode(mrs2, OUTPUT);
     pinMode(mlen, OUTPUT);
     pinMode(mren, OUTPUT);

     Serial.begin(115200);
     // We are not using PWM for now
     digitalWrite(mlen, HIGH);
     digitalWrite(mren, HIGH);
}

void loop()
{
     // Moving Forward
     // Left Motor forward
     digitalWrite(mls1, HIGH);
     digitalWrite(mls2, LOW);
     // Right Motor forward
     digitalWrite(mrs1, HIGH);
     digitalWrite(mrs2, LOW);
     delay(1000);

     // Moving Backward
     // Left motor backward
     digitalWrite(mls1, LOW);
     digitalWrite(mls2, HIGH);
     // right motor backward
     digitalWrite(mrs1, LOW);
     digitalWrite(mrs2, HIGH);
     delay(1000);

     // Stop
     // Left motor Stop
     digitalWrite(mls1, LOW);
     digitalWrite(mls2, LOW);
     // Right Motor Stop
     digitalWrite(mrs1, LOW);
     digitalWrite(mrs2, LOW);
     delay(1000);

     // Turning Right
     // Left Motor forward
     digitalWrite(mls1, HIGH);
     digitalWrite(mls2, LOW);
     // Right Motor Stop
     digitalWrite(mrs1, LOW);
     digitalWrite(mrs2, LOW);
     delay(1000);

     // Turning Left
     // Left motor Stop
     digitalWrite(mls1, LOW);
     digitalWrite(mls2, LOW);
     // Right Motor forward
     digitalWrite(mrs1, HIGH);
     digitalWrite(mrs2, LOW);
     delay(1000);
}