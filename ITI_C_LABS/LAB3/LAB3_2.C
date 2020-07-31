#include<stdio.h>
#include<conio.h>
void main(void)
{
signed int array[10];
signed int max=-32768;
signed int min=32767;
int counter;
clrscr();
	for(counter=0;counter<10;counter++)
	{
	printf("Please Enter the %d value \n",counter+1);
	scanf("%d",&array[counter]);
	}
	 min=array[0];
	 max=array[0];
		for(counter=1;counter<10;counter++)
	{
	if(array[counter]>max)
	max=array[counter];
	if(array[counter]<min)
	min=array[counter];
	}
	printf("\nThe max value is %d and the min value is %d",max,min);
	getch();
}