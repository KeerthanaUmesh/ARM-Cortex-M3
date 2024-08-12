#include<LPC17xx.H>

void delay(unsigned long int x);

int main()
{
	unsigned int k;
SystemInit (); // MUST
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK1=0XF0;
LPC_GPIO0->FIODIR1=0X0F;
for(k=0;k<10;k++)    //superloop
 {

LPC_GPIO0->FIOSET1=0X0F; 
delay(0X10000);
LPC_GPIO0->FIOCLR1=0X0F;
delay(0X10000);

 }
 while(1);
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
