#include<stdio.h>
int main()
{
	int i,n,ele,x=0;
	printf("Enter intial array size: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements in sorted order:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the value to be inserted:\n");
	scanf("%d",&ele);
	i=n-1;
	while(ele<arr[i] && i>=0)
	{
		arr[i+1]=arr[i];
		i--;
	}
	arr[i+1]=ele;
	n++;
	printf("\nElements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
