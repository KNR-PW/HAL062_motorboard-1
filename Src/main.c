/**
 ******************************************************************************
 * @file           : main.c
 * @author         : TODO: Add credits
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_conf.h>
#include "leds/leds.h"
#include "Can/can.h"

// static UART_HandleTypeDef huart3;
void SysTick_Handler(void)
{
	HAL_IncTick();
}

int main(void)
{
	HAL_Init();
	MX_CAN1_Init();
	Leds_init();

	Leds_welcomeFLash();

    /* Loop forever */
	while(1)
	{
		Leds_toggleLed(LED4);
		HAL_Delay(1000);
		Leds_toggleLed(LED4);
		HAL_Delay(1000);

		Can_testMessage();
	}
}

#include <stm32f4xx.h>

// CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;
TIM_HandleTypeDef htim4;
DMA_HandleTypeDef hdma_uart5_rx;
DMA_HandleTypeDef hdma_uart5_tx;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart3_tx;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles Memory management fault.
*/
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

/**
* @brief This function handles Pre-fetch fault, memory access fault.
*/
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

/**
* @brief This function handles Undefined instruction or illegal state.
*/
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
* @brief This function handles Debug monitor.
*/
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
//void SysTick_Handler(void)
//{
//  /* USER CODE BEGIN SysTick_IRQn 0 */
//
//  /* USER CODE END SysTick_IRQn 0 */
//  HAL_IncTick();
//  HAL_SYSTICK_IRQHandler();
//  /* USER CODE BEGIN SysTick_IRQn 1 */
//
//  /* USER CODE END SysTick_IRQn 1 */
//}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles DMA1 stream0 global interrupt.
*/
//void DMA1_Stream0_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA1_Stream0_IRQn 0 */
//
//  /* USER CODE END DMA1_Stream0_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_uart5_rx);
//  /* USER CODE BEGIN DMA1_Stream0_IRQn 1 */
//
//  /* USER CODE END DMA1_Stream0_IRQn 1 */
//}
//
///**
//* @brief This function handles DMA1 stream1 global interrupt.
//*/
//void DMA1_Stream1_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA1_Stream1_IRQn 0 */
//
//  /* USER CODE END DMA1_Stream1_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_usart3_rx);
//  /* USER CODE BEGIN DMA1_Stream1_IRQn 1 */
//
//  /* USER CODE END DMA1_Stream1_IRQn 1 */
//}
//
///**
//* @brief This function handles DMA1 stream3 global interrupt.
//*/
//void DMA1_Stream3_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA1_Stream3_IRQn 0 */
//
//  /* USER CODE END DMA1_Stream3_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_usart3_tx);
//  /* USER CODE BEGIN DMA1_Stream3_IRQn 1 */
//
//  /* USER CODE END DMA1_Stream3_IRQn 1 */
//}

/**
* @brief This function handles CAN1 TX interrupt.
*/
void CAN1_TX_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_TX_IRQn 0 */

  /* USER CODE END CAN1_TX_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_TX_IRQn 1 */

  /* USER CODE END CAN1_TX_IRQn 1 */
}

/**
* @brief This function handles CAN1 RX0 interrupt.
*/
void CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX0_IRQn 0 */

  /* USER CODE END CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX0_IRQn 1 */

  /* USER CODE END CAN1_RX0_IRQn 1 */
}

/**
* @brief This function handles CAN1 RX1 interrupt.
*/
void CAN1_RX1_IRQHandler(void)
{
  /* USER CODE BEGIN CAN1_RX1_IRQn 0 */

  /* USER CODE END CAN1_RX1_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan1);
  /* USER CODE BEGIN CAN1_RX1_IRQn 1 */

  /* USER CODE END CAN1_RX1_IRQn 1 */
}

/**
* @brief This function handles TIM4 global interrupt.
*/
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/**
* @brief This function handles USART1 global interrupt.
*/
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
* @brief This function handles USART3 global interrupt.
*/
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */

  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

  /* USER CODE END USART3_IRQn 1 */
}

/**
* @brief This function handles DMA1 stream7 global interrupt.
*/
//void DMA1_Stream7_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA1_Stream7_IRQn 0 */
//
//  /* USER CODE END DMA1_Stream7_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_uart5_tx);
//  /* USER CODE BEGIN DMA1_Stream7_IRQn 1 */
//
//  /* USER CODE END DMA1_Stream7_IRQn 1 */
//}

/**
* @brief This function handles UART5 global interrupt.
*/
//void UART5_IRQHandler(void)
//{
//  /* USER CODE BEGIN UART5_IRQn 0 */
//
//  /* USER CODE END UART5_IRQn 0 */
//  HAL_UART_IRQHandler(&huart5);
//  /* USER CODE BEGIN UART5_IRQn 1 */
//
//  /* USER CODE END UART5_IRQn 1 */
//}
//
///**
//* @brief This function handles DMA2 stream2 global interrupt.
//*/
//void DMA2_Stream2_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */
//
//  /* USER CODE END DMA2_Stream2_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_usart1_rx);
//  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */
//
//  /* USER CODE END DMA2_Stream2_IRQn 1 */
//}
//
///**
//* @brief This function handles CAN2 TX interrupt.
//*/
//void CAN2_TX_IRQHandler(void)
//{
//  /* USER CODE BEGIN CAN2_TX_IRQn 0 */
//
//  /* USER CODE END CAN2_TX_IRQn 0 */
//  HAL_CAN_IRQHandler(&hcan2);
//  /* USER CODE BEGIN CAN2_TX_IRQn 1 */
//
//  /* USER CODE END CAN2_TX_IRQn 1 */
//}
//
///**
//* @brief This function handles CAN2 RX0 interrupt.
//*/
//void CAN2_RX0_IRQHandler(void)
//{
//  /* USER CODE BEGIN CAN2_RX0_IRQn 0 */
//
//  /* USER CODE END CAN2_RX0_IRQn 0 */
//  HAL_CAN_IRQHandler(&hcan2);
//  /* USER CODE BEGIN CAN2_RX0_IRQn 1 */
//
//  /* USER CODE END CAN2_RX0_IRQn 1 */
//}
//
///**
//* @brief This function handles CAN2 RX1 interrupt.
//*/
//void CAN2_RX1_IRQHandler(void)
//{
//  /* USER CODE BEGIN CAN2_RX1_IRQn 0 */
//
//  /* USER CODE END CAN2_RX1_IRQn 0 */
//  HAL_CAN_IRQHandler(&hcan2);
//  /* USER CODE BEGIN CAN2_RX1_IRQn 1 */
//
//  /* USER CODE END CAN2_RX1_IRQn 1 */
//}
//
///**
//* @brief This function handles DMA2 stream7 global interrupt.
//*/
//void DMA2_Stream7_IRQHandler(void)
//{
//  /* USER CODE BEGIN DMA2_Stream7_IRQn 0 */
//
//  /* USER CODE END DMA2_Stream7_IRQn 0 */
//  HAL_DMA_IRQHandler(&hdma_usart1_tx);
//  /* USER CODE BEGIN DMA2_Stream7_IRQn 1 */
//
//  /* USER CODE END DMA2_Stream7_IRQn 1 */
//}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

