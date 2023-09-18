#include "stm32f10x.h"
#include "gpio.h"
#include "systick.h"
int main()
{
	Gpio_Config();
	Systick_Init();
	while(1)
	{
		Gpio_Blink_Led();
	}
}