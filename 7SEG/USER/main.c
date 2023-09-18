#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
char seg[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0x8f, 0x80, 0x90};
uint32_t delay_time;
void Delay_Ms(uint32_t time);
void GPIO_Config(void);
void SEG_Display(uint32_t number);
int main()
{
	int i;
	GPIO_Config();
	while(1)
	{
		for(i = 0; i < 99; i++)
		{
			SEG_Display(i);
		}
	}
}
void GPIO_Config()
{
	GPIO_InitTypeDef gpio_struct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB, ENABLE);
	gpio_struct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	gpio_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_struct);
	GPIO_ResetBits(GPIOB, GPIO_Pin_0| GPIO_Pin_1);
	
	gpio_struct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	gpio_struct.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_struct);
}

void SEG_Display(uint32_t number)
{
	int i = 0;
	for(i = 0; i < 500; i++)
	{
		GPIOB -> ODR = 0x01;
		GPIOA -> ODR = seg[number/10];
		Delay_Ms(1);
		GPIOB -> ODR = 0x00;
		
		GPIOB -> ODR = 0x02;
		GPIOA -> ODR = seg[number%10];
		Delay_Ms(1);
		GPIOB -> ODR = 0x00;
	}
}

void Delay_Ms(uint32_t time)
{
	int i, j;
	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 0x2aff; j++);
	}
}