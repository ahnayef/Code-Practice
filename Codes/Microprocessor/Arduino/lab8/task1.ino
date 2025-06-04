int in1 = 3;
int in2 = 4;
int enA = 5;

void setup()
{
     pinMode(in1, OUTPUT);
     pinMode(in2, OUTPUT);
     pinMode(enA, OUTPUT);
     Serial.begin(115200);
}

void loop()
{
     digitalWrite(enA, HIGH);
     // ROtate in one direction
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     Serial.println("Rotate in one direction");
     delay(1000);

     // Rotate in Opposite direction
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     Serial.println("Rotate in Opposite direction");
     delay(1000);
}