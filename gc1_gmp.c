#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

void fib(int n, mpz_t a, mpz_t b);

int main(void)
{
	/* gmp init*/
	mpz_t a, b, res1, res2;
	mpf_t resf1, resf2, result;
	mpz_init(a);
	mpz_init(b);
	mpz_init(res1);
	mpz_init(res2);
	mpf_init(result);
	mpf_init(resf1);
	mpf_init(resf2);

	mpz_set_ui(a, 1);
	mpz_set_ui(b, 1);

	/*Fibonacci calculate*/
	/*Fib(100)*/
	fib(100, a, b);
	mpz_set(res1, b);

	/*Fib(101)*/
	mpz_set_ui(a, 1);
	mpz_set_ui(b, 1);

	fib(101, a, b);
	mpz_set(res2, b);

	/*Type casting*/
	mpf_set_z(resf1, res1);
	mpf_set_z(resf2, res2);
	/*Final calculation*/
	mpf_div(result, resf1, resf2);

	gmp_printf("%.8Ff\n", result);

	/*gmp clear*/
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(res1);
	mpz_clear(res2);
	mpf_clear(resf1);
	mpf_clear(resf2);
	mpf_clear(result);

	return EXIT_SUCCESS;
}

void fib(int n, mpz_t a, mpz_t b)
{
	mpz_t tmp;
	mpz_init(tmp);
	if (n == 1)
	{
		mpz_set(b, a);
		return;
	}
	if (n == 2)
	{
		return;
	}

	mpz_add(tmp, a, b);
	mpz_set(a, b);
	mpz_set(b, tmp);

	mpz_clear(tmp);

	return fib(n - 1, a, b);
}
	
