#include <stdio.h>
#include <stdlib.h>

int count_zero = 0;
int count_one = 0;
int map[130][130];
char output[200];
int i_output = 0;

void find(int N, int i_start, int i_end, int j_start, int j_end);
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		getchar();
		for (int j = 1; j <= N; j++)
		{
			char buf[2]; buf[1] = 0;
			scanf("%c", buf);
			map[i][j] = atoi(buf);
		}
	}
	// printf("(");
	find(N, 1, N, 1, N);
	// printf(")");
	// printf("%d\n%d\n", count_one, count_zero);
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
				printf("(");
				find(N, i_start, i_mid, j_start, j_mid);
				find(N, i_start, i_mid, j_mid + 1, j_end);
				find(N, i_mid + 1, i_end, j_start, j_mid);
				find(N, i_mid + 1, i_end, j_mid + 1, j_end);
				printf(")");
				return ;
			}
		}
	}
	if (flag == 1)
		// count_one++;
		printf("1");
	else if (flag == 0)
		// count_zero++;
		printf("0");
}