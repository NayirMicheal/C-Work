/*
 * TIM_priv.h
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */

#ifndef TIM_PRIV_H_
#define TIM_PRIV_H_

#include "TIM_config.h"

#define TIM_u8_NO_DIV_MASK      1
#define TIM_u8_DIV_BY_8_MASK    2
#define TIM_u8_DIV_BY_64_MASK   3
#define TIM_u8_DIV_BY_256_MASK  4
#define TIM_u8_DIV_BY_1024_MASK 5

#define TIM_u8_NORMAL_MODE      0
#define TIM_u8_CTC_MODE         1
#define TIM_u8_FAST_PWM         2
#define TIM_u8_PHASE_CORRECT    3

#define TIM_u8_CTC_NORMAL 0
#define TIM_u8_CTC_TOGGLE 1
#define TIM_u8_CTC_CLEAR  2
#define TIM_u8_CTC_SET    3

#define TIM_u8_FAST_PWM_NORMAL    0
#define TIM_u8_FAST_PWM_REVERSE   1
#define TIM_u8_FAST_PWM_CLEAR_OC0 2
#define TIM_u8_FAST_PWM_SET_OC0   3

#define TIM_u8_PHASE_CORRECT_NORMAL    0
#define TIM_u8_PHASE_CORRECT_REVERSE   1
#define TIM_u8_PHASE_CORRECT_CLEAR_OC0 2
#define TIM_u8_PHASE_CORRECT_SET_OC0   3
#endif /* TIM_PRIV_H_ */
