#include <stdio.h>
#include <limits.h>

int N, K;
int arr_small[20];
int arr_big[20];
int dp_after_K[21];
int dp_before_K[21];

extern inline int min(int a, int b);

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++)
		scanf("%d %d", &arr_small[i], &arr_big[i]);
	scanf("%d", &K);
	dp_before_K[1] = 0;
	dp_after_K[1] = INT_MAX;
	if (N >= 2)
	{
		dp_before_K[2] = dp_before_K[1] + arr_small[1];
		dp_after_K[2] = INT_MAX;
	}
	if (N >= 3)
	{
		dp_before_K[3] = min(dp_before_K[2] + arr_small[2], dp_before_K[1] + arr_big[1]);
		dp_after_K[3] = INT_MAX;
	}
	if (N >= 4)
	{
		dp_before_K[4] = min(dp_before_K[3] + arr_small[3], dp_before_K[2] + arr_big[2]);
		dp_after_K[4] = dp_before_K[1] + K;
	}
	if (N >= 5)
	{
		dp_before_K[5] = min(dp_before_K[4] + arr_small[4], dp_before_K[3] + arr_big[3]);
		dp_after_K[5] = min(dp_before_K[2] + K, dp_after_K[4] + arr_small[4]);
	}
	for (int i = 6; i <= N; i++)
	{
		dp_before_K[i] = min(dp_before_K[i - 1] + arr_small[i - 1], dp_before_K[i - 2] + arr_big[i - 2]);
		dp_after_K[i] = min(dp_before_K[i - 3] + K, min(dp_after_K[i - 1] + arr_small[i - 1], dp_after_K[i - 2] + arr_big[i - 2]));
	}
	// printf("K = %d\n", K);
	// for (int i = 1; i <= N; i++)
	// {
	// 	printf("i = %d, before = %d, after = %d\n", i, dp_before_K[i], dp_after_K[i]);
	// }
	printf("%d\n", min(dp_before_K[N], dp_after_K[N]));
	return 0;
}


extern inline int min(int a, int b)
{
	return (a < b ? a : b);
}