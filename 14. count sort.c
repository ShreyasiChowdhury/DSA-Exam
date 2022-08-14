#include<stdio.h>
void count_sort(int a[],int n,int b[],int k)
{
	int i,j,c[k];
	for(i=0;i<k;i++)
	{
		c[i]=0;
	}
	for(j=0;j<n;j++)
	{
		c[a[j]]=c[a[j]]+1;
	}
	for(i=1;i<k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(j=n-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
}
int main()
{
	int i,j,n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	int a[n];
	int b[n];
	int k=10;
	printf("Enter %d elements (in 0-9 range):\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	count_sort(a,n,b,k);
	printf("Elements in increasing order:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",b[i]);
	}
	return 0;
}
