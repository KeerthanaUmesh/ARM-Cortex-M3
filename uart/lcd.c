#include "LPC17xx.h"  // Include the header file for the specific microcontroller

void delay(unsigned long int ms);

int main() {
		unsigned long int array[7]={0X38, 0X0E, 0X06, 0X01, 0X80};
		int k;

    SystemInit();  
		LPC_GPIO0->FIOMASKH=0xE01F;  // for lcd data pins
    LPC_GPIO0->FIODIRH=0x1FE0;// for lcd data pins
		
	  LPC_GPIO0-> FIOMASK2=0X1F;
		LPC_GPIO0-> FIOMASK3=0XE0;
		LPC_GPIO0-> FIODIRH=0X1FE0;
		
		LPC_GPIO2-> FIOMASK1=0XC7;
		LPC_GPIO2-> FIODIR1=0X38;
		
		LPC_GPIO2-> FIOCLR1=0X18;
	
    for(k=0; k<5; k++)
		{
			LPC_GPIO0->FIOPIN=array[k]<<21; // pin 21 to 28 is data 7:0 in microcontroller that is why we are shifting it by 21 in order to store the data there.
			LPC_GPIO2->FIOSET1=0X20;
			delay(0X10000);
			LPC_GPIO2->FIOCLR1=0X20;
			
		}

}

void delay(unsigned long int ms)
{
unsigned long int i,j;
for (i=0; i<ms; i++)
{
	for (j=0; j<114; j++)
	{
	}
}
}

