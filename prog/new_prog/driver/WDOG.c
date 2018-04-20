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
��busclock�� 56.000MHz
��pllclock��112.000MHz
*************************************************************/
#include "include.h"
#include "wdog.h"	//����wdog.hͷ�ļ�

void WDOG_Disable (void) {
    //�����ж�
    //DisableInterrupts;
    WDOG->CNT=0xD928C520;            /* Unlock watchdog */
    WDOG->TOVAL=0x0000FFFF;          /* Maximum timeout value */
    WDOG->CS &= ~WDOG_CS_EN_MASK;    /* Disable watchdog */
    //�����ж�
    //EnableInterrupts;
}

void WDOG_Unlock(void)
{
    // ����: ���𵥲����Դ˳��򣬷��������CPU��λ
    //�����ж�
    //DisableInterrupts;		
    //д�����Ĵ���,��ɽ���
    WDOG->CNT=0xD928C520;     /* Unlock watchdog */
    //�����ж�
    //EnableInterrupts;		
}

void WDOG_Enable_Once(uint16_t TM) 
{
    /* ע��: ��Ҫ�������Դ˳���!!! �����������CPU��λ*/
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