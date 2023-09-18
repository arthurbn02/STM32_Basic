#include "stm32f10x.h"
#include "gpio.h"
int main()
{
	Gpio_Config();
	while(1)
	{
		Gpio_Read_Button();
	}
}
