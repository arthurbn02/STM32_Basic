#include "pwm.h"

void TIMER_Config(void)
{
	//config timer 1ms
	TIM_TimeBaseInitTypeDef timer_struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	timer_struct.TIM_ClockDivision 		= 0;
	timer_struct.TIM_CounterMode 		= TIM_CounterMode_Up;
	timer_struct.TIM_RepetitionCounter 	= 0;
	timer_struct.TIM_Prescaler 			= 72 - 1;
	timer_struct.TIM_Period 			= 1000 - 1;
	TIM_TimeBaseInit(TIM4, &timer_struct);
}
//config PWM 50%duty
void PWM_Config(void)
{
	TIM_OCInitTypeDef pwm_struct;
	GPIO_InitTypeDef gpio_struct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	pwm_struct.TIM_OCMode		= TIM_OCMode_PWM1;
	pwm_struct.TIM_Pulse 		= 500;
	pwm_struct.TIM_OCPolarity 	= TIM_OCPolarity_High;//tich cuc cao
	pwm_struct.TIM_OutputState 	= TIM_OutputState_Enable;
	TIM_OC4Init(TIM4, &pwm_struct);
	TIM_Cmd(TIM4, ENABLE);
	
	
	gpio_struct.GPIO_Pin 	= GPIO_Pin_9;
	gpio_struct.GPIO_Mode 	= GPIO_Mode_AF_PP;
	gpio_struct.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_struct);
}
