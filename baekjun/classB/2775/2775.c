#include <stdio.h>

long long arr[15][15];

int main()
{
	int t; scanf("%d", &t);
	for (int j = 1; j <= 14; j++)
		arr[0][j] = j;
	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= 14; j++)
		{
			for (int jj = 1; jj <= j; jj++)
				arr[i][j] += arr[i - 1][jj];
		}

	for (int a = 0; a < t; a++)
	{
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%lld\n", arr[k][n]);
	}
}