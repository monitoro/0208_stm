/*
 * ap.c
 *
 *  Created on: Feb 8, 2022
 *      Author: home
 */

#include "ap.h"
#include "led.h"
#include "uart.h"
//extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);



void apInit(void)
{
	uartOpen(_DEF_UART1, 57600);


}


void apMain(void)
{
	uint32_t pre_time;
	pre_time = millis();

	while(1)
	{
		if (millis()-pre_time >= 500)
		{
			pre_time = millis();
			ledToggle(_DEF_LED1);
		}

		if (uartAvailable(_DEF_UART1) > 0)
		{
			uint8_t rx_data;
			rx_data = uartRead(_DEF_UART1);

			uartPrintf(_DEF_UART1, "RxData : %c 0x%X\n", rx_data, rx_data);

		}

	}

}
