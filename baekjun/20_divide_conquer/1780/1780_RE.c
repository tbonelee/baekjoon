#include <stdio.h>

int count_one = 0;
int count_neg_one = 0;
int count_zero = 0;
int cnt[3] = {0,};
int map[2200][2200];

void find(int N, int i_start, int i_end, int j_start, int j_end);
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
	find(N, 1, N, 1, N);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);
}

void find(int N, int i_start, int i_end, int j_start, int j_end)
{
	int temp = map[i_start][j_start];
	if (N == 1)
	{
		cnt[temp + 1]++;
		return ;
	}
	for (int i = i_start; i <= i_end; i++)
	{
		for (int j = j_start; j <= j_end; j++)
		{
			if (map[i][j] != temp)
			{
				printf("N = %d, i_start = %d, i_end = %d, j_start = %d, j_end = %d\n", N, i_start, i_end, j_start, j_end);
				printf("temp = %d, map[i][j] = %d\n", temp, map[i][j]);
				printf("i = %d, j = %d\n\
i_start = %d, i_start + N / 3 - 1 = %d\n\
i_start + N / 3 = %d, i_start + N / 3 * 2 - 1 = %d\n\
i_start + N / 3 * 2 = %d, i_end = %d\n\
j_start = %d, j_start + N / 3 - 1 = %d\n\
j_start + N / 3 = %d, j_start + N / 3 * 2 - 1 = %d\n\
j_start + N / 3 * 2 = %d, j_end = %d\n", i , j, i_start, i_start + N / 3 - 1,\
i_start + N / 3, i_start + N / 3 * 2 - 1, i_start + N / 3 * 2, i_end,\
j_start, j_start + N / 3 -1, j_start + N / 3, j_start + N / 3 * 2 - 1, j_start + N / 3 * 2, j_end );
				find(N / 3, i_start, i_start + N / 3 - 1, j_start, j_start + N / 3 - 1);
				find(N / 3, i_start, i_start + N / 3 - 1, j_start + N / 3 * 1, j_start + N / 3 * 2 - 1);
				find(N / 3, i_start, i_start + N / 3 - 1, j_start + N / 3 * 2, j_end);
				find(N / 3, i_start + N / 3, i_start + N / 3 * 2 - 1, j_start, j_start + N / 3 - 1);
				find(N / 3, i_start + N / 3, i_start + N / 3 * 2 - 1, j_start + N / 3 * 1, j_start + N / 3 * 2 - 1);
				find(N / 3, i_start + N / 3, i_start + N / 3 * 2 - 1, j_start + N / 3 * 2, j_end);
				find(N / 3, i_start + N / 3 * 2, i_end, j_start, j_start + N / 3 - 1);
				find(N / 3, i_start + N / 3 * 2, i_end, j_start + N / 3 * 1, j_start + N / 3 * 2 - 1);
				find(N / 3, i_start + N / 3 * 2, i_end, j_start + N / 3 * 2, j_end);
				return ;
			}
		}
	}

	cnt[temp + 1]++;
}