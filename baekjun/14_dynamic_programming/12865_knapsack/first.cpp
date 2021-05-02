// pair<int, int> temp를 arr[i]에 할당하는 것을 고쳐줬더니 통과
// 직접 할당하려면 make_pair 사용이 필수?
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>


// using namespace std;
// using std::vector;
// using std::pair;
// using std::max;
using namespace std;


int n, k;

int main(){
	scanf("%d %d", &n, &k);
	pair<int, int> arr[101];
	for (int i = 1; i <= n; i++){
		// pair<int, int> temp;
		scanf("%d %d", &arr[i].first, &arr[i].second);
		// arr[i] = temp;
	}
	// vector<vector<int> > dp(n + 1, vector<int>(k));
	// dp[0].assign(k, 0);
	int dp[101][100001] = {0, };
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++){
			int temp;
			if ((temp = j - arr[i].first) >= 0){
				dp[i][j] = max(dp[i - 1][temp] + arr[i].second, dp[i - 1][j]);
			}else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	// int max = 0;
	// for (int j = 0; j <= k; j++){
	// 	if (dp[n][j] > max)
	// 		max = dp[n][j];
	// }
	// printf("%d\n", max);
	printf("%d\n", dp[n][k]);
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= k; j++){
			cout << dp[i][j] << "  ";
		}
		cout << "\n";
	}
}
/////////////////////////////////////////////


// dp[0] = 0;
// dp[1] = 0;
// dp[2] =

// #include <cstdio>
// #include <vector>
// #include <utility>
// #include <algorithm>


// // using namespace std;
// using std::vector;
// using std::pair;
// using std::max;


// int n, k;

// int main(){
// 	scanf("%d %d", &n, &k);
// 	// pair<int, int> arr[101];
// 	int w_arr[101], v_arr[101];
// 	for (int i = 1; i <= n; i++){
// 		scanf("%d %d", &w_arr[i], &v_arr[i]);
// 		// arr[i] = temp;
// 	}
// 	// vector<vector<int> > dp(n + 1, vector<int>(k));
// 	// dp[0].assign(k, 0);
// 	int dp[101][100001];
// 	for (int i = 1; i <= n; i++){
// 		for (int j = 0; j <= k; j++){
// 			int temp;
// 			if ((temp = j - w_arr[i]) >= 0){
// 				dp[i][j] = max(dp[i - 1][temp] + v_arr[i], dp[i - 1][j]);
// 			}else{
// 				dp[i][j] = dp[i - 1][j];
// 			}
// 		}
// 	}
// 	// int max = 0;
// 	// for (int j = 0; j <= k; j++){
// 	// 	if (dp[n][j] > max)
// 	// 		max = dp[n][j];
// 	// }
// 	// printf("%d\n", max);
// 	printf("%d\n", dp[n][k]);
// }