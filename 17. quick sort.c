#include<stdio.h>
void quick(int arr[],int n,int beg,int end,int *locptr)
{
	int left,right,temp;
	left=beg;
	right=end;
	*locptr=beg;
	step2:
	{
		while(arr[*locptr]<=arr[right]&&*locptr!=right)
		{
			right--;
		}
		if(*locptr==right)
		{
			return;
		}
		if(arr[*locptr]>arr[right])
		{
			temp=arr[*locptr];
			arr[*locptr]=arr[right];
			arr[right]=temp;
			*locptr=right;
		}
	}
	goto step3;
	step3:
	{
		while(arr[*locptr]>=arr[left]&&*locptr!=left)
		{
			left++;
		}
		if(*locptr==left)
		{
			return;
		}
		if(arr[*locptr]<arr[left])
		{
			temp=arr[left];
			arr[left]=arr[*locptr];
			arr[*locptr]=temp;
			*locptr=left;
		}
	}
	goto step2;
}
void quick_sort(int arr[],int n)
{
	int beg,end,loc,top=-1;
	int lower[100],upper[100];
	if(n>1)
	{
		top++;
		lower[top]=0;
		upper[top]=n-1;
	}
	while(top!=-1)
	{
		beg=lower[top];
		end=upper[top];
		top--;
		quick(arr,n,beg,end,&loc);
		if(beg<loc-1)
		{
			top++;
			lower[top]=beg;
			upper[top]=loc-1;
		}
		if(loc+1<end)
		{
			top++;
			lower[top]=loc+1;
			upper[top]=end;
		}
	}
}
int main()
{
	int i,j,n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,n);
	printf("Elements in increasing order:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
