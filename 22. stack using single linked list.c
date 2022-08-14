#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
int isempty()
{
	if(top==NULL)
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
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next=top;
	top=temp;
	printf("Data pushed\n\n");
}
void pop()
{
	struct node *temp;
	if(isempty())
	{
		printf("No elements\n\n");
	}
	else
	{
		temp=top;
		printf("Element is %d\n\n",temp->data);
		top=temp->next;
		temp->next=NULL;
		free(temp);
	}
}
void display()
{
	struct node *temp;
	if(isempty())
	{
		printf("Stack is empty\n\n");
	}
	else
	{
		temp=top;
		printf("Elements are:\n");
		while(temp!=NULL)
		{
			printf("%d-->\t",temp->data);
			temp=temp->next;
		}
		printf("\n\n");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Stack - Linked List Operation:\n");
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
