#include<stdio.h>
#include<conio.h>
void main (void)
{
int index1,index2;
int grade[3][4];
int sum[3]={0};
float avr[4]={0};
clrscr();
	for(index1=0;index1<3;index1++)
		for(index2=0;index2<4;index2++)
		{
			printf("please enter the %d student grade %d \n",index1+1,index2+1);
			scanf("%d",&grade[index1][index2]);
		}
	for(index1=0;index1<3;index1++)
		for(index2=0;index2<4;index2++)
		{
		sum[index1]+=grade[index1][index2];
		avr[index2]+=grade[index1][index2];
		}
	   for(index1=0;index1<3;index1++)
	   {
	   printf("\nthe grade for %d student is %d",index1+1,sum[index1]);
	   }
	   for(index2=0;index2<4;index2++)
	   {
	   printf("\nthe avr for %d subject is %f",index2+1,avr[index2]/3.0);
	   }
	   getch();
}