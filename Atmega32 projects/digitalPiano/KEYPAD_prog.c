/*
 * KEYPAD_prog.c
 *
 *  Created on: 31 Jan 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "KEYPAD_priv.h"
#include "KEYPAD_config.h"
#include "KEYPAD_int.h"

static u16 u16ResultLoc=0;

u16 KEYPAD_u16GetStatus(void)
{
	/*Clear previous status*/
	u16ResultLoc=0;

	/*Phase 1*/
	DIO_voidSetPinValue(KEYOAD_u8_OUT_1,DIO_u8_LOW);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_4,DIO_u8_HIGH);
	voidSetSwitchresult(0);

	/*Phase 2*/

	DIO_voidSetPinValue(KEYOAD_u8_OUT_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_2,DIO_u8_LOW);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_4,DIO_u8_HIGH);
	voidSetSwitchresult(1);

	/*Phase 3*/

	DIO_voidSetPinValue(KEYOAD_u8_OUT_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_3,DIO_u8_LOW);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_4,DIO_u8_HIGH);
	voidSetSwitchresult(2);

	/*Phase 4*/

	DIO_voidSetPinValue(KEYOAD_u8_OUT_1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYOAD_u8_OUT_4,DIO_u8_LOW);
	voidSetSwitchresult(3);

	return u16ResultLoc;
}

static void voidSetSwitchresult(u8 u8ColumnCpy)
{
	if(DIO_u8GetPinValue(KEYOAD_u8_INP_1) == DIO_u8_LOW)
	{
		SET_BIT(u16ResultLoc,u8ColumnCpy);
	}
	if(DIO_u8GetPinValue(KEYOAD_u8_INP_2) == DIO_u8_LOW)
	{
		SET_BIT(u16ResultLoc,(u8ColumnCpy+4));
	}
	if(DIO_u8GetPinValue(KEYOAD_u8_INP_3) == DIO_u8_LOW)
	{
		SET_BIT(u16ResultLoc,(u8ColumnCpy+8));
	}
	if(DIO_u8GetPinValue(KEYOAD_u8_INP_4) == DIO_u8_LOW)
	{
		SET_BIT(u16ResultLoc,(u8ColumnCpy+12));
	}
}
