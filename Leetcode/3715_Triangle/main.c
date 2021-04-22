#include <stdio.h>
#include <stdlib.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize);

int main()
{
	int triangleSize;
	printf("trianglesize =");
	scanf("%d", &triangleSize);
	int **triangle = (int **)calloc(triangleSize, sizeof(int *));
	int *triangleColSize = (int *)calloc(triangleSize, sizeof(int));
	printf("now elements\n");
	for (int i = 0; i < triangleSize; i++)
	{
		triangleColSize[i] = i + 1;
		triangle[i] = (int *)calloc(triangleColSize[i], sizeof(int));
		for (int j = 0; j <= i; j++)
			scanf("%d", &triangle[i][j]);
	}
	printf("result = %d\n", minimumTotal(triangle, triangleSize, triangleColSize));
	// return (-1);
	return 0;
}