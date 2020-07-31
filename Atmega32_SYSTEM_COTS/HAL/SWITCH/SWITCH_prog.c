/*
 * SWITCH_prog.c
 *
 *  Created on: 22 Jan 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_int.h"
#include"SWITCH_config.h"
#include "SWITCH_int.h"

u8 SWITCH_u8getSwitchState(void)
{
	u8 resultLoc;
	u8 SwitchStateLoc;
	if(DIO_y8GetPinValue(SWITH_u8_PIN)== SWITCH_u8_OPEN_STATE)
	{
		SwitchStateLoc= SWITCH_u8_RELEASED;
	}
	else if(DIO_y8GetPinValue(SWITH_u8_PIN) != SWITCH_u8_OPEN_STATE)
	{
		SwitchStateLoc= SWITCH_u8_PUSHED;
	}
	return SwitchStateLoc;
}
