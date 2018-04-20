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
#ifndef __PLL_H__
#define __PLL_H__

extern uint32 core_clk_M;//��λMHZ
extern uint32 bus_clk_M;//��λMHZ

//PLL����
typedef enum clk_option
{
    PLLUNULL ,   
    PLL100   = 100,
    PLL112   = 112,
    PLL160   = 160,//�Ƽ�ʹ��ƵΪ160
    PLL180   = 180, 
    PLL184   = 184,  
    PLL188   = 188,
    PLLtest,
} clk_option;



/*********************** PLL���ܺ��� **************************/
void SPLL_Init(clk_option opt);
void PLL_Init(clk_option);     //���໷��ʼ��
void MCU_Init(void);

#endif
