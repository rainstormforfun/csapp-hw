#include <stdio.h>
#include <stdlib.h>

int sum(int a[], unsigned len);

int main(void)
{
	int a[10]={1,1,1,1,1,1,1,1,1,1};
	int len = 0;

	printf("%d\n", sum(a, len));

	return EXIT_SUCCESS;
}

int sum(int a[], unsigned len)
{
	int i, sum = 0;
	for (int i = 0; i <= len - 1; i++)
		sum += a[i];

	return sum;
}
