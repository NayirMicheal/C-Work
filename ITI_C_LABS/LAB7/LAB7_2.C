#include<stdio.h>
#include<conio.h>
void main(void)
{
int **  std_grads;
int std=0,grades=0,i=0,j=0;
int * sum;
float* avg;
clrscr();
printf("enter number of students and grades in order\n");
scanf("%d %d",&std,&grades);
std_grads=(int **) malloc(sizeof(int *) * std);
sum=(int*)malloc(sizeof(int)*std);
avg=(float*)malloc(sizeof(float)*grades);
for(;i<std;i++)
	{
	std_grads[i]=(int *) malloc(sizeof(int) * grades);
	sum[i]=0;
	}
for(i=0;i<std;i++)
	for(j=0;j<grades;j++)
	{
	printf("\nplease the %d student %d grade ",j+1,i+1);
	scanf("%d",&std_grads[i][j]);
	sum[i]+=std_grads[i][j];
	avg[j]+=std_grads[i][j];
	}
for(j=0;j<std;j++)
 printf("\nThe sum for %d student is %d",j+1,sum[j]);
for(i=0;i<grades;i++)
 printf("\nThe average for %d grade is %f",i+1,avg[i]/(float)grades);
getch();
}