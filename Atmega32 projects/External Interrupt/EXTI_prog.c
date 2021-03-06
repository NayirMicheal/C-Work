/*
 * EXTI_prog.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "EXTI_reg.h"
#include "EXTI_priv.h"
#include"EXTI_config.h"
#include "EXTI_int.h"
/*this function shall intialize the EXTI and*/
/*Set its ooperation initially disabled*/
void EXTI_voidInit(void)
{
	/*set EXTI 0 mode to Interrupt on change*/
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

	/*Disable EXTI 0*/
	CLR_BIT(GICR,6);

	/*Clear Flag*/
	SET_BIT(GIFR,6);
}

/*this function shall set the callback pointer*/
/*to the recieved address*/
void EXTI_voidSetCallback(void (*ptrCpy)(void))
{
	EXTI_voidCallback=ptrCpy;
}

/*this function shall enable the external interrupt*/
void EXTI_voidEnable(void)
{
	/*Enable EXTI 0*/
	SET_BIT(GICR,6);

}

/*this function shall disable the external interrupt*/
void EXTI_voidDisable(void)
{
	/*Disable EXTI 0*/
	CLR_BIT(GICR,6);

}

void  __vector_1  (void) __attribute__((signal,used));
void  __vector_1  (void)
{
	EXTI_voidCallback();
}
