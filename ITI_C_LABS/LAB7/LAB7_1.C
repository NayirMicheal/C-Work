#include<stdio.h>
#include<conio.h>
void main(void)
{
int * arr;
int num;
int i,sum=0;
clrscr();
printf("plz enter array size ");
scanf("%d",&num);
arr=(int *)malloc(sizeof(int)*num);
for(i=0;i<num;i++)
	{
	printf("please enter the %d number ",i+1);
	scanf("%d",(arr+i));
	sum+=arr[i];
	}
printf("\nthe sum is %d ",sum);
getch();
}