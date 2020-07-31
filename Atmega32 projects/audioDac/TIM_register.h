/*
 * TIM_register.h
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */

#ifndef TIM_REGISTER_H_
#define TIM_REGISTER_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)
#define OCR0 *((volatile u8*)0x5C)
#endif /* TIM_REGISTER_H_ */
