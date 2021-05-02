#include <iostream>

using std::cin;
using std::cout;
using std::ios;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int a, b;
	for (int i = 0; i < t; i++){
		cin >> a >> b;
		cout << a + b << "\n";
	}

}