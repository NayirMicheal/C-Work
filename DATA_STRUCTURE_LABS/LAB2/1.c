#include<stdio.h>
#include<conio.h>
void swap(int * x,int * y);
void selection(int * arr,int size);
void main (void)
{
	int arr[10]={0};
	int i;
	clrscr();
	printf("please enter the array elements");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection(arr,10);
	for(i=0;i<10;i++)
	{
		printf("element %d is %d\n",i+1,arr[i]);
	}
	getch();
}
void selection(int * arr,int size)
{
	int i=0,j;
	for(i;i<size-1;i++)
		for(j=i+1;j<size;j++)
			if(arr[i]<arr[j])
				swap(&arr[i],&arr[j]);
}
void swap(int * a,int * b)
{
	(*a)=(*a)+(*b);
	(*b)=(*a)-(*b);
	(*a)=(*a)-(*b);
}