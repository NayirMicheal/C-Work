#include<stdio.h>
#include<conio.h>
void main (void)
{
int array[7];
int counter;
clrscr();
	for(counter=0;counter<7;counter++)
	{
	printf("Please Enter the %d value \n",counter+1);
	scanf("%d",&array[counter]);
	}

	for(counter=6;counter>=0;counter--)
	{
	printf("The %d value is %d\n", counter+1,array[counter]);
	}
	getch();
}