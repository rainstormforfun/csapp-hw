#include <stdio.h>
#define MAX_WORD 1000
int main(void)
{
    FILE *fp = fopen("hello.c", "r");
    unsigned int c[MAX_WORD];
    int i = 0;
    while ((c[i] = fgetc(fp)) != EOF)
    {
        i++;
    }
    for (int m = 0; m < i; m += 16)
    {
        for (int j = 0; j < 16 && m + j < i; j++)
        {
            if ((unsigned char) c[m + j] == '\n')
            {
                printf("\\n  ");
            }
            else if ((unsigned char) c[m + j] == '\r')
            {
                printf("\\r  ");
            }
            else if ((unsigned char) c[m + j] == ' ')
            {
                printf("<sp>");
            }
            else
            {
                printf("%c   ", (unsigned char) c[m + j]);
            }
        }
        printf("\n");
        for (int n = 0; n < 16 && n + m < i; n++)
        {
            printf("%.2x  ", (unsigned char) c[n + m]);
        }
        printf("\n");
    }
    return 0;
}
