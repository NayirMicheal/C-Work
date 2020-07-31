#include<stdio.h>
int main(){
	int a,b;
	printf("enter the two numbers a=");
	scanf("%d",&a);
	printf(", b=");
	scanf("%d",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("the swaped teo numbers a=%d, b=%d ",a,b);
}