#include <LPC17xx.H>

void delay(unsigned long int x);

int main()
{
unsigned long int data=0;
SystemInit (); 
	//test LED P0.8
LPC_GPIO0->FIOMASK1=0XFE;
LPC_GPIO0->FIODIR1=0X01;
	
//ADC initialize
	
LPC_SC->PCONP=0X00009000;
LPC_PINCON->PINSEL3=0XC0000000;// to choose 3rd alternate function
LPC_ADC->ADCR=0X00210220;
	
while(1)
{
	while((LPC_ADC->ADSTAT&0X00000020)!=0X00000020)
	{}
		data=(((LPC_ADC->ADDR5)&0X0000FFF0)>>4);
		
		if(data>0X7FF)
			LPC_GPIO0->FIOPIN1=0X00;
		else
			LPC_GPIO0->FIOPIN1=0X01;
			
			
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
