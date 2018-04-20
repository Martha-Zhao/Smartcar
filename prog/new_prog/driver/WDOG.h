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

#ifndef __WDOG_H__
#define __WDOG_H__

void WDOG_Disable (void);
void WDOG_Unlock(void);
void WDOG_Enable_Once(uint16_t TM); 
//Configure for reconfigurable
void WDOG_Enable_Reconfig(uint16_t TM);
#endif 
