#include "internal/stdint.h"
#include "internal/delay.h"

/**
 * @brief delay program by a number of cycles
 * 
 * @param cnt number of cycles, multiplied by 4
 */
void delay_cycles(uint32_t cnt) {
    __asm__ volatile (
        "1:\n\t"
        "nop\n\t"
        "subs %0, #1\n\t"
        "bne 1b"
        : "+r" (cnt)
        :
        : "cc"
    );
}

/**
 * @brief delay program by ms using cycle delay
 * 
 * @param ms time in milliseconds
 */
void delay_ms(uint32_t ms) {
    #ifdef CPU_FREQ
    delay_cycles(ms * (CPU_FREQ / 1000) / 4);
    #else
    delay_cycles(ms * 2000);
    #endif
}
