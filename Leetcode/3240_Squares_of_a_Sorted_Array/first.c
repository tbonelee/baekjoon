/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    int aa = *(int *)a, bb = *(int *)b;
    return (aa - bb);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
        ret[i] = nums[i] * nums[i];
    qsort(ret, numsSize, sizeof(int), &comp);
	*returnSize = numsSize;
	return (ret);
}

int main()
{
	int size;
	scanf("%d", &size);
	int arr[size];
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	sortedSquares(arr, size, )
}