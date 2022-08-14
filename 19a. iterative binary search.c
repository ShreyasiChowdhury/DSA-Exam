#include<stdio.h>
void bubble_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void binary_search(int arr[],int n)
{
	int low,upp,mid,ele=0,flag=0;
	low=0;
	upp=n-1;
	mid=(low+upp)/2;
	printf("\nEnter the element you want to search of sorted array: ");
	scanf("%d",&ele);
	while(low<=upp)
	{
		if(arr[mid]==ele)
		{
			flag=1;
			printf("\n%d element found at location %d\n",ele,mid+1);
			break;
		}
		else if(arr[mid]<ele)
		{
			low=mid+1;
		}
		else
		{
			upp=mid-1;
		}
		mid=(low+upp)/2;
	}
	if(flag==0)
	{
		printf("\n%d element not found\n",ele);
	}
}
int main()
{
	int i,n;
	printf("Enter array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	binary_search(arr,n);
	return 0;
}
