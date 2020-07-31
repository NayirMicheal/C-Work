/*
 * TIM_config.h
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */
#ifdef TIM_INT_H_

#ifndef TIM_PUB_CONFIG_H_
#define TIM_PUB_CONFIG_H_
/****************Public configuration****************/
/*Description: prescaler*/

/*Range     :TIM_u8_NO_DIVISON
            :TIM_u8_DIV_BY_8
            :TIM_u8_DIV_BY_64
            :TIM_u8_DIV_BY_256
            :TIM_u8_DIV_BY_1024*/

#define TIM_u16_PRESCALER  TIM_u16_DIV_BY_1024
#endif /*TIM_PUB_CONFIG_H_*/
#endif /*TIM_INT_H_*/

#ifdef TIM_PRIV_H_

#ifndef TIM_PRIV_CONFIG_H_
#define TIM_PRIV_CONFIG_H_

/****************Private configuration****************/
/*Description: Timer initial value*/
#define TIM_u8_INIT_VALUE 154
#define TIM_u8_OCR0_VALUE 105
#define TIM_u8_MODE TIM_u8_CTC_MODE

#endif /* TIM_PRIV_CONFIG_H_ */
#endif /*TIM_PRIV_H_*/
