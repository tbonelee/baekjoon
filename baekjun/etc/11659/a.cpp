#include <iostream>

using namespace std;

int N, M;

int arr[100001];
int sum[100001];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int idx = 1; idx <= M; idx++){
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}
}