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

#ifndef __WDOG_H__
#define __WDOG_H__

void WDOG_Disable (void);
void WDOG_Unlock(void);
void WDOG_Enable_Once(uint16_t TM); 
//Configure for reconfigurable
void WDOG_Enable_Reconfig(uint16_t TM);
#endif 
