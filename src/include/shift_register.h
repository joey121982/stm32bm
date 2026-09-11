/**
 * @file shift_register.h
 * @brief Custom HAL driver for 74HC595 shift registers
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "io/gpio.h"

typedef struct {
    gpio_t* input;
    gpio_t* sclk;
    gpio_t* lclk;
    gpio_t* oe_n;    
    gpio_t* rst_n;
} sreg_t;

/* initializes all shift register pins */
void sreg_init(const sreg_t* reg);

/* shifts one bit into the shift register */
void shift_bit(const sreg_t* reg, bool bit);

/* shifts one byte of data into the shift register */
void shift_byte(const sreg_t* reg, uint8_t data, bool lsb_first);

/* resets the shift register */
void clear_shift_register(const sreg_t* reg);

/* sets OE low - turns on output */
void enable_shift_register(const sreg_t* reg);

/* sets OE high - turns off output */
void disable_shift_register(const sreg_t* reg);

/* updates the output pins */
void latch_shift_register(const sreg_t* reg);
