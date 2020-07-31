#include<stdio.h>
#include<conio.h>
#define ESC 27
#define ENTER 13
#define TAB 9
#define UARROW  72
#define DARROW    80
#define UPAGE  73
#define DPAGE    81
#define NORMAL  0x07
#define HIGHLIGHTED 0x70
struct Node
{
	struct Node * next;
	struct Node * prev;
	int data;
};
struct LinkedList
{
	struct Node * start;
	struct Node * end;
};
struct Node * create(void);
void appendElement(struct LinkedList *ll,struct Node * node);
void freeList(struct LinkedList * ll);
struct Node * search(struct LinkedList * LL,int num);
void insertNode(struct LinkedList * ll,struct Node * node);
int delete(struct LinkedList * ll,int num);
void display(struct LinkedList * ll);
void main(void)
{
	int cur_location=0,terminate=0;
	char menu[][20]={"New","Search","Delete Node","Insert Node","Display All","Free List"};
	char ch;
	int row=10;
	int col=35;
	int count;
	int number;
	struct LinkedList L={NULL,NULL};
	struct Node* N;
do
 {
	clrscr();
	for(count=0;count<6;count++)
		{
		gotoxy(col,row+2*count);
		if(cur_location==count)
			textattr(HIGHLIGHTED);
		cprintf("%s",menu[count]);
		textattr(NORMAL);
		}
		flushall();
ch=getch();
	switch(ch)
	{
	case NULL:
		ch=getch();
			switch(ch)
			{
			case UARROW:
				cur_location--;
				if(cur_location<0) cur_location=5;
				break;
			case DARROW:
				cur_location++;
				if(cur_location>5) cur_location=0;
				break;
			case UPAGE:
				cur_location=0;
				break;
			case DPAGE:
				cur_location=5;
				break;
			}
			 break;
	case ESC:
		terminate=1;
		 break;
	case TAB:
		cur_location++;
		if(cur_location>5)
		cur_location=0;
		if(cur_location<0)
		cur_location=5;
		break;
		case ENTER:
		switch(cur_location)
		{
			case 0:
			clrscr();
			printf("Please Enter the number to add to linked list ");
			scanf("%d",&number);
			N=create();
			N->data=number;
			insertNode(&L,N);
			getch();
			break;
			case 1:
			clrscr();
			printf("Please Enter the number to search for ");
			scanf("%d",&number);
			N=search(&L,number);
			if(N!=NULL)
				printf("\nfound");
			else
				printf("\nnot found");
			getch();
			break;
			case 2:
			//delete
			clrscr();
			printf("Please Enter the number to Delete form list ");
			scanf("%d",&number);
			if(delete(&L,number))
				printf("success delete");
			else
				printf("Can't delete");
			getch();
			break;
			case 3:
			clrscr();
			printf("Please Enter the number to insert in the list ");
			scanf("%d",&number);
			N=create();
			N->data=number;
			insertNode(&L,N);
			getch();
			break;
			//insert
			case 4:
			clrscr();
			printf("the list is ");
			display(&L);
			getch();
			break;
			//displayall
			case 5:
			clrscr();
			freeList(&L);
			printf("The list is empty now!!");
			getch();
			break;
			//freelist
			//problems in seq search and binary search with struct id and bubble sort and
		}

 }

}while(terminate==0);
}
void display(struct LinkedList * ll)
{
	struct Node * temp;
	temp=ll->start;
	if(temp==NULL)
		printf("Empty Linked List");
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}
struct Node * create(void)
{
	struct Node * temp;
	temp=(struct Node *) malloc(sizeof(struct Node));
	if(temp)
		temp->next=temp->prev=NULL;
	return temp;
}
void appendElement(struct LinkedList *ll,struct Node * node)
{
	if(ll->start == NULL)
	{
		ll->start=ll->end=node;
		node->next=node->prev=NULL;
	}
	else
	{
		ll->end->next=node;
		node->prev=ll->end;
		ll->end=node;
		node->next= NULL;
	}
}
void freeList(struct LinkedList * ll)
{
	struct Node * temp;
	temp=ll->start;
	while(temp)
	{
		ll->start=temp->next;
		free(temp);
		temp=ll->start;
	}
	ll->end=NULL;
}
struct Node * search(struct LinkedList * LL,int num)
{
	struct Node * temp;
	temp=LL->start;
	while(temp!=NULL && temp->data!=num)
	{
		temp=temp->next;
	}
	return temp;
}
void insertNode(struct LinkedList * ll,struct Node * node)
{
	struct Node * temp;
	temp=ll->start;
	if(temp==NULL)
	{
		appendElement(ll,node);
	}
	else
	{
		while(temp && temp->data < node->data)
		{
			temp=temp->next;
		}
		if(temp==NULL)
		{
				appendElement(ll,node);
		}
		else if(temp==ll->start){
			node->prev=NULL;
			temp->prev=node;
			node->next=temp;
			ll->start=node;
		}
		else
		{
			node->next=temp;
			node->prev=temp->prev;
			temp->prev=node;
			node->prev->next=node;
		}
	}
}
int delete(struct LinkedList * ll,int num)
{
	struct Node * temp;
	temp=search(ll,num);
	if(temp==NULL)
		return 0;
	if(ll->start==ll->end)
	{
		ll->start=ll->end=NULL;
	}
	else if(temp->prev==NULL)
	{
		ll->start=temp->next;
		ll->start->prev=NULL;
	}
	else if(temp->next==NULL)
	{
		ll->end=temp->prev;
		ll->end->next=NULL;
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
	free(temp);
	return 1;
}