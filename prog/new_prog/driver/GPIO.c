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
#include "GPIO.h"


GPIO_MemMapPtr GPIOX[5] = {PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR}; //�������ָ�����鱣�� GPIOX �ĵ�ַ
PORT_MemMapPtr PORTX[5] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};
//-------------------------------------------------------------------------*
//������: gpio_init                                                        *
//��  ��: ��ʼ��gpio                                                       *
//��  ��: port:�˿���                                                      *
//        index:ָ���˿�����                                               *
//        dir:���ŷ���,0=����,1=���                                       *
//        data:��ʼ״̬,0=�͵�ƽ,1=�ߵ�ƽ                                  *
//��  ��: ��                                                              *
//��  ��: GPIO_Init(PORTA, 17, 1,0);  PTA17���ų�ʼ��Ϊ�͵�ƽ             *
//-------------------------------------------------------------------------*
void GPIO_Init (GPIO_Type* port, int index, GPIO_CFG dir,int data)
{
  PORT_MemMapPtr p;
  switch((u32)port)
  {
  case 0x400FF000u:
    PCC->PCCn[PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK;
    p = PORTA;
    break;
  case 0x400FF040u:
    PCC->PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK;
    p = PORTB;
    break;
  case 0x400FF080u:
    PCC->PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK;
    p = PORTC;
    break;
  case 0x400FF0C0u:
    PCC->PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;
    p = PORTD;
    break;
  case 0x400FF100u:
    PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
    p = PORTE;
    break;
  default:
    break;
  }
  PORT_PCR_REG(p,index)=PORT_PCR_MUX(1);
  
  if(dir == 1)//output
  {
    GPIO_PDDR_REG(port) |= (1<<index);
    if(data == 1)//output
      GPIO_PDOR_REG(port) |= (1<<index);
    else
      GPIO_PDOR_REG(port) &= ~(1<<index);
  }
  
  else
    GPIO_PDDR_REG(port) &= ~(1<<index);
  
}

//-------------------------------------------------------------------------*
//������: gpio_ctrl                                                        *
//��  ��: ��������״̬                                                     *
//��  ��: port:�˿���                                                      *
//        index:ָ���˿�����                                               *
//        data: ״̬,0=�͵�ƽ,1=�ߵ�ƽ                                     *
//��  ��: ��                                                               *
//��  ��: gpio_ctrl (PORTA, 17,0);  PTA17���ų�����Ϊ�͵�ƽ                 *
//-------------------------------------------------------------------------*
void GPIO_Ctrl (GPIO_Type* port, int index, int data)
{
  if(data == 1)//output
    GPIO_PDOR_REG(port) |= (1<<index);
  else
    GPIO_PDOR_REG(port) &= ~(1<<index);
}

//-----------------------------------------------------------------------*
//������: gpio_reverse                                                   *
//��  ��: �ı�����״̬                                                   *
//��  ��: port:�˿���;                                                   *
//        index:ָ���˿�����                                             *
//��  ��: ��                                                             *
//��  ��: gpio_reverse (PORTA, 17);  PTA17���������ƽ��ת                *
//-----------------------------------------------------------------------*
void GPIO_Reverse (GPIO_Type* port, int index)
{
  GPIO_PDOR_REG(port) ^= (1<<index);
}
//-----------------------------------------------------------------------*
//������: u8 GPIO_Get(PTXn_e ptxn)                                       *
//��  ��: ��ȡ����״̬                                                   *
//��  ��: ptxn�˿������ţ�����PTA17                                      *
//��  ��: ��0,��1                                                        *
//��  ��: x=GPIO_Get(PTA17);  ��ȡPTA17���ŵ�ƽ�ߵ�                      *
//-----------------------------------------------------------------------*
u8 GPIO_Get(PTXn_e ptxn)
{
  return ((GPIO_PDIR_REG(GPIOX_BASE(ptxn)) >> PTn(ptxn )) & 0x01);        // ��ȡ GPIO PDIR ptxn ״̬������ȡ�ܽ������ƽ
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************************************************************************************************
gpio�ⲿ�жϺ���
**************************************************************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------*
//������: Exti_init
//��  ��: �ⲿGPIO�жϳ�ʼ��
//��  ��: portx:�˿�����PTA,PTB,PTC,PTD,PTE��
//          n  :ָ���˿����źţ�0~31��
//     exti_cfg:�жϴ�����ʽ  �磺 rising_down //�����ش������ڲ�����
//��  ��: ��
//��  ��: EXTI_Init(PTC, 16, falling);
//-----------------------------------------------------------------------*
void EXTI_Init(GPIO_Type * port, u8 n, exti_cfg cfg)
{
  // SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK << portx);    //����PORTx�˿�
  IRQn_Type IRQ;
  PORT_MemMapPtr p;
  switch((u32)port)
  {
  case 0x400FF000u:
    p = PORTA_BASE_PTR;
    IRQ=PORTA_IRQn;
    break;
  case 0x400FF040u:
    p = PORTB_BASE_PTR;
    IRQ=PORTB_IRQn;
    break;
  case 0x400FF080u:
    p = PORTC_BASE_PTR;
    IRQ=PORTC_IRQn;
    break;
  case 0x400FF0C0u:
    p = PORTD_BASE_PTR;
    IRQ=PORTD_IRQn;
    break;
  case 0x400FF100u:
    p = PORTE_BASE_PTR;
    IRQ=PORTE_IRQn;
    break;
  default:
    break;
  }
  
  PORT_PCR_REG(p, n) = PORT_PCR_MUX(1) |PORT_PCR_IRQC(cfg) ; // ����GPIO , ȷ������ģʽ ,������������������
  NVIC_EnableIRQ(IRQ);                         //ʹ��PORT�жϣ�PORTA��ISR�жϺ�Ϊ87
}

void PORTA_IRQHandler()
{
  int n;
  n=0;
  if((PORTA_ISFR & (1<<n)))
  {
    PORTA_ISFR |= (1<<n);
    // �û���������ж��ڳ��� 
  }
  n=1;
  if((PORTA_ISFR & (1<<n)))
  {
    PORTA_ISFR |= (1<<n);
    // �û���������ж��ڳ��� 
  }
}


void PORTB_IRQHandler()
{
  int n;
  n=20;
  if((PORTB_ISFR & (1<<n)))
  {
    PORTB_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
    GPIO_Reverse (PTA, 17);
  }
  n=1;
  if((PORTB_ISFR & (1<<n)))
  {
    PORTB_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
  }
}

void PORTC_IRQHandler()
{
  int n;
  n=0;
  if((PORTC_ISFR & (1<<n)))
  {
    PORTC_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
    //GPIO_Ctrl(PTC,1,1);
  }
  
}

void PORTD_IRQHandler()
{
  int n;
  n=0;
  if((PORTD_ISFR & (1<<n)))
  {
    PORTD_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
  }
  n=8;
  if((PORTD_ISFR & (1<<n)))
  {
    PORTD_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
    GPIO_Ctrl(PTC,1,1);
  }
}

void PORTE_IRQHandler()
{
  int n;
  n=25;
  if((PORTE_ISFR & (1<<n)))
  {
    PORTE_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
    
  }
  n=1;
  if((PORTE_ISFR & (1<<n)))
  {
    PORTE_ISFR |= (1<<n);
    /* �û���������ж��ڳ��� */
  }
  
}


