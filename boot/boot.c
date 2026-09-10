#include <stdint.h>

#include "addresses.h"
#include "delay.h"

#define CPU_FREQ 8000000

void setup(void) {
    RCC_APB2ENR |= (1 << 4);        // set IOPCEN
    GPIOC_CRH   &= ~(0xF << 20);    // clear pin 13 bits
    GPIOC_CRH   |= (0x2 << 20);     // enable pin 13 PP output max. 2MHz
}

void boot(void) {
    setup();

    uint32_t program_sp = *(uint32_t*)(0x08004000UL);
    uint32_t program_reset = *(uint32_t*)(0x08004004UL);

    if (program_sp < 0x20000000UL || program_sp > 0x20005000UL) {
        // invalid stack pointer error handler
        while(1) {
            GPIOC_ODR ^= (1 << 13);
            delay_ms(200);
        }
    }

    GPIOC_ODR &= ~(1 << 13);
    delay_ms(2000);
    GPIOC_ODR |= (1 << 13);

    VTOR = 0x08004000UL;
    __asm__ volatile ("msr msp, %0" : : "r" (program_sp) :);
    ((void (*)(void))program_reset)();
}