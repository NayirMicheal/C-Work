/*
 * SevenSeg_prog.c
 *
 *  Created on: 6 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_int.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_int.h"
#include "SEVENSEG_priv.h"

/*Display on Seven segment take a u8 variable a display it on the seven segment */
void SevenSeg_voidDisplayOnSeg(u8 u8PaternCpy)
{
	/*if the seven segment type is Anode type*/
#if u8_SEVENSEG_TYPE == u8_SEVENSEG_ANODE
	/*then set the bit of the common with high value*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_COMMON,DIO_u8_HIGH);
	/*get bit 0 of the sent variable and out it on the seven segment A*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_A,GET_BIT(u8PaternCpy,0));
	/*get bit 1 of the sent variable and out it on the seven segment B*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_B,GET_BIT(u8PaternCpy,1));
	/*get bit 2 of the sent variable and out it on the seven segment C*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_C,GET_BIT(u8PaternCpy,2));
	/*get bit 3 of the sent variable and out it on the seven segment D*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_D,GET_BIT(u8PaternCpy,3));
	/*get bit 4 of the sent variable and out it on the seven segment E*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_E,GET_BIT(u8PaternCpy,4));
	/*get bit 5 of the sent variable and out it on the seven segment F*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_F,GET_BIT(u8PaternCpy,5));
	/*get bit 6 of the sent variable and out it on the seven segment G*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_G,GET_BIT(u8PaternCpy,6));
	/*get bit 7 of the sent variable and out it on the seven segment DOT*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_DOT,GET_BIT(u8PaternCpy,7));
/*else if the seven segment is cathode type*/
#else
	/*then set the common cathode pin with low value*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_COMMON,DIO_u8_LOW);
	/*get bit 0 of the sent variable and out it on the seven segment A*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_A,!GET_BIT(u8PaternCpy,0));
	/*get bit 1 of the sent variable and out it on the seven segment B*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_B,!GET_BIT(u8PaternCpy,1));
	/*get bit 2 of the sent variable and out it on the seven segment C*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_C,!GET_BIT(u8PaternCpy,2));
	/*get bit 3 of the sent variable and out it on the seven segment D*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_D,!GET_BIT(u8PaternCpy,3));
	/*get bit 4 of the sent variable and out it on the seven segment E*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_E,!GET_BIT(u8PaternCpy,4));
	/*get bit 5 of the sent variable and out it on the seven segment F*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_F,!GET_BIT(u8PaternCpy,5));
	/*get bit 6 of the sent variable and out it on the seven segment G*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_G,!GET_BIT(u8PaternCpy,6));
	/*get bit 7 of the sent variable and out it on the seven segment DOT*/
	DIO_voidSetPinValue(u8_SEVENSEG_SEG_DOT,!GET_BIT(u8PaternCpy,7));
#endif


}
