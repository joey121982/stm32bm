#pragma once

/**
 * @brief delay program by a number of cycles
 * 
 * @param cnt number of cycles, multiplied by 4
 */
void delay_cycles(uint32_t cnt);

/**
 * @brief delay program by ms using cycle delay
 * 
 * @param ms time in milliseconds
 */
void delay_ms(uint32_t ms);