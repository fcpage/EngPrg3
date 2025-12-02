#include "bitwise.h" 
#include <stdint.h>

void Wait_ms(uint32_t ms) {
    
    SysTick->CTRL = 0;                    // Disable Timer + SysTick interrupt + default AHB/8 clock + clear CountFlag (how?)

    SysTick->LOAD = ((SystemCoreClock /8) / 1000UL) * ms;     // Set reload register (like BRR)
    SysTick->VAL = 0;                                           // Reset the SysTick counter value
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;                    // Start SysTick. Use AHBclock/8
    
    while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));       // Wait for timeout
    
    SysTick->CTRL = 0;                                          // Disable SysTick until next time
}

void Wait_us(uint32_t us) {
    
    SysTick->CTRL = 0;                    // Disable Timer + SysTick interrupt + default AHB/8 clock + clear CountFlag (how?)

    SysTick->LOAD = (SystemCoreClock /8) * us;     // Set reload register (like BRR)
    SysTick->VAL = 0;                                           // Reset the SysTick counter value
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;                    // Start SysTick. Use AHBclock/8
    
    while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));       // Wait for timeout
    
    SysTick->CTRL = 0;                                          // Disable SysTick until next time
}