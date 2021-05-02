#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a, b, c; cin >> a >> b >> c;
	int tr = 0, tc = 0;
	if (b >= c)
		cout << "-1\n";
	else{
		cout << a / (c - b) + 1 << "\n";
	}
}