int led1 = 3;
int led2 = 10;
int led3 = 5;
int led4 = 6;
int led5 = 9;

int ldr = A0;

int ir1 = A1;
int ir2 = A2;
int ir3 = A3;
int ir4 = A4;
int ir5 = A5;

void setup()
{
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);

    pinMode(ldr, INPUT);

    pinMode(ir, INPUT);
    pinMode(ir1, INPUT);
    pinMode(ir2, INPUT);
    pinMode(ir3, INPUT);
    pinMode(ir4, INPUT);
}

void loop()
{
    Serial.println(analogRead(A0));
    int ldrStatus = analogRead(ldr);
    if (ldrStatus <= 300)
    {
        digitalWrite(led, HIGH);
        analogWrite(led, 255 / 5);

        digitalWrite(led1, HIGH);
        analogWrite(led1, 255 / 5);

        digitalWrite(led2, HIGH);
        analogWrite(led2, 255 / 5);

        digitalWrite(led3, HIGH);
        analogWrite(led3, 255 / 5);

        digitalWrite(led4, HIGH);
        analogWrite(led4, 255 / 5);

        if (analogRead(ir1) <= 40)
        {
            digitalWrite(led1, HIGH);
            delay(1000);
        }

        if (analogRead(ir2) <= 40)
        {
            digitalWrite(led2, HIGH);
            delay(1000);
        }

        if (analogRead(ir3) <= 40)
        {
            digitalWrite(led3, HIGH);
            delay(1000);
        }

        if (analogRead(ir4) <= 40)
        {
            digitalWrite(led4, HIGH);
            delay(1000);
        }

        if (analogRead(ir5) <= 40)
        {
            digitalWrite(led5, HIGH);
            delay(1000);
        }
    }
    else
    {
        digitalWrite(led, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }
}
