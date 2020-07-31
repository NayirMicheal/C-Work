/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_int.h"
#include "DIO_int.h"
#include "DIO_register.h"
#include "TIM_int.h"
#include "SWD_int.h"
void callback(void)
{
	TOG_BIT(PORTA,0);
}
void main(void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH);
	TIM_voidInitialize();
	//TIM_voidEnableInt();
	TIM_voidSetCallBackCTC(callback);
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
		{
			TIM_voidEnableIntCTC();
		}
		else
		{
			TIM_voidDisableIntCTC();
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		}
	}
}
