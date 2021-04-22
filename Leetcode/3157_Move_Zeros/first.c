
#include <stdio.h>

// void moveZeroes(int* nums, int numsSize){
// 	int i = 0, j = 0;
// 	for (; i < numsSize; i++, j++){
// 		for (; nums[i] == 0; i++)
// 			;

// 		if (i < numsSize)
// 			nums[j] = nums[i];
// 	}
// 	for (; j < numsSize; j++){
// 		nums[j] = 0;
// 	}
// }

// void moveZeroes(int* nums, int numsSize){
// 	int i = 0, j = 0;
// 	for (; i < numsSize; i++, j++){
// 		for (; i < numsSize && nums[i] == 0; i++)
// 			;
// 		printf("j = %d, i = %d, nums[i] = %d\n", j, i, nums[i]);
// 		if (i < numsSize)
//     		nums[j] = nums[i];
// 	}
// 	j--;
// 	printf("j = %d\n", j);
// 	if (j >= 0)
// 		for (; j < numsSize; j++){
// 			nums[j] = 0;
// 		}
// }
int main(){
	int arr[1] = {};
	moveZeroes(arr, 1);
	for (int i = 0; i < 1; i++)
		printf("%d ", arr[i]);
}

void moveZeroes(int* nums, int numsSize){
	int i = 0, j = 0;
	for (; i < numsSize; i++){
		printf("j = %d, i = %d, nums[i] = %d\n", j, i, nums[i]);
		if (nums[i])
    		nums[j++] = nums[i];
	}
	printf("j = %d\n", j);
	for (; j < numsSize; j++){
		nums[j] = 0;
	}
}