#include <stdlib.h>
#include <limits.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int **dp = (int **)calloc(triangleSize, sizeof(int *));
	for (int i = 0; i < triangleSize; i++)
	{
		dp[i] = (int *)calloc(triangleColSize[i], sizeof(int));
	}
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangleSize; i++)
	{
		for (int j = 0; j < triangleColSize[i]; j++)
		{
			int min = INT_MAX;
			if (j != 0)
				min = dp[i - 1][j - 1] < min ? dp[i - 1][j - 1] : min;
			if (j != i)
				min = dp[i - 1][j] < min ? dp[i - 1][j] : min;
			dp[i][j] = min + triangle[i][j];

		}
	}
	int finalmin = INT_MAX;
	for (int j = 0; j < triangleSize; j++)
	{
		if (dp[triangleSize - 1][j] < finalmin)
			finalmin = dp[triangleSize - 1][j];

	}
	for (int i = 1; i < triangleSize; i++)
	{
		free(dp[i]);
	}
	free(dp);
	return (finalmin);
}