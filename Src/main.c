/**
 ******************************************************************************
 * @file           : main.c
 * @author         : TODO: Add credits
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include "leds/leds.h"
#include "pwm/pwm.h"

// static UART_HandleTypeDef huart3;
void SysTick_Handler(void)
{
	HAL_IncTick();
}

int main(void)
{
	HAL_Init();
	PWM_Init();

    /* Loop forever */
	while(1)
	{
		PWM_SetDutyCycle(CHANNEL1,100);
		HAL_Delay(5000);
		PWM_SetDutyCycle(CHANNEL1,800);
		HAL_Delay(5000);
	}
}

