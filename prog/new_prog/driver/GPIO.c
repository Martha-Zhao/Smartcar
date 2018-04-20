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
#include "GPIO.h"


GPIO_MemMapPtr GPIOX[5] = {PTA_BASE_PTR, PTB_BASE_PTR, PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR}; //定义五个指针数组保存 GPIOX 的地址
PORT_MemMapPtr PORTX[5] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};
//-------------------------------------------------------------------------*
//函数名: gpio_init                                                        *
//功  能: 初始化gpio                                                       *
//参  数: port:端口名                                                      *
//        index:指定端口引脚                                               *
//        dir:引脚方向,0=输入,1=输出                                       *
//        data:初始状态,0=低电平,1=高电平                                  *
//返  回: 无                                                              *
//简  例: GPIO_Init(PORTA, 17, 1,0);  PTA17引脚初始化为低电平             *
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
//函数名: gpio_ctrl                                                        *
//功  能: 设置引脚状态                                                     *
//参  数: port:端口名                                                      *
//        index:指定端口引脚                                               *
//        data: 状态,0=低电平,1=高电平                                     *
//返  回: 无                                                               *
//简  例: gpio_ctrl (PORTA, 17,0);  PTA17引脚初设置为低电平                 *
//-------------------------------------------------------------------------*
void GPIO_Ctrl (GPIO_Type* port, int index, int data)
{
  if(data == 1)//output
    GPIO_PDOR_REG(port) |= (1<<index);
  else
    GPIO_PDOR_REG(port) &= ~(1<<index);
}

//-----------------------------------------------------------------------*
//函数名: gpio_reverse                                                   *
//功  能: 改变引脚状态                                                   *
//参  数: port:端口名;                                                   *
//        index:指定端口引脚                                             *
//返  回: 无                                                             *
//简  例: gpio_reverse (PORTA, 17);  PTA17引脚输出电平反转                *
//-----------------------------------------------------------------------*
void GPIO_Reverse (GPIO_Type* port, int index)
{
  GPIO_PDOR_REG(port) ^= (1<<index);
}
//-----------------------------------------------------------------------*
//函数名: u8 GPIO_Get(PTXn_e ptxn)                                       *
//功  能: 读取引脚状态                                                   *
//参  数: ptxn端口名引脚，比如PTA17                                      *
//返  回: 低0,高1                                                        *
//简  例: x=GPIO_Get(PTA17);  读取PTA17引脚电平高低                      *
//-----------------------------------------------------------------------*
u8 GPIO_Get(PTXn_e ptxn)
{
  return ((GPIO_PDIR_REG(GPIOX_BASE(ptxn)) >> PTn(ptxn )) & 0x01);        // 获取 GPIO PDIR ptxn 状态，即读取管脚输入电平
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************************************************************************************************
gpio外部中断函数
**************************************************************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------*
//函数名: Exti_init
//功  能: 外部GPIO中断初始化
//参  数: portx:端口名（PTA,PTB,PTC,PTD,PTE）
//          n  :指定端口引脚号（0~31）
//     exti_cfg:中断触发方式  如： rising_down //上升沿触发，内部下拉
//返  回: 无
//简  例: EXTI_Init(PTC, 16, falling);
//-----------------------------------------------------------------------*
void EXTI_Init(GPIO_Type * port, u8 n, exti_cfg cfg)
{
  // SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK << portx);    //开启PORTx端口
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
  
  PORT_PCR_REG(p, n) = PORT_PCR_MUX(1) |PORT_PCR_IRQC(cfg) ; // 复用GPIO , 确定触发模式 ,开启上拉或下拉电阻
  NVIC_EnableIRQ(IRQ);                         //使能PORT中断，PORTA的ISR中断号为87
}

void PORTA_IRQHandler()
{
  int n;
  n=0;
  if((PORTA_ISFR & (1<<n)))
  {
    PORTA_ISFR |= (1<<n);
    // 用户自行添加中断内程序 
  }
  n=1;
  if((PORTA_ISFR & (1<<n)))
  {
    PORTA_ISFR |= (1<<n);
    // 用户自行添加中断内程序 
  }
}


void PORTB_IRQHandler()
{
  int n;
  n=20;
  if((PORTB_ISFR & (1<<n)))
  {
    PORTB_ISFR |= (1<<n);
    /* 用户自行添加中断内程序 */
    GPIO_Reverse (PTA, 17);
  }
  n=1;
  if((PORTB_ISFR & (1<<n)))
  {
    PORTB_ISFR |= (1<<n);
    /* 用户自行添加中断内程序 */
  }
}

void PORTC_IRQHandler()
{
  int n;
  n=0;
  if((PORTC_ISFR & (1<<n)))
  {
    PORTC_ISFR |= (1<<n);
    /* 用户自行添加中断内程序 */
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
    /* 用户自行添加中断内程序 */
  }
  n=8;
  if((PORTD_ISFR & (1<<n)))
  {
    PORTD_ISFR |= (1<<n);
    /* 用户自行添加中断内程序 */
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
    /* 用户自行添加中断内程序 */
    
  }
  n=1;
  if((PORTE_ISFR & (1<<n)))
  {
    PORTE_ISFR |= (1<<n);
    /* 用户自行添加中断内程序 */
  }
  
}


