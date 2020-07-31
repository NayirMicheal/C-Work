/*
 * GPIO.h
 *
 *  Created on: 27 Apr 2018
 *      Author: Nayir
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "GPIO_cfg.h"
typedef enum
{
	portA,
	portB,
	portC
}ports_t;

typedef enum
{
	HIGH,
	LOW
}Level_t;
void GPIO_initialize(void);
Level_t GPIO_readPin(ports_t port,uint8_t pinNumber);
void GPIO_writePin(ports_t port,uint8_t pinNumber,Level_t level);
#endif /* GPIO_H_ */
