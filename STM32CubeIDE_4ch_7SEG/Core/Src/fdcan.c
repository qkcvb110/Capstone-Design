/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.c
  * @brief   This file provides code for the configuration
  *          of the FDCAN instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "fdcan.h"

/* USER CODE BEGIN 0 */
FDCAN_FilterTypeDef sFilterConfig;
/* USER CODE END 0 */

FDCAN_HandleTypeDef hfdcan1;

/* FDCAN1 init function */
void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_FD_NO_BRS;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 1;
  hfdcan1.Init.NominalSyncJumpWidth = 13;
  hfdcan1.Init.NominalTimeSeg1 = 86;
  hfdcan1.Init.NominalTimeSeg2 = 13;
  hfdcan1.Init.DataPrescaler = 25;
  hfdcan1.Init.DataSyncJumpWidth = 1;
  hfdcan1.Init.DataTimeSeg1 = 2;
  hfdcan1.Init.DataTimeSeg2 = 1;
  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 1;
  hfdcan1.Init.ExtFiltersNbr = 0;
  hfdcan1.Init.RxFifo0ElmtsNbr = 2;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_12;
  hfdcan1.Init.RxFifo1ElmtsNbr = 0;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 0;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 2;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_12;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */
  sFilterConfig.IdType = FDCAN_STANDARD_ID; //IdType ?? ?ï¿½ï¿½ï¿?? ID ?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ IDï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½ï¿??ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ .
  sFilterConfig.FilterIndex = 0; //Filterindex ?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ ê°œì˜ ?ï¿½ï¿½?ï¿½ï¿½ï¿?? êµ¬ì„±?ï¿½ï¿½?ï¿½ï¿½ ê²½ìš°?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½. 1ê°œì˜ ?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½ï¿?? ?ï¿½ï¿½ë¬¸ì— 0?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.
  sFilterConfig.FilterType = FDCAN_FILTER_MASK; //FilterType ?? ?ï¿½ï¿½ë¦¬ï¿½? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½. ?ï¿½ï¿½ê¸°ì„œ?ï¿½ï¿½ MASK ?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½
  sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0; //FilterConfig ?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ï¿?? ?ï¿½ï¿½ê³¼í•˜?ï¿½ï¿½ ë©”ì‹œï¿???ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ê²°ì •?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½. RX FIFO 0?ï¿½ï¿½ï¿?? ë³´ë‚´?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.

  sFilterConfig.FilterID1 = 0x11; // ID Node2  //?ï¿½ï¿½ MASK ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ê²½ìš° ID1( 0x22 )?ï¿½ï¿½ IDï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ï¿?? ID2( 0x22 )ï¿?? ë§ˆìŠ¤?ï¿½ï¿½ ë¹„íŠ¸ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.
  sFilterConfig.FilterID2 = 0x7ff; // Ignore because FDCAN_FILTER_TO_RXBUFFER
  sFilterConfig.RxBufferIndex = 0; //RxBufferIndex ?ï¿½ï¿½ FIFO ???ï¿½ï¿½ RX Bufferï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ê²½ìš° ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ï¿??ï¿?? 0?ï¿½ï¿½ï¿?? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½.
  if(HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE END FDCAN1_Init 2 */

}

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspInit 0 */

  /* USER CODE END FDCAN1_MspInit 0 */
  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
    PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* FDCAN1 clock enable */
    __HAL_RCC_FDCAN_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PD0     ------> FDCAN1_RX
    PD1     ------> FDCAN1_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* FDCAN1 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
  /* USER CODE BEGIN FDCAN1_MspInit 1 */

  /* USER CODE END FDCAN1_MspInit 1 */
  }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

  /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_FDCAN_CLK_DISABLE();

    /**FDCAN1 GPIO Configuration
    PD0     ------> FDCAN1_RX
    PD1     ------> FDCAN1_TX
    */
    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_0|GPIO_PIN_1);

    /* FDCAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
  /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

  /* USER CODE END FDCAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
