#include <lpc17xx.h>
#include "uart.h"

void delay(unsigned long int ms);
void gsm_send();
void gsm_init();



int main()
{
	unsigned char x;
	SystemInit (); // MUST
	LPC_PINCON-> PINSEL0 |= 0X00000050;
	uart0_init(); // we have set the baud rate

//read sensor status

	gsm_init();
	gsm_send();

	
	

}


void gsm_init()
{
	int k;
	unsigned char cmd1[]="AT\r\n";
	unsigned char cmd2[]="AT+CREG?\r\n";
	unsigned char cmd3[]="AT+CMGF=1\r\n";
	
	for(k=0;cmd1[k]!='\0';k++)
	{
		LPC_UART0-> THR=cmd1[k]; // loads ASCII value of A into the transmit buffer
		
		while((LPC_UART0->LSR&0X0020)!=0X0020)
		{
		}
		delay(10);
		
	}
	for(k=0;cmd2[k]!='\0';k++)
	{
		LPC_UART0-> THR=cmd2[k]; // loads ASCII value of A into the transmit buffer
		
		while((LPC_UART0->LSR&0X0020)!=0X0020)
		{
		}
		delay(10);
		
	}
	for(k=0;cmd3[k]!='\0';k++)
	{
		LPC_UART0-> THR=cmd3[k]; // loads ASCII value of A into the transmit buffer
		
		while((LPC_UART0->LSR&0X0020)!=0X0020)
		{
		}
		delay(10);
		
	}
	
	
}

void gsm_send()
{
	int k;
	unsigned char cmd4[]="AT+CMGS=\"xxxxxxxxxx\"\r\n";// enter your mobile number here
	unsigned char cmd5[]=" DANGER !!! INTRUDER !!!";

	
	for(k=0;cmd4[k]!='\0';k++)
	{
		LPC_UART0-> THR=cmd4[k]; // loads ASCII value of A into the transmit buffer
		
		while((LPC_UART0->LSR&0X0020)!=0X0020)
		{
		}
		delay(0X10);
		
	}
	for(k=0;cmd5[k]!='\0';k++)
	{
		LPC_UART0-> THR=cmd5[k]; // loads ASCII value of A into the transmit buffer
		
		while((LPC_UART0->LSR&0X0020)!=0X0020)
		{
		}
		delay(0X10);
		
	}
	LPC_UART0-> THR=0X1A;
	while((LPC_UART0->LSR&0X0020)!=0X0020)
		{
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
