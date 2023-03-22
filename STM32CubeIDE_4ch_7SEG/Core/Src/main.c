/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "cmsis_os.h"
#include "fdcan.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "_7_seg.h"
#include <stdio.h>
#include "i2c_lcd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

/**
 * @brief Retargets the C library printf function to the USART
 * @param None
 * @retval None
 */
PUTCHAR_PROTOTYPE{
   HAL_UART_Transmit(&huart3, (uint8_t*)&ch, 1, 0xFFFF);
   return ch;
}

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
FDCAN_FilterTypeDef sFilterConfig;
FDCAN_TxHeaderTypeDef TxHeader;
FDCAN_RxHeaderTypeDef RxHeader;
uint8_t TxData_Node1_To_Node2[8];
uint8_t TxData_Node1_To_Node3[8];
uint8_t RxData_From_Node3[8];
uint8_t RxData_From_Node2[8];
uint8_t RxData_From_Node1[8];
I2C_HandleTypeDef hi2c1;
i2cLcd_HandleTypeDef h_lcd;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int indx = 1;

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
  {
    /* Retreive Rx messages from RX FIFO0 */
	  //?��기서?�� 먼�? RX FIFO0?�� ?��?�� ?��보�?? RxHeader�?? 복사?���?? ?��?��?���?? RxData 배열�?? 복사?��?��?��.
	if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData_From_Node1) != HAL_OK)
    {
    /* Reception Error */
    Error_Handler();
    }
	if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData_From_Node3) != HAL_OK)
	    {
	    /* Reception Error */
	    Error_Handler();
	    }
    //그런 ?��?�� ?�� 메시�???�� ???�� ?��림을 ?��?�� ?��?��?��?��?��?��.
    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
    {
      /* Notification Error */
      Error_Handler();
    }
    //FDCAN2 콜백�?? ?���?? ?��기서?�� ?��?��?���?? ?��?��?���?? ?��?��?��?��. while 루프?��?�� FDCAN1?�� ?��?�� 매초 ?��?��?���?? ?��?��?���?? ?��문입?��?��.

  }
}




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t i2c_lcd_addr = (I2C_LCD_ADDRESS<<1);
//		char strData[32];
//		uint8_t i;
		//clcd 코딩
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_USART3_UART_Init();
  MX_FDCAN1_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  i2cLcd_CreateHandle(&h_lcd, &hi2c1, i2c_lcd_addr);
  i2cLcd_Init(&h_lcd);
  /////clcd 코딩
  HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, 3,3,0,1);

       if(HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
         {
           Error_Handler();
         }

       if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
         {
           /* Notification Error */
           Error_Handler();
         }
       TxHeader.Identifier = 0x22;
       TxHeader.IdType = FDCAN_STANDARD_ID;
       TxHeader.TxFrameType = FDCAN_DATA_FRAME;
       TxHeader.DataLength = FDCAN_DLC_BYTES_8;  //?��?��?�� 길이
       TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
       TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
       TxHeader.FDFormat = FDCAN_FD_CAN;
       TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
       TxHeader.MessageMarker = 0x0;

       /* Configure standard ID reception filter to Rx buffer 0 */


//	  c=RxData_From_Node2[2]-'0';
//	  d=RxData_From_Node2[3]-'0';
//	  e=RxData_From_Node2[4]-'0';
//	  f=RxData_From_Node2[5]-'0';
//	  g=RxData_From_Node2[6]-'0';
//	  h=RxData_From_Node2[7]-'0';

//	  int Distance1 = 0;
//	  int Distance10 = 0;
//	  int Distance100 = 0;
//	  int Distance=1000 = 0;
//	  Distance1=a;
//	  Distance10=a*10+b;
//	  Distance100=a*100+b*10+c;
//	  Distance100=a*1000+c*100+b*10+d;

         /* Start the FDCAN module */


         /* Send Tx buffer message */


         /* Polling for transmission complete on buffer index 0 */

         /* Polling for reception complete on buffer index 0 */
         /* Retrieve message from Rx buffer 0. Rec msg from Node 2 */


  HAL_TIM_Base_Start(&htim1);
  HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
  //uint8_t Distance  = 0;
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//  _7_SEG_EXTI();


  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();
  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//	  _Buzzer_setting();
//
//	      i=0;
//	 	  i2cLcd_ClearDisplay(&h_lcd);
//	 	  HAL_Delay(20);
//	 	 sprintf(strData,"%s",RxData_From_Node3);
//	 	  //sprintf(strData,"%c%c%c%c%c%c%c%c%c%c%c%c%c",RxData_From_Node2[0],RxData_From_Node2[1],RxData_From_Node2[2],RxData_From_Node2[3],RxData_From_Node2[4],RxData_From_Node2[5],RxData_From_Node2[6],RxData_From_Node2[7],RxData_From_Node2[8],RxData_From_Node2[9],RxData_From_Node2[10],RxData_From_Node2[11],RxData_From_Node2[12],RxData_From_Node2[13]);
//	 	  while(strData[i])
//	 	  {
//	 	  i2cLcd_SendChar(&h_lcd, strData[i]);
//	 	  HAL_Delay(100);
//	 	  i++;
//	 	  }
//	 	  i2cLcd_SetCursorPosition(&h_lcd, 0x40);
//	 	  i=0;
//	 	  sprintf(strData,"I2C LCD Test. ");
//	 	  while(strData[i])
//	 	  {
//	 	  i2cLcd_SendChar(&h_lcd, strData[i]);
//	 	  HAL_Delay(100);
//	 	  i++;
//	 	  }
//	 	 sprintf ((char *)TxData_Node1_To_Node3, "hellohellohellohellohellohellohellohellohellohellohellohello%d",indx);
//	 	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData_Node1_To_Node3)!= HAL_OK)
//	 		 	             {
//	 		 	                Error_Handler();
//	 		 	             }
//	 	printf("%s\r\n",TxData_Node1_To_Node3);
//	 	printf("%s\r\n",RxData_From_Node1);
//	 	HAL_Delay(500);
//	 	if(RxData_From_Node1[0] == '1')
//	 	{
	 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, SET);
	 		HAL_Delay(500);
	 		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
	 		HAL_Delay(500);

//	 	}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 32;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void _Buzzer_setting(void)
{
	int a,b;

			  a=RxData_From_Node3[0]-'0';
			  b=RxData_From_Node3[1]-'0';

		  printf("%d   %d \r\n",a,b);
		  HAL_Delay(500);
		  int Distance;

		  if(RxData_From_Node3[0])
		  {
			 Distance = a;
			 if(Distance < 9)
			  {
				  htim1.Instance->CCR1 = 0;
				  HAL_Delay(100);
				  htim1.Instance->CCR1 = 50;
				  HAL_Delay(100);
			  }

		  }
		  if(RxData_From_Node3[0]&&RxData_From_Node3[1])
		  {
			  Distance = a*10+b;
			  if(Distance > 9 && Distance <20)
			  	  	  {
			  	  		  htim1.Instance->CCR1 = 0;
			  	  		  HAL_Delay(1000);
			  	  		  htim1.Instance->CCR1 = 50;
			  	  		  HAL_Delay(1000);
			  	  	  }
		  }
		  printf("%d cm\r\n",Distance);
		  	  HAL_Delay(1000);
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

