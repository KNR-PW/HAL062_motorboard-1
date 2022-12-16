/**
 ******************************************************************************
 * @file           : leds.c
 * @author         : J. Prokopczuk
 * @brief          : Leds driver
 ******************************************************************************
 */

#include <stm32h4xx_hal_rcc.h>
#include <stm32h4xx_hal_gpio.h>
#include <stm32h4xx_hal.h> // Simple HAL delay

#include "leds.h"

void Leds_init(void)
{
	GPIO_InitTypeDef gpio;
	__HAL_RCC_GPIOG_CLK_ENABLE();
	gpio.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_PULLDOWN;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &gpio);
}

void Leds_turnOnLed(Leds_ID ledId){
	switch(ledId){
	case LED1:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2, GPIO_PIN_SET);
		break;
	case LED2:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_3, GPIO_PIN_SET);
		break;
	case LED3:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_4, GPIO_PIN_SET);
		break;
	case LED4:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_SET);
		break;
	}
}

void Leds_turnOffLed(Leds_ID ledId){
	switch(ledId){
	case LED1:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_2, GPIO_PIN_RESET);
		break;
	case LED2:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_3, GPIO_PIN_RESET);
		break;
	case LED3:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_4, GPIO_PIN_RESET);
		break;
	case LED4:
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_5, GPIO_PIN_RESET);
		break;
	}
}

void Leds_toggleLed(Leds_ID ledId){
	switch(ledId){
	case LED1:
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_2);
		break;
	case LED2:
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_3);
		break;
	case LED3:
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_4);
		break;
	case LED4:
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_5);
		break;
	}
}

void Leds_welcomeFLash(void){
	Leds_turnOnLed(LED1);
	Leds_turnOnLed(LED2);
	Leds_turnOnLed(LED3);
	Leds_turnOnLed(LED4);
	HAL_Delay(1000);
	Leds_turnOffLed(LED1);
	Leds_turnOffLed(LED2);
	Leds_turnOffLed(LED3);
	Leds_turnOffLed(LED4);
	HAL_Delay(1000);
}
