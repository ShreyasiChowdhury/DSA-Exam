#include<stdio.h>
int main()
{
	int n,i,item,flag,pos,count=0;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in the array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number of element to be searched: ");
	scanf("%d",&item);
	flag=0;
	for(i=0;i<n;i++)
	{
		count++;
		if(arr[i]==item)
		{
			flag=1;
			pos=i+1;
			break;
		}
	}
	if(flag==1)
		printf("Element is found at positon: %d.",pos);
	else
		printf("Element is not found.");
	printf("\nNumber of shifting operation is: %d",count);
	return 0;
}
