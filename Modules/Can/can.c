/* Includes ------------------------------------------------------------------*/
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_cortex.h>
#include <stm32f4xx_hal_rcc.h>
#include "can.h"
#include <leds/leds.h>

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
static uint32_t CAN_TxMailbox;
static uint32_t HAL_RCC_CAN1_CLK_ENABLED=0;

static CAN_RxHeaderTypeDef CAN_RxHeader;
static uint8_t CAN_RxMsg[8];

static CAN_TxHeaderTypeDef CAN_TxHeader;
static uint8_t CAN_TxData[8];

CAN_HandleTypeDef hcan1;
// CAN_HandleTypeDef hcan2;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {

	if (hcan->Instance == CAN1) {
		HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &CAN_RxHeader, CAN_RxMsg);
		//COM_RunCanAction();
	} else if (hcan->Instance == CAN2) {
		//HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &CAN_RxHeader, CAN_RxMsg);
		//COM_RunCanAction();
	}
	//Leds_toggleLed(LED1);
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan) {

	HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO1, &CAN_RxHeader, CAN_RxMsg);
	//Leds_toggleLed(LED2);
}

/* CAN1 init function */
void MX_CAN1_Init(void) {
	CAN_FilterTypeDef sFilterConfig;

	hcan1.Instance = CAN1;
	hcan1.Init.Prescaler = 40;
	hcan1.Init.Mode = CAN_MODE_NORMAL;
	hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan1.Init.TimeSeg1 = CAN_BS1_9TQ;
	hcan1.Init.TimeSeg2 = CAN_BS2_8TQ;
	hcan1.Init.TimeTriggeredMode = DISABLE;
	hcan1.Init.AutoBusOff = DISABLE;
	hcan1.Init.AutoWakeUp = DISABLE;
	hcan1.Init.AutoRetransmission = DISABLE;
	hcan1.Init.ReceiveFifoLocked = DISABLE;
	hcan1.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan1) != HAL_OK) {
		//_Error_Handler(__FILE__, __LINE__);
	}
	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 0;
	if (HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig) != HAL_OK) {
		volatile uint32_t b = 0;
		b++;
	}

	HAL_CAN_Start(&hcan1);

	if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING)
			!= HAL_OK) {
		volatile uint32_t b = 0;
		b++;
		//Error_Handler(); // MOJE
	}
	/*	  if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO1_MSG_PENDING)!=HAL_OK)
	 {
	 Error_Handler();
	 }*/

}

void Can_testMessage(void){
	CAN_TxHeader.StdId=20;
	CAN_TxHeader.ExtId=20;
	CAN_TxHeader.IDE=CAN_ID_STD;
	CAN_TxHeader.RTR=CAN_RTR_DATA;
	CAN_TxHeader.DLC=8;
	uint8_t dane[8];
	dane[0]=0xAA;
	dane[1]=0xAA;
	for(int i=2;i<8;i++)
	{
		dane[i]=0;
	}
	HAL_CAN_AddTxMessage(&hcan1,&CAN_TxHeader, dane, &CAN_TxMailbox);
	Leds_toggleLed(LED4);
}
/* CAN2 init function */
//void MX_CAN2_Init(void) {
//
//	CAN_FilterTypeDef sFilterConfig;
//	hcan2.Instance = CAN2;
//	hcan2.Init.Prescaler = 5;
//	hcan2.Init.Mode = CAN_MODE_NORMAL;
//	hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
//	hcan2.Init.TimeSeg1 = CAN_BS1_9TQ;
//	hcan2.Init.TimeSeg2 = CAN_BS2_8TQ;
//	hcan2.Init.TimeTriggeredMode = DISABLE;
//	hcan2.Init.AutoBusOff = DISABLE;
//	hcan2.Init.AutoWakeUp = DISABLE;
//	hcan2.Init.AutoRetransmission = DISABLE;
//	hcan2.Init.ReceiveFifoLocked = DISABLE;
//	hcan2.Init.TransmitFifoPriority = DISABLE;
//	if (HAL_CAN_Init(&hcan2) != HAL_OK) {
//		//_Error_Handler(__FILE__, __LINE__);
//	}
//	sFilterConfig.FilterBank = 14;
//	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
//	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
//	sFilterConfig.FilterIdHigh = 0x0000;
//	sFilterConfig.FilterIdLow = 0x0000;
//	sFilterConfig.FilterMaskIdHigh = 0x0000;
//	sFilterConfig.FilterMaskIdLow = 0x0000;
//	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
//	sFilterConfig.FilterActivation = ENABLE;
//	sFilterConfig.SlaveStartFilterBank = 0;
//	if (HAL_CAN_ConfigFilter(&hcan2, &sFilterConfig) != HAL_OK) {
//		/* Filter configuration Error */
//		Error_Handler();
//	}
//	if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING)
//			!= HAL_OK) {
//		Error_Handler();
//	}
//	/* 	  if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING)!=HAL_OK)
//	 {
//	 Error_Handler();
//	 }*/
//
//	HAL_CAN_Start(&hcan2);
//
//}
//
//static uint32_t HAL_RCC_CAN1_CLK_ENABLED = 0;
//
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* System interrupt init*/
  /* MemoryManagement_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
  /* BusFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
  /* UsageFault_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
  /* SVCall_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SVCall_IRQn, 0, 0);
  /* DebugMonitor_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 0, 0);
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

void HAL_CAN_MspInit(CAN_HandleTypeDef *canHandle) {

	GPIO_InitTypeDef GPIO_InitStruct;
	if (canHandle->Instance == CAN1) {
		/* USER CODE BEGIN CAN1_MspInit 0 */

		/* USER CODE END CAN1_MspInit 0 */
		/* CAN1 clock enable */
		HAL_RCC_CAN1_CLK_ENABLED++;
		if (HAL_RCC_CAN1_CLK_ENABLED == 1) {
			__HAL_RCC_CAN1_CLK_ENABLE();
		}


		/**CAN1 GPIO Configuration
		 * Whaaaat?
		 PB8     ------> CAN1_RX
		 PB9     ------> CAN1_TX
		 */
		__HAL_RCC_GPIOA_CLK_ENABLE();
		GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/* CAN1 interrupt Init */
		HAL_NVIC_SetPriority(CAN1_TX_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(CAN1_TX_IRQn);
		HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
		//HAL_NVIC_SetPriority(CAN1_RX1_IRQn, 0, 0);
		//HAL_NVIC_EnableIRQ(CAN1_RX1_IRQn);
		/* USER CODE BEGIN CAN1_MspInit 1 */

		/* USER CODE END CAN1_MspInit 1 */
	}
