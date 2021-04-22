// nums[4]에 네 개의 숫자가 있다고 하자.
// 숫자 i를 만드는 경우의 수는
// i에서 nums[1]을 뺀 숫자를 만드는 경우의 수, i에서 nums[2]를 뺀 숫자를 만드는 경우의 수,
// i에서 nums[3]을 뺀 숫자를 만드는 경우의 수, i에서 nums[4]를 뺀 숫자를 만드는 경우의 수,
// 네 가지를 더한 것이라 할 수 있다.
// i에서 nums[?]를 뺀 숫자를 만들 수 있는 경우의 수에서 nums[?]를 더하면 바로 i가 되기 때문
#include <stdio.h>

#include <stdlib.h>

typedef unsigned int type;

int comp(const void *a, const void *b)
{
	int aa = *(int *)a, bb = *(int *)b;
	return (aa - bb);
}

type combinationSum4(int* nums, int numsSize, int target)
{
	qsort(nums, numsSize, sizeof(int), &comp);
	type *dp = (type *)calloc(target + 1, sizeof(type));
	dp[0] = 1;


	printf("numsSize = %d\n", numsSize);
	for (int i = 0; i < numsSize ; i++)
		printf("nums[%d]= %d\n", i, nums[i]);

	printf("0 => dp[i] = %u\n", dp[0]);
	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j < numsSize && i - nums[j] >= 0; j++)
		{
			// printf("(in)");
			// printf(" i = %d, j = %d, nums[j] = %d\n", i, j, nums[j]);
			dp[i] += dp[i - nums[j]];
		}
		// if (i > 300)
		// {
			printf("dp[%d] = %u\n", i, dp[i]);
		// }
	}
	type ret = dp[target];
	free (dp);
	return (ret);
}

#include <stdio.h>
int main()
{
	printf("arr length = ");
	int numsSize; scanf("%d", &numsSize);
	printf("nums = ");
	int nums[200];
	for (int i = 0; i < numsSize; i++)
		scanf("%d", &nums[i]);
	// printf("numsSize = %d\n", numsSize);
	// for (int i = 0; i < numsSize ; i++)
	// 	printf("nums[%d]= %d\n", i, nums[i]);
	printf("target = ");
	int target;
	scanf("%d", &target);

	long long ret;
	ret = combinationSum4(nums, numsSize, target);
	// printf("\nreturn = %d\n", ret);

	// for (int i = 1; i <= 1000; i++)
	// 	printf("fact[%d] = %d\n", i, fact[i]);

	return 0;

}