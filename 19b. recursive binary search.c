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
void binary_search(int arr[],int low,int upp,int ele)
{
	int mid;
	mid=(low+upp)/2;
	if(low>upp)
	{
		printf("\nElement not found\n\n");
        return;
    }
	if(arr[mid]==ele)
	{
		printf("\n%d element found at location %d\n",ele,mid+1);
	}
	else if(arr[mid]>ele)
	{
		binary_search(arr,low,mid-1,ele);
	}
	else if(arr[mid]<ele)
	{
		binary_search(arr,mid+1,upp,ele);
	}
}
int main()
{
	int i,n,ele;
	printf("Enter array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	printf("\nEnter the element you want to search of sorted array: ");
	scanf("%d",&ele);
	binary_search(arr,0,n,ele);
	return 0;
}
