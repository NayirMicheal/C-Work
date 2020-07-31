#include<stdio.h>
#include<conio.h>
void main (void)
{
	int num;
	int arr[10]={0};
	int i,found=0;
	clrscr();
	for(i=0;i<10;i++)
	{
		printf("Enter the %d array item ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter a number to search ");
	scanf("%d",&num);
	for(i=0;i<10&&!found;i++)
	{
		if(arr[i]==num)
			found=1;
	}
	if(found)
	{
		printf("\nThe number found at index %d",i);
	}
	else
	{
		printf("\nnot found");
	}
	getch();
}