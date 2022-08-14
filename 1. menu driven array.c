#include<stdio.h>
#include<stdlib.h>
int n,arr[50];
void update(int pos,int ele)
{
	int i;
	arr[pos-1]=ele;
	printf("Element updated\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}
void insert(int pos,int ele)
{
	int i;
	for(i=n;i>=pos-1;i--)
	{
		arr[i+1]=arr[i];
	}
	n=n+1;
	arr[pos-1]=ele;
	printf("Element inserted\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n");
}
void search(int ele)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			printf("\nElement found at location %d\n\n",i+1);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\nItem not found\n\n");
	}
}
void rem(int ele)
{
	int i,j,k;
	for(i=0;i<n;++i)
	{
		if(arr[i]==ele)
		{
			break;
		}
	}
	if(i<n)
	{
		n=n-1;
		for(j=i;j<n;++j)
		{
			arr[j]=arr[j+1];
		}
	}
	printf("Element deleted\n");
	for(k=0;k<n;k++)
	{
		printf("%d\t",arr[k]);
	}
	printf("\n\n");
}
void display(int ele)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==ele)
		{
			printf("\nElement: %d\nLocation: %d\n\n",ele,i+1);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("\nItem is not present\n\n");
	}
}
int main()
{
	int i,ch,ele,pos;
	printf("Enter intial array size: ");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	while(1)
	{
		printf(":Array Operation:\n\n");
		printf("1.Update\n");
		printf("2.Insert\n");
		printf("3.Search\n");
		printf("4.Remove\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the position and updated value:\n");
				scanf("%d%d",&pos,&ele);
				update(pos,ele);
				break;
			case 2:
				printf("Enter the position and value to be inserted:\n");
				scanf("%d%d",&pos,&ele);
				insert(pos,ele);
				break;
			case 3:
				printf("Enter the value searched for: ");
				scanf("%d",&ele);
				search(ele);
				break;
			case 4:
				printf("Enter the element to be removed: ");
				scanf("%d",&ele);
				rem(ele);
				break;
			case 5:
				printf("Enter element to be displayed: ");
				scanf("%d",&ele);
				display(ele);
				break;
			case 6:
				printf("\nProgram ends\n");
				exit(0);
			default:
				printf("\nInvalid Input\n");
				exit(1);
		}
	}
	return 0;
}
