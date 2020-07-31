/*
 * ADC_int.h
 *
 *  Created on: 16 Apr 2018
 *      Author: Nayir
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#define ADC0                  0
#define ADC1                  1
#define ADC2                  2
#define ADC3                  3
#define ADC4                  4
#define ADC5                  5
#define ADC6                  6
#define ADC7                  7
#define ADC0_DIFF_ADC0        8
#define ADC0_DIFF_ADC1        9

void ADC_voidInit(void);
u8 ADC_voidStartConversion(u8 channelIdCpy,u16 * ReadValuePtrCpy);
#if ADC_RESOLUTION_MODE == ADC_10_BIT_MODE
u16 ADC_u16GetLastValue(void);
#elif ADC_RESOLUTION_MODE == ADC_8_BIT_MODE
u8 ADC_u16GetLastValue(void);
#endif
void ADC_voidEnableInterrupt(void);
void ADC_voidDisableInterrupt(void);
void ADC_voidSetCallback(void (* funcptr)(void));
#endif /* ADC_INT_H_ */
