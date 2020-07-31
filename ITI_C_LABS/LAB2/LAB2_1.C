#include<conio.h>
#include<stdio.h>
void main (void)
{
int number=0;
int col,row,counter,dx,dy;
clrscr();
	do
	{
	printf("Please enter an odd number\n");
	scanf("%d",&number);
	}
   while((number%2)==0);
 col=number/2;
 row=0;
 dx=80/(number+1);
 dy=25/(number+1);
 gotoxy((col+1)*dx,(row+1)*dy);
 printf("1");
 for(counter=1;counter<number*number;counter++)
 {
 if((counter%number)!=0)
	 {
	col--; if(col<0) col=number-1;
	row--; if(row<0) row=number-1;
	 }
 else
	{
	 row++; if(row>(number-1)) row=0;
	}
	gotoxy((col+1)*dx,(row+1)*dy);
	printf("%d",counter+1);
 }
  gotoxy((col+1)*dx,(row+1)*dy);
	printf("%d",counter);
   getch();

}