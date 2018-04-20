/*************************************************************
【平    台】龙邱S32K智能车核心板V2
【编    写】CHIUSIR
【E-mail  】chiusir@163.com
【软件版本】V1.0
【最后更新】2017年04月22日
【相关信息参考下列地址】
【网    站】http://www.lqist.cn
【淘宝店铺】http://shop36265907.taobao.com
------------------------------------------------
【dev.env.】IAR7.8
【Target  】S32K144
【Crystal 】  8.000Mhz
【busclock】 80.000MHz
【pllclock】160.000MHz
*************************************************************/
#ifndef INCLUDE_H_
#define INCLUDE_H_
    //////////////////////////////////////////
    // 通用头文件
    #include <stdio.h>                       //printf
    #include <string.h>                      //memcpy
    #include <stdlib.h>                      //malloc    
    #include <stdint.h>    
    #include <time.h>                        //使用当前时钟做种子    
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
    //#include "wdog.h"	//包含wdog.h头文件
    //////////////////////////////////////////
    // 外部设备及自定义功能驱动的头文件
    #include "LED.h"
//    #include "KEY.h"
//    #include "Algorithm.h"
//    #include "LQ12864.h"
//    #include "LQ9AX.h"    
//    #include "LQnRF24L01.h"


#endif
































