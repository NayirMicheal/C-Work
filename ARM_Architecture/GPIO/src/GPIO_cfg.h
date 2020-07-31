/*
 * GPIO_cfg.h
 *
 *  Created on: 27 Apr 2018
 *      Author: Nayir
 */

#ifndef GPIO_CFG_H_
#define GPIO_CFG_H_


typedef enum
{
	ANALOG=0,
	FLOATING_INPUT=1,
	INPUT_WITH_PULL_UP_DOWN=2,
	GPO_PUSH_PULL=0,
	GPO_OPEN_DRAIN=1,
	AF_PUSH_PULL=2,
	AF_OPEN_DRAIN=3
}input_output_mode_t;

typedef enum
{
	INPUT_MODE=0,
	OUTPUT_MODE_10MHZ=1,
	OUTPUT_MODE_20MHZ=2,
	OUTPUT_MODE_50MHZ=3
}pin_mode_t;

typedef enum
{
	PULL_UP,
	PULL_DOWN,
	NON_PULL_UP_DOWN
}input_pull_t;
typedef struct
{
	input_output_mode_t IoMode;
	pin_mode_t pinMode;
	input_pull_t pulltype;
}pin_cfg_t;

extern pin_cfg_t portA_cfg [16];
extern pin_cfg_t portB_cfg [16];
extern pin_cfg_t portC_cfg [16];
#endif /* GPIO_CFG_H_ */
