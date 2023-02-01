/**
 ******************************************************************************
 * @file           : main.c
 * @author         : TODO: Add credits
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include "motors/timers.h"
#include "motors/pwm.h"

// static UART_HandleTypeDef huart3;
void SysTick_Handler(void){
	HAL_IncTick();
}

int main(void) {
	HAL_Init();
	InitTimers();

//	motor_calibration(CHANNEL2);

	/* Loop forever */
	while (1) {
//	PWM_SetDutyCycle(CHANNEL2, 850);

	}
}
