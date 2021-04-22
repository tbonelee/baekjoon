#include <stdlib.h>

int comp(const void *a, const void *b){
	int aa = *(int *)a, bb = *(int *)b;
	return (aa - bb);
}

int heightChecker(int* heights, int heightsSize){
	int *temp = (int *)malloc(sizeof(int) * heightsSize);
	for (int i = 0; i < heightsSize; i++)
		temp[i] = heights[i];
	qsort(temp, heightsSize, sizeof(int), &comp);
	int ret = 0;
	for (int i = 0; i < heightsSize; i++)
		if (heights[i] != temp[i])
			ret++;
	free(temp);
	return (ret);
}