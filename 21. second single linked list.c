#include<stdio.h>
#include<stdlib.h>
int length();
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_beg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		printf("\nNode has been inserted successfully\n\n");
	}
	else
	{
		temp->next=head;
		head=temp;
		printf("\nNode has been inserted successfully\n\n");
	}
}
void insert_end()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		printf("\nNode has been appended successfully\n\n");
	}
	else
	{
		struct node *p;
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		printf("\nNode has been appended successfully\n\n");
	}
}
void del_beg()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty\n\n");
	}
	else
	{
		if(head->next==NULL)
		{
			printf("Deleted node is %d\n",temp->data);
			head=NULL;
		}
		else
		{
			printf("Deleted node is %d\n",temp->data);
			head=temp->next;
			free(temp);
		}
		printf("First node deleted successfully\n\n");
	}
}
void del_end()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty\n\n");
	}
	else
	{
		if(head->next==NULL)
		{
			printf("Deleted node is %d\n",temp->data);
			head=NULL;
		}
		else
		{
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			printf("Deleted node is %d\n",temp->next->data);
			struct node *p=temp->next;
			temp->next=NULL;
			free(p);
		}
		printf("Last node deleted successfully\n\n");
	}
}
void display()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty\n\n");
	}
	else
	{
		printf("\nList is:\n");
		while(temp!=NULL)
		{
			printf("%d --> ",temp->data);
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
		printf("Single Linked List Operation:\n");
		printf("1.Insret at begin\n");
		printf("2.Insert at end\n");
		printf("3.Delete from beginning\n");
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
