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
void fill_emps(struct Employee emp[],int size);
void print_emps(struct Employee emp[],int size);
void main(void)
{
int size=5;
struct Employee emp[5]={'\0'};
clrscr();
fill_emps(emp,size);
print_emps(emp,size);
getch();
}

void fill_emps(struct Employee emp[],int size)
{
float temp;
int i=0;
	for(;i<size;i++)
	{
		gotoxy(1,i*4+1);
		printf("Employee %d",i+1);
		gotoxy(1,i*4+2);
		printf("ID:");
		gotoxy(1,i*4+3);
		printf("Name:");
		gotoxy(1,i*4+4);
		printf("Age:");
		gotoxy(40,i*4+2);
		printf("salary:");
		gotoxy(40,i*4+3);
		printf("bouns:");
		gotoxy(40,i*4+4);
		printf("deduction:");
		gotoxy(4,i*4+2);
		scanf("%d",&emp[i].id);
		gotoxy(6,i*4+3);
		flushall();
		gets(emp[i].name);
		gotoxy(5,i*4+4);
		scanf("%d",&emp[i].age);
		gotoxy(48,i*4+2);
		scanf("%f",&temp);
		emp[i].salary=temp;
		gotoxy(47,i*4+3);
		scanf("%f",&temp);
		emp[i].bouns=temp;
		gotoxy(51,i*4+4);
		scanf("%f",&temp);
		emp[i].deduction=temp;
	}
}
void print_emps(struct Employee emp[],int size)
{
int i=0;
	for(;i<size;i++)
	{
	printf("The %d Employee data ID=%d, Name=%s, Age=%d, NetSalary=%f\n",i+1,emp[i].id,emp[i].name,emp[i].age,emp[i].salary-emp[i].deduction+emp[i].bouns);
	}
}
