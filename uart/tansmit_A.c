#include<LPC17xx.H>

void delay(unsigned long int x);
void uart0_init(void);
int main()
	
{unsigned int k;
SystemInit (); 
LPC_SC->PCONP|=0X00000000;
LPC_PINCON->PINSEL0|=0X00000050;
LPC_SC->PCLKSEL0|=0X00000000;
	
uart0_init();// for baud rate

for(k=0;k<10;k++){
LPC_UART0->THR='A';


	while((LPC_UART0->LSR &0X0020)!=0X0020)
	{}

	}	
		while(1);
}

void uart0_init(void)
{
LPC_UART0->LCR = 0x83;
LPC_UART0->DLM=0X00;
LPC_UART0->DLL=0X75;
LPC_UART0->FDR=0X00000010;
LPC_UART0->LCR=0X03;

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