//	else if (canHandle->Instance == CAN2) {
//		/* USER CODE BEGIN CAN2_MspInit 0 */
//
//		/* USER CODE END CAN2_MspInit 0 */
//		/* CAN2 clock enable */
//		__HAL_RCC_CAN2_CLK_ENABLE();
//		HAL_RCC_CAN1_CLK_ENABLED++;
//		if (HAL_RCC_CAN1_CLK_ENABLED == 1) {
//			__HAL_RCC_CAN1_CLK_ENABLE();
//		}
//
//		/**CAN2 GPIO Configuration
//		 PB12     ------> CAN2_RX
//		 PB6     ------> CAN2_TX
//		 */
//		GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_6;
//		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//		GPIO_InitStruct.Pull = GPIO_NOPULL;
//		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//		GPIO_InitStruct.Alternate = GPIO_AF9_CAN2;
//		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//		/* CAN2 interrupt Init */
//		HAL_NVIC_SetPriority(CAN2_TX_IRQn, 0, 0);
//		HAL_NVIC_EnableIRQ(CAN2_TX_IRQn);
//		HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 0, 0);
//		HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
//		HAL_NVIC_SetPriority(CAN2_RX1_IRQn, 0, 0);
//		HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);
//		/* USER CODE BEGIN CAN2_MspInit 1 */
//
//		/* USER CODE END CAN2_MspInit 1 */
//	}
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef *canHandle) {

	if (canHandle->Instance == CAN1) {
		/* USER CODE BEGIN CAN1_MspDeInit 0 */

		/* USER CODE END CAN1_MspDeInit 0 */
		/* Peripheral clock disable */
		HAL_RCC_CAN1_CLK_ENABLED--;
		if (HAL_RCC_CAN1_CLK_ENABLED == 0) {
			__HAL_RCC_CAN1_CLK_DISABLE();
		}

		/**CAN1 GPIO Configuration
		 PB8     ------> CAN1_RX
		 PB9     ------> CAN1_TX
		 */
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8 | GPIO_PIN_9);

		/* CAN1 interrupt Deinit */
		HAL_NVIC_DisableIRQ(CAN1_TX_IRQn);
		HAL_NVIC_DisableIRQ(CAN1_RX0_IRQn);
		HAL_NVIC_DisableIRQ(CAN1_RX1_IRQn);
		/* USER CODE BEGIN CAN1_MspDeInit 1 */

		/* USER CODE END CAN1_MspDeInit 1 */
	} else if (canHandle->Instance == CAN2) {
		/* USER CODE BEGIN CAN2_MspDeInit 0 */

		/* USER CODE END CAN2_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_CAN2_CLK_DISABLE();
		HAL_RCC_CAN1_CLK_ENABLED--;
		if (HAL_RCC_CAN1_CLK_ENABLED == 0) {
			__HAL_RCC_CAN1_CLK_DISABLE();
		}

		/**CAN2 GPIO Configuration
		 PB12     ------> CAN2_RX
		 PB6     ------> CAN2_TX
		 */
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12 | GPIO_PIN_6);

		/* CAN2 interrupt Deinit */
		HAL_NVIC_DisableIRQ(CAN2_TX_IRQn);
		HAL_NVIC_DisableIRQ(CAN2_RX0_IRQn);
		HAL_NVIC_DisableIRQ(CAN2_RX1_IRQn);
		/* USER CODE BEGIN CAN2_MspDeInit 1 */

		/* USER CODE END CAN2_MspDeInit 1 */
	}
}

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

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
