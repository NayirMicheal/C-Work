#include <stdio.h>
void main(void)
{
	int x;
	int temp=0;
	int digit;
	printf("please enter a number to find the generic root for it ");
	scanf("%d",&x);
	while(x!=0)
	{
		digit=x%10;
		temp+=digit;
		x/=10;
		if(temp>9 && x==0){
		x=temp;
		temp=0;}	
	}
	printf("the generic root for it is %d",temp);
}