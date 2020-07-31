#include<stdio.h>
#include<conio.h>
void main(void)
{
int arr[5];
int * ptr;
int index;
ptr=arr;
clrscr();
printf("plz enter array elements\n");
for(index=0;index<5;index++)
{
scanf("%d",(ptr+index));
}
for(index=0;index<5;index++)
{
printf("\nthe array element %d is %d",index+1,*(ptr+index));
}
getch();
}