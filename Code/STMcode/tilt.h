#ifndef TILT_H
#define TILT_H

#include "main.h"

#define BACKWARD 0
#define FORWARD 1
#define OFF 0
#define ON 1
#define A 0
#define B 1

int init_tilt(ctrl* c);
int tilt_dir(ctrl* c);
int tilt_move(ctrl* c);
int tilt_clear(ctrl* c);
int tilt_home(ctrl* c);
int tilt_vib(ctrl* c);
int tilt_output(ctrl* c);

int init_encoder(ctrl* c);
int enc_input(ctrl* c);
int enc_output(ctrl* c);

#endif