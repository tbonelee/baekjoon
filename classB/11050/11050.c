#include <stdio.h>

int main()
{
    int n, k; scanf("%d %d", &n, &k);
    int num = 1;
    for (int i = 1; i <= n; i++)
        num *= i;
    int denom1 = 1, denom2 = 1;
    for (int i = 1; i <= k; i++)
        denom1 *= i;
    for (int i = 1; i <= n - k; i++)
        denom2 *= i;
    printf("%d\n", num / denom1 / denom2);
}