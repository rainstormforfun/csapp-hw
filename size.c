#include <stdio.h>
#include <inttypes.h>

int main(void)
{       
        printf("int = %lu\n", sizeof(int));
        printf("float = %lu\n", sizeof(float));
        printf("double = %lu\n", sizeof(double));
        printf("char = %lu\n", sizeof(char));
        printf("long = %lu\n", sizeof(long));
        printf("long long = %lu\n", sizeof(long long));
        printf("short = %lu\n", sizeof(short));
        printf("char * = %lu\n", sizeof(char *));
        printf("long double = %lu\n", sizeof(long double));
	return 0;
}
