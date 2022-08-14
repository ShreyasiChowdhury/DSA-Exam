#include<stdio.h>
#include<stdlib.h>
#define size 5
int cqueue[size];
int front=-1,rear=-1;
int isfull()
{
	if((rear+1)%size==front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty()
{
	if(front==-1&&rear==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert(int ele)
{
	if(isfull())
	{
		printf("Circular Queue is full\n\n");
	}
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		cqueue[rear]=ele;
		printf("\nItem inserted\n\n");
	}
	else
	{
		rear=(rear+1)%size;
		cqueue[rear]=ele;
		printf("\nItem inserted\n\n");
	}
}
void del()
{
	if(isempty())
	{
		printf("Circular Queue is empty\n\n");
	}
	else if(front==rear)
	{
		printf("The deleted item is %d\n\n",cqueue[front]);
		front=rear=-1;
	}
	else
	{
		printf("The deleted item is %d\n\n",cqueue[front]);
		front=(front+1)%size;
	}
}
void display()
{
	int i;
	if(isempty())
	{
		printf("\nCircular Queue is empty\n\n");
	}
	else if(front>rear)
	{
		printf("Elements are:\n");
		for(i=front;i<size;i++)
		{
			printf("%d\t",cqueue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d\t",cqueue[i]);
		}
		printf("\n\n");
	}
	else
	{
		printf("Elements are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",cqueue[i]);
		}
		printf("\n\n");
	}
}
int main()
{
	int ele,ch;
	printf("Circular Queue\n\n");
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element: ");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nProgram ends\n");
				exit(0);
			default:
				printf("\nInvalid input\n");
				exit(1);
		}
	}
	return 0;
}
