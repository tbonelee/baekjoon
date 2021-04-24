

int countBinarySubstrings(char * s){
	int ret = 0;
	int nums[2] = {0, 0};
	nums[s[0] - '0']++;
	for (int i = 1; s[i]; i++){
		if (s[i] != s[i - 1]){
			ret += nums[0] < nums[1] ? nums[0] : nums[1];
			nums[s[i] - '0'] = 1;
		}
		else{
			nums[s[i] - '0']++;
		}
	}
	ret += nums[0] < nums[1] ? nums[0] : nums[1];
	return (ret);
}