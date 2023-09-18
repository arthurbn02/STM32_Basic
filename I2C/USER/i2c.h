
#include "stm32f10x.h"                  // Device header
	
#ifndef __ABC__
#define __ABC__

#ifdef __cplusplus
 extern "C" {
#endif

#define I2C_ADDRESS     0x4e
#define I2C1_SCL 		GPIO_Pin_6
#define I2C1_SDA		GPIO_Pin_7

void Lcd_Config(void);
void Lcd_First_Config(void);
void I2c_Lcd_Data_Write(uint8_t data);
void I2c_Lcd_Send_String(uint8_t *String);
void clear_LCD(void);
void I2c_Lcd_Command_Write(uint8_t data);


#ifdef __cplusplus
}
#endif

#endif
