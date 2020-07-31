#include<stdio.h>
#include<conio.h>
#define ESC 27
#define ENTER 13
#define TAB 9
#define UARROW  72
#define DARROW    80
#define UPAGE  73
#define DPAGE    81
#define NORMAL  0x07
#define HIGHLIGHTED 0x70
void main(void)
{
int cur_location=0,terminate=0;
char menu[][10]={"New","Display","Exit"};
char ch;
int row=10;
int col=35;
int count;
do
{
clrscr();
	for(count=0;count<3;count++)
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
				if(cur_location<0) cur_location=2;
				break;
			case DARROW:
				cur_location++;
				if(cur_location>2) cur_location=0;
				break;
			case UPAGE:
				cur_location=0;
				break;
			case DPAGE:
				cur_location=2;
				break;
			}
		 break;
	case ESC:
		terminate=1;
		 break;
	case TAB:
		cur_location++;
		if(cur_location>2)
		cur_location=0;
		if(cur_location<0)
		cur_location=2;
		break;
	case ENTER:
		switch(cur_location)
		{
		case 0:
		clrscr();
		printf("The New item is pressed press any key to back");
		getch();
		break;
		case 1:
		clrscr();
		printf("The Display item is pressed press any key to back");
		getch();
		break;
		case 2:
		terminate=1;
		break;
		}
		 break;
	}
}while(terminate==0);
}

