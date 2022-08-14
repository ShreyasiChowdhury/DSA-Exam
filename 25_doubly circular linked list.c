#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *head=NULL;
void insert_beg()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOVERFLOW\n\n");
	}
	else
	{
		printf("Enter node data: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			head->prev=ptr;
			ptr->next=head;
			head=ptr;
		}
		printf("\nNode has been inserted successfully\n\n");
	}
}
void insert_end()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOVERFLOW\n\n");
	}
	else
	{
		printf("Enter node data: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			head->prev=ptr;
			ptr->next=head;
		}
	}
	printf("\nNode has been inserted successfully\n\n");
}
void del_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nUNDERLOW\n\n");
	}
	else if(head->next==head)
	{
		printf("Deleted node is %d\n",head->data);
		head=NULL;
		free(head);
		printf("First node deleted successfully\n\n");
	}
	else
	{
		temp=head;
		printf("Deleted node is %d\n",temp->data);
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		(head->next)->prev=temp;
		free(head);
		head=temp->next;
		printf("First node deleted successfully\n\n");
	}
}
void del_end()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n\n");
	}
	else if(head->next==head)
	{
		printf("Deleted node is %d\n",head->data);
		head=NULL;
		free(head);
		printf("Last node deleted successfully\n\n");
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		printf("Deleted node is %d\n",temp->data);
		(temp->prev)->next=head;
		head->prev=temp->prev;    
		free(temp);
		printf("Last node deleted successfully\n\n");
	}
}
void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("List is empty\n\n");
	}
	else
	{
		printf("\nList is:\n");
		while(temp->next!=head)
		{
			printf("%d --> ",temp->data);
			temp=temp->next;
		}
		printf("%d --> ",temp->data);
		printf("\n\n");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Circular Doubly Linked List Operation:\n");
		printf("1.Insert at begin\n");
		printf("2.Insert at end\n");
		printf("3.Delete from begin\n");
		printf("4.Delete from end\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_beg();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				del_beg();
				break;
			case 4:
				del_end();
				break;
			case 5:
				display();
				break;
			case 6:
				printf("\nProgram ends\n");
				exit(0);
			default:
				printf("\nInvalid input\n");
				exit(1);
		}
	}
	return 0;
}
