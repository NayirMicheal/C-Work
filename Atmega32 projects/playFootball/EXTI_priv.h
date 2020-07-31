/*
 * EXTI_priv.h
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

static void (*EXTI_voidCallback_INT0) (void);
static void (*EXTI_voidCallback_INT1) (void);

#define EXTI_ON 1
#define EXTI_OFF 0
#endif /* EXTI_PRIV_H_ */
