/*
 * it.c
 *
 *  Created on: 23/01/2021
 *      Author: PC
 */

#include "stm32f4xx.h"
UART_HandleTypeDef huart2; //Handle of UART 2

void SysTick_Handler(void){

	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(){

	HAL_UART_IRQHandler(&huart2);

}


