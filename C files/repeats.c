#include<stdio.h>
int repeat(int n,int * array,int num)
{
	int max;
	int temp_max=1;
	int i=1;
	for(i;i<n;i++)
	{
		max=1;
		if(array[i-1]==num)
			while(array[i-1]==array[i]){
			max++;
			i++;
			}
			
		if(max>temp_max)
			temp_max=max;
	}
	return temp_max;
}

void main(void)
{
	int i=0;
 int arr[20]={6,6,6,6,6,6,6,7,7,7,15,15,6,6,5,5,5,6,6,6};
  printf("%d \n",repeat(20,arr,6));
  
}