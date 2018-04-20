
#include "include.h"
#include <stdio.h>  


void main( void )
{
  
  SPLL_Init(PLL160);
  //LED_Init();  
  while( 1 )
    {
      //LED_Ctrl(LED1, RVS);       //LED闪烁
      //LED_Ctrl(LED2, RVS);       //LED闪烁
      time_delay_ms(100); 
    }
}
