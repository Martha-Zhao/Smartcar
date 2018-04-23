/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "clocks_and_modes.h"
#include "GPIO.h"

void delay (int t)
{
	int i = 1000, j = 1000;
	for (;t > 0 ;t--)
	{
		for (i = 1000; i > 0 ;i--)
		{
			for (j = 1000; j > 0 ;j--)
			{

			}
		}
	}
}

int main()
{
	GPIO_Init();

	while (1)
	{
		GPIO_Reverse(LED1);
		delay(1000);
	}

	return 0;

}
