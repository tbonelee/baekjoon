	#include <stdlib.h>
	#include <string.h>

	int leastBricks(int** wall, int wallSize, int* wallColSize){
		int *wall_memo_sum = (int *)malloc(sizeof(int) * wallSize);
		int *wall_memo_idx = (int *)malloc(sizeof(int) * wallSize);
		int width = 0;
		for (int i = 0; i < wallColSize[0]; i++)
			width += wall[0][i];
		memset(wall_memo_sum, 0, sizeof(int) * wallSize);
		memset(wall_memo_idx, 0, sizeof(int) * wallSize);
		int min = 15000;
		for (int i = 1; i < width; i++)
		{
			int num = 0;
			for (int j = 0; j < wallSize; j++)
			{
				if (wall_memo_sum[j] < i)
				{
					wall_memo_sum[j] += wall[wall_memo_idx[j]++];
				}
				if (wall_memo_sum[j] > i)
					num++;
			}
			if (num < min)
				min = num;
		}
		free(wall_memo_sum);
		free(wall_memo_idx);
		return min;
	}


#include <stdlib.h>
#include <string.h>

int leastBricks(int** wall, int wallSize, int* wallColSize){

	int width = 0;
	for (int i = 0; i < wallColSize[0]; i++)
		width += wall[0][i];
	int *memo = (int *)malloc(sizeof(int) * (width + 1));
	memset(memo, 0, sizeof(int) * (width));


	for (int i = 0; i < wallSize; i++)
	{
		int sum = 0;
		for (int j = 0; j < wallColSize[i]; j++)
		{
			sum += wall[i][j];
			memo[sum]++;
		}
	}
	int max = 0;
	for (int i = 1; i < width; i++)
		if (memo[i] > max)
			max = memo[i];
	free(memo);
	return (wallSize - max);
	// for (int i = 1; i < width; i++)
	// {
	// 	int num = 0;
	// 	for (int j = 0; j < wallSize; j++)
	// 	{
	// 		if (wall_memo_sum[j] < i)
	// 		{
	// 			wall_memo_sum[j] += wall[wall_memo_idx[j]++];
	// 		}
	// 		if (wall_memo_sum[j] > i)
	// 			num++;
	// 	}
	// 	if (num < min)
	// 		min = num;
	// }

}