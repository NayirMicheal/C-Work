/*
 * GIE.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_reg.h"
#include "GIE_priv.h"
#include "GIE_config.h"
#include "GIE_int.h"
void GIE_EnableGlobalInterrupt(void)
{
	SET_BIT(SREG,7);
}

void GIE_DisableGlobalInterrupt(void)
{
	CLR_BIT(SREG,7);
}
