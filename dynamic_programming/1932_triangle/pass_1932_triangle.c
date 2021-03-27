#include <stdio.h>


// depth는 삼각형에서 몇 번째 줄인지(N이면 맨 밑의 줄, 1이면 맨 윗 줄)
// idx는 해당 줄에서 왼쪽에서 몇 번째 숫자인지
int max(int N, int tri[][N + 1], int memo[][N + 1])
{
	memo[1][1] = tri[1][1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				memo[i][j] = memo[i - 1][j] + tri[i][j];
			else if (j == i)
				memo[i][j] = memo[i - 1][j - 1] + tri[i][j];
			else
				memo[i][j] = (memo[i - 1][j] > memo[i - 1][j - 1] ? memo[i - 1][j] : memo[i - 1][j - 1])
							+ tri[i][j];
			// printf("memo[%d][%d] = %d\n", i, j, memo[i][j]);
		}
	}

	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		// printf("memo[N][%d] = %d\n", i, memo[N][i]);
		if (memo[N][i] > ret)
			ret = memo[N][i];
	}
	return (ret);
}

int main()
{
	int N;
	scanf("%d", &N);

	int tri[N + 1][N + 1];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &tri[i][j]);

	// memo[i][j]는 i번째 줄에서 j번째 숫자를 선택할 수 있는 경로를 선택했을 때
	// 해당 숫자까지의 sum 중 가능한 가장 큰 값
	int memo[N + 1][N + 1];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			memo[i][j] = 0;


	printf("%d\n", max(N, tri, memo));

}