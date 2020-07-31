/*
 * TIM.c
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIM_register.h"
#include "TIM_priv.h" /*always private first*/
#include "TIM_int.h"


static void (* TIM_CallBack) (void);

/*Description: This function shall init the Timer prephiral*/
void TIM_voidInitialize(void)
{
	/*clear flag*/
	SET_BIT(TIFR,0);
	/*disable interrupt*/
	CLR_BIT(TIMSK,0);
	/*initialize timer register*/
	TCNT0=TIM_u8_INIT_VALUE;
	/*set prescaler (which powers the timer not the interrupt but the timer it self)*/
#if TIM_u16_PRESCALER == TIM_u16_NO_DIVISON
	TCCR0 = TIM_u8_NO_DIV_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_8
	TCCR0 = TIM_u8_DIV_BY_8_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_64
	TCCR0 = TIM_u8_DIV_BY_64_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_256
	TCCR0 = TIM_u8_DIV_BY_256_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_1024
	TCCR0 = TIM_u8_DIV_BY_1024_MASK;
#endif
}

/*Description: enable Timer interrupt*/
void TIM_voidEnableInt(void)
{
	SET_BIT(TIMSK,0);
}

/*Description: disable Timer interrupt*/
void TIM_voidDisableInt(void)
{
	CLR_BIT(TIMSK,0);
}

/*Description: set Timer callback function*/
void TIM_voidSetCallBack(void (* ptrCpy) (void))
{
	TIM_CallBack=ptrCpy;
}

/*Description: init timer register*/
void TIM_voidInitRegister(u8 u8ValueCpy)
{
	TCNT0 = u8ValueCpy;
}


void __vector_11 (void)__attribute__((signal,used));
void __vector_11 (void)
{
	TIM_CallBack();
}
