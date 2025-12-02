#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>
#include "SysClock.h"
#include "system_stm32f3xx.h"
#include "bitwise.h"

#define SHUTDOWN 0

typedef struct Stylus{
	int stp[2];
	int dir[2];
	int ena[2];
	int slp[2];
	int rst[2];
	int mod[2];
}stylus;

typedef struct Tilt{
	int cmd;	//position instruction
	int set;	//home position
	int dir;	//direction
	int vib;	//vibe instruciton
}tilt;

typedef struct Encoder{
	int pulse[2];		//pulsetrain valus
	int dir;				//current direction
	int pos;				//current position
}enc;

typedef struct Coms{
stylus* ss;
tilt* tt;
}coms;

typedef struct Ui{
	int pot;
	int swi;
	int pos[2];

}ui;

typedef struct Control{
	stylus* s;
	tilt* t;
	enc* e;
	ui* u;
	coms* o;
	
	int home_pos;
}ctrl;

stylus s;
tilt t;
enc e;
coms o;
ui u;
ctrl c;

int init_com(ctrl* c);
int com_txrx(ctrl* c);

#endif