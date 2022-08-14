#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
int isempty()
{
	if(front==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else
	{
		printf("\nEnter value: ");
		scanf("%d",&item);
		ptr->data=item;
		if(front==NULL)
		{
			front=ptr;
			rear=ptr;
			front->next=NULL;
			rear->next=NULL;
		}
		else
		{
			rear->next=ptr;
			rear=ptr;
			rear->next=NULL;
		}
		printf("Insertion completed\n\n");
	}
}
void pop()
{
	struct node *ptr;
	if(isempty())
	{
		printf("\nUNDERFLOW\n\n");
		return;
	}
	else
	{
		ptr=front;
		printf("\nPopped value is %d\n",ptr->data);
		front=front->next;
		free(ptr);
		printf("Deletion completed\n\n");
	}
}
void display()
{
	struct node *ptr;
	ptr=front;
	if(isempty())
	{
		printf("\nQueue is empty\n\n");
	}
	else
	{
		printf("\n:Queue items:\n");
		while(ptr!=NULL)
		{
			printf("%d-->\t",ptr->data);
			ptr=ptr->next;
		}
		printf("\n\n");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Queue - Linked List Operation:\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nProgram ends\n");
				exit(0);
			default:
				printf("\nInvalid Input\n");
				exit(1);
		}
	}
	return 0;
}
