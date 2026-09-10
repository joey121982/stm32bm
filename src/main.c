#include <stdint.h>

#include "io/gpio.h"
#include "common.h"

void setup() {
    system_init();
}

void main() {
    gpio_t PC13 = {
        .port = GPIOC,
        .pin = 13
    };

    gpio_init(PC13, OUTPUT_PP);
}