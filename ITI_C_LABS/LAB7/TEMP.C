#include<stdio.h>
#include<conio.h>
#define ESC    27
#define ENTER  13
#define HPAGE  71
#define EPAGE  79
#define RARROW 77
#define LARROW 75
void drawLineEditor(int size,int row,int col);
void main (void)
{
	int size,row,col;
	clrscr();
	printf("please enter the size of line editor ");
	scanf("%d",&size);
	printf("please enter the row and col of line editor ");
	scanf("%d %d",&row,&col);
	drawLineEditor(size,row,col);
	getch();
}
void drawLineEditor(int size,int row,int col)
{
	char * ptr_cur=NULL;
	char * ptr_str=NULL;
	char * ptr_end=NULL;
	int cursor=1;
	int count=0;
	int i;
	char* chars;
	char terminate=0;
	char ch='\0';
	size++;
	chars=(char*)malloc(sizeof(char)*size);
	for(i=0;i<size;i++)
	{
	chars[i]='\0';
	}
   ptr_cur=chars;
   ptr_str=chars;
   ptr_end=chars;
	clrscr();
	for(;cursor<size;cursor++)
	{   gotoxy(row+cursor,col);
		textattr(0x70);
		cprintf(" ");
	}
	textattr(0x07);
	cursor=1;
	gotoxy(row+cursor,col);
	do
	{
		ch=getch();
		switch(ch)
		{
			case ESC:
			ptr_str=ptr_end=ptr_end=chars;
			cursor=1;
			ptr_end[cursor-1]='\0';
			gotoxy(row+cursor,col);
			printf("\nEmpty array of string %s",ptr_str);
			terminate=1;
			break;
			case ENTER:
			while(chars[count]!='\0')
				{
				count++;
				}
			ptr_end[count]='\0';
		for(cursor=1;cursor<(size+1);cursor++)
		{   gotoxy(row+cursor,col);
		textattr(0x07);
		cprintf("%c",ptr_str[cursor-1]);
		}
		   //	gotoxy(row,col);
		   //	textattr(0x07);
		   //	cprintf("%s",chars);
			terminate=1;
			free(chars);
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
				gotoxy(row+cursor,col);
				}

				break;
				case LARROW:
				if(ptr_cur>ptr_str)
				{
				ptr_cur--;
				cursor--;
				gotoxy(row+cursor,col);
				}
				break;
				case HPAGE:
				ptr_cur=ptr_str;
				cursor=1;
				gotoxy(row+cursor,col);
				break;
				case EPAGE:
				ptr_cur=ptr_end;
				count=0;
				while(chars[count]!='\0')
				{
				count++;
				}
				cursor=count+1;
				gotoxy(row+cursor,col);
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
				gotoxy(row+cursor,col);
				}
				}
			}
			break;

		}
	}while(terminate==0);
	printf("\npress any key to continue");
}