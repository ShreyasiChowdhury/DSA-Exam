#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
};
struct node *root=NULL,*curr=NULL;
void insert(int d)
{
	struct node *t,*p;
	t=(struct node*)malloc(sizeof(struct node));
	t->data=d;
	t->prev=NULL;
	t->next=NULL;
	p=root;
	if(root==NULL)
	{
		root=t;
	}
	else
	{
		struct node *curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(t->data>curr->data)
			{
				curr=curr->next;
			}
			else
			{
				curr=curr->prev;
			}
		}
		if(t->data>p->data)
		{
			p->next=t;
		}
		else
		{
			p->prev=t;
		}
	}
	printf("\nInsertion successfull\n\n");
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->prev);
		preorder(root->next);
	}
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->prev);
		printf("%d\t",root->data);
		inorder(root->next);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->prev);
		postorder(root->next);
		printf("%d\t",root->data);
	}
}
void search(int item)
{
	int i=0,flag=1;
	if(root==NULL)
	{
		printf("\nTree is empty\n\n");
		return;
	}
	struct node *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==item)
		{
			printf("\nElement %d is present\n\n",item);
			flag=0;
			break;
		}
		else if(item<temp->data)
		{
			temp=temp->prev;
		}
		else
		{
			temp=temp->next;
		}
		i++;
	}
	if(flag==1)
	{
		printf("\nElement %d not found\n\n",item);
	}
}
int main()
{
	int ch,item;
	while(1)
	{
		printf(":BINARY SEARCH TREE OPERATIONS:\n\n");
		printf("1.Insert\n");
		printf("2.Inorder Traverse\n");
		printf("3.Preorder Traverse\n");
		printf("4.Postorder Traverse\n");
		printf("5.Search\n");
		printf("6.Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				printf("\nElements in inorder:\n");
				inorder(root);
				printf("\n\n");
				break;
			case 3:
				printf("\nElements in preorder:\n");
				preorder(root);
				printf("\n\n");
				break;
			case 4:
				printf("\nElements in postorder:\n");
				postorder(root);
				printf("\n\n");
				break;
			case 5:
				printf("\nEnter the data to search: ");
				scanf("%d",&item);
				search(item);
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
