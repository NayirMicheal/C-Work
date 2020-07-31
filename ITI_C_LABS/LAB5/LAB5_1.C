#include<stdio.h>
#include<conio.h>
int fact(int number);
void main(void)
{
int num;
clrscr();
printf("please enter a number to calculate factorial ");
scanf("%d",&num);
printf("%d",fact(num));
getch();
}
int fact (int number)
{
if(number==1)
return 1;
return number * fact(number-1);
}