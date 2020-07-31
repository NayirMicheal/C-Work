#include<stdio.h>
#include<conio.h>
#include<string.h>
void main (void)
{
char firstname[5][10]={'\0'};
char lastname[5][10]={'\0'};
char fullname[5][20]={'\0'};
int i;
clrscr();
flushall();
for(i=0;i<5;i++)
{
printf("\nplease enter the %d firstname\n",i+1);
gets(firstname[i]);
printf("please enter the %d lastname\n",i+1);
gets(lastname[i]);
strcpy(fullname[i],firstname[i]);
strcat(fullname[i]," ");
strcat(fullname[i],lastname[i]);
printf("the %d full name is ",i+1);
puts(fullname[i]);
printf("\n");
}
getch();
}