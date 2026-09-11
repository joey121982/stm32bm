#include <stdint.h>

#include "internal/delay.h"
#include "io/gpio.h"
#include "common.h"

gpio_t PC13 = {
    .port = GPIOC,
    .pin = 13
};

void setup() {
    system_init();

    gpio_init(PC13, OUTPUT_PP);
}

void main() {
    setup();

    while(1) {
        gpio_write(PC13, LOW);
        delay_ms(500);
        gpio_write(PC13, HIGH);
        delay_ms(3000);
    }
}