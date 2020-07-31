/*
 * EXTI_priv.h
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define EXTI_u8_LOW_LEVEL     0
#define EXTI_u8_ON_CHANGE     1
#define EXTI_u8_FALLING_EDGE  2
#define EXTI_u8_RAISING_EDGE  3

static void (*EXTI_voidCallback) (void);

#endif /* EXTI_PRIV_H_ */
