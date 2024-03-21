#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef int64_t int64;
typedef struct num
{
	int64 digits[SIZE];
	int max_digits;
} num;

void fib(int n, num *a, num *b, num *result);
void num_add(num *result, num *a, num *b);
void num_init(num *a);
void num_printf(num *result);
void num_set(num *des, num *src);
void num_div(num *a, num *b);
void num_mul(num *mul_result, num *a, int times);
void num_sub(num *result, num *a, num *b);

int main(void)
{
	num *a = malloc(sizeof(num));		
	num *b = malloc(sizeof(num));
	num *result_a = malloc(sizeof(num));
	num *result_b = malloc(sizeof(num));

	num_init(a);
	num_init(b);
	num_init(result_a);
	num_init(result_b);
	a -> digits[0] = 1;
	b -> digits[0] = 1;	

	fib(100, a, b, result_a);
	num_printf(result_a);

	num_init(a);
	num_init(b);
	a -> digits[0] = 1;
	b -> digits[0] = 1;	
	fib(101, a, b, result_b);
	num_printf(result_b);

	num_div(result_a, result_b);

	free(a);	
	free(b);
	free(result_a);
	free(result_b);

	return EXIT_SUCCESS;
}

void fib(int n, num *a, num *b, num * result)
{
	if (n == 1)
	{
		num_set(result, a);
		return;
	}
	if (n == 2)
	{
		num_set(result, b);
		return;
	}

	num_init(result);
	num_add(result, a, b);	
	num_set(a, b);
	num_set(b, result);

	return fib(n - 1, a, b, result);
}

void num_init(num *a)
{
	a -> max_digits = 1;
	for (int i = 0; i < SIZE; i++)
	{
		a -> digits[i] = 0;
	}	

	return;
}

void num_add(num *result, num *a, num *b)
{
	int max_digits = (a -> max_digits > b -> max_digits) ? a -> max_digits : b -> max_digits;

	result -> max_digits = max_digits;

	int carry = 0;
	for (int i = 0; i < max_digits; i++)
	{
		if (a -> digits[i] + b -> digits[i] + carry >= 1E17)	
		{
			result -> digits[i] = a -> digits[i] + b -> digits[i] + carry - (1E17 - 1);
			carry = 1;
	    }
		else
		{
			result -> digits[i] = a -> digits[i] + b -> digits[i] + carry;
			carry = 0;
		}
		
	}

	if (carry != 0)
	{
		result -> digits[max_digits] = 1;
		(result -> max_digits)++;
	}

	return;
}

void num_printf(num *result)
{
	for (int i = result -> max_digits - 1; i >= 0; i--)
		printf("%" PRIu64 "", result -> digits[i]);
	printf("\n");

	return;
}

void num_set(num *des, num *src)
{
	des -> max_digits = src -> max_digits;
	for (int i = 0; i < src -> max_digits; i++)
		des -> digits[i] = src -> digits[i];
	
	return;
}

void num_div(num *a, num *b)
{
	printf("0.");
	num *quotient = malloc(sizeof(num));
	num *mod = malloc(sizeof(num));
	num *mul_result = malloc(sizeof(num));
	num_init(quotient);
	num_init(mod);
	num_init(mul_result);

	num_set(quotient, a);
	num_set(mod, b);

	while (quotient)	

	free(quotient);
	free(mod);
	free(mul_result);
	
	return;
}

void num_mul(num *mul_result, num* a, int times)
{
	num *tmp = malloc(sizeof(num));
	num_init(tmp);

	for (int i = 0; i < times; i++)
	{
		num_add(mul_result, a, 0);
	}
	
	free(tmp);

	return;
}

void num_sub(num *result, num *a, num *b)
{
	int max_digits;
	if (a -> max_digits == b -> max_digits)
	{
		for (int i = a -> max_digits - 1; i >= 0; i--)
		{
			if(a -> digits[i] > b -> digits[i])
				break;
			else
			{
				num *tmp = malloc(sizeof(num));
				num_init(tmp);
				num_set(tmp, a);
				num_set(a, b);
				num_set(b, tmp);
				free(tmp);
				break;
			}
		}
		max_digits = a -> max_digits;
	}
	else
	{
		max_digits = (a -> max_digits > b -> max_digits) ? a -> max_digits : b -> max_digits;
		result -> max_digits = max_digits;
	}


	int carry = 0;
	for (int i = 0; i < max_digits; i++)
	{
		if (a -> digits[i] - b)
	}
}