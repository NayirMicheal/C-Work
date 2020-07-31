/*
 * NVIC.c
 *
 *  Created on: 4 May 2018
 *      Author: Nayir
 */
#include <stdio.h>
#include "NVIC.h"
#include "BIT_MATH.h"
#define NVIC_BASE_ADD 		0xE000E100
#define NVIC_STIR 		*((volatile uint32_t* const) 0xE000EF00))
typedef struct
{
	uint32_t ISER0;
	uint32_t ISER1;
	uint32_t ISER2;

	uint32_t ICER0;
	uint32_t ICER1;
	uint32_t ICER2;

	uint32_t ISPR0;
	uint32_t ISPR1;
	uint32_t ISPR2;

	uint32_t ICPR0;
	uint32_t ICPR1;
	uint32_t ICPR2;

	uint32_t IABR0;
	uint32_t IABR1;
	uint32_t IABR2;

	uint32_t IPR0;
	uint32_t IPR1;
	uint32_t IPR2;
	uint32_t IPR3;
	uint32_t IPR4;
	uint32_t IPR5;
	uint32_t IPR6;
	uint32_t IPR7;
	uint32_t IPR8;
	uint32_t IPR9;
	uint32_t IPR10;
	uint32_t IPR11;
	uint32_t IPR12;
	uint32_t IPR13;
	uint32_t IPR14;
	uint32_t IPR15;
	uint32_t IPR16;
	uint32_t IPR17;
	uint32_t IPR18;
	uint32_t IPR19;
	uint32_t IPR20;

} NVIC_t;

volatile NVIC_t * const NVIC_Base=(volatile NVIC_t * const) NVIC_BASE_ADD;

void NVIC_enableInterrupt(interrupt_t index)
{
	if(index<32)
	{
		SET_BIT(NVIC_Base->ISER0,index);
	}
	else
	{
		SET_BIT(NVIC_Base->ISER1,(index-32));
	}
}
void NVIC_disableInterrupt(interrupt_t index)
{
	if(index<32)
	{
		SET_BIT(NVIC_Base->ICER0,index);
	}
	else
	{
		SET_BIT(NVIC_Base->ICER1,(index-32));
	}
}
void NVIC_generateSwInterrupt(interrupt_t index)
{
	if(index<32)
	{
		SET_BIT(NVIC_Base->ISPR0,index); //set pending
		SET_BIT(NVIC_Base->ISER0,index); //Enable
	}
	else
	{
		SET_BIT(NVIC_Base->ISPR1,(index-32));
		SET_BIT(NVIC_Base->ISER1,(index-32));
	}
}
void NVIC_disableAllInterruptrequest(void)
{
	//asm("MOV R0,#1");
	//asm("MSR PRIMASK,R0");
	asm("CPSID i"); //not sure that the compiler will understand it
}
void NVIC_enableAllInterruptrequest(void)
{
	//asm("MOV R0,#0");
	//asm("MSR PRIMASK,R0");
	asm("CPSIE i"); //not sure that the compiler will understand it
}

