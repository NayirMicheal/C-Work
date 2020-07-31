#include<stdio.h>
#include<conio.h>
void swap(int * x,int * y);
void BuBBle(int * arr,int size);
void main (void)
{
	int arr[10]={0};
	int i;
	clrscr();
	printf("please enter the array elements\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	BuBBle(arr,10);
	for(i=0;i<10;i++)
	{
		printf("element %d is %d\n",i+1,arr[i]);
	}
	getch();
}
void BuBBle(int * arr,int size)
{
	int sorted=0;
	int i;
	while(!sorted)
	{
	sorted=1;
	for(i=size-1;i>0;i--)
	if(arr[i]<arr[i-1])
	{
		swap(&arr[i],&arr[i-1]);
		sorted=0;
	}
	}
}
void swap(int * a,int * b)
{
	(*a)=(*a)+(*b);
	(*b)=(*a)-(*b);
	(*a)=(*a)-(*b);
}