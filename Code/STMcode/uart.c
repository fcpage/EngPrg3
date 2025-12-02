////////////////////////////////////////////////////////////////////////////
//SENG72005 - Embedded Systems Software - Lab 1														//
//																																				//
//By: 					Fergus Page																								//
//Date:					January 21, 2025																					//
//Version:			1.0																												//
//Description:	This file contains functions to initialize and configure	//
//								UART communication on the STM32F303RE microcontroller.	//
////////////////////////////////////////////////////////////////////////////

#include "SysClock.h"
#include "uart.h"
#include "stdio.h"
#include "stdarg.h"

void UART2_Init(void)
{
	//Enable PA2 and PA3 on AF7 for UART2 Comm.
	//1. Enable APB1, so it's now driven by the scaled clock.
	RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;		//1
	
	//Select SYSCLK as USART2 clock source.		// 01
	RCC -> CFGR3 &= ~RCC_CFGR3_USART2SW_1;		// clear the MSB.
	RCC -> CFGR3 |= RCC_CFGR3_USART2SW_0;			// set the LSB.
	// Enable the GPIO clock.
	RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;			/////////////////COMMENT/////////////////////////////////
	
	//2. Set MODER to AF for PA2 and PA3. 
	GPIOA -> MODER &= ~(0x03UL << (2*2) );		// clear GPIOA pin 2 mode bits.
	GPIOA -> MODER &= ~(0x03UL << (2*3) );		// clear GPIOA pin 3 mode bits.
	GPIOA -> MODER |= (0x02UL << (2*2) );			// set GPIOA pin 2 to 10 for AF.
	GPIOA -> MODER |= (0x02UL << (2*3) );			// set GPIOA pin 3 to 10 for AF.
	
	//3. Alternative Function Register for PA2 and PA3. Set to 07 (AF7).
	GPIOA -> AFR[0] |= (0x07UL << (4*2) );		//Set PA2 to AF7
	GPIOA -> AFR[0] |= (0x07UL << (4*3) );		//Set PA2 to AF7
	
	//4. Set output speed register (OSPEEDR) to LOW speed.
	GPIOA -> OSPEEDR &= ~(0x3UL << (2*2) );		//Set speed to low for PA2 - on the low bridge.
	GPIOA -> OSPEEDR &= ~(0x3UL << (2*3) );		//Set speed to low for PA3 - on the low bridge.
	
	//5. Set Pull-up/pull-down register (PUPDR) to No Pull.
	GPIOA -> PUPDR &= ~(0x3UL << (2*2) );		//No pull down for PA2.
	GPIOA -> PUPDR &= ~(0x3UL << (2*3) );		//No pull down for PA3.
	
	//6. Set output type register (OTYPER) to push/pull.
	GPIOA -> OTYPER &= ~(0x1UL << 2);				//No pull down for PA2.
	GPIOA -> OTYPER &= ~(0x1UL << 3);				//No pull down for PA3.
}

void UART2_Config(void)
{
	//1. Disable UART2 (set UE on CR1 to 0).
	USART2 -> CR1 &= ~USART_CR1_UE;
	
	//2. Set BRR to hit 9600 baud.
	USART2 ->BRR = SystemCoreClock / 9600;
	
	//3. Configure data size  (8bit), start bit (1), stop bit (1/2/1.5), parity bit (none/even/odd).
	//OVER8 setup (16x).
	USART2 -> CR1 &= ~USART_CR1_M;
	
	//Stop bit configuration
	USART2 -> CR2 &= ~USART_CR2_STOP;
	
	//4.Enable transmit and receive system blocks (TE and RE).
	USART2 -> CR1 |= USART_CR1_RE;
	USART2 -> CR1 |= USART_CR1_TE;
	
	//5. Enable UART2 (set UE on CR1 to 1).
	USART2 -> CR1 |= USART_CR1_UE;
	
	//6. Wait for USART2 block to boot up and get ready.
	while( (USART2 -> ISR &= USART_ISR_REACK == 0 ) );
	while( (USART2 -> ISR &= USART_ISR_TEACK == 0 ) );
}

int UARTputc(char ch)																	//Send a single char over USART2.
{
	while(!(USART2->ISR & USART_ISR_TXE));							//Wait for an input character. Check that the transmission register is empty, and nothing will be overwritten.
	USART2 -> TDR = (uint8_t)ch;												//Move the character into the UART data transmission register. This automatically suppresses the TXE flag, and the hardware
																											//	will automatically set the TC flag when done transmitting.	
	return 0;																						//Complete.
}

int UARTputs(char* str)															//Send a string over USART2.						
{
	while(*str)																					//For as long as the string has another meaningful character in it,
	{
		UARTputc(*str++);																	//Place the next character using UARTputc.
	}
	
	return 0;																						//Complete.
}

int UARTprintf(char* format, ...)
{
	va_list args;
	char* buff = NULL;
	int sz = 1024;
	
	va_start(args, format);
	vsnprintf(buff, sz, format, args);
	
	
	
	va_end(args);

	return 0;
}

char UARTgetc(void)																		//Receive a character over USART2.
{
	while(!(USART2 -> ISR & USART_ISR_RXNE));						//Wait for a character to arrive.
	return(USART2 -> RDR);															//When it's there, return that character. Complete.
}

char UARTgetcNB(void)																		//Receive a character over USART2.
{
	if(USART2 -> ISR & USART_ISR_RXNE)									//Wait for a character to arrive.
	{
		return(USART2 -> RDR);															//When it's there, return that character. Complete.
	}
	
	else
	{
		return(0x31);
	}
	
}
