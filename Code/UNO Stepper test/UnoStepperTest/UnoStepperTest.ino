#define EN 2
#define M1 3
#define M2 4
#define M3 5
#define RST 6
#define SLP 7
#define STP 8
#define DIR 9
#define HIGH 1
#define LOW 0 

int enable;
int mode[3];
int reset;
int sleep;
int step;
int direction;

void setup()
{

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  enable = LOW;
  reset = HIGH;
  sleep = HIGH;
  step = LOW;
  direction = LOW;

  for(int i = 0; i < 3; i++)
  {
    mode[i] = LOW;
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(STP, step);
  step = !step;
  delayMicroseconds(1000);

}


