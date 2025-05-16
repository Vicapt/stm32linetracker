#ifndef __BUZZER_H
#define __BUZZER_H

#include "stm32f10x.h"

// 硬件配置（引脚根据实际情况更改）
#define BUZZER_PORT      GPIOC
#define BUZZER_PIN       GPIO_Pin_13
#define BUZZER_RCC       RCC_APB2Periph_GPIOC

// 操作宏
#define BUZZER_ON()      GPIO_SetBits(BUZZER_PORT, BUZZER_PIN)
#define BUZZER_OFF()     GPIO_ResetBits(BUZZER_PORT, BUZZER_PIN)

void Buzzer_Init(void);

#endif /* __BUZZER_H */
