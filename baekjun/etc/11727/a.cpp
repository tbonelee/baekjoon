#include <iostream>

using namespace std;

int memo[1001];
int n;

void dp(int n);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp(n);

	cout << memo[n] << "\n";
}

void dp(int n){
	memo[0] = 1;
	memo[1] = 1;
	for (int i = 2; i <= n; i++){
		memo[i] = (memo[i - 1] + memo[i - 2] * 2) % 10007;
	}
}