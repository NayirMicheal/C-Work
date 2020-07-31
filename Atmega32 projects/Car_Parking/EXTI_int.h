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
void EXTI_voidInit(void);

/*this function shall set the callback pointer*/
/*to the recieved address*/
void EXTI_voidSetCallback(void (*ptrCpy)(void));

/*this function shall enable the external interrupt*/
void EXTI_voidEnable(void);

/*this function shall disable the external interrupt*/
void EXTI_voidDisable(void);


#endif /* EXTI_INT_H_ */
