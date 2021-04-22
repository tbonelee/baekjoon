#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fact[1001];
int numcopy[200];
int ret = 0;
int memo[200];

int comp(const void *a, const void *b);

void backtrack(int target, int numsSize, int idx, int sum);

void calc_comb(void);

int combinationSum4(int* nums, int numsSize, int target)
{
	int temp = 1;
	for (int i = 1; i <= 1000; i++)
	{
		temp *= i;
		fact[i] = temp;
	}

	for (int i = 0; i < numsSize; i++)
		numcopy[i] = nums[i];
	qsort(numcopy, numsSize, sizeof(int), &comp);

	for (int i = 0; i <= target / numcopy[0]; i++)
	{
		memo[0] = i;
		backtrack(target, numsSize, 1, numcopy[0] * i);
		memo[0] = -1;
	}
	return (ret);
}

void backtrack(int target, int numsSize, int idx, int sum)
{
	if (idx == numsSize)
	{
		// printf("idx = numsSize\n");
		// printf(" idx = %d, sum = %d, target = %d\n", idx, sum, target);
		if (sum == target)
		{
			// printf("sum = target\n");
			calc_comb();
		}
		return ;
	}
	int remain = target - sum;
	// printf("remain = %d, idx = %d\n", remain, idx);
	for (int i = 0; i <= remain / numcopy[idx]; i++ )
	{
		memo[idx] = i;
		backtrack(target, numsSize,idx + 1, sum + (i * numcopy[idx]));
		memo[idx] = -1;
	}
}


void calc_comb(void)
{
	int num = 0;
	int denom = 1;
	for (int i = 0; i < 200; i++)
	{
		num += memo[i];
		if (memo[i] > 0)
			denom *= fact[memo[i]];
	}
	// printf("denom = %d\n", denom);
	ret += fact[num] / denom;
}

// void backtrack(int arr[], int target, int numsSize, int *ret, int idx, int sum)
// {


// 	if (sum == target)
// 	{
// 		// printf("(success)ret = %d\n", *ret + 1);
// 		*ret += 1;
// 		return ;
// 	}
// 	else if (sum > target)
// 		return ;
// 	else if ((target - sum) < arr[0])
// 		return ;
// 	if (idx == numsSize)
// 		return ;
// 	// int remain = target - sum;
// 	// int n = remain / arr[idx];
// 	for (int i = 0; i < numsSize; i++)
// 	{
// 		// printf("i = %d, idx = %d, sum = %d, ret = %d\n", i, idx, sum + arr[idx], *ret);
// 		backtrack(arr, target, numsSize, ret, i, sum + arr[i] );
// 	}
// 	// backtrack(arr, target, numsSize, ret, idx, sum + arr[idx]);
// 	// backtrack(arr, target, numsSize, ret, idx + 1, sum + arr[idx]);
// 	// backtrack(arr, target, numsSize, ret, idx + 1, sum);


// }

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

	// for (int i = 1; i <= 1000; i++)
	// 	printf("fact[%d] = %d\n", i, fact[i]);

	return 0;

}