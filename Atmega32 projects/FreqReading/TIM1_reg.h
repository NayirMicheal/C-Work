/*
 * TIM1_reg.h
 *
 *  Created on: 28 Mar 2018
 *      Author: Nayir
 */

#ifndef TIM1_REG_H_
#define TIM1_REG_H_

#define TCCR1A *((u8*)0x4F)
#define TCCR1B *((u8*)0x4E)
#define TCNT1  *((u16*)0x4C)
#define TIMSK  *((u8*)0x59)
#define TIFR   *((u8*)0x58)

#endif /* TIM1_REG_H_ */
