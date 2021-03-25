#include <stdio.h>
#include <stdlib.h>

#define abs_dev(a, b) (a > b ? a - b : b - a)

typedef struct s_info{
	int cases;
	int team1[200000][20];
	int team2[200000][20];
	int temp[20];
	int count;
	int min;
} t_info;

int factorial(int num)
{
	if (num == 0)
		return 1;
	else
		return (num * factorial(num - 1));
}

void find(int N, int arr[][N], t_info *info, int index, int before)
{
	if (index == N / 2)
	{
		for (int i = 0; i < N; i++)
			info->team1[info->count][i] = info->temp[i];
		info->count++;
		return ;
	}

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
	for (int idx = 0; idx <info->cases; idx++)
		for (int i = 0; i < N; i++)
			if (info->team1[idx][i] == 0)
				info->team2[idx][i] = 1;
}

void find_min_deviation(int N, int arr[][N], t_info *info)
{
	int score1 = 0;
	int score2 = 0;
	int dev;

	for (int i = 0; i < N; i++)
		for (int j = 0; j <N; j++)
		{
			if (info->team1[0][i] == 1 && info->team1[0][j] == 1
			&& i != j)
				score1 += arr[i][j];
			if (info->team2[0][i] == 1 && info->team2[0][j] == 1
			&& i != j)
				score2 += arr[i][j];

		}
	info->min = abs_dev(score1, score2);

	for (int idx = 1; idx < info->cases; idx++)
	{
		score1 = 0, score2 = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (info->team1[idx][i] == 1 && info->team1[idx][j] == 1
				&& i != j)
					score1 += arr[i][j];
				if (info->team2[idx][i] == 1 && info->team2[idx][j] == 1
				&& i != j)
					score2 += arr[i][j];
			}
		dev = abs_dev(score1, score2);
		if (dev < info->min)
			info->min = dev;
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	int arr[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	int cases = factorial(N) / (factorial(N / 2) * factorial(N / 2));

	t_info *info = (t_info *)malloc(sizeof(t_info));
	info->cases = cases;

	for (int i = 0; i < cases; i++)
		for (int j = 0; j < N; j++)
		{
			info->team1[i][j] = 0;
			info->team2[i][j] = 0;
		}
	for (int j = 0; j < N; j++)
		info->temp[j] = 0;

	find (N, arr, info, 0, 0);

	fills_team2(N, info);

	find_min_deviation(N, arr, info);

	printf("%d", info->min);

	return 0;
}