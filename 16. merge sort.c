#include<stdio.h>
void merge(int a[],int n1,int index1,int b[],int n2,int index2,int c[],int index)
{
	while(n1&&n2)
	{
		if(a[index1]<b[index2])
		{
			c[index]=a[index1];
			index++;
			index1++;
			n1--;
		} 
		else
		{
			c[index]=b[index2];
			index++;
			index2++;
			n2--;
		}
	}
	while(n1)
	{
		c[index]=a[index1];
		index++;
		index1++;
		n1--;
	}
	while(n2)
	{
		c[index]=b[index2];
		index++;
		index2++;
		n2--;
	}
}
void mergepass(int arr[],int n,int l,int a[])
{
	int j,lb;
	int q,s,r;
	q=n/(2*l);
	s=2*l*q;
	r=n-s;
	for(j=0;j<q;j++)
	{
		lb=(2*j)*l;
		merge(arr,l,lb,arr,l,lb+l,a,lb);
	}
	if(r<=l)
	{
		for(j=0;j<r;j++)
		{
			a[s+j]=arr[s+j];
		}
	}
	else
	{
		merge(arr,l,s,arr,r-l,s+l,a,s);
	}
}
void merge_sort(int arr[],int n)
{
	int l=1,a[n];
	while(l<n)
	{
		mergepass(arr,n,l,a);
		mergepass(a,n,2*l,arr);
		l=4*l;
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
	merge_sort(arr,n);
	printf("Elements in increasing order:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
