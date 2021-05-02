#include <stdio.h>
#include <stdlib.h>

typedef struct s_info{
	int cases;
	int team1[200000][20];
	int team2[200000][20];
	int temp[20];
	int count;
	long long min;
	int min_idx;
} t_info;

int factorial(int num)
{
	if (num == 0)
		return (1);
	else
		return (num * factorial(num - 1));
}

void find(int N, int arr[][N], t_info *info, int index, int before)
{
	if (index == N / 2)
	{
		for (int i = 0; i < N; i++)
		{
					// printf("before - info->team1[%d][%d] = %d\n", info->count, i, info->team1[info->count][i]);

			info->team1[info->count][i] = info->temp[i];
				printf(" after - info->team1[%d][%d] = %d\n", info->count, i, info->team1[info->count][i]);

		}
		info->count++;
		return ;
	}
	// printf("info->temp[index - 1] = %d\n, index = %d\n",	info->temp[index - 1], index);
	int i;
	if (index == 0)
		i = 0;
	else
		i = before + 1;
	for (; i < N; i++)
	{
		info->temp[i] = 1;
		find(N, arr, info, index + 1, i);
		info->temp[i] = 0;
	}
}

void fills_team2(int N, t_info *info)
{
	for (int idx = 0; idx < info->cases; idx++)
		for (int i = 0; i < N; i++)
			if (info->team1[idx][i] == 0)
				info->team2[idx][i] = 1;
}

void find_min_deviation(int N, int arr[][N], t_info *info)
{
	long long score1 = 0;
	long long score2 = 0;
	long long dev = 0;

	// {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (info->team1[0][i] == 1 && info->team1[0][j] == 1
				&& i != j)
				{
					score1 += arr[i][j];

					printf("i = %d, j = %d, arr[i][j] = %d\n", i, j, arr[i][j]);
				}
				if (info->team2[0][i] == 1 && info->team2[0][j] == 1
				&& i != j)
				{
					score2 += arr[i][j];

					printf("2) i = %d, j = %d, arr[i][j] = %d\n", i, j, arr[i][j]);
				}
			}
		info->min = (score1 > score2 ? score1 - score2 : score2 - score1);
		info->min_idx = 0;

		printf("idx = %d, dev = %lld, info->min = %lld\n score1 = %lld, score2 = %lld\n", 0, dev, info->min, score1, score2);

	// }


	for (int idx = 1; idx < info->cases; idx++)
	{
		score1 = 0, score2 = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (info->team1[idx][i] == 1 && info->team1[idx][j] == 1
				&& i != j)
				{
					score1 += arr[i][j];
					printf("i = %d, j = %d, arr[i][j] = %d\n", i, j, arr[i][j]);
				}
				if (info->team2[idx][i] == 1 && info->team2[idx][j] == 1
				&& i != j)
				{
					score2 += arr[i][j];
					printf("2) i = %d, j = %d, arr[i][j] = %d\n", i, j, arr[i][j]);
				}
		}
		dev = (score1 > score2 ? score1 - score2 : score2 - score1);
		printf("idx = %d, dev = %lld, info->min = %lld\n score1 = %lld, score2 = %lld\n", idx, dev, info->min, score1, score2);
		if (dev < info->min)
		{
			info->min = dev;
			info->min_idx = idx;
		}

	}

	// printf("info->min = %lld \n", info->min);
}

int main()
{
	int N;
	scanf("%d", &N);

	int arr[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	// 팀 구성의 경우의 수
	int cases = factorial(N) / (factorial(N / 2) * factorial(N / 2));

	// printf("cases = %d\n", cases);

	// printf("here");
	t_info *info = (t_info *)malloc(sizeof(t_info));
	info->cases = cases;
	// info->team1 = (int **)malloc(sizeof(int *) * (cases));
	// info->team2 = (int **)malloc(sizeof(int *) * (cases));
	// for (int i = 0; i < cases; i++)
	// {
	// 	info->team1[i] = (int *)malloc(sizeof(int) * N);
	// 	info->team2[i] = (int *)malloc(sizeof(int) * N);
	// }
	// info->temp = (int *)malloc(sizeof(int) * N);



	// 초기화
	for (int i = 0; i < cases; i++)
		for (int j = 0; j < N; j++)
		{
			info->team1[i][j] = 0;
			info->team1[i][j] = 0;
		}
	for (int j = 0; j < N; j++)
		info->temp[j] = 0;

	// printf("info->team1[0][0] = %d\n", info->team1[0][0]);

	find (N, arr, info, 0, 0);

	fills_team2(N, info);

	// printf("passed");
	/////////////////////
	// for (int i = 0; i < cases; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 		printf("team1[%d][%d] = %d, ", i, j, info->team1[i][j]);
	// 	printf("\n");
	// }
	// printf("=================\n");
	// for (int i = 0; i < cases; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 		printf("team2[%d][%d] = %d, ", i, j, info->team2[i][j]);
	// 	printf("\n");
	// }
////////////////////////////////


	find_min_deviation(N, arr, info);

	printf("%lld\n", info->min);

	// for (int i = 0; i < cases; i++)
	// {
	// 	free(info->team1[i]);
	// 	free(info->team2[i]);
	// }
	// free(info->team1);
	// free(info->team2);
	// free(info);
	return 0;
}