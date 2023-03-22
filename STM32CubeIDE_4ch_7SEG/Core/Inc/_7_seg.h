/*
 * _7_seg.h
 *
 *  Created on: Dec 15, 2022
 *      Author: qkcvb
 */

#ifndef INC__7_SEG_H_
#define INC__7_SEG_H_
void PowerOn_7_SEG_D1(void);
void PowerOff_7_SEG_D1(void);
void PowerOn_7_SEG_D2(void);
void PowerOff_7_SEG_D2(void);
void PowerOn_7_SEG_D3(void);
void PowerOff_7_SEG_D3(void);
void PowerOn_7_SEG_D4(void);
void PowerOff_7_SEG_D4(void);
void On_7_SEG_AllPin(void);
void Off_7_SEG_AllPin(void);
void On_7_SEG_OnePin(uint16_t pinNum);
void Off_7_SEG_OnePin(uint16_t pinNum);
void _7_SEG_Pin_Test(void);
void _7_SEG_Num_Test(char num);
void _7_SEG_Num_Test2(int num);
void _7_SEG_20181367_Test(void);
void _7_SEG_1234_Test(void);
//void _7_SEG_ultra(void);
void delay (uint16_t time);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HCSR04_Read (void);
void _7_SEG_EXTI (void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif /* INC__7_SEG_H_ */
