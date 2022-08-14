#include<stdio.h>
int min(int arr[],int k,int n)
{
	int i,loc,min;
	min=arr[k];
	loc=k;
	for(i=k+1;i<n;i++)
	{
		if(min>arr[i])
		{
			min=arr[i];
			loc=i;
		}
	}
	return loc;
}
void selection_sort(int arr[],int n)
{
	int i,loc,temp;
	for(i=0;i<n-1;i++)
	{
		loc=min(arr,i,n);
		temp=arr[i];
		arr[i]=arr[loc];
		arr[loc]=temp;
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
	int i,n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	print(arr,n);
	return 0;
}
