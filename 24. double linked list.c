#include<stdio.h>
#include<stdlib.h>
int length();
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *head=NULL;
int len=0;
int length()
{
	struct node *temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void insert_beg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	printf("\n");
}
void insert_end()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
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
		temp->prev=p;
	}
	printf("\n");
}
void del_beg()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nUNDERFLOW\n\n");
	}
	else
	{
		if(head->next==NULL)
		{
			printf("Deleted node is %d\n",head->data);
			head=NULL;
			free(head);
		}
		else
		{
			printf("Deleted node is %d\n",temp->data);
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
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
	else
	{
		if(head->next==NULL)
		{
			printf("Deleted node is %d\n",head->data);
			head=NULL;
			free(head);
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			printf("Deleted node is %d\n",temp->data);
			temp->prev->next=NULL;
			free(temp);
		}
		printf("Last node deleted successfully\n\n");
	}
}
void display()
{
	struct node *temp=head;
	if(temp==NULL)
	{
		printf("\nList is empty\n\n");
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
		printf("Double Linked List Operation:\n");
		printf("1.Insert at begin\n");
		printf("2.Insert at end\n");
		printf("3.Delete at begin\n");
		printf("4.Delete at end\n");
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
