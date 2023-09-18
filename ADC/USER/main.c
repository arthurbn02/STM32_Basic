#include "stm32f10x.h"
#include "usart.h"
#include "adc.h"
uint8_t Recei[1000];
void Delay_Ms(uint32_t time);
int main()
{
	float volt;
	float adc_value;
	USART_Config(9600);
	Adc_Config();
	while(1)
	{
		adc_value = Adc_Read();
		volt = Adc_Volt(adc_value);
		printf("ADC value %f -> Vold %f\n", adc_value, volt);
		Delay_Ms(1000);
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
