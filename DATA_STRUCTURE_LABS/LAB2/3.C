#include<stdio.h>
#include<conio.h>
void merge(int * a,int low,int mid,int high);
void mergesort(int * a,int low,int high);
void main(void)
{
	int arr[10]={0};
	int i;
	clrscr();
	printf("please enter the array elements\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,9);
	for(i=0;i<10;i++)
	{
		printf("element %d is %d\n",i+1,arr[i]);
	}
	getch();
}
void mergesort(int * arr,int low,int high)
{
	if(low<high)
	{
	int	m=(low+high)/2;
		mergesort(arr,low,m);
		mergesort(arr,m+1,high);
		merge(arr,low,m,high);
	}
}
void merge(int* arr,int low,int mid,int high)
{
	int b[1000];
int i=low,j=mid+1,k=0;
while(i<=mid&&j<=high)
{
	if(arr[i]<arr[j])
		b[k++]=arr[i++];
	else
		b[k++]=arr[j++];
}	
while(i<=mid)
	b[k++]=arr[i++];
while(j<=mid)
	b[k++]=arr[j++];
k--;
while(k>=0)
{
	arr[low+k]=b[k];
	k--;
}
}