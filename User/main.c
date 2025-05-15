#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Sensor.h"
#include "Timer.h"

uint16_t Time;

int main(void)
{
	
	OLED_Init();
	OLED_ShowString(1,1,"Time:");
	OLED_ShowString(3,1,"Code:");
	Sensor_Init();
	Timer_Init();
	//Motor_Init();
	//Motor_SetSpeed(1 , 0);
	//Motor_SetSpeed(2 , 0);
	
	
	
	while (1)
	{
		OLED_ShowNum(2,1,Time,5);
		OLED_ShowNum(4,1,Sensor_Get(),5);
	}
}
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Time ++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
