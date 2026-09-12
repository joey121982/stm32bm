#pragma once

#include "internal/stdint.h"

/************************ SCB ************************/

#define SCB_BASE 0xE000ED00
#define VTOR (*(volatile uint32_t*)(SCB_BASE + 0x08))


/************************ RCC ************************/

#define RCC_BASE 0x40021000
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC_BASE + 0x18UL))


/************************ GPIO ************************/

#define GPIOx_CRL_OFFSET    0x00
#define GPIOx_CRH_OFFSET    0x04
#define GPIOx_IDR_OFFSET    0x08
#define GPIOx_ODR_OFFSET    0x0C
#define GPIOx_BSRR_OFFSET   0x10

#define GPIOA_BASE 0x40010800
#define GPIOA_CRL   (*(volatile uint32_t*)(GPIOA_BASE + GPIOx_CRL_OFFSET))
#define GPIOA_CRH   (*(volatile uint32_t*)(GPIOA_BASE + GPIOx_CRH_OFFSET))
#define GPIOA_IDR   (*(volatile uint32_t*)(GPIOA_BASE + GPIOx_IDR_OFFSET))
#define GPIOA_ODR   (*(volatile uint32_t*)(GPIOA_BASE + GPIOx_ODR_OFFSET))
#define GPIOA_BSRR  (*(volatile uint32_t*)(GPIOA_BASE + GPIOx_BSRR_OFFSET))

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRL   (*(volatile uint32_t*)(GPIOB_BASE + GPIOx_CRL_OFFSET))
#define GPIOB_CRH   (*(volatile uint32_t*)(GPIOB_BASE + GPIOx_CRH_OFFSET))
#define GPIOB_IDR   (*(volatile uint32_t*)(GPIOB_BASE + GPIOx_IDR_OFFSET))
#define GPIOB_ODR   (*(volatile uint32_t*)(GPIOB_BASE + GPIOx_ODR_OFFSET))
#define GPIOB_BSRR  (*(volatile uint32_t*)(GPIOB_BASE + GPIOx_BSRR_OFFSET))

#define GPIOC_BASE 0x40011000
#define GPIOC_CRL   (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_CRL_OFFSET))
#define GPIOC_CRH   (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_CRH_OFFSET))
#define GPIOC_IDR   (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_IDR_OFFSET))
#define GPIOC_ODR   (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_ODR_OFFSET))
#define GPIOC_BSRR  (*(volatile uint32_t*)(GPIOC_BASE + GPIOx_BSRR_OFFSET))

#define GPIOD_BASE 0x40011400
#define GPIOD_CRL   (*(volatile uint32_t*)(GPIOD_BASE + GPIOx_CRL_OFFSET))
#define GPIOD_CRH   (*(volatile uint32_t*)(GPIOD_BASE + GPIOx_CRH_OFFSET))
#define GPIOD_IDR   (*(volatile uint32_t*)(GPIOD_BASE + GPIOx_IDR_OFFSET))
#define GPIOD_ODR   (*(volatile uint32_t*)(GPIOD_BASE + GPIOx_ODR_OFFSET))
#define GPIOD_BSRR  (*(volatile uint32_t*)(GPIOD_BASE + GPIOx_BSRR_OFFSET))

#define GPIOE_BASE 0x40011800
#define GPIOE_CRL   (*(volatile uint32_t*)(GPIOE_BASE + GPIOx_CRL_OFFSET))
#define GPIOE_CRH   (*(volatile uint32_t*)(GPIOE_BASE + GPIOx_CRH_OFFSET))
#define GPIOE_IDR   (*(volatile uint32_t*)(GPIOE_BASE + GPIOx_IDR_OFFSET))
#define GPIOE_ODR   (*(volatile uint32_t*)(GPIOE_BASE + GPIOx_ODR_OFFSET))
#define GPIOE_BSRR  (*(volatile uint32_t*)(GPIOE_BASE + GPIOx_BSRR_OFFSET))

#define GPIOF_BASE 0x40011C00
#define GPIOF_CRL   (*(volatile uint32_t*)(GPIOF_BASE + GPIOx_CRL_OFFSET))
#define GPIOF_CRH   (*(volatile uint32_t*)(GPIOF_BASE + GPIOx_CRH_OFFSET))
#define GPIOF_IDR   (*(volatile uint32_t*)(GPIOF_BASE + GPIOx_IDR_OFFSET))
#define GPIOF_ODR   (*(volatile uint32_t*)(GPIOF_BASE + GPIOx_ODR_OFFSET))
#define GPIOF_BSRR  (*(volatile uint32_t*)(GPIOF_BASE + GPIOx_BSRR_OFFSET))

#define GPIOG_BASE 0x40012000
#define GPIOG_CRL   (*(volatile uint32_t*)(GPIOG_BASE + GPIOx_CRL_OFFSET))
#define GPIOG_CRH   (*(volatile uint32_t*)(GPIOG_BASE + GPIOx_CRH_OFFSET))
#define GPIOG_IDR   (*(volatile uint32_t*)(GPIOG_BASE + GPIOx_IDR_OFFSET))
#define GPIOG_ODR   (*(volatile uint32_t*)(GPIOG_BASE + GPIOx_ODR_OFFSET))
#define GPIOG_BSRR  (*(volatile uint32_t*)(GPIOG_BASE + GPIOx_BSRR_OFFSET))
