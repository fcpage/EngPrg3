#include "stylus.h"

int init_stepper(ctrl* c)				//set initial valuesfor each axis
{
	
	for(int i = 0; i < 2; i++)			
	{
		s.slp[i] = !SLEEP;										//alarm bout to go off
		s.ena[i] = ENABLE;										//enabler
		s.rst[i] = !RESET;										//do not reset yet
		s.stp[i] = HALF;											//half steps
		s.dir[i] = NEGATIVE;									//toward the origin
		s.mod[i] = *patterns[s.mod[i]];				//start with full steps
		
		sty_sleep(c, i);											//wake
		sty_enable(c, i);											//enable
		sty_reset(c, i);											//toggle reset	
		sty_set_mode(c, i);										//set the mode
		sty_set_dir(c, i);										//set the direction
	}
	
	for(int i = 0; i < FULL_SCALE_X; i++)		//send stylus to x origin
	{
		sty_step(c, X);												//get to steppin
	}
	
	for(int i = 0; i < FULL_SCALE_Y; i++)		//send stylus to y origin
	{
		sty_step(c, Y);												//STEP!
	}
	
		return 0;
}	

int sty_step(ctrl* c, int axis)
{
	
	sty_set_mode(c, axis);								//set the step size
	sty_set_dir(c, axis);									//set the directiion
	
	for(int i = 0; i < s.stp[axis]; i++)	//toggle the pins
	{	
																				//set pin high										//
		Wait_us(2);													//wait for a halfcycle
																				//set pin low											//
		Wait_us(2);													//wait for a halfcycle
	}
	
	return 0;
}

int sty_set_dir(ctrl* c, int axis)
{
	//set bits
		
	return 0;
}

int sty_set_mode(ctrl* c, int axis)
{
	
	//c->s->mod[axis][0]	//set hardware
	//c->s->mod[axis][1] 	//set hardware
	//c->s->mod[axis][2]	//set hardware
	
	return 0;
}

int sty_sleep(ctrl* c, int axis)
{
	//= c->s->slp[axis];		//set hardware 

	return 0;
}

int sty_reset(stylus s, int axis)
{
	//= s.rst[axis];		//set hardware
	
	
	return 0;
}

int sty_enable(stylus s, int axis)
{
	//=ms.ena[axis];		//set hardware
	
	
	return 0;
}