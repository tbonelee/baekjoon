#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

void find(int N, int arr[][100], int i, int j, ll dp[][100]);

int main()
{
	int N; scanf("%d", &N);
	int arr[100][100];
	ll dp[100][100];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	find(N, arr, N - 1, N - 1, dp);
	printf("%lld\n", dp[N - 1][N - 1]);
}


void find(int N, int arr[][100], int i, int j, ll dp[][100])
{
	ll sum = 0;
	for (int ii = 1; ii <= 9 && i - ii >= 0; ii++)
	{
		if (ii == arr[i - ii][j])
		{
			if (dp[i - ii][j] == -1)
				find(N, arr, i - ii, j, dp);
			sum += dp[i - ii][j];
		}
	}

	for (int jj = 1; jj <= 9 && j- jj >= 0; jj++)
	{
		if (jj == arr[i][j - jj])
		{
			if (dp[i][j - jj] == -1)
				find(N, arr, i, j - jj, dp);
			sum += dp[i][j - jj];
		}
	}
	dp[i][j] = sum;
}