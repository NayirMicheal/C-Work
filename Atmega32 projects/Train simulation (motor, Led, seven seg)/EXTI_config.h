/*
 * EXTI_config.h
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

#define EXTI_ON 1
#define EXTI_OFF 0

#define EXTI_MODE_LOW_LEVEL 0
#define EXTI_MODE_LOGICAL_CHANGE 1
#define EXTI_MODE_FALLING_EDGE 2
#define EXTI_MODE_RAISING_EDGE 3

#define EXTI_INT0_MODE EXTI_MODE_FALLING_EDGE
#define EXTI_INT1_MODE EXTI_MODE_LOGICAL_CHANGE
#define EXTI_INT2_MODE EXTI_MODE_FALLING_EDGE

#define EXTI_INT0_ENABLE EXTI_ON
#define EXTI_INT1_ENABLE EXTI_OFF
#define EXTI_INT2_ENABLE EXTI_OFF


#endif /* EXTI_CONFIG_H_ */
