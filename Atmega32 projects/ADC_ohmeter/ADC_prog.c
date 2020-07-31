/*
 * ADC_prog.c
 *
 *  Created on: 16 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_reg.h"
#include "ADC_priv.h"
#include "ADC_config.h"
#include "ADC_int.h"
static void (* ADCIntCallBack) (void);
#if ADC_RESOLUTION_MODE == ADC_10_BIT_MODE
static u16 LastADCValue;
#elif ADC_RESOLUTION_MODE == ADC_8_BIT_MODE
static u8 LastADCValue;
#endif
void ADC_voidInit(void)
{
	/*Choose voltage reference*/
#if ADC_REF_VOLT ==ADC_External_VREF
	CLR_BIT(ADMUX,7);
	CLR_BIT(ADMUX,6);
#elif ADC_REF_VOLT ==ADC_VCC_VREF
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#elif ADC_REF_VOLT ==ADC_INTERNAL_VREF
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#endif

	/*choose the prescaler*/
	ADCSRA|=ADC_PRECALER_DIV;

#if ADC_RESOLUTION_MODE == ADC_8_BIT_MODE
	SET_BIT(ADMUX,5);
#elif ADC_RESOLUTION_MODE == ADC_10_BIT_MODE
	CLR_BIT(ADMUX,5);
#endif

#if ADC_TRIGGERING_MODE == NOT_USED
	CLR_BIT(ADCSRA,5);
#elif ADC_TRIGGERING_MODE == FREE_RUNNING_MODE
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == TIMER0_CMPMATCH
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == TIMER0_OVF
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == TIMER1_CMPMATCH_B
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == TIMER1_ICU
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == TIMER1_OVF
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == ANALOG_COMPARTOR
	SET_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#elif ADC_TRIGGERING_MODE == EXT_INT0
	SET	_BIT(ADCSRA,5);
	SFIOR=(u8)(ADC_TRIGGERING_MODE<<5);
#endif


	/*Enable ADC*/
	SET_BIT(ADCSRA,7);

}
#if ADC_RESOLUTION_MODE ==ADC_10_BIT_MODE
Status_t ADC_voidStartConversion(u8 channelIdCpy,u16 * ReadValuePtrCpy)
{
	/*choose desired channel ADMUX*/
	ADMUX |=channelIdCpy;
	/*start converion by writing on ADSC=1*/
	SET_BIT(ADCSRA,6);
	/*if interrupt is enabled */
	if(GET_BIT(ADCSRA,3)==1)
	{
		return NOK;
	}
	/*else not enable*/
	else
	{
		/*while ADIF==0 check for interrupt flag set*/
		while(!GET_BIT(ADCSRA,4));
		/*clear ADIF by writing 1*/
		SET_BIT(ADCSRA,4);
		/*update readValuePtr*/
		*ReadValuePtrCpy=ADCHL;
		/*update last value will return from getLastResult function*/
		LastADCValue=*ReadValuePtrCpy;
		/*return ok*/
		return OK;
	}
}
#elif ADC_RESOLUTION_MODE==ADC_8_BIT_MODE

Status_t ADC_voidStartConversion(u8 channelIdCpy,u8 * ReadValuePtrCpy)
{
	/*choose desired channel ADMUX*/
	ADMUX |=channelIdCpy;
	/*start converion by writing on ADSC=1*/
	SET_BIT(ADCSRA,6);
	/*if interrupt is enabled */
	if(GET_BIT(ADCSRA,3)==1)
	{
		return NOK;
	}
	/*else not enable*/
	else
	{
		/*while ADIF==0 check for interrupt flag set*/
		while(!GET_BIT(ADCSRA,4));
		/*clear ADIF by writing 1*/
		SET_BIT(ADCSRA,4);
		/*update readValuePtr*/
		*ReadValuePtrCpy=ADCH;
		/*update last value will return from getLastResult function*/
		LastADCValue=*ReadValuePtrCpy;
		/*return ok*/
		return OK;
	}
}
#endif

#if ADC_RESOLUTION_MODE == ADC_10_BIT_MODE
u16 ADC_u16GetLastValue(void)
{
	return LastADCValue;
}
#elif ADC_RESOLUTION_MODE == ADC_8_BIT_MODE
u8 ADC_u16GetLastValue(void)
{
	return LastADCValue;
}
#endif
void ADC_voidEnableInterrupt(void)
{
	/*Enable ADC Interrupt*/
	SET_BIT(ADCSRA,3);

}
void ADC_voidDisableInterrupt(void)
{
	/*Disable ADC Interrupt*/
	CLR_BIT(ADCSRA,3);

}
void ADC_voidSetCallback(void (* funcptr)(void))
{
	ADCIntCallBack=funcptr;
}
void __vector_16 (void)__attribute__((signal,used));
void __vector_16 (void)
{
#if ADC_RESOLUTION_MODE == ADC_10_BIT_MODE
	LastADCValue=ADCHL;
#elif ADC_RESOLUTION_MODE == ADC_8_BIT_MODE
	LastADCValue=ADCH;
#endif
}
