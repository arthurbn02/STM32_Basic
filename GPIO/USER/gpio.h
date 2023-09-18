#ifndef __GPIO__
#define __GPIO__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_gpio.h"  
#include "stdio.h"
void Gpio_Config(void);
void Gpio_Read_Button(void);
#ifdef __cplusplus
}
#endif

#endif
