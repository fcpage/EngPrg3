#ifndef STYLUS_H
#define STYLUS_H

#include "main.h"

#define X 0
#define Y 1
#define DOWN 0
#define UP 1
#define LEFT 0
#define RIGHT 1
#define ENABLE 1
#define SLEEP 0
#define RESET 0
#define HALF_PERIOD 5
#define FULL_SCALE_X 1024		//Calculate steps and change
#define FULL_SCALE_Y 720		//Calculate steps and change
#define NEGATIVE 0
#define POSITIVE 1


enum patterns {FULL = 0, HALF, QUARTER, EIGHTH, SIXTEENTH};
int patterns[5][3] = {	{0,0,0}, {1,0,0}, {0,1,0}, {1,1,0}, {1,1,1}		};
	
int init_stylus(ctrl* c);
int sty_step(ctrl* c, int axis);
int sty_set_dir(ctrl* c, int axis);
int sty_set_mode(ctrl* c, int axis);
int sty_sleep(ctrl* c, int axis);
int sty_reset(ctrl* c, int axis);
int sty_enable(ctrl* c, int axis);

#endif