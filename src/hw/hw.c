/*
 * hw.c
 *
 *  Created on: Feb 8, 2022
 *      Author: home
 */

#include "hw.h"


void hwInit(void)
{

	bspInit();
	rtcInit();

	resetInit();
	ledInit();
	usbInit();
	uartInit();

}

