/*************************************************************
��ƽ    ̨������S32K���ܳ����İ�V2
����    д��CHIUSIR
��E-mail  ��chiusir@163.com
������汾��V1.0
�������¡�2017��04��22��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://shop36265907.taobao.com
------------------------------------------------
��dev.env.��IAR7.8
��Target  ��S32K144
��Crystal ��  8.000Mhz
��busclock�� 80.000MHz
��pllclock��160.000MHz
*************************************************************/
#ifndef INCLUDE_H_
#define INCLUDE_H_
    //////////////////////////////////////////
    // ͨ��ͷ�ļ�
    #include <stdio.h>                       //printf
    #include <string.h>                      //memcpy
    #include <stdlib.h>                      //malloc    
    #include <stdint.h>    
    #include <time.h>                        //ʹ�õ�ǰʱ��������    
    #include "S32K144.h"
    #include "common.h"
    //////////////////////////////////////////
    #include "GPIO.h"
    //#include "FTM.h"
    //#include "UART.h"
    //#include "ADC.h"
    #include "SPLL.h"   
   //#include "PIT.h"
    #include "I2C.h"
    //#include "FlexIO_I2C.h"
    //#include "SPI.h"
    //#include "DMA.h"
    //#include "LPTMR.h"
    //#include "FLASH.h"
    //#include "RTC.h"
    //#include "LPSPI.h"
    #include "vectors.h" 
    //#include "wdog.h"	//����wdog.hͷ�ļ�
    //////////////////////////////////////////
    // �ⲿ�豸���Զ��幦��������ͷ�ļ�
    #include "LED.h"
//    #include "KEY.h"
//    #include "Algorithm.h"
//    #include "LQ12864.h"
//    #include "LQ9AX.h"    
//    #include "LQnRF24L01.h"


#endif
































