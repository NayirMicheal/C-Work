/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DELAY.h"
#include "GIE_int.h"
#include "DIO_int.h"
#include "EXTI_int.h"
#include "TIM_int.h"
#include "SWD_int.h"
static u8 Exti_flag=0;
void Motor(void);
void callback(void)
{
TOG_BIT(PORTB,3);
}
void MotorMove(void)
{
	Exti_flag=1;
}
void main(void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH);
	TIM_voidInitialize();
	TIM_voidSetCallBackCTC(callback);
	EXTI_voidInit();
	EXTI_voidSetCallback(MotorMove);
	EXTI_voidEnable(); // on pin 26 pin D2
	//may need pull up to Ext pin D2
	TIM_voidSetCallBackCTC(callback); // connect IR Led on pin B3 (11)
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
			DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_LOW);
		}
		if(Exti_flag==1)
		{
			Motor();
		}
	}
}
void Motor(void)
{
	static u8 motordirection=0;
	if(0==motordirection)
	{
	for(u8 i=0;i<255;i++)
	{
	DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
	Delay_ms(2);
	DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
	Delay_ms(2);
	DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
	Delay_ms(2);
	DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH);
	Delay_ms(2);
	}
	motordirection=1;
	}
	else if(1==motordirection)
	{
		for(u8 i=0;i<255;i++)
		{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH);
		Delay_ms(2);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
		Delay_ms(2);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
		Delay_ms(2);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
		Delay_ms(2);
		}
		motordirection=0;
	}
	Exti_flag=0;
}
