#include <iostream>

using namespace std;

int memo[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= n; i++)
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
	cout << memo[n] << "\n";
}