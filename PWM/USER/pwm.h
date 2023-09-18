#ifndef __TIMER__
#define __TIMER__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_gpio.h" 
#include "stm32f10x_tim.h"
#include "stdio.h"
void TIMER_Config(void);
void PWM_Config(void);
#ifdef __cplusplus
}
#endif

#endif
