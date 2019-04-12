const int relay1 = 7;
const int relay2 = 6;
const int vcc = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(vcc, OUTPUT);
}

void extend(){
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}

void retract(){
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
}

void stopactuator(){
  digitalWrite(vcc, LOW);
  delay(1000);
  digitalWrite(vcc, HIGH);
}

void middle(){
  extend();
  delay(1000);
}

void loop() {
  //Input is in degrees
  //Convert the degrees to a linear length for actuator
  //Then convert that linear length into time for the delay
  //Determine if the input is regarding an angular change only in the
  //x-axis, y-axis, or z-axis
  //If x-axis then change only one actuator and use its corresponding relays
  //Else use the other relays

  digitalWrite(vcc, HIGH);
  extend();
  delay(2000);
  stopactuator();
  retract();
  delay(2000);
  stopactuator();
  middle();
  stopactuator();

}
