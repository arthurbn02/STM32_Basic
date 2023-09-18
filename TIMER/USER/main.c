#include "stm32f10x.h"
#include "gpio.h"
#include "timer.h"
int main()
{
	Gpio_Config();
	Timer_Config();
	while(1)
	{
		Gpio_Blink_Led();
	}
} 
