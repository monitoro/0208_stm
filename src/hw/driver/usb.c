/*
 * usb.c
 *
 *  Created on: 2022. 2. 14.
 *      Author: home
 */

#include "usb.h"
#include "usb_device.h"




bool usbInit(void)
{
	bool ret = true;

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */


  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12, GPIO_PIN_RESET);
  delay(100);
  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12, GPIO_PIN_SET);

  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


//  for (int i=0; i<LED_MAX_CH; i++)
//  {
//    GPIO_InitStruct.Pin = led_tbl[i].pin;
//    HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStruct);
//
//    ledOff(i);
//
//  }

  MX_USB_DEVICE_Init();
  return ret;
}
