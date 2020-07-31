/*
 * GPIO_cfg.c
 *
 *  Created on: 27 Apr 2018
 *      Author: Nayir
 */
#include <stdio.h>
#include "GPIO_cfg.h"

pin_cfg_t portA_cfg [16]={
		{INPUT_WITH_PULL_UP_DOWN,INPUT_MODE,PULL_UP},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN}
};

pin_cfg_t portB_cfg [16]={
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN}
};

pin_cfg_t portC_cfg [16]={
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN},
		{GPO_PUSH_PULL,OUTPUT_MODE_50MHZ,NON_PULL_UP_DOWN}
};
