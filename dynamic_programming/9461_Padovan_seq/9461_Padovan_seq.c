#include <stdio.h>

long long g_memo[101];

long long rec(int n)
{
	if (n <= 3)
	{
		g_memo[n] = 1;
		return g_memo[n];
	}
	if (g_memo[n - 2] == 0)
		g_memo[n - 2] = rec(n - 2);
	if (g_memo[n - 3] == 0)
		g_memo[n - 3] = rec(n - 3);
	return (g_memo[n - 2] + g_memo[n - 3]);
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0, input; i < N; i++)
	{
		scanf("%d", &input);
		printf("%lld\n", rec(input));
	}
	return 0;
}


	// for (int i = 0; i < N; i++)
	// 	scanf("%d", arr + i);
	// for (int i = 0; i < N; i++)
	// 	printf("%d\n", rec(arr[i]));