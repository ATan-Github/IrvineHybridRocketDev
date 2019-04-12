const int relay1 = 6;
const int relay2 = 7;
const int relay3 = 8;
const int relay4 = 9;
const int vcc = 10;

const int precheck_toggle = 2;
const int ext_t = 1000;


struct Extend
{
  Extend(const int& relay1, const int& relay2):
  r1(relay1), r2(relay2)
  {
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
  }

  int r1;
  int r2;
};

struct Retract
{
  Retract(const int& relqy1, const int& relqy2):
  r1(relay1), r2(relay2)
  {
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
  }

  int r1;
  int r2;
};

struct LA_1
{
  LA_1(const int& relay1, const int& relay2):
  r1(relay1), r2(relay2){}

  int r1, r2;
  float position = -1;
  struct Extend extend = {r1,r2};
  struct Retract retract = {r1,r2};
};

struct LA_2
{
  LA_2(const int& relay3, const int& relay4):
  r3(relay3), r4(relay4){}

  int r3, r4;
  float position = -1;
  struct Extend extend = {r3,r4};
  struct Retract retract = {r3, r4};
};


void startactuators();
void stopactuators();


struct LA_1 la1 = {relay1, relay2};
struct LA_2 la2 = {relay3, relay4};

void setup()
{
  Serial.begin(9600);
  pinMode(vcc, OUTPUT);
  pinMode(precheck_toggle, INPUT);

  startactuators();
  la1.retract;
  la2.retract;
  delay(2000);
  la1.extend;
  la2.extend;
  delay(1000);
  stopactuators();
}

void stopactuators()
{
  digitalWrite(vcc, LOW);
}

void startactuators()
{
  digitalWrite(vcc, HIGH);
}

void loop()
{
    startactuators();

    la1.retract;
    delay(ext_t);
    la1.extend;
    delay(ext_t);

    la1.extend;
    delay(ext_t);
    la1.retract;
    delay(ext_t);

    la2.retract;
    delay(ext_t);
    la2.extend;
    delay(ext_t);

    la2.extend;
    delay(ext_t);
    la2.retract;
    delay(ext_t);

    stopactuators();
    delay(3000);
}

