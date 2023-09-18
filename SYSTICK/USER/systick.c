#include "systick.h"

uint32_t delay_time;
void Systick_Init()
{
	//1ms
	SysTick_Config(SystemCoreClock / 1000);
	SystemCoreClockUpdate();
}
void SysTick_Handler(void)
{
	if(delay_time > 0)
	{
		delay_time--;
	}
}

void Delay_Ms(uint32_t time)
{
	delay_time = time;
	while(delay_time);
}
