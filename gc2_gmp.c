#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

void fib(int n, mpz_t result);

int main(void)
{
	/*gmp init*/
	mpz_t a, b, result;
	mpf_t f_a, f_b, f_result;
		
	mpz_init(a);
	mpz_init(b);
	mpz_init(result);
	mpf_init(f_a);
	mpf_init(f_b);
	mpf_init(f_result);

	/*Fibonacci calculation*/
	fib(100, result);
	mpf_set_z(f_a, result);

	fib(101, result);
	mpf_set_z(f_b, result);

	/*Final calculation*/
	mpf_div(f_result, f_a, f_b);
	gmp_printf("%.8Ff\n", f_result);

	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(result);
	mpf_clear(f_a);
	mpf_clear(f_b);
	mpf_clear(f_result);

	return EXIT_SUCCESS;
}

void fib(int n, mpz_t result)
{
	mpz_t a, b;
	mpz_init(a);
	mpz_init(b);

	mpz_set_si(a, 1);
	mpz_set_si(b, 1);

	for (int i = 3; i <= n; i++)
	{
		mpz_add(result, a, b);
		mpz_set(a, b);
		mpz_set(b, result);
	}

	mpz_set(result, b);

	mpz_clear(a);
	mpz_clear(b);

	return;
}
