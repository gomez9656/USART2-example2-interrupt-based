/*
 * main.c
 *
 *  Created on: 23/01/2021
 *      Author: PC
 */

#include "stm32f4xx_hal.h"
#include "main.h"

void SystemCoreClockConfig();

int main(){

	/* Basic initialization */
	HAL_Init();
	SystemCoreClockConfig();

	return 0;
}

/*
 * You can use it when you need an specific clock
 * By default will be internal clock
 */
void SystemCoreClockConfig(){

}
