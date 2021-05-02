#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double r; cin >> r;
	cout.precision(6);
	cout << fixed;
	cout << r * r * 3.14159265359 << "\n";
	cout << (r * r) * 2 << "\n";
}