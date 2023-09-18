#include "gpio.h"

int stt_old = 0, stt_new = 0, blink = 0;

void Delay_Ms(uint32_t time);

void Gpio_Config()
{
	GPIO_InitTypeDef gpio_struct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOB, ENABLE);
	//config led
	gpio_struct.GPIO_Pin = GPIO_Pin_13;
	gpio_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &gpio_struct);
	//config button
	gpio_struct.GPIO_Pin = GPIO_Pin_0;
	gpio_struct.GPIO_Mode = GPIO_Mode_IPD;
	gpio_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_struct);
}

void Gpio_Read_Button()
{
	stt_old = stt_new;
	stt_new = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
	if(stt_new == 1 && stt_old == 0)
	{
		blink = !blink;
		GPIO_WriteBit(GPIOC, GPIO_Pin_13, blink);
	}
	Delay_Ms(1);
}

void Delay_Ms(uint32_t time)
{
	uint32_t i, j;
	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 0x2aff; j++)
		{
		}
	}
}
