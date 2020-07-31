/*
 * TIM1_int.h
 *
 *  Created on: 28 Mar 2018
 *      Author: Nayir
 */

#ifndef TIM1_INT_H_
#define TIM1_INT_H_

#include "TIM1_config.h"

#define TIM1_NO_DIVISION           1
#define TIM1_8_DIVISION            2
#define TIM1_64_DIVISION           4
#define TIM1_256_DIVISION          8
#define TIM1_1024_DIVISION         16
#define TIM1_EXT_CLK_FALLING_EDGE  32
#define TIM1_EXT_CLK_RISING_EDGE   64

void TIM1_voidNormalInitialize(void);
void voidTIM1_StartCount(void);
void voidTIM1_StopCount(void);
void voidTIM1_EnableOverflowInterrupt(void);
void voidTIM1_DisableOverflowInterrupt(void);
u16 VoidTIM1_GetCounter(void);
void voidTIM1_ClearCounter(void);
#endif /* TIM1_INT_H_ */
