#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
	int *check = (int *)malloc(sizeof(int) * numsSize);
	memset(check, 0, sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++)
		check[nums[i] - 1]++;
	*returnSize = 0;
	for (int i = 0; i < numsSize; i++)
		if (check[i] == 0){
			check[(*returnSize)++] = i + 1;
		}
	int *ret = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; i++)
		ret[i] = check[i];
	free(check);
	return (ret);
}