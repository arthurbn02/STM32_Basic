#include "adc.h"
void Adc_Config()
{
	ADC_InitTypeDef adc_struct;
	GPIO_InitTypeDef gpio_struct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
	//init pin read adc
	gpio_struct.GPIO_Pin =  GPIO_Pin_0;
	gpio_struct.GPIO_Mode = GPIO_Mode_AIN;
	gpio_struct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_struct);
	
	/*cau hinh ADC1*/
	adc_struct.ADC_Mode = ADC_Mode_Independent;
	adc_struct.ADC_ScanConvMode = DISABLE;
	adc_struct.ADC_ContinuousConvMode = ENABLE;
	adc_struct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	adc_struct.ADC_DataAlign = ADC_DataAlign_Right;
	adc_struct.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &adc_struct);

	/* Cau hinh chanel, rank, thoi gian lay mau */
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
		/* Cho phep bo ADC1 hoa dong */
	ADC_Cmd(ADC1, ENABLE);   
	/* cho phep cam bien nhiet hoat dong */
	ADC_TempSensorVrefintCmd(ENABLE);
	/* Reset thanh ghi cablib  */   
	ADC_ResetCalibration(ADC1);
	/* Cho thanh ghi cablib reset xong */
	while(ADC_GetResetCalibrationStatus(ADC1));
	/* Khoi dong bo ADC */
	ADC_StartCalibration(ADC1);	
	/* Cho trang thai cablib duoc bat */
	while(ADC_GetCalibrationStatus(ADC1));
	/* Bat dau chuyen doi ADC */ 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);	
}

float Adc_Read()
{
	return(ADC_GetConversionValue(ADC1));
}

float Adc_Volt(int adc_value)
{
	float v_supply = 3.3, v_out, adc_resolution = 4096;
	v_out = (adc_value * v_supply) / adc_resolution;
}