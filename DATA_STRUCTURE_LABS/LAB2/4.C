#include<stdio.h>
#include<conio.h>
void merge(int * a,int *L,int leftcount,int* R,int rightcount);
void mergesort(int * a,int size);
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
	mergesort(arr,10);
	for(i=0;i<10;i++)
	{
		printf("element %d is %d\n",i+1,arr[i]);
	}
	getch();
}
void merge(int * A,int *L,int leftcount,int* R,int rightcount)
{
	int i=0,j=0,k=0;
	while(i<leftcount && j<rightcount)
	{
		if(L[i]<R[j])
			A[k]=L[i++];
		else
			A[k]=R[j++];
		k++;
	}
	while(i<leftcount)
		A[k++]=L[i++];
	while(j<rightcount)
		A[k++]=R[j++];
}
void mergesort(int * A,int size)
{
	int mid,*L,*R,i;
	if(size<2) return;
	mid=size/2;
	L=(int *)malloc(sizeof(int)*mid);
	R=(int *)malloc(sizeof(int)*(size-mid));
	for(i=0;i<mid;i++)
		L[i]=A[i];
	for(i=mid;i<size;i++)
		R[i-mid]=A[i];
	mergesort(L,mid);
	mergesort(R,size-mid);
	merge(A,L,mid,R,size-mid);
	free(L);
	free(R);
	return;
}