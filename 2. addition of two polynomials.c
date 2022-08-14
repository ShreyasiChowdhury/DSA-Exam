#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,l,m,n,size=0;
	printf("Enter total number of coefficient in first polynomial: ");
	scanf("%d",&m);
	int a[m];
	printf("Enter elements of first polynomial:\n");
	for(i=0;i<m;i++)
	{
		printf("Enter coefficient of x^%d: ",i);
		scanf("%d",&a[i]);
	}
	printf("Enter total number of coefficient in second polynomial: ");
	scanf("%d",&n);
	int b[n];
	printf("Enter elements of second polynomial:\n");
	for(j=0;j<n;j++)
	{
		printf("Enter coefficient of x^%d: ",j);
		scanf("%d",&b[j]);
	}
	if(m>n)
	{
		size=m;
	}
	else
	{
		size=n;
	}
	int c[size];
	k=0;
	if(m>n)
	{
		for(i=0;i<n;i++)
		{
			c[k]=a[i]+b[i];
			k++;
		}
		for(i=n;i<m;i++)
		{
			c[k]=a[i];
			k++;
		}
	}
	else
	{
		for(j=0;j<m;j++)
		{
			c[k]=a[j]+b[j];
			k++;
		}
		for(j=m;j<n;j++)
		{
			c[k]=b[j];
			k++;
		}
	}
	printf("Result is:\n");
	for(l=size-1;l>=0;l--)
	{
		printf("%dx^%d  ",c[l],l);
		if(l==0)
		{
			break;
		}
		else if(c[l]>=0)
		{
			printf("+");
		}
		else if(c[l]<0)
		{
			continue;
		}
	}
	return 0;
}
