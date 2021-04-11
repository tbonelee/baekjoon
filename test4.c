
#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long rec = 0;

    for (unsigned long long i = 0; i <18446744073709551610; i++ )
    {
        int i = 0;
        int j = 0;
        i++;
        j++;
            for (unsigned long long i = 0; i <18446744073709551610; i++ )
            {
				rec++;
            }
    }
    printf("Hello World!");
}
