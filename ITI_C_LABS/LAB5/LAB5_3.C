#include<stdio.h>
#include<conio.h>
int pow(int number,int power);
void main(void)
{
int number,power;
clrscr();
printf("please enter a base number ");
scanf("%d",&number);
printf("\nplease enter a power number ");
scanf("%d",&power);
printf("\nthe result is %d",pow(number,power));
getch();
}
int pow(int number,int power)
{
if(power==0)
return 1;
return number * pow(number,power-1);
}