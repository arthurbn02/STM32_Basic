#include "gpio.h"
#include "systick.h"
int blink = 0;

void Gpio_Config()
{
	GPIO_InitTypeDef gpio_struct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	//config led
	gpio_struct.GPIO_Pin = GPIO_Pin_13;
	gpio_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio_struct);
}

void Gpio_Blink_Led()
{
	blink = !blink;
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, blink);
	Delay_Ms(1000);
}
