#include<stdio.h>
#include<stdlib.h>
#define capacity 5
int stack[capacity];
int top=-1;
int isfull()
{
	if(top==capacity-1)
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
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void peek()
{
	if(isempty())
	{
		printf("\nStack is empty\n\n");
	}
	else
	{
		printf("Peek element: %d\n\n",stack[top]);
	}
}
void push(int ele)
{
	if(isfull())
	{
		printf("\nStack is overflow\n\n");
	}
	else
	{
		top++;
		stack[top]=ele;
		printf("\n%d pushed at %d position\n\n",ele,top+1);
	}
}
int pop()
{
	if(isempty())
	{
		return 0;
	}
	else
	{
		return stack[top--];
	}
}
void display()
{
	int i;
	if(isempty())
	{
		printf("\nStack is empty\n\n");
	}
	else
	{
		printf("Stack elements are:\n");
		for(i=0;i<=top;i++)
		{
			printf("%d\t",stack[i]);
		}
		printf("\n\n");
	}
}
int main()
{
	int ch,item=0;
	while(1)
	{
		printf("Stack Operation:\n");
		printf("1.Peek\n");
		printf("2.Push\n");
		printf("3.Pop\n");
		printf("4.Traverse\n");
		printf("5.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				peek();
				break;
			case 2:
				printf("Enter element: ");
				scanf("%d",&item);
				push(item);
				break;
			case 3:
				item=pop();
				if(item==0)
				{
					printf("\nStack is underflow\n\n");
				}
				else
				{
					printf("\nPopped item: %d\n\n",item);
				}
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\nProgram ends\n");
				exit(0);
			default:
				printf("\nInvalid Input\n");
				exit(1);
		}
	}
	return 0;
}
