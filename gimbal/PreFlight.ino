// This will run through the flow of startup, check up, and fake flight numbers
const int relay1 = 6;
const int relay2 = 7;

const int relay3 = 8;
const int relay4 = 9;

const int vcc = 10;

const int precheck = 2

const int ext_t = 1000;

void la1_retract();
void la1_retract();
void la2_extend();
void la2_extend();
void middle();
void startactuators();
void stopactuators();

void setup()
{ // Runs through start up code to zero actuators
    Serial.begin(9600);
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    pinMode(vcc, OUTPUT);
    pinMode(precheck, INPUT);

    startactuators();
    la1_retract();
    la2_retract();
    delay(2000);
    middle();
    stopactuators();
}

void la1_extend()
{// Extends linear actuator 1
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
}

void la1_retract()
{// Retracts linear actuator 1
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}

void la2_extend()
{// extends linear actuator 2
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, HIGH);
}

void la2_retract()
{// retracts linear actuator 2
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
}

void stopactuators()
{// stops relay board
  digitalWrite(vcc, LOW);
}

void startactuators()
{// starts relay board
    digitalWrite(vcc,HIGH);
}

void middle()
{// Extends actuators for 1 second
    la1_extend();
    la2_extend();
    delay(1000);
}

void loop(roll, pitch )
{
    if(digitalRead(precheck) == HIGH)
    {
        startactuators();
    // Tilt Left
        la1_retract();
        delay(ext_t);
        la1_extend();
        delay(ext_t);
    // Tilt right
        la1_extend();
        delay(ext_t);
        la1_retract();
        delay(ext_t);
    // Tilt Up
        la2_extend();
        delay(ext_t);
        la2_retract();
        delay(ext_t);
    // Tilt Down
        la2_retract();
        delay(ext_t);
        la2_extend();
        delay(ext_t);

        stop actuators();
        delay(ext_t);
    }
}
