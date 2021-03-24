#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void    swap(char **a, char **b)
{
        char *temp;
        temp = *a;
        *a = *b;
        *b = temp;
}
int     main()
{
        char a[] = "12";
        char b[] = "ab";


        // swap(&a, &b);
		// char c[] = "asdb";
        // printf("%s %s\n", a ,b);

        swap((char **)a, (char **)b);
		// char c[] = "asdb";
        printf("%s %s\n", a ,b);


        return (0);
}