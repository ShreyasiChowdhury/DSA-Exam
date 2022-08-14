#include<stdio.h>
void insertion_sort(int arr[],int n)
{
	int i,j,temp,k,count=0;
	for(i=1;i<n;i++)
	{
		for(j=i;j>0&&arr[j-1]>arr[j];j--)
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
		}
		printf("\nArray elements are after %d pass:\n",++count);
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
	int i,n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr,n);
	print(arr,n);
	return 0;
}
