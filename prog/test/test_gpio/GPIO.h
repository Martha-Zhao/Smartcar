/*
 * GPIO.h
 *
 *  Created on: 2018Äê4ÔÂ23ÈÕ
 *      Author: ZZY
 */
#ifndef __GPIO_H__
#define __GPIO_H__

typedef enum
{
    LED1 = 1,
    LED2 = 2,
}LED_n;


void GPIO_Init (void);
void GPIO_Reverse (LED_n LED_NUM);
#endif

