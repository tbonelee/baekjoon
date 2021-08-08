#include <iostream>
using namespace std;

int N, B, C;
long long ret;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			if (A[i] % C > 0)
				ret += (A[i] / C) + 2;
			else
				ret += (A[i] / C) + 1;
		} else {
			ret += 1;
		}
	}
	cout << ret << "\n";
}