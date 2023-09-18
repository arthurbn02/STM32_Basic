#include "stm32f10x.h"
#include "pwm.h"
int main()
{
	TIMER_Config();
	PWM_Config();
	while(1)
	{
//		TIM4->CCR4 = 300;
	}
}
