
#ifndef __ADC__
#define __ADC__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x_adc.h"  
#include "stdio.h"
#include <stdarg.h>
void Adc_Config(void);
float Adc_Read(void);
float Adc_Volt(int adc_value);
#ifdef __cplusplus
}
#endif

#endif