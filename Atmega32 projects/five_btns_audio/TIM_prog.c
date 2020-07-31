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
static void (* TIM_CallBack_CTC) (void);

/*Description: This function shall init the Timer prephiral*/
void TIM_voidInitialize(void)
{
	/*clear flag*/
	SET_BIT(TIFR,0);
	SET_BIT(TIFR,1);
	/*disable interrupt for counting and ctc*/
	CLR_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);
#if TIM_u8_MODE == TIM_u8_NORMAL_MODE
	/*initialize timer register*/
	TCNT0=TIM_u8_INIT_VALUE;
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
#elif TIM_u8_MODE== TIM_u8_CTC_MODE
	OCR0=TIM_u8_OCR0_VALUE;
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
#endif
	/*set prescaler (which powers the timer not the interrupt but the timer it self)*/
#if TIM_u16_PRESCALER == TIM_u16_NO_DIVISON
	TCCR0 |= TIM_u8_NO_DIV_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_8
	TCCR0 |= TIM_u8_DIV_BY_8_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_64
	TCCR0 |= TIM_u8_DIV_BY_64_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_256
	TCCR0 |= TIM_u8_DIV_BY_256_MASK;
#elif  TIM_u16_PRESCALER == TIM_u16_DIV_BY_1024
	TCCR0 |= TIM_u8_DIV_BY_1024_MASK;
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

/*Description: enable Timer interrupt CTC*/
void TIM_voidEnableIntCTC(void)
{
	SET_BIT(TIMSK,1);
}

/*Description: disable Timer interrupt CTC*/
void TIM_voidDisableIntCTC(void)
{
	CLR_BIT(TIMSK,1);
}


/*Description: set Timer callback function*/
void TIM_voidSetCallBack(void (* ptrCpy) (void))
{
	TIM_CallBack=ptrCpy;
}

/*Description: set CTC Timer callback function*/
void TIM_voidSetCallBackCTC(void (* ptrCpy) (void))
{
	TIM_CallBack_CTC=ptrCpy;
}

/*Description: init timer register*/
void TIM_voidInitCountingRegister(u8 u8ValueCpy)
{
	TCNT0 = u8ValueCpy;
}

/*Description: init OCR0 timer register*/
void TIM_voidInitCTCRegister(u8 u8ValueCpy)
{
	OCR0 = u8ValueCpy;
}

void __vector_11 (void)__attribute__((signal,used));
void __vector_11 (void)
{
	TIM_CallBack();
}


void __vector_10 (void)__attribute__((signal,used));
void __vector_10 (void)
{
	TIM_CallBack_CTC();
}
