#include <stdio.h>
#include <stdlib.h>

u_int64_t fib(int n, u_int64_t a, u_int64_t b);

int main(void)
{
	printf("%.8lf\n", (double) fib(100, 0, 1) / (double) fib(101, 0, 1));
	/*for (int i = 0; i <= 99; i++)
	{
		printf("fib(%d) = %llu\n", i, fib(i, 0, 1));
	}*/
	return EXIT_SUCCESS;
}

u_int64_t fib(int n, u_int64_t a, u_int64_t b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (a + b < a)
    {
	    a = a >> 5;
	    b = b >> 5;
    }
    return fib(n - 1, b, a + b);	
}

