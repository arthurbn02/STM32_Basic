#include "stm32f10x.h"
#include "usart.h"
uint8_t Recei[1000];
void Delay_Ms(uint32_t time);
int main()
{
	USART_Config(9600);
	while(1)
	{
		USART_SendString("Electronics of PTIT\n");
		Delay_Ms(2000);
	}
}

void Delay_Ms(uint32_t time)
{
	uint32_t i, j;
	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 0x2aff; j++);
	}
}
