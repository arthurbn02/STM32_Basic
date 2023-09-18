#include "system.h"
#include "usart.h"
xSemaphoreHandle xSemaphoreBin;
void RTOS_Run()
{
	//khoi tao semaphore binary, gia tri 0
	xSemaphoreBin = xSemaphoreCreateBinary();
	xSemaphoreGive(xSemaphoreBin);
	xTaskCreate(RTOS_Task_1, (const char *)"Task 1", 128, NULL, 1, NULL);
	xTaskCreate(RTOS_Task_2, (const char *)"Task 2", 128, NULL, 1, NULL);
	vTaskStartScheduler();
}

//comment 2 dong xSemaphoreTake va xSemaphoreGive de thay su khac biet khi: dung xSemaphoreBin hoac khong dung Mutex



void RTOS_Task_1(void *p)
{
		//delay cho den khi nhan duoc mutex
		xSemaphoreTake(xSemaphoreBin, portMAX_DELAY);
		USART_SendString("Task 1 take semaphore binary\n");
		vTaskDelay(5000);
		USART_SendString("Task 1 give semaphore binary\n");
		xSemaphoreGive(xSemaphoreBin);
		vTaskDelay(1000);
}

void RTOS_Task_2(void *p)
{
		//delay cho den khi nhan duoc mutex
		xSemaphoreTake(xSemaphoreBin, portMAX_DELAY);
		USART_SendString("Task 2 take semaphore binary\n");
		xSemaphoreGive(xSemaphoreBin);
		vTaskDelay(1000);
}