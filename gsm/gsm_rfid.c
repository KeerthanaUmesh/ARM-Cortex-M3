#include <LPC17xx.H>
#include "uart.h"
#include <string.h>
#include "compare.h"

void delay(unsigned long int x);
//void uart_init(void);
void gsm_send();
void gsm_init();

int main()
{
    int i;
    char m[13];
	char y[]="yes";
char n[]="no";
int a,b;
char str1[]="0900820A5CDD";
char str2[]="09008207109C";
    SystemInit (); // MUST
		LPC_SC->PCONP|=0X02008000;
    LPC_PINCON-> PINSEL0 |= 0X00000050;
		LPC_PINCON-> PINSEL9 |= 0X0F000000;
    uart0_init();
    uart3_init(); 	// we have set the baud rate
    LPC_GPIO1->FIOMASK3=0XDF;
    LPC_GPIO1->FIODIR3=0X20;
	
gsm_init();
    while(1){
       
for(i=0;i<12;i++)
{
while((LPC_UART3->LSR&0X01)!=0X01)
        {
        }
        m[i]=LPC_UART3->RBR;

}
m[12]='\0';

a=strcompare(str1,m);
//b=strcompare(str2,m);

    if(a==0)


        {
				LPC_GPIO1->FIOSET3=0X20;
				gsm_send();
        }
        else
        {
            LPC_GPIO1->FIOCLR3=0X20;
					for(i=0;n[i]!='\0';i++)
						{
							LPC_UART0->THR=n[i];
							while((LPC_UART0->LSR&0X20)!=0X20)
							{}
						}
        }  
               
        }


}


void delay(unsigned long int ms)
{
unsigned long int i,j;
for (i=0; i<ms; i++)
{
  for(j=0;j<114;j++);
}
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
