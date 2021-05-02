#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int x1, y1, r1, x2, y2 ,r2;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double leng = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (r1 < r2)
			swap(r1, r2);

		if (leng == 0) {
			if (r1 == r2)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}

		else if (leng > abs(r1 - r2) && leng < r1 + r2)
			cout << 2 << endl;

		else if (leng == r1 + r2 || leng == abs(r1 - r2))
			cout << 1 << endl;

		else
			cout << 0 << endl;
	}
	return 0;
}