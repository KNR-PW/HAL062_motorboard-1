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

uint16_t duty=100;

// static UART_HandleTypeDef huart3;
void SysTick_Handler(void)
{
	HAL_IncTick();
}

void motor_calibration()
{
	PWM_SetDutyCycle(CHANNEL2,100);
	HAL_Delay(5000);
	PWM_SetDutyCycle(CHANNEL2,50);
	HAL_Delay(5000);
	PWM_SetDutyCycle(CHANNEL2,75);
	HAL_Delay(5000);

}

int main(void)
{
	HAL_Init();
	PWM_Init();
	Leds_init();
	motor_calibration();
	PWM_SetDutyCycle(CHANNEL2,80);


    /* Loop forever */
	while(1)
	{
//		PWM_SetDutyCycle(CHANNEL2,duty);
//		HAL_Delay(200);

		//PWM_SetDutyCycle(CHANNEL2,85); //bo jest kuleczka cyny
	}
}

