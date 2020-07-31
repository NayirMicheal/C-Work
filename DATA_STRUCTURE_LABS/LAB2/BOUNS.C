#include<stdio.h>
#include<conio.h>
struct Employee{
int id;
char name[20];
int age;
float bouns;
float salary;
float deduction;
};
void BuBBle(struct Employee * arr,int size);
void swapI(int * a,int * b);
void swapF(float * a,float *b);
void swapC(char * a,char *b);
void main(void)
{
int num;
struct Employee* emp;
int i=0;
float temp;
clrscr();
printf("Enter number of Employee ");
scanf("%d",&num);
emp=(struct Employee *)malloc(sizeof(struct Employee)*num);
clrscr();
for(;i<num;i++)
{
	gotoxy(1,i*4+2);
		printf("Employee %d",i+1);
		gotoxy(1,i*4+3);
		printf("ID:");
		gotoxy(1,i*4+4);
		printf("Name:");
		gotoxy(1,i*4+5);
		printf("Age:");
		gotoxy(40,i*4+3);
		printf("salary:");
		gotoxy(40,i*4+4);
		printf("bouns:");
		gotoxy(40,i*4+5);
		printf("deduction:");
		gotoxy(4,i*4+3);
		scanf("%d",&emp[i].id);
		gotoxy(6,i*4+4);
		flushall();
		gets(emp[i].name);
		gotoxy(5,i*4+5);
		scanf("%d",&emp[i].age);
		gotoxy(48,i*4+3);
		scanf("%f",&temp);
		emp[i].salary=temp;
		gotoxy(47,i*4+4);
		scanf("%f",&temp);
		emp[i].bouns=temp;
		gotoxy(51,i*4+5);
		scanf("%f",&temp);
		emp[i].deduction=temp;
		printf("\n");
}
BuBBle(emp,num);
for(i=0;i<num;i++)
	{
		printf("Employee %d id and name is %d %s\n",i+1,emp[i].id,emp[i].name);
	}
	getch();

}
void BuBBle(struct Employee * arr,int size)
{
	int sorted=0;
	int i;
	while(!sorted)
	{
		sorted=1;
	for(i=size-1;i>0;i--)	
	if(arr[i].id>arr[i-1].id)
		{
		swapI(&(arr[i].id),&(arr[i-1].id));
		swapI(&(arr[i].age),&(arr[i-1].age));
		swapC(arr[i].name,arr[i-1].name);
		swapF(&(arr[i].salary),&(arr[i-1].salary));
		swapF(&(arr[i].deduction),&(arr[i-1].deduction));
		swapF(&(arr[i].bouns),&(arr[i-1].bouns));
		sorted=0;
		}
	}
}
void swapI(int * a,int * b)
{
	(*a)=(*a)+(*b);
	(*b)=(*a)-(*b);
	(*a)=(*a)-(*b);
}
void swapF(float * a,float *b)
{
	(*a)=(*a)+(*b);
	(*b)=(*a)-(*b);
	(*a)=(*a)-(*b);	
}
void swapC(char * a,char * b)
{
	char temp[20];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}