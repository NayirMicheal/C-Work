/*
 * TIM1_prog.c
 *
 *  Created on: 28 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIM1_reg.h"
#include "TIM1_priv.h"
#include "TIM1_int.h"

static void  (*ICU_CallBack) (void);
void TIM1_voidNormalInitialize(void)
{
	/*Disable Interrupt Overflow and Clear the overflow interrupt flag */
	CLR_BIT(TIMSK,2);
	SET_BIT(TIFR,2);
	/*Choose Normal Port Operation*/
	CLR_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
	CLR_BIT(TCCR1A,5);
	CLR_BIT(TCCR1A,4);

	/*Choose Normal Operation*/
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
}

void TIM1_voidStartCount(void)
{
#if TIM1_PRESCALER == TIM1_NO_DIVISION
	TCCR1B|=TIM1_NO_DIVISION_MASK;
#elif TIM1_PRESCALER == TIM1_8_DIVISION
	TCCR1B|=TIM1_8_DIVISION_MASK;
#elif TIM1_PRESCALER == TIM1_64_DIVISION
	TCCR1B|=TIM1_64_DIVISION_MASK;
#elif TIM1_PRESCALER == TIM1_256_DIVISION
	TCCR1B|=TIM1_256_DIVISION_MASK;
#elif TIM1_PRESCALER == TIM1_1024_DIVISION
	TCCR1B|=TIM1_1024_DIVISION_MASK;
#elif TIM1_PRESCALER == TIM1_EXT_CLK_RISING_EDGE_MASK
	TCCR1B|=TIM1_EXT_CLK_RISING_EDGE_MASK;
#elif TIM1_PRESCALER == TIM1_EXT_CLK_FALLING_EDGE_MASK
	TCCR1B|=TIM1_EXT_CLK_FALLING_EDGE_MASK;
#endif
}

void TIM1_voidStopCount(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void TIM1_voidEnableOverflowInterrupt(void)
{
	/*Enable Interrupt*/
	SET_BIT(TIMSK,2);
}

void TIM1_voidDisableOverflowInterrupt(void)
{
	/*Enable Interrupt*/
	CLR_BIT(TIMSK,2);
}

u16 TIM1_voidGetCounter(void)
{
	return TCNT1;
}

void TIM1_voidClearCounter(void)
{
	TCNT1=0;
}

void ICU_voidChooseEdge(u8 Edge)
{
	if(Edge==ICU_RAISING_EDGE)
	{
		SET_BIT(TCCR1B,6);
		SET_BIT(TCCR1B,7);
	}
	else if(Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,6);
		SET_BIT(TCCR1B,7);
	}
}

void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,5);
}
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,5);
}

u16 ICU_voidGetICR1(void)
{
	return ICR1;
}

void ICU_voidSetCallBack(void (* funptr) (void))
{
	ICU_CallBack=funptr;
}

void __vector_6 (void)__attribute__((signal,used));
void __vector_6 (void)
{
	ICU_CallBack();
}
