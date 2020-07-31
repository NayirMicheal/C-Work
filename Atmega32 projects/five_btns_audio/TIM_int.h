/*
 * TIM_int.h
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */

#ifndef TIM_INT_H_
#define TIM_INT_H_
#define TIM_u16_NO_DIVISON   1
#define TIM_u16_DIV_BY_8     8
#define TIM_u16_DIV_BY_64    64
#define TIM_u16_DIV_BY_256   256
#define TIM_u16_DIV_BY_1024  1024

#define TIM_u8_TIM_RES 		8

#include "TIM_config.h"

/*Description: This function shall init the Timer prephiral*/
void TIM_voidInitialize(void);

/*Description: enable Timer interrupt*/
void TIM_voidEnableInt(void);

/**/
void TIM_voidEnableIntCTC(void);

/*Description: disable Timer interrupt*/
void TIM_voidDisableInt(void);

/**/
void TIM_voidDisableIntCTC(void);

/*Description: set Timer callback function*/
void TIM_voidSetCallBack(void (* ptrCpy) (void));

/**/
void TIM_voidSetCallBackCTC(void (* ptrCpy) (void));

/*Description: init timer register*/
void TIM_voidInitCountingRegister(u8 u8ValueCpy);

/**/
void TIM_voidInitCTCRegister(u8 u8ValueCpy);

/**/
void TIM_voidSetCallBackCTC(void (* ptrCpy) (void));
#endif /* TIM_INT_H_ */
