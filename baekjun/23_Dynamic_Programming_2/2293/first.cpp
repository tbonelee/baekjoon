#include <vector>
#include <iostream>

using namespace std;

int n, k;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	vector<int> coins;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		int temp; cin >> temp;
		if (temp > 10000)
			continue;
		cnt++;
		coins.push_back(temp);
	}
	vector<int> memo(k + 1);
	vector<int> memobefore(k + 1, 0);
	memobefore[0] = 1;
	memo = memobefore;
	// for (int i = 0; i <= k; i++)
	// 	cout << memo[i] << " ";
	// 	cout << "\n";
	for (int i = 0; i < cnt; i++){
		for (int j = 0; j <= k; j++){
			int mult = coins[i];
			while (j + mult <= k){
				if (memobefore[j] > 0 && j + mult <= k){
					memo[j + mult] += memobefore[j];
				}
				mult += coins[i];
			}
		}
		memobefore = memo;
	}
	// for (int i = 0; i <= k; i++)
	// 	cout << memo[i] << " ";
	// 	cout << "\n";
	cout << memo[k] << "\n";


}