#include "tilt.h"

int init_tilt(ctrl* c, int home_pos)		//move the tray to vertical position, then move to defined setpoint
{
	t.set = home_pos;
	t.cmd = t.set;
	t.dir = FORWARD;			//set direction to forward
	tilt_clear(c);
	tilt_home(t);
	
	
	return 0;
}

int tilt_move(tilt t)
{
	tilt_dir(t);		//toggle the direction
	tilt_output(t);	//output setpoint pwm
	
	return 0;
}

int tilt_dir(tilt t)
{
	if (t.dir == FORWARD)
	{
		
	}
	
	else if(t.dir == BACKWARD)
	{
		
	}
	
	return 0;
}


int tilt_clear(tilt t)
{
	
	return 0;
}

int tilt_home(tilt t)
{
	tilt_output(t.cmd);
	
	return 0;
}

int tilt_vib(tilt t)
{
	
	return 0;
}

int tilt_output(tilt t)
{
	
	return 0;
}




int init_encoder(enc e)
{
	//set up encoder mode on TIM2, PA0 and PA1
	
	return 0;
}

int enc_input(enc e)
{
	//input and pre-processing
	
	return 0;
}

int enc_output(enc e)
{
	//output feedback pwm

	return 0;
}