#ifndef MODULE_PWM_PWM_H
#define MODULE_PWM_PWM_H

#include <stm32f4xx_hal.h>


typedef enum
{
	CHANNEL1 = TIM_CHANNEL_1,
	CHANNEL2 = TIM_CHANNEL_2,
	CHANNEL3 = TIM_CHANNEL_3,
} ChannelType;


HAL_StatusTypeDef PWM_Init();
HAL_StatusTypeDef PWM_SetDutyCycle(ChannelType channel, uint16_t duty);



#endif // MODULE_PWM_PWM_H
