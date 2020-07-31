#include<stdio.h>
#include<conio.h>
void main (void)
{
	int num;
	int arr[10]={0};
	int i,found=0;
	int hi=9,lo=0,mid;
	clrscr();
	printf("Enter sorted array\n");
	for(i=0;i<10;i++)
	{
		printf("Enter the %d array item ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter a number to search ");
	scanf("%d",&num);
	for(;hi>lo&&!found;)
	{
		mid=(hi+lo)/2;
		if(arr[mid]>num)
			hi=mid-1;
		else if(arr[mid]<num)
			lo=mid+1;
		else
		found=1;
	}
	if(found)
	{
		printf("\nThe number found at index %d",mid+1);
	}
	else
	{
		printf("\nnot found");
	}
	getch();

}