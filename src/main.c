#include <stdint.h>

#include "internal/common.h"
#include "internal/delay.h"
#include "io/gpio.h"

#include "shift_register.h"

gpio_t row_pins[8];     /* inverted logic */

uint8_t col_data;
gpio_t  sreg_input;
gpio_t  sclk;
gpio_t  lclk;
gpio_t  col_en;         /* inverted logic */
gpio_t  col_rst;        /* inverted logic */
sreg_t sreg;

void setup() {
    system_init();

    for (int i = 0; i < 8; i++) {
        row_pins[i].port = GPIOA;
        row_pins[i].pin = i;

        gpio_init(row_pins[i], OUTPUT_PP);
        gpio_write(row_pins[i], HIGH);      // disable all columns at start
    }

    sreg_input.port = GPIOB;
    sreg_input.pin = 8;

    sclk.port = GPIOB;
    sclk.pin = 9;

    lclk.port = GPIOB;
    lclk.pin = 10;

    col_en.port = GPIOB;
    col_en.pin = 11;

    col_rst.port = GPIOB;
    col_rst.pin = 12;

    sreg.input = &sreg_input;
    sreg.sclk = &sclk;
    sreg.lclk = &lclk;
    sreg.oe_n = &col_en;
    sreg.rst_n = &col_rst;
    sreg_init(&sreg);
}

void main() {
    setup();

    while (1) {

    }
}