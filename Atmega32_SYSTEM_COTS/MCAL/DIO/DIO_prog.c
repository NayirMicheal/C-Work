#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"

void DIO_voidInitialize(void)
{
	DDRA = DIO_u8_PORTA_DIRECTION;
	DDRB = DIO_u8_PORTB_DIRECTION;
	DDRC = DIO_u8_PORTC_DIRECTION;
	DDRD = DIO_u8_PORTD_DIRECTION;
}
void DIO_voidSetPinValue(u8 u8PinIndexCpy,u8 u8PinValueCpy)
{	
	/*Check if the PIN index in PORTA range */
	if( (u8PinIndexCpy >= DIO_u8_PORTA_START) && (u8PinIndexCpy <= DIO_u8_PORTA_END) )
	{
		if(u8PinValueCpy == DIO_u8_HIGH)
		{
			SET_BIT(PORTA,u8PinIndexCpy);
		}
		else
		{
			CLR_BIT(PORTA,u8PinIndexCpy);
		}			
	}
	
	/*Check if the PIN index in PORTB range */
	else if( (u8PinIndexCpy >= DIO_u8_PORTB_START) && (u8PinIndexCpy <= DIO_u8_PORTB_END) )
	{
		u8PinIndexCpy -= DIO_u8_PORTA_SIZE;	
		if(u8PinValueCpy == DIO_u8_HIGH)
		{
			SET_BIT(PORTB,u8PinIndexCpy);
		}
		else
		{
			CLR_BIT(PORTB,u8PinIndexCpy);
		}			
	}
	
	/*Check if the PIN index in PORTC range */
	else if( (u8PinIndexCpy >= DIO_u8_PORTC_START) && (u8PinIndexCpy <= DIO_u8_PORTC_END) )
	{
		u8PinIndexCpy -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);	
		if(u8PinValueCpy == DIO_u8_HIGH)
		{
			SET_BIT(PORTC,u8PinIndexCpy);
		}
		else
		{
			CLR_BIT(PORTC,u8PinIndexCpy);
		}			
	}
	
	/*Check if the PIN index in PORTD range */
	else if( (u8PinIndexCpy >= DIO_u8_PORTD_START) && (u8PinIndexCpy <= DIO_u8_PORTD_END) )
	{
		u8PinIndexCpy -= (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE);	
		if(u8PinValueCpy == DIO_u8_HIGH)
		{
			SET_BIT(PORTD,u8PinIndexCpy);
		}
		else
		{
			CLR_BIT(PORTD,u8PinIndexCpy);
		}			
	}
}
u8 DIO_u8GetPinValue (u8 u8PinIndexCpy)
{
	u8 actualIndexLoc;
	u8 digitalPinValue;
	u8 HighOrLow;
	if( (u8PinIndexCpy >= DIO_u8_PORTA_START) && (u8PinIndexCpy <= DIO_u8_PORTA_END))
	{
		actualIndexLoc=u8PinIndexCpy;
		digitalPinValue=GET_BIT(PINA,actualIndexLoc);
	}
	else if( (u8PinIndexCpy >= DIO_u8_PORTC_START) && (u8PinIndexCpy <= DIO_u8_PORTC_END))
	{
		actualIndexLoc=u8PinIndexCpy-DIO_u8_PORTA_SIZE;
		digitalPinValue=GET_BIT(PINB,actualIndexLoc);
	}
	else if((u8PinIndexCpy >= DIO_u8_PORTC_START) && (u8PinIndexCpy <= DIO_u8_PORTC_END))
	{
		actualIndexLoc=u8PinIndexCpy-DIO_u8_PORTA_SIZE-DIO_u8_PORTB_SIZE;
		digitalPinValue=GET_BIT(PINB,actualIndexLoc);
	}
	else if((u8PinIndexCpy >= DIO_u8_PORTD_START) && (u8PinIndexCpy <= DIO_u8_PORTD_END))
	{
		actualIndexLoc=u8PinIndexCpy-DIO_u8_PORTA_SIZE-DIO_u8_PORTB_SIZE-DIO_u8_PORTC_SIZE;
		digitalPinValue=GET_BIT(PIND,actualIndexLoc);
	}

	if(digitalPinValue == 0)
	{
		HighOrLow=DIO_u8_LOW;
	}
	else if(digitalPinValue ==1)
	{
		HighOrLow=DIO_u8_HIGH;
	}
	return HighOrLow;
}

