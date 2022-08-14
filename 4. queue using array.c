#include<stdio.h>
#include<stdlib.h>
#define capacity 5
int queue[capacity];
int front=0,rear=0;
int isfull()
{
	if(capacity==rear)
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
	if(front==rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue()
{
	if(isfull())
	{
		printf("Queue is full\n\n");
	}
	else
	{
		int ele;
		printf("Enter element: ");
		scanf("%d",&ele);
		queue[rear]=ele;
		rear++;
		printf("Inserted successfully\n\n");
	}
}
void dequeue()
{
	if(isempty())
	{
		printf("Queue is empty\n\n");
	}
	else
	{
		int i;
		printf("Deleted %d\n\n",queue[front]);
		for(i=0;i<rear-1;i++)
		{
			queue[i]=queue[i+1];
		}
		rear--;
	}
}
void display()
{
	if(isempty())
	{
		printf("Queue is empty\n\n");
	}
	else
	{
		int i=0;
		printf("Elements are:\n");
		for(i=front;i<rear;i++)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n\n");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf(":Queue Operation:\n\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
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
