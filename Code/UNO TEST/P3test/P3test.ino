#include <WiFiS3.h>
#include <RTC.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define RX D0
#define TX D1
#define INTERRUPT_SETUP D2
#define INTERRUPT_ERASE D3
#define UNIVERSAL_SLEEP D4
#define BUZZER_PWM D5
#define DCS_DIR D6
#define X_DIR D7
#define Y_DIR D8
#define DCS_PWM D9
#define X_STEP D10
#define Y_STEP D11
#define X_MODE D12
#define Y_MODE D13

#define DAC A0 
#define X_ENABLE A1
#define Y_ENABLE A2
#define DCS_ENABLE A3
#define DCS_FEEDBACK A4
#define DCS_ZERO A5

//A0 uses DAC option.

int tiltO;
int stylusO;

void receive()
{

}

void report()
{

}

void stylusX(int dir, int steps, int size)
{

    if (dir == LEFT)
    {

        //set direction pin x to left 

    }

    else if (dir == RIGHT)
    {

    }

    else
    {

    }

}

void stylusY(int dir, int steps, int size)
{

}

void stylusHome()
{

}

void tilt(int dir, int position)
{

}

void shake()
{

}

void monitor(int motor)
{

}

void enabler(int motor)
{

}

void setup()
{

    pinMode(RX, INPUT);
    pinMode(TX, OUTPUT);
    pinMode(INTERRUPT_SETUP, INPUT);
    pinMode(INTERRUPT_ERASE, INPUT);
    pinMode(UNIVERSAL_SLEEP, OUTPUT);
    pinMode(BUZZER_PWM, OUTPUT);
    pinMode(DCS_DIR, OUTPUT);
    pinMode(X_DIR, OUTPUT);
    pinMode(Y_DIR, OUTPUT);
    pinMode(DCS_PWM, OUTPUT);
    pinMode(X_STEP, OUTPUT);
    pinMode(Y_STEP, OUTPUT);
    pinMode(X_MODE, OUTPUT);
    pinMode(Y_MODE, OUTPUT);

    pinMode(DAC, OUTPUT);
    pinMode(X_ENABLE, OUTPUT);
    pinMode(Y_ENABLE, OUTPUT);
    pinMode(DCS_ENABLE, OUTPUT);
    pinMode(DCS_FEEDBACK, INPUT);
    pinMode(DCS_ZERO, INPUT);
}

void loop()
{


}
