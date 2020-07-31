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

#define ICU_RAISING_EDGE            1
#define ICU_FALLING_EDGE            0
void TIM1_voidNormalInitialize(void);
void TIM1_voidStartCount(void);
void TIM1_voidStopCount(void);
void TIM1_voidEnableOverflowInterrupt(void);
void TIM1_voidDisableOverflowInterrupt(void);
u16  TIM1_voidGetCounter(void);
void TIM1_voidClearCounter(void);
void ICU_voidChooseEdge(u8 Edge);
u16 ICU_voidGetICR1(void);
void ICU_voidSetCallBack(void (* funptr) (void));
void ICU_voidDisableInterrupt(void);
void ICU_voidEnableInterrupt(void);
#endif /* TIM1_INT_H_ */
