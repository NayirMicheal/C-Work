#include<stdio.h>
#include<conio.h>
struct stack{
	int * stk;
	int size;
	int tos;
};
int initstack(struct stack * s,int size);
int isEmpty(struct stack * s);
int isFull(struct stack * s);
int push(struct stack * s,int data);
int pop(struct stack * s,int * data);
void main(void)
{
struct stack s1;
int x;
clrscr();
initstack(&s1,10);
push(&s1,5);
push(&s1,59);
push(&s1,95);
push(&s1,91);
push(&s1,22);
push(&s1,33);
push(&s1,66);
push(&s1,88);

pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
pop(&s1,&x);
printf("%d\n",x);
getch();
}
int initstack(struct stack * s,int size)
{
s->size=size;
s->tos=0;	
if(s->stk=(int *)malloc(sizeof(int)*size))
return 1;
return 0;
}
int isEmpty(struct stack * s)
{
	if(s->tos==0)
		return 1;
	return 0;
}
int isFull(struct stack * s)
{
	return (s->size==s->tos);
}
int push(struct stack * s,int data)
{
	if(isFull(s))
		return 0;
s->stk[s->tos]=data;
s->tos++;
return 1;
}
int pop(struct stack * s,int * data)
{
	if(isEmpty(s))
		return 0;
s->tos--;
*data=s->stk[s->tos];
return 1;
}