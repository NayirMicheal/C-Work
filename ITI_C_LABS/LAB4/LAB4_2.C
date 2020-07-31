#include<stdio.h>
#include<conio.h>
#define ENTER 13
void main(void)
{
char ch;
char data[40]={'\0'};
int index=0;
clrscr();
flushall();
do{
//index++;
//if(index>38)
//break;
ch=getche();
if(ch!=ENTER)
data[index]=ch;
index++;
}while((ch!=ENTER)&&(index<38));
data[index]='\0';
printf("\nThe printed text is %s",data);
getch();
}