#include<stdio.h>
int main(){
	int number;
	int digit;
	int temp;
	int count=0;
	printf("enter the number ");
	scanf("%d", &number);
	temp=number;
	while(temp!=0)
	{
		digit=temp%10;
		temp/=10;
		count++;
	}
	printf("%d",count);
	
}