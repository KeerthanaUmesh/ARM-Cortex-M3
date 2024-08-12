// without uart header
#include<LPC17xx.H>

void delay(unsigned long int x);
void uart0_init(void);
int main()
{
SystemInit (); // MUST->system initialization
LPC_SC->PCONP|=0X00000000;// no need bydefault uart 0 is 1
LPC_PINCON->PINSEL0|=0X00000050;
LPC_SC->PCLKSEL0|=0X00000000;// for clk division(peripheral)
	
uart0_init();// for baud rate

	
	LPC_UART0->THR='A';// data to be communicated;
	while((LPC_UART0->LSR &0X0020)!=0X0020)// status reg=1 come out of loop
	{}

		
		while(1);

}


void uart0_init(void)
{//automatically baud rate calxulated with these vcalues
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
