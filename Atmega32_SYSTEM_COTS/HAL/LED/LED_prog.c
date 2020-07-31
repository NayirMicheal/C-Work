#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"
void LED_voidSetLedOn(void)
{
		
	
	#if LED_u8_MODE == LED_u8_NORMAL
		DIO_voidSetPinValue(LED_u8_PIN,DIO_u8_HIGH);
	#else
		DIO_voidSetPinValue(LED_u8_PIN,DIO_u8_LOW);
	#endif
}
void LED_voidSetLedOff(void)
{
	#if LED_u8_MODE == LED_u8_NORMAL
		DIO_voidSetPinValue(LED_u8_PIN,DIO_u8_LOW);
	#else
		DIO_voidSetPinValue(LED_u8_PIN,DIO_u8_HIGH);
	#endif
}