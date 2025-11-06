#include <CheapStepper.h>
#include <Buzzer.h>

int serv = 0;
int step[2] = {1};
int angle[2] = {0};

CheapStepper stepperX(8, 9, 10, 11);
CheapStepper stepperY(4, 5, 6, 7);
Buzzer buzzer(13);

void setup() {

  buzzer.begin(0);

}

void loop() {
  
  serv = (serv++ % 255);
  analogWrite(3, serv);

  stepperX.run();
  stepperY.run();
  angle[1] = angle[1] + step[1];
  angle[0] = angle[0] + step[0];
  stepperX.newMoveDegreesCW(step[0]);
  stepperY.newMoveDegreesCW(step[1]);

  delay(1);
  digitalWrite(3, HIGH);
  delay(1);
  digitalWrite(3, LOW);
  buzzer.sound(NOTE_G7 , 1000);

}

