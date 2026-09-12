#include "internal/common.h"
#include "internal/delay.h"
#include "io/gpio.h"

#include "shift_register.h"

gpio_t row_pins[8];

uint8_t col_data;
gpio_t  sreg_input;
gpio_t  sclk;
gpio_t  lclk;
gpio_t  col_en;         /* inverted logic */
gpio_t  col_rst;        /* inverted logic */
sreg_t sreg;

static const uint8_t smiley_face[8] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b01000010,
    0b00111100
};

void setup() {
    system_init();

    for (int i = 0; i < 8; i++) {
        row_pins[i].port = GPIOA;
        row_pins[i].pin = i;

        gpio_init(row_pins[i], OUTPUT_PP);
        gpio_write(row_pins[i], LOW);      // disable all rows at start
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

void display_matrix(const uint8_t* matrix_data) {
    for (int row = 0; row < 8; row++) {
        shift_byte(&sreg, ~matrix_data[row], false);
        int prev_row = (row == 0) ? 7 : (row - 1);
        
        gpio_write(row_pins[prev_row], LOW);
        latch_shift_register(&sreg);
        gpio_write(row_pins[row], HIGH);
        delay_ms(1);
    }
}

void main() {
    setup();

    while (1) {
        display_matrix(smiley_face);
    }
}