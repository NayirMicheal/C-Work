#include "STD_TYPES.h"
#include "DIO_int.h"
#include "LEDS_priv.h"
#include "LEDS_int.h"
void LEDS_voidSetLedOn(u8 u8LedIndexCpy)
{

	if(u8LedIndexCpy < LEDS_u8_LEDS_NB)
	{
		if (LEDS_u8LedMode[u8LedIndexCpy] == LEDS_u8_MODE_NORMAL)
		{
			DIO_voidSetPinValue(LEDS_u8LedToDioLink[u8LedIndexCpy],DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(LEDS_u8LedToDioLink[u8LedIndexCpy],DIO_u8_LOW);
		}
	}
	else
	{

	}
}
void LEDS_voidSetLedOff(u8 u8LedIndexCpy)
{

	if(u8LedIndexCpy < LEDS_u8_LEDS_NB)
	{
		if (LEDS_u8LedMode[u8LedIndexCpy] == LEDS_u8_MODE_NORMAL)
		{
			DIO_voidSetPinValue(LEDS_u8LedToDioLink[u8LedIndexCpy],DIO_u8_LOW);
		}
		else
		{
			DIO_voidSetPinValue(LEDS_u8LedToDioLink[u8LedIndexCpy],DIO_u8_HIGH);
		}
	}
	else
	{

	}
}
