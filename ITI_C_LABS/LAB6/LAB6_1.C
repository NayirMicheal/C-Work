#include<stdio.h>
#include<conio.h>
void swap(int *,int *);
void main (void)
{
int num_a,num_b;
clrscr();
printf("plz enter the two numbers\n");
scanf("%d %d",&num_a,&num_b);
swap(&num_a,&num_b);
printf("num a is %d, num b is %d",num_a,num_b);
getch();
}
void swap(int * a,int * b)
{
int temp;
temp=*a;
*a=*b;
*b=temp;
}