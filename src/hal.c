#include "internal/common.h"
#include "internal/addresses.h"
#include "io/gpio.h"

void system_init() {
    VTOR = 0x08004000UL;
}

void gpio_init(gpio_t gpio, gpio_mode_t mode) {
    RCC_APB2ENR |= (1 << (2 + gpio.port));

    const uint16_t port_offset = 0x0400;
    
    volatile uint32_t* port_addr;
    uint8_t pin_offset;

    /* determine port config address */
    port_addr = (uint32_t*)(GPIOA_BASE + gpio.port * port_offset);
    if (gpio.pin > 7) port_addr += 1;   // use CRH offset

    pin_offset = (gpio.pin % 8) * 4;
    
    /* determine config from mode */
    uint32_t pin_config;

    switch (mode) {
    case INPUT:
    case INPUT_PULL_DOWN:
    case INPUT_PULL_UP:
        pin_config = 0b1000;
        break;
    case INPUT_ANALOG:
        pin_config = 0b0000;
        break;
    case INPUT_FLOATING:
        pin_config = 0b0100;
        break;

    case OUTPUT:
    case OUTPUT_PP:
        pin_config = 0b0010;
        break;
    case OUTPUT_OPEN_DRAIN:
        pin_config = 0b0110;
        break;
    default:
        // TODO: error handling
        break;
    }

    if (mode == INPUT_PULL_DOWN) {
        gpio_write(gpio, LOW);
    } else if (mode == INPUT_PULL_UP) {
        gpio_write(gpio, HIGH);
    }

    (*port_addr) &= ~(0xFUL << pin_offset);       // clear pin config
    (*port_addr) |= (pin_config << pin_offset);   // set new config
}

void gpio_toggle(gpio_t gpio) {
    const uint16_t port_offset = 0x0400;
    
    volatile uint32_t* port_addr;

    /* determine port config address */
    port_addr = (uint32_t*)(GPIOA_BASE + gpio.port * port_offset);
    port_addr += 3;  // ODR offset

    (*port_addr) ^= (1 << gpio.pin);
}

void gpio_write(gpio_t gpio, gpio_value_t value) {
    const uint16_t port_offset = 0x0400;
    
    volatile uint32_t* port_addr;

    /* determine port config address */
    port_addr = (uint32_t*)(GPIOA_BASE + gpio.port * port_offset);
    port_addr += 4;  // BSRR offset

    if (value == HIGH) {
        (*port_addr) = (1 << gpio.pin);
    } else if (value == LOW) {
        (*port_addr) = (1 << (gpio.pin + 16));
    }
}

gpio_value_t gpio_read(gpio_t gpio) {
    const uint16_t port_offset = 0x0400;
    
    volatile uint32_t* port_addr;

    /* determine port config address */
    port_addr = (uint32_t*)(GPIOA_BASE + gpio.port * port_offset);
    port_addr += 2;  // IDR offset

    return (*port_addr) & (1 << gpio.pin) ? HIGH : LOW;
}