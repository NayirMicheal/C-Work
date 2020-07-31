#include<stdio.h>
#include<conio.h>
#define ESC 27
#define ENTER 13
#define UARROW  72
#define DARROW    80
#define TAB 9
#define UPAGE  71
#define DPAGE    79
#define NORMAL  0x07
#define HIGHLIGHTED 0x70
struct Employee
{
int id;
char name[20];
int age;
float bouns;
float salary;
float deduction;
};
void ADD_NEW(int* emp_count,int * arr_emp,struct Employee * emp,int emp_number);
void DIS_ONE(int* arr_emp,struct Employee emp[],int emp_number);
void DIS_ALL(int * emp_count,struct Employee emp[],int * arr_emp);
void main(void)
{
int cur_location=0,terminate=0;
char menu[][15]={"New","Display","Display All","Exit"};
char ch;
int row=10;
int col=35;
int emp_count=0;
int emp_numbers;
int count;
struct Employee* emp;
int arr_emp[5]={0};
clrscr();
printf("Please Enter number of Employees ");
scanf("%d",&emp_numbers);
emp=(struct Employee*)malloc(sizeof(struct Employee)*emp_numbers);
do
{
clrscr();
	for(count=0;count<4;count++)
		{
		gotoxy(col,row+2*count);
		if(cur_location==count)
			textattr(HIGHLIGHTED);
		cprintf("%s",menu[count]);
		textattr(NORMAL);
		}
flushall();
ch=getch();
	switch(ch)
	{
	case NULL:
		ch=getch();
			switch(ch)
			{
			case UARROW:
				cur_location--;
				if(cur_location<0) cur_location=3;
				break;
			case DARROW:
				cur_location++;
				if(cur_location>3)
				cur_location=0;
				break;
			case UPAGE:
				cur_location=0;
				break;
			case DPAGE:
				cur_location=3;
				break;
			}
		 break;
	case ESC:
		terminate=1;
		 break;
		case TAB:
		cur_location++;
		if(cur_location>3)
		cur_location=0;
		if(cur_location<0)
		cur_location=3;
		break;
	case ENTER:
		switch(cur_location)
		{
		case 0:
		ADD_NEW(&emp_count,arr_emp,emp,emp_numbers);
		getch();
		break;
		case 1:
		DIS_ONE(arr_emp,emp,emp_numbers);
		getch();
		break;
		case 2:
		DIS_ALL(&emp_count,emp,arr_emp);
		getch();
		break;
		case 3:
		terminate=1;
		break;
		}
		 break;
	}
}while(terminate==0);
}
void ADD_NEW(int* emp_count,int * arr_emp,struct Employee emp[],int emp_numbers)
{
	int _emp;
	int i;
	char ok=1;
	float temp;
	clrscr();
	if(*emp_count<=(emp_numbers-1)){
	printf("Enter the employee number ");
	scanf("%d",&_emp);
	if(_emp<=emp_numbers && _emp>=1){
	for(i=0;i<*emp_count;i++)
	{
		if(arr_emp[i]==_emp)
		{
		printf("this record exist before");
		ok=0;
		}
	}
	if(ok==1)
	{
	clrscr();
	arr_emp[*emp_count]=_emp;
	gotoxy(1,1);
	printf("Employee %d",_emp);
	gotoxy(1,2);
	printf("ID:");
	gotoxy(1,3);
	printf("Name:");
	gotoxy(1,4);
	printf("Age:");
	gotoxy(40,2);
	printf("salary:");
	gotoxy(40,3);
	printf("bouns:");
	gotoxy(40,4);
	printf("deduction:");
	gotoxy(4,2);
	scanf("%d",&emp[_emp-1].id);
	gotoxy(6,3);
	flushall();
	gets(emp[_emp-1].name);
	gotoxy(5,4);
	scanf("%d",&emp[_emp-1].age);
	gotoxy(48,2);
	scanf("%f",&temp);
	emp[_emp-1].salary=temp;
	gotoxy(47,3);
	scanf("%f",&temp);
	emp[_emp-1].bouns=temp;
	gotoxy(51,4);
	scanf("%f",&temp);
	emp[_emp-1].deduction=temp;
	(*emp_count)++;
	printf("Press any key to continue");
			}
		ok=1;
		}
		else{
		printf("out of boundries");
		}
	}
		else
		{
			printf("Sorry you exceeded the max number,press any key to continue");
		}

}
void DIS_ONE(int* arr_emp,struct Employee emp[],int emp_numbers)
{
	int emp_to_print;
	char ok_dis=0;
	int i;
	clrscr();
	printf("Enter Employee Number to display the info ");
	scanf("%d",&emp_to_print);
		if(emp_to_print>=1 && emp_to_print<=emp_numbers)
		{
			for(i=0;i<emp_numbers;i++)
			{
				if(arr_emp[i]==emp_to_print)
					ok_dis=1;
			}
			if(ok_dis==1)
			printf("\nThe %d Employee data ID=%d, Name=%s, Age=%d, NetSalary=%f\n",emp_to_print,emp[emp_to_print-1].id,emp[emp_to_print-1].name,emp[emp_to_print-1].age,emp[emp_to_print-1].salary-emp[emp_to_print-1].deduction+emp[emp_to_print-1].bouns);
		else
			printf("Icorrect index,press any key to continue");
		ok_dis=0;
		}
		else
		{
		printf("out of boundries");
		}

}
void DIS_ALL(int * emp_count,struct Employee * emp,int * arr_emp)
{
	int count;
	clrscr();
		if(*emp_count>=1)
		{
		for(count=0;count<*emp_count;count++)
		{
		printf("\nThe %d Employee data ID=%d, Name=%s, Age=%d, NetSalary=%f\n",arr_emp[count],emp[arr_emp[count]-1].id,emp[arr_emp[count]-1].name,emp[arr_emp[count]-1].age,emp[arr_emp[count]-1].salary-emp[arr_emp[count]-1].deduction+emp[arr_emp[count]-1].bouns);
		}
		}
		else
		{
		printf("There is no records in the table\n");
		}
}