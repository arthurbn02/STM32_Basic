#include "system.h"
#include "usart.h"
EventGroupHandle_t Event;
uint8_t event_bit1, event_bit2;
void RTOS_Run()
{
	Event = xEventGroupCreate();
	event_bit1 = (1 << 0);
	event_bit2 = (1 << 1);
	xTaskCreate(RTOS_Task_1, (const char *)"Task 1", 128, NULL, 1, NULL);
	xTaskCreate(RTOS_Task_2, (const char *)"Task 2", 128, NULL, 1, NULL);
	vTaskStartScheduler();
}


void RTOS_Task_1(void *p)
{
	while(1)
	{
		if(USART_FlagDB() == 1)
		{
			if(USART_Compare("set1") == 1)
			{
				xEventGroupSetBits(Event, event_bit1);
			}
			else if(USART_Compare("set2") == 1)
			{
				xEventGroupSetBits(Event, event_bit2);
			}
		}
	}
}

void RTOS_Task_2(void *p)
{
	uint8_t event_bit;
	while(1)
	{
		event_bit = xEventGroupWaitBits(Event, event_bit1, pdTRUE, pdFALSE, 0);
		if(event_bit & event_bit1)
		{
			USART_SendString("Set 1 ok\n");
		}
		event_bit = xEventGroupWaitBits(Event, event_bit2, pdTRUE, pdFALSE, 0);
		if(event_bit & event_bit2)
		{
			USART_SendString("Set 2 ok\n");
		}
	}
}