#include <LPC17xx.h>

void uart0_init(void)
{//automatically baud rate calxulated with these vcalues
LPC_UART0->LCR = 0x83;
LPC_UART0->DLM=0X00;
LPC_UART0->DLL=0X75;
LPC_UART0->FDR=0X00000010;
LPC_UART0->LCR=0X03;

}

void uart3_init(void)
	{//automatically baud rate calxulated with these vcalues
LPC_UART3->LCR = 0x83;
LPC_UART3->DLM=0X00;
LPC_UART3->DLL=0X75;
LPC_UART3->FDR=0X00000010;
LPC_UART3->LCR=0X03;

}
