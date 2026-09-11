#pragma once

typedef enum {
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF,
    GPIOG
} gpio_port_t;

typedef struct {
    gpio_port_t port;
    uint8_t pin;    
} gpio_t;

typedef enum {
    INPUT,
    OUTPUT,
    INPUT_ANALOG,
    INPUT_FLOATING,
    INPUT_PULL_UP,
    INPUT_PULL_DOWN,
    OUTPUT_PP,
    OUTPUT_OPEN_DRAIN
} gpio_mode_t;

typedef enum {
    LOW,
    HIGH
} gpio_value_t;

void gpio_init(gpio_t gpio, gpio_mode_t mode);
void gpio_toggle(gpio_t gpio);
void gpio_write(gpio_t gpio, gpio_value_t value);
gpio_value_t gpio_read(gpio_t gpio);