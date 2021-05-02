#include <iostream>

using namespace std;

bool is_hansu(int n){
	if (n < 100)
		return true;
	int first;

	first = n % 10 - (n / 10) % 10;
	while ((n /= 10) >= 10){
		if (first != n % 10 - (n / 10) % 10)
			return false;
	}
	return true;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int c; cin >> c;
	int cnt = 0;
	for (int i = 1; i <= c; i++)
		if (is_hansu(i))
			cnt++;
	cout << cnt << "\n";
}

// int main(){
// 	while (1){
// 		int n; cin >> n;
// 		cout << is_hansu(n) << "\n";
// 	}
// }