#include<stdio.h>
int main()
{
	int c,i;
	long count[26]={0};
	printf("Enter the string: ");
	while((c=getchar())!='\n')
	{
		count[c-'a']++;
	}
	printf("\nOccurence of every letter in the string is:\n");
	for(i=0;i<26;i++)
	{
		printf("%c = %ld\n",'a'+i,count[i]);
	}
	return 0;
}
