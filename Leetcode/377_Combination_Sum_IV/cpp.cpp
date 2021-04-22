class Solution {
public:
int combinationSum4(vector& nums, int target) {
vector dp(target);
int i, j;
dp[0] = 1;
for(i = 1; i <= target; ++i) {
for(j = 0; j < nums.size(); ++j) {
if(i - nums[j] >= 0) {
dp[i] += dp[i - nums[j]];
}
}
if(i > 300) {
cout << i << " " << dp[i] << endl;
}
}
return dp[target];
}
};