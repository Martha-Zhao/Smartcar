/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
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
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#ifndef __LED_H__
#define __LED_H__

//����ģ���
typedef enum
{
  LED1=1,
  LED2=2,
  LEDALL=4,//ȫ���ĸ�   
} LEDn_e;

typedef enum
{
  ON=0,  //��
  OFF=1, //��
  RVS=2, //��ת  
}LEDs_e;


/*********************** UART���ܺ��� **************************/
//��ʼ��
extern void LED_Init(void);
extern void LED_Ctrl(LEDn_e ledno, LEDs_e sta);
/********************************************************************/

#endif 
