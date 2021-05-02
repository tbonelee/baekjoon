// 11066과 비슷한 방식으로 해결

#include <utility>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

ll dp(vector<pair<int, int> > &matrix, int n){
	vector<vector<ll> > memo(n, vector<ll>(n, 0));
	for (int i = 2; i <= n; i++){
		for (int j = 0; j + i <= n; j++){
			ll min_num = LLONG_MAX;
			for (int k = 0; k < i - 1; k++){
				min_num = min(min_num, memo[j][j + k] + memo[j + k + 1][j + i  - 1] + matrix[j].first * matrix[j + k].second * matrix[j + i - 1].second);
			}
			memo[j][j + i - 1] = min_num;
		}
	}
	return memo[0][n - 1];
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<pair<int, int> > matrix;
	for (int i = 0; i < n; i++){
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		matrix.push_back(temp);
	}
	cout << dp(matrix, n) << "\n";

}