// memo[i][j]는 인덱스 i부터 인덱스 j까지의 원소만 있을 때 최소 비용
// memo[i][j] = sum of lists(from idx = i to idx = j) + min {memo[i][i + k] + memo[i + k + 1][end]}(from k = 1 to k = end - i - 1)

// 연속되는(!) 문서를 합치는 문제. 문제 잘 읽기

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

void dp(int start, int end, vector<vector<int> > &memo, vector<int> &lists, int &k){

	if (start == end){
		memo[start][end] = 0;
		return ;
	}
	int mintemp = INT_MAX;
	for (int i = 0; start + i + 1 <= end; i++){
		if (memo[start][start + i] == -1)
			dp(start, start + i, memo, lists, k);
		if (memo[start + i + 1][end] == -1)
			dp(start + i + 1, end, memo, lists, k);

		mintemp = min(mintemp, memo[start][start + i] + memo[start + i + 1][end]);
	}
	if (mintemp == INT_MAX)
		mintemp = 0;
	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += lists[i];
	memo[start][end] = mintemp + sum;


}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 0; i < t; i++){
		int k; cin >> k;
		vector<vector<int> > memo(k, vector<int>(k, -1));
		int cnt = 0;
		vector<int> lists;
		for (int j = 0; j < k; j++){
			int temp; cin >> temp;
			lists.push_back(temp);
		}
		dp(0, k - 1, memo, lists, k);

		// for (int i = 0; i < k; i++){
		// 	for (int j = 0; j < k; j++){
		// 		cout << memo[i][j] << "  ";

		// 	}
		// 	cout << "\n";
		// }

		cout << memo[0][k - 1] << "\n";

	}
}