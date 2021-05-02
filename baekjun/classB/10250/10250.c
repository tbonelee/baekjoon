#include <stdio.h>

int t, h, w, n;

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &h, &w, &n);
		int quotient = (n - 1) / h;
		int remainder = (n - 1) % h + 1;
		int ret = remainder * 100 + quotient + 1;
		printf("%d\n", ret);

	}

}