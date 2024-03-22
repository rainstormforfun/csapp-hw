#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define PRECISE 8
#define MAXIMUM 1E17

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
void num_mul(num *mul_result, num *a, int times);
int num_sub(num *result, num *a, num *b);
void num_div(num *a, num *b);

int main(void)
{
	num *a = malloc(sizeof(num));		
	num *b = malloc(sizeof(num));
	num *result_a = malloc(sizeof(num));
	num *result_b = malloc(sizeof(num));
	num *tmp = malloc(sizeof(num));

	num_init(a);
	num_init(b);
	num_init(result_a);
	num_init(result_b);
	num_init(tmp);
	a -> digits[0] = 1;
	b -> digits[0] = 1;	

	fib(100, a, b, result_a);

	num_init(a);
	num_init(b);
	a -> digits[0] = 1;
	b -> digits[0] = 1;	
	fib(101, a, b, result_b);

	num_div(result_a, result_b);

	free(a);	
	free(b);
	free(result_a);
	free(result_b);
	free(tmp);

	return EXIT_SUCCESS;
}

void fib(int n, num *a, num *b, num * result)
{
	for (int i = 3; i <= n; i++)
	{
		num_add(result, a, b);
		num_set(a, b);
		num_set(b, result);
	}
	return;
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
		if (a -> digits[i] + b -> digits[i] + carry >= MAXIMUM)	
		{
			result -> digits[i] = a -> digits[i] + b -> digits[i] + carry - (MAXIMUM - 1);
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
	num *div_result = malloc(sizeof(num));
	num *sub_result = malloc(sizeof(num));
	num_init(quotient);
	num_init(mod);
	num_init(mul_result);
	num_init(div_result);
	num_init(sub_result);

	num_set(mod, a);

	int count = 0;
	int count_2 = 0;
	for (int i = 0; i <= PRECISE; i++)
	{
		count = 0;
		num_set(quotient, mod);

		num_mul(mul_result, quotient, 10);
		num_set(quotient, mul_result);

		while (num_sub(sub_result, quotient, b) == 1)	
		{
			num_mul(mul_result, quotient, 10);
			num_set(quotient, mul_result);
			if (i != 0)
			{
				printf("0");
				i++;
			}
		}

		num *quotient_tmp = malloc(sizeof(num));
		num_init(quotient_tmp);
		num_set(quotient_tmp, quotient);

		while (num_sub(sub_result, quotient_tmp, b) == 0)
		{
			count++;
			num_set(quotient_tmp, sub_result);
		}
		if (i == PRECISE - 1)
		{
			count_2 = count;
			num_set(mod, quotient_tmp);

			free(quotient_tmp);

			continue;
		}
		if (i == PRECISE)
		{
			if (count >= 5)
			{
				printf("%d", count_2 + 1);
			}
			free(quotient_tmp);
			break;
		}
		printf("%d", count);

		num_set(mod, quotient_tmp);

		free(quotient_tmp);
	}
	printf("\n");

	free(quotient);
	free(mod);
	free(mul_result);
	free(div_result);
	free(sub_result);
	
	return;
}

void num_mul(num *mul_result, num *a, int times)
{
	num *mul_result_sum = malloc(sizeof(num));
	num_init(mul_result_sum);

	for (int i = 0; i < times; i++)
	{
		num_add(mul_result, a, mul_result_sum);
		num_set(mul_result_sum, mul_result);
	}
	
	free(mul_result_sum);

	return;
}

int num_sub(num *result, num *a_org, num *b_org)
{
	int max_digits;
	int flag = 0;
	num *a = malloc(sizeof(num));
	num *b = malloc(sizeof(num));
	num_init(a);
	num_init(b);
	num_set(a, a_org);
	num_set(b, b_org);
	if (a -> max_digits == b -> max_digits)
	{
		max_digits = a -> max_digits;
		for (int i = max_digits - 1; i >= 0; i--)
		{
			if(a -> digits[i] > b -> digits[i])
				break;
			else if(a -> digits[i] < b -> digits[i])
			{
				num *tmp = malloc(sizeof(num));
				num_init(tmp);
				num_set(tmp, a);
				num_set(a, b);
				num_set(b, tmp);
				free(tmp);
				flag = 1;
				break;
			}
		}
	}
	else if (a -> max_digits > b -> max_digits)
	{
		max_digits = a -> max_digits;
	}
	else
	{
		max_digits = b -> max_digits;
		num *tmp = malloc(sizeof(num));
		num_init(tmp);
		num_set(tmp, a);
		num_set(a, b);
		num_set(b, tmp);
		free(tmp);
		flag = 1;
	
	}

	result -> max_digits = max_digits;

	int carry = 0;
	for (int i = 0; i < max_digits; i++)
	{
		if (a -> digits[i] - b -> digits[i] - carry < 0)
		{
			result -> digits[i] = a -> digits[i] - b -> digits[i] - carry + MAXIMUM;
			carry = 1;
		}
		else
		{
			result -> digits[i] = a -> digits[i] - b -> digits[i] - carry;
			carry = 0;
		}
	}
	
	free(a);
	free(b);
	return flag;
}
