#include <stdio.h>

int count_blue = 0;
int count_white = 0;
int map[130][130];

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
	printf("%d\n%d\n", count_white, count_blue);
}

void find(int N, int i_start, int i_end, int j_start, int j_end)
{
	int flag = map[i_start][j_start];
	int i, j;
	for (i = i_start; i <= i_end; i++)
	{
		for (j = j_start; j <= j_end; j++)
		{
			if (map[i][j] != flag)
			{
				int i_mid = (i_start + i_end) / 2;
				int j_mid = (j_start + j_end) / 2;
				find(N, i_start, i_mid, j_start, j_mid);
				find(N, i_start, i_mid, j_mid + 1, j_end);
				find(N, i_mid + 1, i_end, j_start, j_mid);
				find(N, i_mid + 1, i_end, j_mid + 1, j_end);
				return ;
			}
		}
	}
	if (flag == 1)
		count_blue++;
	else if (flag == 0)
		count_white++;
}