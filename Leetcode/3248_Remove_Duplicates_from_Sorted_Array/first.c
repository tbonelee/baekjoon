
int removeDuplicates(int* nums, int numsSize){
	int leng = numsSize;
	for (int i = numsSize - 1; i >= 0; i--){
		if (i != numsSize - 1 && nums[i] == nums[i + 1]){
			for (int j = i; j < leng - 1; j++){
				nums[j] = nums[j + 1];
			}
			leng--;
		}
	}
	return leng;
}