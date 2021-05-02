#include <stdio.h>

int g_memo[1000001];


int rec(int N)
{
	if (N == 1)
		return 1;
	else if (N == 2)
		return 2;

	if (g_memo[N - 1] == -1)
		g_memo[N - 1] = rec(N - 1);
	if (g_memo[N - 2] == -1)
		g_memo[N - 2] = rec(N - 2);
	return ((g_memo[N - 1] + g_memo[N - 2]) % 15746);
}

int main()
{

	for (int i = 0; i <= 1000000; i++)
		g_memo[i] = -1;
	int N;
	scanf("%d", &N);


	printf("%d\n", rec(N));
}