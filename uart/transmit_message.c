
#include <LPC17xx.H>
#include "uart.h"

void delay(unsigned long int x);

int main()
{
unsigned char msg[]="hello world";
unsigned char k;
SystemInit (); // MUST->system initialization
LPC_SC->PCONP|=0X00000000;// no need bydefault uart 0 is 1
LPC_PINCON->PINSEL0|=0X00000050;
LPC_SC->PCLKSEL0|=0X00000000;// for clk division(peripheral)
	
uart0_init();// for baud rate
for(k=0;msg[k]!='\0';k++)
	{
	
	LPC_UART0->THR=msg[k];// data to be communicated;
	while((LPC_UART0->LSR &0X0020)!=0X0020)// status reg=1 come out of loop
	{}

	}	
		while(1);// coz code too fast not able to virtually show

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

