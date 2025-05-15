#include "stm32f10x.h"
#include "stm32f10x.h"                  // Device header

uint16_t Sensor_State[5];
uint16_t Sensor_State_code;

void Sensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint16_t Sensor_Get(void)
{
	Sensor_State[0] = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
	Sensor_State[1] = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	Sensor_State[2] = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12);
	Sensor_State[3] = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
	Sensor_State[4] = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
	Sensor_State_code = Sensor_State[0]*10000 + Sensor_State[1]*1000 + Sensor_State[2]*100 + Sensor_State[3]*10 + Sensor_State[4]*1;
	return Sensor_State_code;
}


