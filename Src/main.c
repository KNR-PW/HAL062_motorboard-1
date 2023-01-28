/**
 ******************************************************************************
 * @file           : main.c
 * @author         : TODO: Add credits
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include "motors/timers.h"

// static UART_HandleTypeDef huart3;
void SysTick_Handler(void) {
	HAL_IncTick();
}

int main(void) {
	InitTimers();

	/* Loop forever */
	while (1) {

	}
}
