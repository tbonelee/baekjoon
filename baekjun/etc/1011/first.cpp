#include <iostream>
#include <cmath>

using namespace std;

// int pyramid_num(int num){
// 	int temp = (num + 1) / 2;
// 	if (num & 1)
// 		return temp * temp;
// 	else
// 		return temp * temp + (num / 2);
// }

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	for (int i = 0; i < t; i++){
		int x, y; cin >> x >> y;
		int dist = y - x;
		int j = sqrt(dist);
		if (dist <= (j - 1) * (j - 1))
			cout << 2 * (j - 2) << "\n";
		else if (dist <= (j - 1) * (j - 1))
			cout << 2 * (j - 1) << "\n";
		else if (dist <= j * j - j)
			cout << 2 * (j - 1) << "\n";
		else if (dist <= j * j)
			cout << 2 * j - 1 << "\n";
		else if (dist <= (j + 1) * (j + 1) - (j + 1))
			cout << 2 * j << "\n";
		else
			cout << 2 * (j + 1) - 1 << "\n";
	}
}

// int main(){
// 	cout << sqrt(3) << endl;
// }

// int main(){
// 	cin.tie(NULL);
// 	ios::sync_with_stdio(false);
// 	int t; cin >> t;
// 	for (int i = 0; i < t; i++){
// 		int x, y; cin >> x >> y;
// 		int dist = y - x;
// 		for (int i = 1; ; i++){
// 			if (pyramid_num(i - 1) < dist && dist <= pyramid_num(i)){
// 				cout << i << "\n";
// 				break ;
// 			}
// 		}
// 	}
// }