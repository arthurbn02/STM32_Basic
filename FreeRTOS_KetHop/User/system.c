#include "system.h"
#include "usart.h"
xQueueHandle xQueue;
EventGroupHandle_t Event;
xSemaphoreHandle xMutex;
uint8_t event_bit;
void RTOS_Run()
{
	RTOS_Config();
	xTaskCreate(RTOS_Task_1, (const char *)"Task 1", 128, NULL, 1, NULL);
	xTaskCreate(RTOS_Task_2, (const char *)"Task 2", 128, NULL, 1, NULL);
	vTaskStartScheduler();
}

void RTOS_Config()
{
	Event = xEventGroupCreate();
	xMutex = xSemaphoreCreateMutex();
	event_bit = (1 << 0);
	//tao queue voi 10 block, moi block size = 4 byte
	xQueue = xQueueCreate(10, sizeof(int));
}

void RTOS_Task_1(void *p)
{
	int data_send;
	while(1)
	{
		if(USART_FlagDB() == 1)
		{
			xSemaphoreTake(xMutex, portMAX_DELAY);
			if(USART_Compare("set1") == 1)
			{
				data_send = 1;
				xQueueSend(xQueue, &data_send, 10);
				xEventGroupSetBits(Event, event_bit);
			}
			else if(USART_Compare("set2") == 1)
			{
				data_send = 2;
				xQueueSend(xQueue, &data_send, 10);
				xEventGroupSetBits(Event, event_bit);
			}
			xSemaphoreGive(xMutex);
		}
	}
}

void RTOS_Task_2(void *p)
{
	int data_receive;
	uint8_t event_bit_flag;
	while(1)
	{
		event_bit_flag = xEventGroupWaitBits(Event, event_bit, pdTRUE, pdFALSE, 0);
		if(event_bit_flag & event_bit)
		{
			xSemaphoreTake(xMutex, portMAX_DELAY);
			if(xQueueReceive(xQueue, &data_receive, 10))
			{
				if(data_receive == 1)
				{
					USART_SendString("Set 1 ok\n");
				}
				else if(data_receive == 2)
				{
					USART_SendString("Set 2 ok\n");
				}
			}
			xSemaphoreGive(xMutex);
		}

	}
}