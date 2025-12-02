////////////////////////////////////////////////////////////////////////////
//SENG72005 - Embedded Systems Software - Lab 1														//
//																																				//
//By: 					Fergus Page																								//
//Date:					January 21, 2025																					//
//Version:			1.0																												//
//Description:	This file contains function declarations which are 				//
//								defined in uart.c. Header file to match uart.c.					//
////////////////////////////////////////////////////////////////////////////

#ifndef __UART_H
#define __UART_H
#endif

#include "stm32f303xe.h"

void UART2_Init(void);
void UART2_Config(void);
int UARTputc(char ch);
int UARTputs(char* str);
int UARTprintf(char* str, ...);
char UARTgetc();
char UARTgetcNB(void);
