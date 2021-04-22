#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int *ret = (int *)malloc(sizeof(int) * ASize);
	*returnSize = ASize;
	int idx = 0;
	for (int i = 0; i < ASize; i++)
		if (A[i] % 2 == 0)
			ret[idx++] = A[i];
	for (int i = 0; i < ASize; i++)
		if (A[i] % 2 != 0)
			ret[idx++] = A[i];
	return ret;
}