#include <LPC17xx.H>
#include "uart0.h"
#include <string.h>
#include "compare.h"

void delay(unsigned long int x);

int main()
{
    int i;
    char m[13];
int a,b;
char str1[]="09008206C944";
char str2[]="840085A99038";
    SystemInit (); // MUST
    LPC_SC->PCONP|=0X00008000;
    LPC_PINCON-> PINSEL0 |= 0X00000050;
    uart_init(); // we have set the baud rate
    LPC_GPIO1->FIOMASK3=0XDF;
    LPC_GPIO1->FIODIR3=0X20;
    while(1){
       
for(i=0;i<12;i++)
{
while((LPC_UART0->LSR&0X01)!=0X01)
        {
        }
        m[i]=LPC_UART0->RBR;

}
m[12]='\0';

a=strcompare(str1,m);
b=strcompare(str2,m);
    if(a==0 && b==0)
        {
LPC_GPIO1->FIOSET3=0X20;
        }
        else
        {
            LPC_GPIO1->FIOCLR3=0X20;
        }  
               
        }
   
}


void delay(unsigned long int ms)
{
unsigned long int i;
for (i=0; i<ms; i++)
{
}
}
