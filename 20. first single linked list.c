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
void search(int item)
{
	struct node *ptr;
	int i=0,flag;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nEmpty list\n\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("\nItem found at location %d\n\n",i+1);
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
			i++;
			ptr=ptr->next;
		}
		if(flag==1)
		{
			printf("\nItem not found\n\n");
		}
	}
}
int main()
{
	int ch,item;
	while(1)
	{
		printf("Single Linked List Operation:\n");
		printf("1.Insret at begin\n");
		printf("2.Insert at end\n");
		printf("3.Display\n");
		printf("4.Search\n");
		printf("5.Quit\n");
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
				display();
				break;
			case 4:
				printf("\nEnter the element you want to search: ");
				scanf("%d",&item);
				search(item);
				break;
			case 5:
				printf("\nProgram ends\n");
				exit(0);
			default:
				printf("\nInvalid input\n");
				exit(1);
		}
	}
	return 0;
}
