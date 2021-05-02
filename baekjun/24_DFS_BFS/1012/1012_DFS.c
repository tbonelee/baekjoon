
#include <stdio.h>
#include <stdbool.h>

typedef struct s_location
{
	int m;
	int n;
}	t_location;


int		sub(bool map[][50], int M, int N, int m, int n);

int main()
{
	int T; scanf("%d", &T);
	bool map[50][50] = {false,};
	int M, N, K;
	int temp_m, temp_n;
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d %d", &M, &N, &K);
		for (int j = 1; j <= K; j++)
		{
			scanf("%d %d", &temp_m, &temp_n);
			map[temp_m][temp_n] = true;
		}
		int cnt = 0;
		for (int m = 0; m < M; m++)
		{
			for (int n = 0; n < N; n++)
			{
				if (map[m][n] == true)
				{
					cnt++;
					sub(map, M, N, m, n);
				}
			}
		}

		printf("%d\n", cnt);
		for (int m = 0; m < M; m++)
		{
			for (int n = 0; n < N; n++)
			{
				map[m][n] = false;
			}
		}
	}
}



int		sub(bool map[][50], int M, int N, int m, int n)
{
	map[m][n] = false;
	if (m != 0 && map[m - 1][n])
	{
		sub(map, M, N, m - 1, n);
	}
	if (n != 0 && map[m][n - 1])
	{
		sub(map, M, N, m, n - 1);
	}
	if (m != M - 1 && map[m + 1][n])
	{
		sub(map, M, N, m + 1, n);
	}
	if (n != N - 1 && map[m][n + 1])
	{
		sub(map, M, N, m, n + 1);
	}

	return (0);
}
