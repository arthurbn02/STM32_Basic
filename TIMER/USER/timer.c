#include "timer.h"
int tim_presscaler = 36000, tim_period = 2;
void Delay(void);
void Timer_Config()
{
	TIM_TimeBaseInitTypeDef timer_struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	timer_struct.TIM_CounterMode = TIM_CounterMode_Up;
	timer_struct.TIM_Prescaler = tim_presscaler - 1;
	timer_struct.TIM_Period = 65535;
	TIM_TimeBaseInit(TIM2, &timer_struct);
}
void Delay(void)
{
	TIM_Cmd(TIM2, ENABLE);
	TIM_SetCounter(TIM2, 0);
	while(TIM_GetCounter(TIM2) < tim_period);
	TIM_Cmd(TIM2, DISABLE);
}

void Delay_Ms(uint32_t time)
{
	while(time--)
	{
		Delay();
	}
}
