/*
 ******************************************************************************
 * @file           : pwm.c
 * @author         : K. Czechowicz, A. Rybojad
 * @brief          : Functions to manual set PWM
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include "pwm.h"
#include "timers.h"

HAL_StatusTypeDef PWM_SetDutyCycle(ChannelType channel, uint16_t duty) {
	__HAL_TIM_SET_COMPARE(&htim5, channel, duty);
	return HAL_OK;
}

void motor_calibration(ChannelType channel) {
	PWM_SetDutyCycle(channel, 1000);
	HAL_Delay(5000);
	PWM_SetDutyCycle(channel, 500);
	HAL_Delay(5000);
	PWM_SetDutyCycle(channel, 750);
	HAL_Delay(5000);
}
