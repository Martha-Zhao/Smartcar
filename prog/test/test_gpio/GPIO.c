/*
 * GPIO.c
 *
 *  Created on: 2018Äê4ÔÂ23ÈÕ
 *      Author: ZZY
 */

#include "S32K144.h"
#include "GPIO.h"

// LED1  PTC1
// LED2  PTE13

#define LED1_MASK  PCC_PORTC_INDEX
#define LED2_MASK  PCC_PORTE_INDEX

#define LED1_PORT  PORTC
#define LED2_PORT  PORTE

#define LED1_PT  PTC
#define LED2_PT  PTE

#define LED1_INDEX  1
#define LED2_INDEX  13

void GPIO_Init()
{
    PCC-> PCCn[LED1_MASK] = PCC_PCCn_CGC_MASK;  //Enable clock for PTC
	//PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
    PCC-> PCCn[LED2_MASK] = PCC_PCCn_CGC_MASK;  //Enable clock for PTE

    LED1_PT->PDDR |= 1 << LED1_INDEX; //PTC1 OUTPUT
    LED2_PT->PDDR |= 1 << LED2_INDEX;//PTE13 OUTPUT

    LED1_PORT -> PCR[LED1_INDEX] =  0X00000100; //PTC1 GPIO
    LED2_PORT -> PCR[LED2_INDEX] = 0X00000100; //PTE13 GPIO

    LED1_PT->PSOR = 1 << LED1_INDEX; //PTC1 = 1
    LED2_PT->PSOR = 1 << LED2_INDEX; // PTE13 = 1

}

void GPIO_Reverse(LED_n LED_NUM)
{
    switch (LED_NUM)
    {
    case LED1:
        LED1_PT->PTOR = 1 << LED1_INDEX;
        break;
    case LED2:
        LED2_PT->PSOR = 1 << LED2_INDEX;
        break;
    default :
        break;
    }
}


