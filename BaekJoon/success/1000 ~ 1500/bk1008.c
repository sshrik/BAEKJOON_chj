#include<stdio.h>

int main()	{
	int a, b;
	scanf(" %d %d", &a, &b);

	printf("%.19Lf\n", (long double)a/b);

	return 0;
}