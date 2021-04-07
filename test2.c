
#include <stdio.h>

int		g_arr[10];
int		g_sign = 1;
int		N,M;

void	DFS(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M - 1; i++)
		{
			for (int j = i + 1; j < M; j++)
			{
				if (g_arr[i] == g_arr[j])
				{
					g_sign = 0;
                    break ;
				}
			}
		}
		if (g_sign)
		{
			for (int i = 0; i < M; i++)
			{
				printf("%d ", g_arr[i]);
			}
			printf("\n");
		}
		g_sign = 1;
		return ;
	}
	for (int i = 1; i <= N; i++)
	{
		g_arr[depth] = i;
		DFS(depth + 1);
	}
}
#include <time.h>
int	main()
{
	scanf("%d %d", &N, &M);

	clock_t start[100];
	clock_t end[100];
	for (int i = 0; i < 10 ; i++)
	{
		start[i] = clock();
		DFS(0);
		end[i] = clock();
	}
	// printf("here");
	double mean = 0;
	for (int i = 0; i < 10; i++)
	{
		mean += (double)(end[i] - start[i]);
		printf("Time%d %lf\n", i, (double)(end[i] - start[i])/CLOCKS_PER_SEC);
	}
	mean /= 10;
	printf("Time: %lf\n", mean / CLOCKS_PER_SEC);




	return (0);
}
