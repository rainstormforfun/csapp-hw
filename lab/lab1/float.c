#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float f;

	for (;;)
	{
		printf("Please input a float:");
		scanf("%f", &f);
		printf("Value of this float is %f\n", f);
		if(f == 0) 
			break;
	}
	return EXIT_SUCCESS;
}
