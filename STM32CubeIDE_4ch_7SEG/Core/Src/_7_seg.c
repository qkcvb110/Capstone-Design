#include "gpio.h"
#include "_7_seg.h"
#include "tim.h"
#include "stdint.h"

#include <stdio.h>
#include <math.h>
#include "usart.h"
void PowerOn_7_SEG_D1(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, SET);
}
void PowerOff_7_SEG_D1(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, RESET);
}
void PowerOn_7_SEG_D2(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, SET);
}
void PowerOff_7_SEG_D2(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, RESET);
}
void PowerOn_7_SEG_D3(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, SET);
}
void PowerOff_7_SEG_D3(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, RESET);
}
void PowerOn_7_SEG_D4(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, SET);
}
void PowerOff_7_SEG_D4(void)
{
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, RESET);
}

void On_7_SEG_AllPin(void)
{
On_7_SEG_OnePin (GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5
| GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9);
}
void Off_7_SEG_AllPin(void)
{
Off_7_SEG_OnePin (GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5
| GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9);
}


void On_7_SEG_OnePin(uint16_t pinNum)
{
   HAL_GPIO_WritePin(GPIOE,pinNum, RESET);
}
void Off_7_SEG_OnePin(uint16_t pinNum)
{
   HAL_GPIO_WritePin(GPIOE,pinNum, SET);
}
void _7_SEG_Pin_Test(void)
{

        Off_7_SEG_AllPin();HAL_Delay(500);


        On_7_SEG_OnePin(GPIO_PIN_2);HAL_Delay(500);
        On_7_SEG_OnePin(GPIO_PIN_3);HAL_Delay(500);
        On_7_SEG_OnePin(GPIO_PIN_4);HAL_Delay(500);
        On_7_SEG_OnePin(GPIO_PIN_5);HAL_Delay(500);
        On_7_SEG_OnePin(GPIO_PIN_6);HAL_Delay(500);
        On_7_SEG_OnePin(GPIO_PIN_7);HAL_Delay(500);
        On_7_SEG_OnePin(GPIO_PIN_8);HAL_Delay(500);

}
void _7_SEG_Num_Test(char num)
{
  Off_7_SEG_AllPin();
  switch(num){
        case 0x30:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
        break;
        case 0x31:
        On_7_SEG_OnePin(GPIO_PIN_3|GPIO_PIN_4);
        break;
        case 0x32:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_6|GPIO_PIN_5);
        break;
        case 0x33:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_4|GPIO_PIN_5);
        break;
        case 0x34:
        On_7_SEG_OnePin(GPIO_PIN_4|GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_7);
        break;
        case 0x35:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_4|GPIO_PIN_5);
        break;
        case 0x36:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8);
        break;
        case 0x37:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_7|GPIO_PIN_3|GPIO_PIN_4);
        break;
        case 0x38:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8);
        break;
        case 0x39:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_7);
        break;
}
}
void _7_SEG_Num_Test2(int num)
{
  Off_7_SEG_AllPin();
  switch(num){
        case 0:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
        break;
        case 1:
        On_7_SEG_OnePin(GPIO_PIN_3|GPIO_PIN_4);
        break;
        case 2:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_6|GPIO_PIN_5);
        break;
        case 3:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_4|GPIO_PIN_5);
        break;
        case 4:
        On_7_SEG_OnePin(GPIO_PIN_4|GPIO_PIN_3|GPIO_PIN_8|GPIO_PIN_7);
        break;
        case 5:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_4|GPIO_PIN_5);
        break;
        case 6:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8);
        break;
        case 7:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_7|GPIO_PIN_3|GPIO_PIN_4);
        break;
        case 8:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8);
        break;
        case 9:
        On_7_SEG_OnePin(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_7);
        break;
}
}
void _7_SEG_20181367_Test(void)
{

	On_7_SEG_OnePin(GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_6|GPIO_PIN_4|GPIO_PIN_3);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_1|GPIO_PIN_2);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_1|GPIO_PIN_2);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_6|GPIO_PIN_2|GPIO_PIN_3);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_0|GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6);HAL_Delay(500);Off_7_SEG_AllPin();
	On_7_SEG_OnePin(GPIO_PIN_0|GPIO_PIN_5|GPIO_PIN_1|GPIO_PIN_2);HAL_Delay(500);Off_7_SEG_AllPin();
}

void _7_SEG_1234_Test(void)
{
	PowerOn_7_SEG_D1();
	_7_SEG_Num_Test2(1);
	HAL_Delay(0);
	PowerOff_7_SEG_D1();
	PowerOn_7_SEG_D2();
	_7_SEG_Num_Test2(2);
	HAL_Delay(0);
	PowerOff_7_SEG_D2();
	PowerOn_7_SEG_D3();
	_7_SEG_Num_Test2(3);
	HAL_Delay(0);
	PowerOff_7_SEG_D3();
	PowerOn_7_SEG_D4();
	_7_SEG_Num_Test2(4);
	HAL_Delay(0);
	PowerOff_7_SEG_D4();
}

#define TRIG_PIN GPIO_PIN_5

#define TRIG_PORT GPIOA




uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
uint8_t Is_First_Captured = 0;  // is the first value captured ?
uint8_t Distance  = 0;
uint8_t TxData_Node1_To_Node2[12];
uint8_t RxData_From_Node2[12];
int a = 0;

void delay (uint16_t time)
{
	__HAL_TIM_SET_COUNTER(&htim3, 0);
	while (__HAL_TIM_GET_COUNTER (&htim3) < time);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
	{
		if (Is_First_Captured==0) // if the first value is not captured
		{
			IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured==1)   // if the first is already captured
		{
			IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (IC_Val2 > IC_Val1)
			{
				Difference = IC_Val2-IC_Val1;
			}

			else if (IC_Val1 > IC_Val2)
			{
				Difference = (0xffff - IC_Val1) + IC_Val2;
			}

			Distance = Difference * 0.34/2;
			Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
		}
	}
}

void HCSR04_Read (void)
{
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_CC1);
}

void _7_SEG_ultra(void)
{
	PowerOn_7_SEG_D1();
 	_7_SEG_Num_Test(RxData_From_Node2[0]);
 	HAL_Delay(0);
	PowerOff_7_SEG_D1();
 	PowerOn_7_SEG_D2();
 	_7_SEG_Num_Test(RxData_From_Node2[1]);
 	HAL_Delay(0);
 	PowerOff_7_SEG_D2();
 	PowerOn_7_SEG_D3();
 	_7_SEG_Num_Test(RxData_From_Node2[2]);
 	HAL_Delay(0);
 	PowerOff_7_SEG_D3();
 	PowerOn_7_SEG_D4();
 	_7_SEG_Num_Test(RxData_From_Node2[3]);
 	HAL_Delay(0);
 	PowerOff_7_SEG_D4();
}

uint8_t flag = 0;
void _7_SEG_EXTI (void)
{
	while (1)
		{
			if(flag == 1)
			{


					_7_SEG_ultra();


			}
		}
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
/* Prevent unused argument(s) compilation warning */
	flag = 1;
/* NOTE: This function Should not be modified,
when the callback is needed, the HAL_GPIO_EXTI_Callback
could be implemented in the user file
*/
}

