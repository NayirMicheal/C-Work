#include<stdio.h>
void main(void)
{
int number,sum=0;
clrscr();
printf("please enter number to be added\n");
do
{
scanf("%d",&number);
sum+=number;
}while(sum<100);
printf("you exceed the 100 by %d and the last sum is %d ",	sum-100,sum-number);
getch();
}
