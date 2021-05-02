// dp[j] < cost가 j일 때 확보할 수 있는 최대 메모리
// dp[j + memory[i]] = max{dp[j + costs[i]], dp[j] + memory[i]}

#include <utility>
#include <vector>
#include <iostream>

using namespace std;

int n, m;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<int> memory;
	vector<int> costs;
	int cost_sum_max = 0;

	for (int i = 0; i < n; i++){
		int temp; cin >> temp;
		memory.push_back(temp);
	}
	for (int i = 0; i < n; i++){
		int temp; cin >> temp;
		costs.push_back(temp);
		cost_sum_max += temp;
	}



	vector<int> dp(cost_sum_max + 1, -1);
	vector<int> dp_backup(cost_sum_max + 1, -1);
	dp[0] = 0;
	dp_backup = dp;
	int result = 1000000;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= cost_sum_max; j++){
			if (dp_backup[j] >= 0){
				if (j + costs[i] <= cost_sum_max){
					if (dp_backup[j + costs[i]] < dp_backup[j] + memory[i]){
						dp[j + costs[i]] = dp_backup[j] + memory[i];
						if (dp[j + costs[i]] >= m && j + costs[i] < result)
							result = j + costs[i];
					}
				}
			}
		}
		dp_backup = dp;
		// for (int j = 0; j <= cost_sum_max; j++){
		// 	cout << dp[j] << " ";
		// }
		// cout << "\n";
	}



	cout << result << "\n";
}