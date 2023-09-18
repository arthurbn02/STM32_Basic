#include "system.h"
#include "usart.h"
xQueueHandle xQueue;
void RTOS_Run()
{
	//tao queue voi 10 block, moi block size = 4 byte
	xQueue = xQueueCreate(10, sizeof(int));
	xTaskCreate(RTOS_Task_1, (const char *)"Task 1", 128, NULL, 1, NULL);
	xTaskCreate(RTOS_Task_2, (const char *)"Task 2", 128, NULL, 1, NULL);
	vTaskStartScheduler();
}

void RTOS_Task_1(void *p)
{
	int data_send;
	while(1)
	{
		if(USART_FlagDB() == 1)
		{
			if(USART_Compare("set1") == 1)
			{
				data_send = 1;
				xQueueSend(xQueue, &data_send, 10);
			}
			else if(USART_Compare("set2") == 1)
			{
				data_send = 2;
				xQueueSend(xQueue, &data_send, 10);
			}
		}
	}
}

void RTOS_Task_2(void *p)
{
	int data_receive;
	while(1)
	{
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
	}
}