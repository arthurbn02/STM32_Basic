#include "timer.h"

uint32_t delay_time;
void Timer_Config()
{
	TIM_TimeBaseInitTypeDef timer_struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	timer_struct.TIM_ClockDivision = 0;
	timer_struct.TIM_CounterMode = TIM_CounterMode_Up;
	timer_struct.TIM_RepetitionCounter = 0;
	timer_struct.TIM_Prescaler = 36000 - 1;
	timer_struct.TIM_Period = 2 - 1;
	TIM_TimeBaseInit(TIM2, &timer_struct);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	NVIC_EnableIRQ(TIM2_IRQn);
}
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		if(delay_time > 0)
		{
			delay_time--;
		}
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}

void Delay_Ms(uint32_t time)
{
	delay_time = time;
	while(delay_time);
}
