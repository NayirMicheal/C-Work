/*
 * main.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "GIE_int.h"
#include "RTO_int.h"

void Task1(void)
{
	TOG_BIT(PORTA,0);
}
void Task2(void)
{
	TOG_BIT(PORTA,1);
}
void Task3(void)
{
	TOG_BIT(PORTA,2);
}
void main(void)
{
	DIO_voidInitialize();
	Timer0_init();
	GIE_EnableGlobalInterrupt();
	while(1)
	{


	}
}



