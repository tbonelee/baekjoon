// 이전 문제에서 가져올 때 배열 크기를 늘려주지 않았음.
// 시간초과로 나와서 계속 알고리즘 개선을 해봤지만 나중에 배열 크기 늘려줬더니 통과

// * 시간초과라고 나와도 효율성 문제 아닐 수 있음

#include <stdio.h>

int count_one = 0;
int count_neg_one = 0;
int count_zero = 0;
int cnt[3] = {0,};
int map[2200][2200];

void find(int N, int i_start, int j_start);
int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	find(N, 1, 1);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);
}

void find(int N, int i_start, int j_start)
{
	int temp = map[i_start][j_start];
	if (N == 1)
	{
		cnt[temp + 1]++;
		return ;
	}
	for (int i = i_start; i < i_start + N; i++)
	{
		for (int j = j_start; j < j_start + N; j++)
		{
			if (map[i][j] != temp)
			{
				int n = N / 3, n2 = (N / 3) * 2;
				find(n, i_start, j_start);
				find(n, i_start, j_start + n);
				find(n, i_start, j_start + n2);
				find(n, i_start + n, j_start);
				find(n, i_start + n, j_start + n);
				find(n, i_start + n, j_start + n2);
				find(n, i_start + n2, j_start);
				find(n, i_start + n2, j_start + n);
				find(n, i_start + n2, j_start + n2);
				return ;
			}
		}
	}

	cnt[temp + 1]++;
}