/**
 * @file shift_register.c
 * @brief Custom HAL driver for 74HC595 shift registers
 */

#include "shift_register.h"

#include "internal/delay.h"

void sreg_init(const sreg_t* reg) {
    gpio_init(*(reg->input), OUTPUT_PP);
    gpio_write(*(reg->input), LOW);
    
    gpio_init(*(reg->sclk), OUTPUT_PP);
    gpio_write(*(reg->sclk), LOW);
    
    gpio_init(*(reg->lclk), OUTPUT_PP);
    gpio_write(*(reg->lclk), LOW);
    
    gpio_init(*(reg->oe_n), OUTPUT_PP);
    gpio_write(*(reg->oe_n), HIGH);
    
    gpio_init(*(reg->rst_n), OUTPUT_PP);
    gpio_write(*(reg->rst_n), HIGH);
}

void shift_bit(const sreg_t* reg, bool bit) {
    gpio_write(*reg->input, bit ? HIGH : LOW);
    gpio_write(*reg->sclk, HIGH);
    delay_cycles(2);
    gpio_write(*reg->sclk, LOW);
}

void shift_byte(const sreg_t* reg, uint8_t data, bool lsb_first) {
    for(int i = 0; i < 8; i++) {
        if (lsb_first) {
            shift_bit(reg, (data & 1) != 0);
            data >>= 1;
        } else {
            shift_bit(reg, (data & 0x80) != 0);
            data <<= 1;
        }
    }
}

void clear_shift_register(const sreg_t* reg) {
    gpio_write(*(reg->rst_n), LOW);
    delay_cycles(2);
    gpio_write(*(reg->rst_n), HIGH);
    latch_shift_register(reg);
}

void enable_shift_register(const sreg_t* reg) {
    gpio_write(*(reg->oe_n), LOW);
}

void disable_shift_register(const sreg_t* reg) {
    gpio_write(*(reg->oe_n), HIGH);
}

void latch_shift_register(const sreg_t* reg) {
    gpio_write(*(reg->lclk), HIGH);
    delay_cycles(2);
    gpio_write(*(reg->lclk), LOW);
}
