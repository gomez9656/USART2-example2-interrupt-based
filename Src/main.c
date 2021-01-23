/*
 * main.c
 *
 *  Created on: 23/01/2021
 *      Author: PC
 */

#include "stm32f4xx.h"
#include "main.h"
#include <string.h>

/*
 * Functions prototypes
 */
void SystemCoreClockConfig();
void UART2_Init();
void Error_handler();


UART_HandleTypeDef huart2; //Handle of UART 2

char *user_data = "The application is up!\r\n";

int main(){

	/* Basic initialization */
	HAL_Init();
	SystemCoreClockConfig();

	UART2_Init();

	uint16_t len_of_data = strlen(user_data);
	HAL_UART_Transmit(&huart2, (uint8_t*)user_data, len_of_data, HAL_MAX_DELAY);

	while(1);

	return 0;
}

/*
 * You can use it when you need an specific clock
 * By default will be internal clock
 */
void SystemCoreClockConfig(){

}

/*
 * Function to initialize the UART2 peripheral
 */
void UART2_Init(){

	//1. Linking handle struct to base address
	huart2.Instance = USART2;

	//2. Init the handle variable
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;

	//3. Use the API to initialize
	if(HAL_UART_Init(&huart2) != HAL_OK){

		//There is a problem
		Error_handler();
	}
}

void Error_handler(void){
	while(1);
}
