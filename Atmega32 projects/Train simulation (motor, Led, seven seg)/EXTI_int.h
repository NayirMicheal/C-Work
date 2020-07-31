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
void EXTI_voidSetCallback_EXT0(void (*ptrCpy)(void));
void EXTI_voidSetCallback_EXT1(void (*ptrCpy)(void));


/*this function shall enable the external interrupt*/
void EXTI_voidEnable_EXT0(void);
void EXTI_voidEnable_EXT1(void);

/*this function shall disable the external interrupt*/
void EXTI_voidDisable_EXT0(void);
void EXTI_voidDisable_EXT1(void);


#endif /* EXTI_INT_H_ */
