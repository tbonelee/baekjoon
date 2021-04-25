// 참조 : https://debuglog.tistory.com/80
// dp[i] : i번째 와인을 마시던 안 마시던 상관 없이 i번째 위치에서 최대로 얻을 수 있는 누적 와인량
// dp[0] ~ dp[n]
// dp[0] = 0;
// dp[1] = array[1];
// dp[2] = array[1] + array[2];
// i >= 3
// dp[i] =
// 	(이번에 안 마신 경우)dp[i - 1] (<= 이번에 안 마신 경우, 직전의 최대량과 동일)
// 	(직전에 안 마시고 이번에 마시는 경우)dp[i - 2] + array[i] (<= 직전에 안 마시고 이번에 마시는 경우, 두번째 전의 최대량에 이번 와인을 더한 것과 동일)
// 	(직전에 마시고 이번에도 마시는 경우)dp[i - 3] + array[i - 1] + array[i] (<= 직전에 마시고 이번에도 마시는 경우, 두번째 전에는 못 마시므로 건너 뛰고 i - 3번째의 최대량에 i-1, i번째 와인을 더한 것)
#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int main(){
	int n; scanf("%d", &n);
	vector<int> array(n + 1);
	for (int i = 1; i < array.size(); i++){
		scanf("%d", &array[i]);
	}
	vector<int> dp(n + 1, 4);
	dp[0] = 0;
	dp[1] = array[1];
	dp[2] = array[1] + array[2];
	for (int i = 3; i <= n; i++){
		dp[i] = max(dp[i - 1], max(dp[i - 2] + array[i], dp[i - 3] + array[i - 1] + array[i]));
	}
	// for (int i = 0; i < n; i++){
	// 	printf("array[%d] = %d\n", i, array[i]);
	// 	for (int j = 0; j < 2; j++){
	// 		printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	printf("%d\n", dp[n]);
}