#include<LPC17xx.H>

void delay(unsigned long int x);

int main()
{
	unsigned int c;
	c=0;
SystemInit (); // MUST
LPC_SC->PCONP=0X00008000;
LPC_GPIO0->FIOMASK1=0XF0;
LPC_GPIO0->FIODIR1=0X0F;
while(1)    //superloop
 {
	 

LPC_GPIO0->FIOSET1=c;
delay(0X1000);
LPC_GPIO0->FIOCLR1=c;
delay(0X1000);
	 c=c+1;
	 if(c>16)
		 c=0;

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
