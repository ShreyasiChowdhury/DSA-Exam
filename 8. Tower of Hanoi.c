#include<stdio.h>
void TOH(int,char,char,char);
int main()
{
	int i;
	printf("TOWER OF HANOI\n");
	printf("Enter the number of disks: ");
	scanf("%d",&i);
	printf("\n");
	TOH(i,'A','B','C');
	return 0;
}
void TOH(int n,char beg,char aux,char end)
{
	if(n>=1)
	{
		TOH(n-1,beg,end,aux);
		printf("%d disc move %c to %c\n",n,beg,end);
		TOH(n-1,aux,beg,end);
	}
}
