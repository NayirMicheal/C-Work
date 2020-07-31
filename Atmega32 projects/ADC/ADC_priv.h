/*
 * ADC_priv.h
 *
 *  Created on: 16 Apr 2018
 *      Author: Nayir
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define ADC_External_VREF     0
#define ADC_VCC_VREF		  1
#define ADC_INTERNAL_VREF     2


#define ADC_PRESCALER2        1
#define ADC_PRESCALER4        2
#define ADC_PRESCALER8        3
#define ADC_PRESCALER16       4
#define ADC_PRESCALER32       5
#define ADC_PRESCALER64       6
#define ADC_PRESCALER128      7

#define ADC_8_BIT_MODE         0
#define ADC_10_BIT_MODE        1


#define FREE_RUNNING_MODE     0
#define ANALOG_COMPARTOR      1
#define EXT_INT0              2
#define TIMER0_CMPMATCH       3
#define TIMER0_OVF            4
#define TIMER1_CMPMATCH_B     5
#define TIMER1_OVF            6
#define TIMER1_ICU            7
#define NOT_USED              8
typedef enum
{
	NOK=0,
	OK
}Status_t;
#endif /* ADC_PRIV_H_ */
