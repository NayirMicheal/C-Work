/*
 * main.c
 *
 *  Created on: 2 May 2018
 *      Author: Nayir
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SPI_int.h"
#include "GIE_int.h"
#include "GLCD.h"
#include "DELAY.h"
#include "image.h"
void main(void)
{
	DIO_voidInitialize();
	SPI_init();
	GLCD_init();
	GLCD_updateGlcd(Array);
	while(1)
	{
	}
}

