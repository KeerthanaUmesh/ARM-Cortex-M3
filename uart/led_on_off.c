// press 1 led on and press 0 led off
// using uart 0
#include <LPC17xx.H>
#include "uart.h"

void delay(unsigned long int x);

int main()
{unsigned char k;
SystemInit (); // MUST->system initialization
LPC_SC->PCONP|=0X00008000;
LPC_PINCON->PINSEL0|=0X00000050;
LPC_GPIO1->FIOMASK3=0XDF;
LPC_GPIO1->FIODIR3=0X20;

	
uart0_init();// for baud rate
	
	while(1){
	while((LPC_UART0->LSR &0X0001)!=0X0001)// status reg=1 come out of loop
	{}
	k=LPC_UART0->RBR;
		if(k=='1')
			LPC_GPIO1->FIOSET3=0X20;
		else if(k=='0')
			LPC_GPIO1->FIOCLR3=0X20;
	
		
	}
	

}
	
	
void delay(unsigned long int x)
{
unsigned int i;
unsigned int j;
for(i=0;i<x;i++)
{
for(j=0;j<114;j++);
}
}

