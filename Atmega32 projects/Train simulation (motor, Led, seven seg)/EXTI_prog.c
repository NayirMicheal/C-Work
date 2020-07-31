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
#if EXTI_INT0_ENABLE == EXTI_ON
#if EXTI_INT0_MODE ==EXTI_MODE_LOGICAL_CHANGE
	/*set EXTI 0 mode to Interrupt on change*/
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);


#elif EXTI_INT0_MODE == EXTI_MODE_LOW_LEVEL
	/*set EXTI 0 mode to Interrupt on change*/
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTI_INT0_MODE == EXTI_MODE_RAISING_EDGE
	/*set EXTI 0 mode to Interrupt on change*/
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif EXTI_INT0_MODE == EXTI_MODE_FALLING_EDGE
	/*set EXTI 0 mode to Interrupt on change*/
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif
	/*Disable EXTI 0*/
	CLR_BIT(GICR,6);

	/*Clear Flag*/
	SET_BIT(GIFR,6);
#endif
#if EXTI_INT1_ENABLE == EXTI_ON

#if EXTI_INT1_MODE ==EXTI_MODE_LOGICAL_CHANGE
	/*set EXTI 1 mode to Interrupt on change*/
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif EXTI_INT1_MODE == EXTI_MODE_LOW_LEVEL
	/*set EXTI 0 mode to Interrupt on change*/
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif EXTI_INT1_MODE == EXTI_MODE_RAISING_EDGE
	/*set EXTI 0 mode to Interrupt on change*/
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif EXTI_INT1_MODE == EXTI_MODE_FALLING_EDGE
	/*set EXTI 0 mode to Interrupt on change*/
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#endif
	/*Disable EXTI 0*/
	CLR_BIT(GICR,7);

	/*Clear Flag*/
	SET_BIT(GIFR,7);
#endif
}

/*this function shall set the callback pointer*/
/*to the recieved address*/
void EXTI_voidSetCallback_EXT0(void (*ptrCpy)(void))
{
	EXTI_voidCallback_INT0=ptrCpy;
}

void EXTI_voidSetCallback_EXT1(void (*ptrCpy)(void))
{
	EXTI_voidCallback_INT1=ptrCpy;
}
/*this function shall enable the external interrupt*/
void EXTI_voidEnable_EXT0(void)
{
	/*Enable EXTI 0*/
	SET_BIT(GICR,6);

}

void EXTI_voidEnable_EXT1(void)
{
	/*Enable EXTI 1*/
	SET_BIT(GICR,7);

}
/*this function shall disable the external interrupt*/
void EXTI_voidDisable_EXT0(void)
{
	/*Disable EXTI 0*/
	CLR_BIT(GICR,6);
}

void EXTI_voidDisable_EXT1(void)
{
	/*Disable EXTI 1*/
	CLR_BIT(GICR,7);
}
void  __vector_1  (void) __attribute__((signal,used));
void  __vector_1  (void)
{
	EXTI_voidCallback_INT0();
}

void  __vector_2  (void) __attribute__((signal,used));
void  __vector_2  (void)
{
	EXTI_voidCallback_INT1();
}
