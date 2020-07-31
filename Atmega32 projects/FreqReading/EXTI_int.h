/*
 * EXTI_int.h
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

/*this function shall intialize the EXTI and*/
/*Set its ooperation initially disabled*/
#define EXTI_u8_LOW_LEVEL     0
#define EXTI_u8_ON_CHANGE     1
#define EXTI_u8_FALLING_EDGE  2
#define EXTI_u8_RAISING_EDGE  3

void EXTI_voidInit(void);

/*this function shall set the callback pointer*/
/*to the recieved address*/
void EXTI_voidSetCallback(void (*ptrCpy)(void));

/*this function shall enable the external interrupt*/
void EXTI_voidEnable(void);

/*this function shall disable the external interrupt*/
void EXTI_voidDisable(void);
/*Change Exti Mode*/
void EXTI_voidChangeMode(u8 Mode);


#endif /* EXTI_INT_H_ */
