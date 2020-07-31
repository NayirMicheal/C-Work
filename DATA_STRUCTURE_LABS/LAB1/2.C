#include<stdio.h>
#include<conio.h>
#include<string.h>
struct Employee{
int id;
char name[20];
int age;
float bouns;
float salary;
float deduction;
};
void main(void)
{
	struct Employee emp[5]={'\0'};
	int i,found=0;
	float temp;
	char nam[20];
	clrscr();
	for(i=0;i<5;i++)
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
	printf("\nEnter a name to search ");
	flushall();
	gets(nam);
	for(i=0;i<5&&!found;i++)
	{
		if(strcmpi(nam,emp[i].name)==0)
			found=1;
	}
	if(found)
	{
		printf("\nThe number found at index %d",i);
	}
	else
	{
		printf("\nnot found");
	}
	getch();
}