/* Counting stars. */
/* 2439 && 2441 question */
#include<stdio.h>

int main()	{
	int n, i, j;
	
	scanf(" %d", &n);

	for(i = 0; i < n; i++)	{
		for(j = 0; j < i; j++)	{
			printf(" ");
		}
		for(j = n; j > i; j--)	{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
