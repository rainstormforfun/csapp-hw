#include <stdio.h>
#include <stdlib.h> 
#include <inttypes.h>

u_int64_t fib(int n);

int main(void)
{
	u_int64_t result = 0, a = 0, b = 1;
	
	/*for (int i = 1; i < 101; i++)
	{
		printf("fib(%d) = %" PRIu64 "\n", i, fib(i));
	}*/
	printf("%.8lf\n",(double) fib(100) / (double) fib(101));
	return EXIT_SUCCESS;
}

u_int64_t fib(int n)
{
	u_int64_t a = 0, b = 1, result = 0;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 3; i <= n; i++)
	{
		result = 0;
		if (a + b < a)
		{
			a = a >> 5;
			b = b >> 5;
			/*printf("Overflow!\n");*/
		}	
		result = a + b;	
		a = b;
		b = result;
	}
	return b;
}
