#include "stm32f10x.h"
#include "i2c.h"
int main()
{
	Lcd_Config();
	Lcd_First_Config();
	I2c_Lcd_Send_String("ELECTRONICS PTIT");
	while(1)
	{
		
	}
}
