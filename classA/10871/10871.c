#include <stdio.h>

int main()
{
	int n, x; scanf("%d %d", &n , &x);
	for (int i = 1; i <= n; i++)
	{
		int temp; scanf("%d", &temp);
		if (temp < x)
			printf("%d ", temp);
	}
	printf("\n");

}