#include "control.h"

int init_control(ctrl* c)
{
	c.home_pos = c.u.pot;
	
	
	return 0;
}

int init_all(ctrl* c)
{
	init_control(c);
	init_com(c);
	init_stylus(c);
	init_tilt(c);
	init_ui(c);
	init_encoder(c);
	
	return 0;
}

int con_perform(ctrl* c)
{
	con_update(c);
	sty_step(c, X);	//x movement
	sty_step(c, Y);	//y movement
	tilt_move(c);		//tilt movement
	ui_output(c);		//report stylus position
		
	return 0;
}

int con_update(ctrl* c)
{
	ui_input(c);			//hardware inputs
	c->s = c->o->ss;
	c->t = c->o->tt
	com_txrx(c);			//get new instructions/send current status
	
	return 0;
}