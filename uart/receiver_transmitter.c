#include <LPC17xx.H>
#include "uart.h"

void delay(unsigned long int x);

int main()
{unsigned char k;
SystemInit (); // MUST->system initialization
LPC_PINCON->PINSEL0|=0X00000050;

	
uart0_init();// for baud rate
	
	while(1){
	while((LPC_UART0->LSR &0X0001)!=0X0001)// check status reg
	{}
	k=LPC_UART0->RBR;
	LPC_UART0->THR=k;
		
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

