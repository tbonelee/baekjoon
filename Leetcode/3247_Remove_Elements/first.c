
int removeElement(int* nums, int numsSize, int val){
	int numRemove = 0;
	for (int i = 0; i < numsSize; i++){
		if (nums[i] == val){
			numRemove++;
		}
	}
	int i = 0, j = 0;
	for (;i < numsSize - numRemove;){
		if (nums[j] == val){
			j++;
		}
		else{
			nums[i++] = nums[j++];
		}
	}
    return numsSize - numRemove;
}