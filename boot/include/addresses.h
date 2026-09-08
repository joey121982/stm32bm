#pragma once

#include <stdint.h>

/* SCB */
#define SCB_BASE 0xE000ED00
#define VTOR (*(volatile uint32_t*)(SCB_BASE + 0x08))

/* RCC */
#define RCC_BASE 0x40021000
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC_BASE + 0x18UL))

/* GPIO */
#define GPIOx_CRH_OFFSET 0x04
#define GPIOx_ODR_OFFSET 0x0C

#define GPIOC_BASE 0x40011000
#define GPIOC_CRH (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_CRH_OFFSET))
#define GPIOC_ODR (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_ODR_OFFSET))
