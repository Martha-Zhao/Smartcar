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
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#ifndef __LED_H__
#define __LED_H__

//定义模块号
typedef enum
{
  LED1=1,
  LED2=2,
  LEDALL=4,//全部四个   
} LEDn_e;

typedef enum
{
  ON=0,  //亮
  OFF=1, //灭
  RVS=2, //反转  
}LEDs_e;


/*********************** UART功能函数 **************************/
//初始化
extern void LED_Init(void);
extern void LED_Ctrl(LEDn_e ledno, LEDs_e sta);
/********************************************************************/

#endif 
