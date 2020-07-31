#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"

#include "LEDS_priv.h"
#include "LEDS_config.h"
#include "LEDS_int.h"
void LEDS_voidSetLedOn(u8 u8LedPinCPY)
{

	switch(u8LedPinCPY)
	{
	case LEDS_u8_LED0:
#if LEDS_u8_MODE0 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN0,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN0,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED1:
#if LEDS_u8_MODE1 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN1,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN1,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED2:
#if LEDS_u8_MODE2 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN2,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN2,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED3:
#if LEDS_u8_MODE3 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN3,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN3,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED4:
#if LEDS_u8_MODE4 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN4,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN4,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED5:
#if LEDS_u8_MODE5 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN5,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN5,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED6:
#if LEDS_u8_MODE6 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN6,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN6,DIO_u8_LOW);
#endif
		break;
	case LEDS_u8_LED7:
#if LEDS_u8_MODE7 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN7,DIO_u8_HIGH);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN7,DIO_u8_LOW);
#endif
		break;
	}

}
void LEDS_voidSetLedOff(u8 u8LedPinCPY)
{
	switch(u8LedPinCPY)
	{
	case LEDS_u8_LED0:
#if LEDS_u8_MODE0 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN0,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN0,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED1:
#if LEDS_u8_MODE1 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN1,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN1,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED2:
#if LEDS_u8_MODE2 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN2,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN2,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED3:
#if LEDS_u8_MODE3 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN3,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN3,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED4:
#if LEDS_u8_MODE4 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN4,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN4,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED5:
#if LEDS_u8_MODE5 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN5,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN5,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED6:
#if LEDS_u8_MODE6 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN6,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN6,DIO_u8_HIGH);
#endif
		break;
	case LEDS_u8_LED7:
#if LEDS_u8_MODE7 == LEDS_u8_NORMAL
		DIO_voidSetPinValue(LEDS_u8_PIN7,DIO_u8_LOW);
#else
		DIO_voidSetPinValue(LEDS_u8_PIN7,DIO_u8_HIGH);
#endif
		break;
	}
}
