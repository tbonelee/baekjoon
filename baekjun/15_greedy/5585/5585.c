#include <stdio.h>

int main()
{
	int N; scanf("%d", &N);
	N = 1000 - N;
	// printf("N = %d\n", N);
	int coin[6] = {500, 100, 50, 10, 5, 1};
	int ret = 0;
	for (int i = 0; i < 6; i++)
	{
		if (N >= coin[i])
		{
			// printf("+ = %d, ", N / coin[i]);
			ret += N / coin[i];
			N -= coin[i] * (N / coin[i]);
			// printf("ret = %d, coin = %d\n", ret, coin[i]);
		}
		if (N == 0)
			break;
	}
	printf("%d\n", ret);
	return 0;
}