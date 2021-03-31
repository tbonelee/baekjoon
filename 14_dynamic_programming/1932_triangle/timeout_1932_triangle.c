#include <stdio.h>

#define MAX 2147483647

// depth번째 줄, 왼쪽에서 idx번째에 있는 숫자로 오는 경로 중 가장 큰 sum값을 return하는 함수
int max(int N, int tri[][N + 1], int memo[][N + 1], int idx, int depth)
{
	int ret;

	if (idx == 1)
		ret = memo[depth - 1][idx] + tri[depth][idx];
	else if (idx == depth)
		ret = memo[depth - 1][idx - 1] + tri[depth][idx];

	else
	{
		if (memo[depth - 1][idx] > memo[depth - 1][idx - 1])
			ret = memo[depth - 1][idx] + tri[depth][idx];
		else
			ret = memo[depth - 1][idx - 1] + tri[depth][idx];
	}
	return (ret);
}

// depth는 삼각형에서 몇 번째 줄인지(N이면 맨 밑의 줄, 1이면 맨 윗 줄)
// idx는 해당 줄에서 왼쪽에서 몇 번째 숫자인지
void rec(int N, int tri[][N + 1], int memo[][N + 1], int idx, int depth)
{
	if (depth == 0)
		return ;

	// 삼각형 맨 위의 숫자의 경우 && 아직 기록이 안 된 경우
	if (depth == 1 && memo [1][1] == 0)
	{
		memo[1][1] = tri[1][1];
		return ;
	}
	// 가장 왼쪽에 있는 숫자의 경우 && 아직 기록이 안 된 경우
	else if (idx == 1 && memo[depth - 1][idx] == 0)
		rec(N, tri, memo, idx, depth - 1);

	// 가장 오른쪽에 있는 숫자의 경우 && 아직 기록이 안 된 경우
	else if (idx == depth && memo[depth - 1][idx - 1] == 0)
		rec(N, tri, memo, idx - 1, depth - 1);

	else
	{
		if (memo[depth - 1][idx - 1] == 0)
			rec(N, tri, memo, idx - 1, depth - 1);
		if (memo[depth - 1][idx] == 0)
			rec(N, tri, memo, idx, depth - 1);
	}

	memo[depth][idx] = max(N, tri, memo, idx, depth);

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

	for (int i = 1; i <= N; i++)
		rec(N, tri, memo, i, N);

	int max = -1;
	for (int i = 1; i <= N; i++)
		if (memo[N][i] > max)
			max = memo[N][i];

	printf("%d\n", max);

}