/*
 * msp.c
 *
 *  Created on: 23/01/2021
 *      Author: PC
 */

#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
	//Low level initializations

	//1. Set up priority grouping
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions
	SCB->SHCSR |= 0x7 << 16; //usage fault, memory fault and bus fault system exception

	//3. Configure the priority for the system exception
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

/*
 * Configure the low level initialization of the UART2 peripheral
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart){

	GPIO_InitTypeDef gpio_uart;

	//1. Enable the clock
	__HAL_RCC_USART2_CLK_ENABLE();

	//2. Pin muxing configuration
	gpio_uart.Pin = GPIO_PIN_2;
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_uart.Alternate = GPIO_AF7_USART2; //USART2_TX

	HAL_GPIO_Init(GPIOA, &gpio_uart); //Initialize GPIOA2 with gpio_uart configuration

	gpio_uart.Pin = GPIO_PIN_3;	//USART2_RX
	HAL_GPIO_Init(GPIOA, &gpio_uart); //Initialize GPIOA3 with gpio_uart configuration

	//3. Enable the IRQ in the NVIC and set up priority
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);

}
