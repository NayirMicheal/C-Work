#include<stdio.h>
#include<conio.h>
struct queue{
	int * que;
	int size;
	int out;
};
int initqueue(struct queue * q,int size);
int isEmpty(struct queue * q);
int isFull(struct queue * q);
int input(struct queue * q,int data);
int output(struct queue * q,int *data);
void main(void)
{
	struct queue q1;
int x;
clrscr();
initqueue(&q1,10);
input(&q1,5);
input(&q1,59);
input(&q1,95);
input(&q1,91);
input(&q1,22);
input(&q1,33);
input(&q1,66);
input(&q1,88);

output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
output(&q1,&x);
printf("%d\n",x);
getch();
}
int initqueue(struct queue * q,int size)
{
q->size=size;
q->out=0;
if(q->que=(int *)malloc(sizeof(int)*size))
return 1;
return 0;
}
int isEmpty(struct queue * q)
{
		if(q->out==0)
		return 1;
	return 0;
}
int isFull(struct queue * q)
{
	return (q->size==q->out);
}
int input(struct queue * q,int data)
{
	if(isFull(q))
		return 0;
	q->que[q->out]=data;
	q->out++;
	return 1;
}
int output(struct queue * q,int *data)
{
	int i;
	if(isEmpty(q))
		return 0;
	q->out--;
	*data=q->que[0];
	for(i=0;i<q->out;i++)
	{
		q->que[i]=q->que[i+1];
	}
	return 1;
}