/*
 * main.c
 *
 *  Created on: 6 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"DIO_int.h"
#include "SEVENSEG_int.h"
#include "DELAY.h"

int main (void)
{	DIO_voidInitialize();

	while(1)
	{
		SevenSeg_voidDisplayOnSeg(0b11111111);

	}
	return 0;
}
