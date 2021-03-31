#include <stdio.h>

int    fibonacci(int n, int a, int b)
{
    if (n == 0)
        return (a);
    else if (n == 1)
        return (b);
    else
        return (fibonacci(n - 1, b, a + b));
}

int    main()
{
    int n;

    scanf("%d", &n);
    printf("%d", fibonacci(n, 0, 1));
    return 0;
}