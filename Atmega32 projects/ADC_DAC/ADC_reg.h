/*
 * ADC_reg.h
 *
 *  Created on: 27 Mar 2018
 *      Author: Nayir
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX   *((volatile u8*) 0x27)
#define ADCSRA  *((volatile u8*) 0x26)
#define SFIOR   *((volatile u8*) 0x50)
#define ADCH    *((volatile u8*) 0x25)
#define ADCL    *((volatile u8*) 0x24)
#define ADCHL   *((volatile u16*) 0x24)
#endif /* ADC_REG_H_ */
