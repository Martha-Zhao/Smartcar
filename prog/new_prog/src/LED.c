/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
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

20170422--测试OK
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#include "include.h"
/*******************************************************************************
Function Name : void LED_Init(void)
Engineer      : chiusir
Date          : 7-15-2017
Parameters    : NONE
Modifies      : NONE
Returns       : NONE
Notes         : LED所用GPIO初始化
Issues        : NONE
*******************************************************************************/
void LED_Init(void)
{
  GPIO_Init(PTC, 1,GPO,0);
  GPIO_Init(PTE,13,GPO,0);
}
/*******************************************************************************
Function Name : void LED_Ctrl(LEDn_e ledno, LEDs_e sta)
Engineer      : chiusir
Date          : 7-15-2017
Parameters    : LEDn_e ledno为灯的编号, LEDs_e sta灯的状态
Modifies      : NONE
Returns       : NONE
Notes         : NONE
Issues        : NONE
*******************************************************************************/
void LED_Ctrl(LEDn_e ledno, LEDs_e sta)
{
  switch(ledno) 
  {  
  case LED1:
    if(sta==ON)        GPIO_Ctrl(PTE,13,0);
    else if(sta==OFF) GPIO_Ctrl(PTE,13,1);
    else if(sta==RVS) GPIO_Reverse (PTE,13);
    break;    
  case LED2:
    if(sta==ON)        GPIO_Ctrl(PTC, 1,0);
    else if(sta==OFF) GPIO_Ctrl(PTC, 1,1);
    else if(sta==RVS) GPIO_Reverse (PTC, 1);
    break;
  case LEDALL:
    if(sta==ON) 
    {  
      GPIO_Ctrl(PTC,1 ,0);
      GPIO_Ctrl(PTE,13,0);
    }
    else if(sta==OFF)
    { 
      GPIO_Ctrl(PTC,1,1);
      GPIO_Ctrl(PTE,13,1);
    }
    else if(sta==RVS)
    {  
      GPIO_Reverse (PTE, 13); 
      GPIO_Reverse (PTC, 1);      
    }
    break;
  default:
    break;    
  }   
}