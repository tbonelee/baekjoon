#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void dp(vector<vector<int> > &map, vector<vector<ll> > &memo, int ipos, int jpos){
	// cout << "call " << ipos << ", " << jpos << "\n";
	if (ipos == 0 && jpos == 0){
		memo[ipos][jpos] = 1;
		// cout << "ipos = " << ipos << ", " << "jpos = " << jpos << ", memo = " << memo[ipos][jpos] << "\n";
		return ;
	}
	ll sum = 0;
	if (ipos - 1 >= 0 && map[ipos][jpos] < map[ipos - 1][jpos]){
		if (memo[ipos - 1][jpos] == -1)
			dp(map, memo, ipos - 1, jpos);
		// cout << "(1)ipos = " << ipos << ", " << "jpos = " << jpos << ", memo[ipos - 1][jpos] = " << memo[ipos - 1][jpos] << "\n";

		sum += memo[ipos - 1][jpos];
	}
	if (jpos - 1 >= 0 && map[ipos][jpos] < map[ipos][jpos - 1]){
		if (memo[ipos][jpos - 1] == -1)
			dp(map, memo, ipos, jpos - 1);
		// cout << "(2)ipos = " << ipos << ", " << "jpos = " << jpos << ", memo[ipos][jpos - 1] = " << memo[ipos][jpos - 1] << "\n";

		sum += memo[ipos][jpos - 1];
	}
	if (ipos + 1 < map.size() && map[ipos][jpos] < map[ipos + 1][jpos]){
		if (memo[ipos + 1][jpos] == -1)
			dp(map, memo, ipos + 1, jpos);
		// cout << "(1)ipos = " << ipos << ", " << "jpos = " << jpos << ", memo[ipos + 1][jpos] = " << memo[ipos + 1][jpos] << "\n";

		sum += memo[ipos + 1][jpos];
	}
	if (jpos + 1 < map[0].size() && map[ipos][jpos] < map[ipos][jpos + 1]){
		if (memo[ipos][jpos + 1] == -1)
			dp(map, memo, ipos, jpos + 1);
		// cout << "(2)ipos = " << ipos << ", " << "jpos = " << jpos << ", memo[ipos][jpos + 1] = " << memo[ipos][jpos + 1] << "\n";

		sum += memo[ipos][jpos + 1];
	}
	memo[ipos][jpos] = sum;
	// cout << "ipos = " << ipos << ", " << "jpos = " << jpos << ", memo = " << memo[ipos][jpos] << "\n";
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int m, n; cin >> m >> n;
	vector<vector<int> > map(m, vector<int>(n));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> map[i][j];
			// cout << map[i][j];
		}
		// cout << "\n";
	}
	vector<vector<ll> > memo(m, vector<ll>(n, -1));
	dp(map, memo, m - 1, n - 1);
	cout << memo[m - 1][n - 1] << "\n";
	// cout << 0ll << "\n";/
}