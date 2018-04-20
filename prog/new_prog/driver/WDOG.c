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
#include "include.h"
#include "wdog.h"	//包含wdog.h头文件

void WDOG_Disable (void) {
    //关总中断
    //DisableInterrupts;
    WDOG->CNT=0xD928C520;            /* Unlock watchdog */
    WDOG->TOVAL=0x0000FFFF;          /* Maximum timeout value */
    WDOG->CS &= ~WDOG_CS_EN_MASK;    /* Disable watchdog */
    //开总中断
    //EnableInterrupts;
}

void WDOG_Unlock(void)
{
    // 警告: 请勿单步调试此程序，否则会引起CPU复位
    //关总中断
    //DisableInterrupts;		
    //写解锁寄存器,完成解锁
    WDOG->CNT=0xD928C520;     /* Unlock watchdog */
    //开总中断
    //EnableInterrupts;		
}

void WDOG_Enable_Once(uint16_t TM) 
{
    /* 注意: 不要单步调试此程序!!! ，否则会引起CPU复位*/
   // DisableInterrupts;                    // disable global interrupt
    WDOG->CNT = 0xD928C520;               //unlock watchdog
    while(WDOG->CS&WDOG_CS_ULK_MASK==0); //wait until registers are unlocked
    WDOG->TOVAL = TM;                     //set timeout value
    WDOG->CS = WDOG_CS_EN(1) | WDOG_CS_CLK(1) | WDOG_CS_INT(1) |
    WDOG_CS_WIN(0) | WDOG_CS_UPDATE(0);
    while(WDOG->CS&WDOG_CS_RCS_MASK==0); //wait until new configuration takes effect
    //EnableInterrupts;                     //enable global interrupt		
}
//Configure for reconfigurable
void WDOG_Enable_Reconfig(uint16_t TM) 
{
    //DisableInterrupts;                    //disable global interrupt
    WDOG->CNT = 0xD928C520;               //unlock watchdog
    while(WDOG->CS&WDOG_CS_ULK_MASK==0); //wait until registers are unlocked
    WDOG->TOVAL = TM;                     //set timeout value
    WDOG->CS = WDOG_CS_EN(1) | WDOG_CS_CLK(1) | WDOG_CS_INT(1) |
    WDOG_CS_WIN(0) | WDOG_CS_UPDATE(1);
    while(WDOG->CS&WDOG_CS_RCS_MASK==0); //wait until new configuration takes effect
   //EnableInterrupts;                     //enable global interrupt
}