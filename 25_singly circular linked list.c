#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
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
		printf("\nEnter the node data: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			ptr->next=head;
			temp->next=ptr;
			head=ptr;
		}
		printf("\nNode inserted successfully\n\n");
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
		printf("\nEnter the node data: ");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=head;
		}
		printf("\nNode inserted successfully\n\n");
	}
}
void del_beg()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n\n");
	}
	else if(head->next==head)
	{
		printf("\n%d node deleted successfully\n\n",head->data);
		head=NULL;
		free(head);
	}
	else
	{
		ptr=head;
		printf("\n%d node deleted successfully\n\n",ptr->data);
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->next=head->next;
		free(head);
		head=ptr->next;
	}
}
void del_end()
{
	struct node *ptr,*preptr;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n\n");
	}
	else if(head->next==head)
	{
		printf("\n%d node deleted successfully\n\n",head->data);
		head=NULL;
		free(head);
	}
	else
	{
		ptr=head;
		while(ptr->next!=head)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		printf("\n%d node deleted successfully\n\n",ptr->data);
		preptr->next=ptr->next;
		free(ptr);
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\nEmpty List\n\n");
	}
	else
	{
		printf("\nList is:\n");
		while(ptr->next!=head)
		{
			printf("%d --> ",ptr->data);
			ptr=ptr->next;
		}
		printf("%d --> ",ptr->data);
		printf("\n\n");
	}
}

int main()
{
	int ch;
	while(1)
	{
		printf("Circular Singly Linked List Operation:\n");
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
