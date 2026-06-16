// delay.h
#ifndef __DELAY_H
#define __DELAY_H

#include "tim.h"

void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
void delay_init(void);

#endif