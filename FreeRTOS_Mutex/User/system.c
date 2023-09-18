#include "system.h"
#include "usart.h"
xSemaphoreHandle xMutex;
void RTOS_Run()
{
	//khoi tao mutex, gia tri 1
	xMutex = xSemaphoreCreateMutex();
	xTaskCreate(RTOS_Task_1, (const char *)"Task 1", 128, NULL, 1, NULL);
	xTaskCreate(RTOS_Task_2, (const char *)"Task 2", 128, NULL, 1, NULL);
	vTaskStartScheduler();
}

//comment 2 dong xSemaphoreTake va xSemaphoreGive de thay su khac biet khi: dung Mutex hoac khong dung Mutex



void RTOS_Task_1(void *p)
{
		//delay cho den khi nhan duoc mutex
		xSemaphoreTake(xMutex, portMAX_DELAY);
		USART_SendString("Task 1 take Mutex\n");
		vTaskDelay(5000);
		USART_SendString("Task 1 give Mutex\n");
		xSemaphoreGive(xMutex);
		vTaskDelay(1000);
}

void RTOS_Task_2(void *p)
{
		//delay cho den khi nhan duoc mutex
		xSemaphoreTake(xMutex, portMAX_DELAY);
		USART_SendString("Task 2 take Mutex\n");
		xSemaphoreGive(xMutex);
		vTaskDelay(1000);
}