/*
 * uart.c
 *
 *  Created on: 2022. 2. 10.
 *      Author: home
 */


#include "uart.h"

//static은 여기서만 쓰는 변수 선언.. 이름이 같아도 된다. 그래서 쓰는거구나..
static bool is_open[UART_MAX_CH];



//버퍼를 관리하는 함수 만들기
//현재 버퍼에 들어온 데이터 갯수
extern uint32_t cdc_Available(void);

//데이터를 읽어가는 함수
extern uint8_t  cdcRead(void);


//버퍼에 데이터를 쓰는 함수
extern void     cdcDataIn(uint8_t rx_data);


//usb 통신으로 데이터를 보내는 함수
extern uint32_t cdcWrite(uint8_t *p_data, uint32_t length);


extern uint32_t cdcGetBaud(void);



bool uartInit(void)
{
	for (int i=0; i<UART_MAX_CH; i++)
	{
		is_open[i] = false;

	}
	return true;
}

bool uartOpen(uint8_t ch, uint32_t baud)
{
	bool ret = false;
	switch(ch)
		{
			case _DEF_UART1:
				is_open[ch] = true;
				ret = true;
				break;

		}
	return ret;
}

uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdc_Available();
			break;
	}
	return ret;

}

uint8_t uartRead(uint8_t ch)
{
	uint8_t ret;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcRead();
			break;
	}
	return ret;
}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
	uint32_t ret = 0;
	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcWrite(p_data, length);
			break;

	}
	return ret;
}

uint32_t uartPrintf(uint8_t ch, char *fmt, ...)
//스트링이 어떤 길이가 들어올지 모르니 가변인자 fmt 사용함.
{
//	가변인자 초기화
	char buf[256];
	va_list args;
	int len;
	uint32_t ret;

	va_start(args, fmt);
//	버퍼에 가변인자 스트링을 받아서 vsnprintf 함수에서 처리
	len = vsnprintf(buf, 256, fmt, args);

//	uartWrite(ch, buf, len);
	ret = uartWrite(ch, (uint8_t *)buf, len);
	va_end(args);

	return ret;

}

uint32_t uartGetBaud(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_UART1:
			ret = cdcGetBaud();
			break;

	}

	return ret;
}

