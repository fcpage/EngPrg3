#ifndef BITWISE_H
#define BITWISE_H

#include "main.h"

#define GPIOx( port ) GPIO ## port
//   GPIOx(B) will be expanded into  GPIOB   as part of the code

// We need some Macros...
#define SET_BITS( port, mask ) ( (port) |= (mask) )
// for example...
//    GPIOB->ODR |= 0x8000;   // OG code
//    SET_BITS(GPIOB->ODR, 0x8000)   // Macro usage, like a function
//    it would be nice if i can ...
//			SET_BITS( B, ODR, 0x8000 )  ...this is much better to use
#define SET_BITS_P( port, reg, mask ) ( (GPIOx(port) -> (reg)) |= (mask) )
//    SET_BITS_P( B, ODR, 0x8000 )
//    will be expanded into (GPIOB -> ODR |= 0x8000)

#define CLEAR_BITS( port, mask )  ( (port) &= (~(mask)) )
#define FLIP_BITS( port, mask )  ( (port) ^= (mask) )

#define FORCE_BITS( port, mask, value ) \
	( (port) = ( ( (port) & (~(mask)) ) | ( (value) & (mask) )) )

#define OTYPER_PP 0UL
#define OTYPER_OD 1UL
#define GPIO_OTYPER_SET( port, pin, type ) \
	FORCE_BITS( GPIOx(port) -> OTYPER, (1UL << ( (pin) * 1)), ((type) << ( (pin) * 1)) )

// If this can be built correctly, I can do...
//  GPIO_OTYPER_SET( B, 2, OTYPER_PP )

// MODER, OTYPER, PUPDR, OSPEEDR, ENABLE_CLOCK

void Wait_ms(uint32_t ms);
void Wait_us(uint32_t us);

#endif
