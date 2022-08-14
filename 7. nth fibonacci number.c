#include<stdio.h>
int fibo(int x)
{
	if(x==1||x==2)
	{
		return 1;
	}
	else
	{
		return(fibo(x-1)+fibo(x-2));
	}
}
int main()
{
	int i,n,a;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		a=fibo(i);
	}
	printf("Result is: %d",a);
	return 0;
}
