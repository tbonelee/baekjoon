
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize){
	int *temp = (int *)malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++)
		temp[i] = arr[i];
	int max = -1;
	for (int i = arrSize - 1; i >= 0; i--){
		arr[i] = max;
		if (temp[i] > max)
			max = temp[i];
	}
	free(temp);
	*returnSize = arrSize;
	return arr;
}