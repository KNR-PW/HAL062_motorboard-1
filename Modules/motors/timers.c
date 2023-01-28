/*
 ******************************************************************************
 * @file           : timers.c
 * @author         : D. Mucha
 * @brief          : Timers configuration
 ******************************************************************************
 */

#include <stm32f4xx_hal.h> // this include replaces including <stm32f4xx_hal_tim.h>,
// including only <stm32f4xx_hal_tim.h> causes compilation errors
#include "timers.h"
#include "pwm_consts.h"

void InitTimers() {
	TIM1_Init();
	TIM2_Init();
	TIM3_Init();
	TIM5_Init();
}

void TIM1_Init() {
//	TIM_HandleTypeDef htim;
//	TIM_Encoder_InitTypeDef sConfig;
//
//	htim1.Instance = TIM1;
//	htim1.Init.Prescaler = 0;
//	htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
//	htim1.Init.Period = 65535;
//	htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
//	htim1.Init.RepetitionCounter = 0;
//	htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
//	sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
//	sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
//	sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
//	sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
//	sConfig.IC1Filter = 0;
//	sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
//	sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
//	sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
//	sConfig.IC2Filter = 0;
//
//	HAL_TIM_Encoder_Init(&htim, &sConfig);
//	// both TIM_CHANNEL_1 and TIM_CHANNEL_2 used
//	HAL_TIM_Encoder_Start(&htim, TIM_CHANNEL_ALL);

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
