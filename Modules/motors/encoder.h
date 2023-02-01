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

/* number of pulse that encoder count */
volatile uint16_t enc1PulseNumber;
volatile uint16_t enc2PulseNumber;
volatile uint16_t enc3PulseNumber;

/* number of pulse that encoder generates per second */
volatile int16_t enc1PulsePerSec;
volatile int16_t enc2PulsePerSec;
volatile int16_t enc3PulsePerSec;

/* angular value of motors */
extern volatile int16_t motor1Velocity;
extern volatile int16_t motor2Velocity;
extern volatile int16_t motor3Velocity;

#endif //MOTORS_ENCODER_H_
