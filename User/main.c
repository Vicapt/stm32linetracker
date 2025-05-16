#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Sensor.h"
#include "Timer.h"
#include "Buzzer.h"

uint16_t Time;
int i=0;
uint16_t State_Group =0;

int main(void)
{
	//初始化
	OLED_Init();
	Sensor_Init();
	Timer_Init();
	//Motor_Init();
	//Buzzer_Init();
	
	OLED_ShowString(1,1,"Time:");
	
	while (1)
	{
		//oled显示
		OLED_ShowNum(2,1,Time,5);
		OLED_ShowNum(4,1,Sensor_Get(),5);
		OLED_ShowNum(3,1,State_Group,5);
		
		if (State_Group == 10101)
			
		
		//巡线+记录状态编号
		
		switch(Sensor_Get())
		{
			case 0b00000:
			if(State_Group % 10 != 0)
			{
				Motor_SetSpeed(1 , 0);
				Motor_SetSpeed(2 , 0);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 0;
			}
			break;
			
			case 0b11111:
			if(State_Group % 10 != 1)
			{
				Motor_SetSpeed(1 , 50);
				Motor_SetSpeed(2 , 50);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 1;
			}
			break;
			
			case 0b00100:
			if(State_Group % 10 != 2)
			{
				Motor_SetSpeed(1 , 50);
				Motor_SetSpeed(2 , 50);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 2;
			}
			break;
			
			case 0b01110:
			if(State_Group % 10 != 3)
			{
				Motor_SetSpeed(1 , 50);
				Motor_SetSpeed(2 , 50);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 3;
			}
			break;
			
			case 0b01100:
			if(State_Group % 10 != 4)
			{
				Motor_SetSpeed(1 , 20);
				Motor_SetSpeed(2 , 20);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 4;
			}
			break;
			
			case 0b11100:
			if(State_Group % 10 != 5)
			{
				Motor_SetSpeed(1 , 20);
				Motor_SetSpeed(2 , 20);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 5;
			}
			break;
			
			case 0b00110:
			if(State_Group % 10 != 6)
			{
				Motor_SetSpeed(1 , 20);
				Motor_SetSpeed(2 , 20);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 6;
			}
			break;
			
			case 0b00111:
			if(State_Group % 10 != 7)
			{
				Motor_SetSpeed(1 , 20);
				Motor_SetSpeed(2 , 20);
				
				State_Group = State_Group%10000;
				State_Group *= 10;
				State_Group += 7;
			}
			break;
			
		}
	}
}
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Time++;
	}
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}

