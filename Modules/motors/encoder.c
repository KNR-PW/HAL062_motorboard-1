/*
 ******************************************************************************
 * @file           : encoder.c
 * @author         : K. Czechowicz, A. Rybojad
 * @brief          : Encoders configuration and reading data
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include "encoder.h"
#include "encoder_consts.h"
#include "timers.h"


/* angular value of motors */
volatile int16_t motor1Velocity;
volatile int16_t motor2Velocity;
volatile int16_t motor3Velocity;

void TIM7_IRQHandler(void) {
	HAL_TIM_IRQHandler(&htim7);
}

// @brief interrupt for angular speed calculation
// @param htim handler for TIM7 interrupt clock
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM7) {

		// getting actual position of encoder
		enc1PulseNumber = __HAL_TIM_GET_COUNTER(&htim1);
		enc2PulseNumber = __HAL_TIM_GET_COUNTER(&htim2);
		enc3PulseNumber = __HAL_TIM_GET_COUNTER(&htim3);

		// checking if direction is negative
		// if position decreases from high value then direction is negative
		// uint16_t converted to int16_t and set as negative value
		if (enc1PulseNumber > ENC1_MAX_PULSE_VALUE / 2) {
			enc1PulseNumber = ENC1_MAX_PULSE_VALUE - enc1PulseNumber;
			enc1PulseNumber = (int16_t) enc1PulseNumber;
			enc1PulseNumber = -1 * enc1PulseNumber;
		} else
			(int16_t) enc1PulseNumber;

		if (enc2PulseNumber > ENC2_MAX_PULSE_VALUE / 2) {
			enc2PulseNumber = ENC2_MAX_PULSE_VALUE - enc2PulseNumber;
			enc2PulseNumber = (int16_t) enc2PulseNumber;
			enc2PulseNumber = -1 * enc2PulseNumber;
		} else
			(int16_t) enc2PulseNumber;

		if (enc3PulseNumber > ENC3_MAX_PULSE_VALUE / 2) {
			enc3PulseNumber = ENC3_MAX_PULSE_VALUE - enc3PulseNumber;
			enc3PulseNumber = (int16_t) enc3PulseNumber;
			enc3PulseNumber = -1 * enc3PulseNumber;
		} else
			(int16_t) enc3PulseNumber;

		// evaluating number of pulses occurred in one second
		enc1PulsePerSec = enc1PulseNumber * 1000 / VELOCITY_CLOCK_TIME;
		enc2PulsePerSec = enc2PulseNumber * 1000 / VELOCITY_CLOCK_TIME;
		enc3PulsePerSec = enc3PulseNumber * 1000 / VELOCITY_CLOCK_TIME;

		// evaluating angular speed basing on encoder resolution
		motor1Velocity = enc1PulsePerSec / ENC1_PULSE_PER_ROTATION;
		motor2Velocity = enc2PulsePerSec / ENC2_PULSE_PER_ROTATION;
		motor3Velocity = enc3PulsePerSec / ENC3_PULSE_PER_ROTATION;

		// resetting counter for next interrupt
		__HAL_TIM_SET_COUNTER(&htim1, 0);
		__HAL_TIM_SET_COUNTER(&htim2, 0);
		__HAL_TIM_SET_COUNTER(&htim3, 0);
	}
}
