#include <stdio.h>
#include <stdlib.h>

long fib(int n);

int main(void)
{
	printf("%.8f", (double) fib(100) / (double) fib(101));

	return EXIT_SUCCESS;
}

long fib(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if(n == 2)
	{
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}
