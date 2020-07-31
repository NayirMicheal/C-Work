#include <stdio.h>
void main(void)
{
	int number;
	int counter;
	int divisor;
	char prime_bool=1;
	printf("please enter a number to find the prime factors for it ");
	scanf("%d",&number);
	while(number!=1)
	{
		for(divisor=number/2;divisor>1;divisor--)
		{
			if(number%divisor==0)
			{
				for(counter=(divisor/2)+1;counter>1;counter--)
				{
					if(divisor%counter==0)
					{
						prime_bool=0;
						break;
					}
				}
				if(divisor==2 || divisor==3)
				{
				prime_bool=1;	
				}
				if(prime_bool==1)
				{
					if(number<=3)
					{
						divisor=number;
					}
					printf(" %d ",divisor);
					number/=divisor;
				}
			}
		}			
	}

}