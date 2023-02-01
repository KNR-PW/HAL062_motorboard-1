/*
 ******************************************************************************
 * @file           : timers.h
 * @author         : D. Mucha
 * @brief          : Timers configuration
 ******************************************************************************
 */

#ifndef MOTORS_TIMERS_H_
#define MOTORS_TIMERS_H_

// [Timer - Encoder - Pin] mapping for our custom motor board
// TIM1_CH1 - ENK1_A - PA8
// TIM1_CH2 - ENK1_B - PA9
// TIM2_CH1 - ENK2_A - PA5
// TIM2_CH2 - ENK2_B - PB3
// TIM3_CH1 - ENK3_A - PA6
// TIM3_CH2 - ENK3_B - PA7

// [Timer - PWM - Pin] PWM generation for our custom motor board
// TIM5_CH1 - PWM1 - PA0
// TIM5_CH2 - PWM2 - PA1
// TIM5_CH3 - PWM3 - PA2

// @brief Initialize all timers
void InitTimers();

// @brief Initialize encoder1 timer
void TIM1_Init();

// @brief Initialize encoder2 timer
void TIM2_Init();

// @brief Initialize encoder3 timer
void TIM3_Init();

// @brief Initialize PWM timer
void TIM5_Init();

// @brief Initialize timer for measuring speed
void TIM7_Init(void);

// @brief Readings encoder data
void TIM7_IRQHandler(void);

typedef enum {
	CHANNEL1 = TIM_CHANNEL_1, // PWM1
	CHANNEL2 = TIM_CHANNEL_2, // PWM2
	CHANNEL3 = TIM_CHANNEL_3, // PWM3
} ChannelType;

// @brief required motor calibration before first usage
// @param channel enum type number of channel to precise motor
void motor_calibration(ChannelType channel);

// @brief Setting duty of motors PWM
// @param channel enum type number of channel to precise motor
// @param duty duty chosen from 500 to 1000
// @returns predefined enum status type from HAL library
HAL_StatusTypeDef PWM_SetDutyCycle(ChannelType channel, uint16_t duty);

#endif /* MOTORS_TIMERS_H_ */
