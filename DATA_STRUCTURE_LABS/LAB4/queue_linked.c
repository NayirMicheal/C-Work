#include<stdio.h>
#include<conio.h>
struct Node
{
	struct Node * next;
	struct Node * prev;
	int data;
};
struct queue{
	struct Node * front,* rear;
};
struct Node* newNode(int k);
struct queue *createQueue();
int isEmpty(struct queue * q);
int input(struct queue * q,int data);
int output(struct queue * q,int *data);
void main(void)
{
	int x;
	struct queue * que=createQueue();
	input(que,7);
	input(que,21);
	input(que,8);
	input(que,5);
	output(que,&x);
	printf("%d",x);
	
	output(que,&x);
	printf("%d",x);
	
	output(que,&x);
	printf("%d",x);
	
	output(que,&x);
	printf("%d",x);
}
struct Node* newNode(int k)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
	temp->prev=NULL;
    return temp; 
}
 
// A utility function to create an empty queue
struct queue *createQueue()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(struct queue * q)
{
	if(q->front == NULL && q->rear == NULL)
	return 0;
	return 1;
}
int input(struct queue * q,int data)
{
	Node * temp;
	struct Node * No;
if(q->front == NULL && q->rear == NULL)
{
	if(temp=newNode(data))return 0;
	q->front=temp;
	q->rear=temp;
	temp->next=temp->prev=NULL;
}
else
{
	No=q->front;
	while(No!=NULL)
	{
		No=No->next;
	}
	if(temp=newNode(data))return 0;
	temp->next=NULL;
	temp->prev=q->rear;
	q->rear->next=temp;
	q->rear=temp;
}
return 1;	
}
int output(struct queue * q,int *data)
{
	if(isEmpty(q))return 0;
	Node * freed;
	freed=q->front;
	freed->next->prev=NULL;
	*data=q->front->data;
	q->front=freed->next;
	free(freed);
		
}
