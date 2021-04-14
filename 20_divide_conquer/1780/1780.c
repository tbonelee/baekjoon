#include <stdio.h>

int count_one = 0;
int count_neg_one = 0;
int count_zero = 0;
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
	printf("%d\n%d\n%d\n", count_neg_one, count_zero, count_one);
}

void find(int N, int i_start, int i_end, int j_start, int j_end)
{
	int flag = map[i_start][j_start];
	int i, j;
	int flag1 = flag, flag2 = flag, flag3 = flag, flag4 = flag, flag5 = flag, flag6 = flag, flag7 = flag, flag8 = flag, flag9 = flag;
	int i_one3rd = i_start + (i_end + 1 - i_start) / 3 * 1;
	int i_two3rd = i_start + (i_end + 1 - i_start) / 3 * 2;
	int j_one3rd = j_start + (j_end + 1 - j_start) / 3 * 1;
	int j_two3rd = j_start + (j_end + 1 - j_start) / 3 * 2;
	// flag = map[i_start][j_start];
	for (i = i_start; i < i_one3rd; i++)
		for (j = j_start; j < j_one3rd; j++)
		{
			if (flag1 == -2)
				break ;
			if (map[i][j] != flag)
			{
			// 	printf("flag1, i_start = %d, i_end = %d\n", i_start, i_end);
			// 	printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag1 = -2;
				find(N, i_start, i_one3rd - 1, j_start, j_one3rd - 1);
				break ;
			}
		}
	// flag = map[i_start]
	for (i = i_start; i < i_one3rd; i++)
		for (j = j_one3rd; j < j_two3rd; j++)
		{
			if (flag2 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag2, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag2 = -2;
				find(N, i_start, i_one3rd - 1, j_one3rd, j_two3rd - 1);
				break ;
			}
		}
	for (i = i_start; i < i_one3rd; i++)
		for (j = j_two3rd; j <= j_end; j++)
		{
			if (flag3 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag3, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end,flag);
				flag3 = -2;
				find(N, i_start, i_one3rd - 1, j_two3rd, j_end);
				break ;
			}
		}
	for (i = i_one3rd; i < i_two3rd; i++)
		for (j = j_start; j < j_one3rd; j++)
		{
			if (flag4 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag4, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag4 = -2;
				find(N, i_one3rd, i_two3rd - 1, j_start, j_one3rd - 1);
				break ;
			}
		}
	for (i = i_one3rd; i < i_two3rd; i++)
		for (j = j_one3rd; j < j_two3rd; j++)
		{
			if (flag5 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag5, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag5 = -2;
				find(N, i_one3rd, i_two3rd - 1, j_one3rd, j_two3rd - 1);
				break ;
			}
		}
	for (i = i_one3rd; i < i_two3rd; i++)
		for (j = j_two3rd; j <= j_end; j++)
		{
			if (flag6 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag6, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag6 = -2;
				find(N, i_one3rd, i_two3rd - 1, j_two3rd, j_end);
				break ;
			}
		}
	for (i = i_two3rd; i <= i_end; i++)
		for (j = j_start; j < j_one3rd; j++)
		{
			if (flag7 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag7, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag7 = -2;
				find(N, i_two3rd, i_end, j_start, j_one3rd - 1);
				break ;
			}
		}
	for (i = i_two3rd; i <= i_end; i++)
		for (j = j_one3rd; j < j_two3rd; j++)
		{
			if (flag8 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag8, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag8 = -2;
				find(N, i_two3rd, i_end, j_one3rd, j_two3rd - 1);
				break ;
			}
		}
	for (i = i_two3rd; i <= i_end; i++)
		for (j = j_two3rd; j <= j_end; j++)
		{
			if (flag9 == -2)
				break ;
			if (map[i][j] != flag)
			{
				// printf("flag9, i_start = %d, i_end = %d\n", i_start, i_end);
				// printf("       j_start = %d, j_end = %d, flag = %d\n", j_start, j_end, flag);
				flag9 = -2;
				find(N, i_two3rd, i_end, j_two3rd, j_end);
				break ;
			}
		}




	if (flag1 == flag && flag2 == flag && flag3 == flag
	&& flag4 == flag && flag5 == flag && flag6 == flag
	&& flag7 == flag && flag8 == flag && flag9 == flag)
	{
		// printf("flag = %d, i_start = %d i_end = %d\n", flag, i_start, i_end);
		// printf("           j_start = %d j_end = %d\n", j_start, j_end);
		if (flag == 1)
			count_one++;
		else if (flag == 0)
			count_zero++;
		else if (flag == -1)
			count_neg_one++;
	}
	else
	{
		int cnt = 0;
		if (flag1 == flag)
			cnt++;
		if (flag2 == flag)
			cnt++;
		if (flag3 == flag)
			cnt++;
		if (flag4 == flag)
			cnt++;
		if (flag5 == flag)
			cnt++;
		if (flag6 == flag)
			cnt++;
		if (flag7 == flag)
			cnt++;
		if (flag8 == flag)
			cnt++;
		if (flag9 == flag)
			cnt++;

		if (flag == 1)
			count_one += cnt;
		else if (flag == 0)
			count_zero += cnt;
		else if (flag == -1)
			count_neg_one += cnt;

	}

	// for (i = i_start; i <= i_end; i++)
	// {
	// 	for (j = j_start; j <= j_end; j++)
	// 	{
	// 		if (map[i][j] != flag)
	// 		{
	// 			find(N, i_start, i_one3rd - 1, j_start, j_one3rd - 1);
	// 			find(N, i_start, i_one3rd - 1, j_one3rd, j_two3rd - 1);
	// 			find(N, i_start, i_one3rd - 1, j_two3rd, j_end);
	// 			find(N, i_one3rd, i_two3rd - 1, j_start, j_one3rd - 1);
	// 			find(N, i_one3rd, i_two3rd - 1, j_one3rd, j_two3rd - 1);
	// 			find(N, i_one3rd, i_two3rd - 1, j_two3rd, j_end);
	// 			find(N, i_two3rd, i_end, j_start, j_one3rd - 1);
	// 			find(N, i_two3rd, i_end, j_one3rd, j_two3rd - 1);
	// 			find(N, i_two3rd, i_end, j_two3rd, j_end);
	// 			return ;
	// 		}
	// 	}
	// }

}