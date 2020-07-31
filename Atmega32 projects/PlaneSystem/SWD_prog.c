/*
 * SWD_prog.c
 *
 *  Created on: 24 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"DIO_int.h"
#include"SWD_priv.h"
#include"SWD_int.h"


u8 SWD_u8GetSwitchState(u8 u8SwIdxCpy)
{
	u8 DioStateLoc;
	u8 SwitchStateLoc;
	if(u8SwIdxCpy < SWD_u8_SW_NB)
	{
		DioStateLoc=DIO_u8GetPinValue(SWD_u8SwToDioLink[u8SwIdxCpy]);
		/*if switch state equals its open state return released*/
		if(DioStateLoc==SWD_u8SwOpenState[u8SwIdxCpy])
		{
			SwitchStateLoc= SWD_u8RELEASED;
		}
		/*if switch state not equal open state return pushed */
		else if(DioStateLoc != SWD_u8SwOpenState[u8SwIdxCpy])
		{
			SwitchStateLoc= SWD_u8PUSHED;
		}
	}
	/* Error: returned if the number of switch isn't in the range */
	else{
		SwitchStateLoc= SWD_u8ERROR;
		}
	return SwitchStateLoc;
}
