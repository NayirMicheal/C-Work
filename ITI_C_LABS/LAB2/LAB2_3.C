#include<stdio.h>
#include<conio.h>
void main(void)
{
int character;

clrscr();
printf("plz enter a number \n");
scanf("%d",&character);
switch(character)
{
case 0:
printf("you entered 0");
break;
case 1:
printf("you entered 1");
break;
case 3:
printf("you entered 3");
break;
default:
printf("you entered blabla");
break;
}
getch();
}