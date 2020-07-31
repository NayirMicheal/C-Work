#include<stdio.h>
#include<conio.h>
#define ESC    27
#define ENTER  13
#define HPAGE  71
#define EPAGE  79
#define RARROW 77
#define LARROW 75
void main (void)
{
	char * ptr_cur=NULL;
	char * ptr_str=NULL;
	char * ptr_end=NULL;
	int cursor=1;
	int count=0;
	int i;
	char* chars;
	int size;
	char terminate=0;
	char ch;
	ptr_cur=ptr_str=ptr_end=chars;
	clrscr();
	printf("please enter the size of line editor ");
	scanf("%d",&size);
	size++;
	chars=(char*)malloc(sizeof(char)*size);
	clrscr();
	for(;cursor<size;cursor++)
	{   gotoxy(cursor,2);
		textattr(0x70);
		cprintf(" ");
	}
	textattr(0x07);
	cursor=1;
	gotoxy(cursor,2);
	do
	{
		ch=getch();
		switch(ch)
		{
			case ESC:
			ptr_str=ptr_end=ptr_end=chars;
			cursor=1;
			chars[cursor-1]='\0';
			gotoxy(cursor,2);
			printf("\nEmpty array of string %s",ptr_str);
			terminate=1;
			break;
			case ENTER:
			ptr_end='\0';
			printf("\nThe printed string is %s",chars);
			terminate=1;
			break;
			case NULL:
			ch=getch();
			switch(ch)
			{
				case RARROW:
					count=0;
				while(chars[count]!='\0')
				{
				count++;
				}
				if(ptr_cur<(ptr_str+size-1)&&ptr_end<(ptr_str+size)&&count>cursor)
				{
				ptr_cur++;
				cursor++;
				gotoxy(cursor,2);
				}

				break;
				case LARROW:
				if(ptr_cur>ptr_str)
				{
				ptr_cur--;
				cursor--;
				gotoxy(cursor,2);
				}
				break;
				case HPAGE:
				ptr_cur=ptr_str;
				cursor=1;
				gotoxy(cursor,2);
				break;
				case EPAGE:
				ptr_cur=ptr_end;
				count=0;
				while(chars[count]!='\0')
				{
				count++;
				}
				cursor=count+1;
				gotoxy(cursor,2);
				break;
			}
			break;
			default:
			if(isprint(ch))
			{
			 if(cursor<size){
				chars[cursor-1]=ch;
				printf("%c",chars[cursor-1]);

				if(ptr_cur<(ptr_str+size))
				{
				if(ptr_end==ptr_cur)
				ptr_end++;
				ptr_cur++;
				cursor++;
				gotoxy(cursor,2);
				}
				}
			}
			break;

		}
	}while(terminate==0);
	printf("\npress any key to continue");
	getch();
}