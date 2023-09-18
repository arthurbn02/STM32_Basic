#ifndef __TIMER__
#define __TIMER__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_gpio.h" 
#include "stm32f10x_tim.h"
#include "stdio.h"
void Timer_Config(void);
void Delay_Ms(uint32_t);
#ifdef __cplusplus
}
#endif

#endif
