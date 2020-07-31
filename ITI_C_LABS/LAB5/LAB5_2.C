#include<stdio.h>
#include<conio.h>
int fib(int num);
void main(void)
{
int number;
clrscr();
printf("please enter a number to calculate the fib series ");
scanf("%d",&number);
printf("%d",fib(number));
getch();
}
int fib(int num)
{
if(num==2 || num==1)
return 1;
return fib(num-1) + fib(num-2);
}