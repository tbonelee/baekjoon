#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector<int> A;
long long ret;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		if (A[i] <= B) {
			ret += 1;
		} else {
			if ((A[i] - B) % C > 0)
				ret += ((A[i] - B) / C) + 2;
			else
				ret += ((A[i] - B) / C) + 1;
		}
	}
	cout << ret << "\n";
}