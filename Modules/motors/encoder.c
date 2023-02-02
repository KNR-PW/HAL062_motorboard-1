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


void TIM7_IRQHandler(void) {
	HAL_TIM_IRQHandler(&htim7);
}

// @brief interrupt for angular speed calculation
// @param htim handler for TIM7 interrupt clock
int16_t get_motor_velocity(uint16_t position, uint16_t PULSE_PER_ROTATION){ {

		int16_t pulsePerSec;
		int16_t motorVelocity;

		// checking if direction is negative
		// if position decreases from high value then direction is negative
		// uint16_t converted to int16_t and set as negative value
		if (position > ENC_MAX_PULSE_VALUE / 2) {
			position = ENC_MAX_PULSE_VALUE - position;
			position = (int16_t) position;
			position = -1 * position;
		} else
			(int16_t) position;

		// evaluating number of pulses occurred in one second
		pulsePerSec = position * 1000 / VELOCITY_CLOCK_TIME;

		// evaluating angular speed basing on encoder resolution
		motorVelocity = pulsePerSec / PULSE_PER_ROTATION;

		return motorVelocity;
	}
}
