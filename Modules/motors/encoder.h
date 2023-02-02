/*
 ******************************************************************************
 * @file           : encoder.h
 * @author         : K. Czechowicz, A. Rybojad
 * @brief          : Encoders configuration and reading data
 ******************************************************************************
 */

#ifndef MOTORS_ENCODER_H_
#define MOTORS_ENCODER_H_

// @brief Readings encoder data
void TIM7_IRQHandler(void);

int16_t get_motor_velocity(uint16_t position, uint16_t PULSE_PER_ROTATION);

#endif //MOTORS_ENCODER_H_
