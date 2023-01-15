/*
 ******************************************************************************
 * @file           : timers.c
 * @author         : D. Mucha
 * @brief          : Timers configuration
 ******************************************************************************
 */

#include "timers.h"
#include "pwm_consts.h"
#include "stm32f4xx_hal_tim.h"

void InitTimers() {
	TIM1_Init();
	TIM2_Init();
	TIM3_Init();
	TIM5_Init();
}

void TIM1_Init() {
}

void TIM2_Init() {
}

void TIM3_Init() {
}

void TIM5_Init() {
	TIM_HandleTypeDef htim;
	htim.Instance = TIM5;
	htim.Init.Prescaler = PWM_PRESCALER;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim.Init.Period = PWM_MAX_DUTY;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim.Init.RepetitionCounter = PWM_REPETITION_COUNTER;
	htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
	if (HAL_TIM_PWM_Init(&htim) != HAL_OK) {
		// TODO: error handling needed
	}
	if (HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1 | TIM_CHANNEL_2 | TIM_CHANNEL_3)
			!= HAL_OK) {
		// TODO: error handling needed
	}
}

void TIM1_IRQHandler(void) {
	// g_encoder1Tick = read_encoder_data JACEK HELP!!!
}

void TIM2_IRQHandler(void) {
	// g_encoder2Tick=
}

void TIM3_IRQHandler(void) {
	// g_encoder3Tick=
}
