#include<LPC17xx.H>

void delay(unsigned long int x);

int main()
{
SystemInit (); // MUST
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK1=0XFE;
LPC_GPIO0->FIODIR1=0X01;
while(1)    //superloop
 {

LPC_GPIO0->FIOSET1=0X01; //MAKING THE BIT HIGH
delay(0X10000);
LPC_GPIO0->FIOCLR1=0X01;
delay(0X10000);
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
