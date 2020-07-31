#include<stdio.h>
#include<conio.h>
void main(void)
{
char ch;
clrscr();
printf("Enter a char\n");
ch=getche();
switch(ch)
{
case NULL:
	ch=getch();
	printf("\nExtended Char with ASCII %d",ch);
	break;
default:
	printf("\nNormal Char with ASCII %d", ch);
	break;
}
getch();
}