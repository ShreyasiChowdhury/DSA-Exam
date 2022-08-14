#include<stdio.h>
void bubble_sort(int arr[],int n)
{
	int i,j,k,temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		printf("\nArray elements are after %d pass:\n",i+1);
		for(k=0;k<n;k++)
		{
			printf("%d\t",arr[k]);
		}
		printf("\n");
	}
}
void print(int arr[],int n)
{
	int i;
	printf("\nSorted list in increasing order:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int n,i,temp;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d integers:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	print(arr,n);
	return 0;
}
