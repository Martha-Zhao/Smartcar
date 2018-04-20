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
【busclock】 56.000MHz
【pllclock】112.000MHz
*************************************************************/
#ifndef __PLL_H__
#define __PLL_H__

extern uint32 core_clk_M;//单位MHZ
extern uint32 bus_clk_M;//单位MHZ

//PLL参数
typedef enum clk_option
{
    PLLUNULL ,   
    PLL100   = 100,
    PLL112   = 112,
    PLL160   = 160,//推荐使主频为160
    PLL180   = 180, 
    PLL184   = 184,  
    PLL188   = 188,
    PLLtest,
} clk_option;



/*********************** PLL功能函数 **************************/
void SPLL_Init(clk_option opt);
void PLL_Init(clk_option);     //锁相环初始化
void MCU_Init(void);

#endif
