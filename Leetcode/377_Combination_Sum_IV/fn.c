#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b);

void backtrack(int arr[], int target, int numsSize, int *ret, int idx, int sum);

int combinationSum4(int* nums, int numsSize, int target)
{
	int ret = 0;
	int arr[200];
	for (int i = 0; i < numsSize; i++)
		arr[i] = nums[i];
	qsort(arr, numsSize, sizeof(int), &comp);

	// for(int i = 0; i < numsSize; i++)
	// 	printf("%d ", arr[i]);

	for (int i = 0; i < numsSize; i++)
		backtrack(arr, target, numsSize, &ret, i, arr[i]);

	return (ret);
}

void backtrack(int arr[], int target, int numsSize, int *ret, int idx, int sum)
{


	if (sum == target)
	{
		// printf("(success)ret = %d\n", *ret + 1);
		*ret += 1;
		return ;
	}
	else if (sum > target)
		return ;
	else if ((target - sum) < arr[0])
		return ;
	if (idx == numsSize)
		return ;
	// int remain = target - sum;
	// int n = remain / arr[idx];
	for (int i = 0; i < numsSize; i++)
	{
		// printf("i = %d, idx = %d, sum = %d, ret = %d\n", i, idx, sum + arr[idx], *ret);
		backtrack(arr, target, numsSize, ret, i, sum + arr[i] );
	}
	// backtrack(arr, target, numsSize, ret, idx, sum + arr[idx]);
	// backtrack(arr, target, numsSize, ret, idx + 1, sum + arr[idx]);
	// backtrack(arr, target, numsSize, ret, idx + 1, sum);


}

int comp(const void *a, const void *b)
{
	int aa = *(int *)a, bb = *(int *)b;
	return (aa - bb);
}

int main()
{
	printf("arr length = ");
	int numsSize; scanf("%d", &numsSize);
	printf("nums = ");
	int nums[200];
	for (int i = 0; i < numsSize; i++)
		scanf("%d", &nums[i]);
	printf("target = ");
	int target;
	scanf("%d", &target);

	int ret;
	ret = combinationSum4(nums, numsSize, target);
	printf("\nreturn = %d\n", ret);

	return 0;

}