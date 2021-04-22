#include <stdio.h>

int main()
{
    long double a, b;
    scanf("%Lf %Lf", &a, &b);
    printf("%.9Lf", a / b);
}