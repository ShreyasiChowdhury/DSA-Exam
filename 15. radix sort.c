#include<stdio.h>
int get_max(int arr[],int n)
{
	int i,max=arr[0];
	for(1;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}
	return max;
}
void radix_sort(int arr[],int n)
{
	int bucket[n][n],bucket_cnt[n];
	int i,j,k,r,NOP=0,divisor=1,lar,pass;
	lar=get_max(arr,n);
	while(lar>0)
	{
		NOP++;
		lar/=n;
	}
	for(pass=0;pass<NOP;pass++)
	{
		for(i=0;i<n;i++)
		{
			bucket_cnt[i]=0;
		}
		for(i=0;i<n;i++)
		{
			r=(arr[i]/divisor)%n;
			bucket[r][bucket_cnt[r]]=arr[i];
			bucket_cnt[r]+=1;
		}
		i=0;
		for(k=0;k<n;k++)
		{
			for(j=0;j<bucket_cnt[k];j++)
			{
				arr[i]=bucket[k][j];
				i++;
			}
		}
		divisor*=n;
		printf("After pass %d : ",pass+1);
		for (i=0;i<n;i++)
		{
			printf("%d\t",arr[i]);
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
	printf("Enter the number of items to be sorted: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter items:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,n);
	print(arr,n);
	return 0;
}
