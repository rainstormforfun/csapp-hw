#include <stdio.h>
#include <stdlib.h>

long fib(int n);

int main(void)
{
	printf("%lf\n", (double) fib(100) / (double) fib(101));
	return EXIT_SUCCESS;
}

long fib(int n)
{
	long a = 1, b = 1, result = 0;
	for (int i = 3; i <= n; i++)
	{
		result = a + b;	
		a = b;
		b = result;
	}	
	return result;
}
