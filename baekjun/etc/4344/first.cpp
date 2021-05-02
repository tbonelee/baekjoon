#include <iostream>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int c; cin >> c;
	for (int i = 0; i < c; i++){
		int n; cin >> n;
		cout << fixed;
		cout.precision(3);
		double sum = 0;
		vector<double> temp(n);
		for (int j = 0; j < n; j++){
			cin >> temp[j];
			sum += temp[j];
		}
		double cnt = 0;
		for (int j = 0; j < n; j++){
			if (temp[j] * n > sum)
				cnt++;
		}
		cout << cnt / n * 100 << "%\n";
	}
}