#include <iostream>

using std::ios;
using std::cin;
using std::cout;
using std::endl;

int main(){
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b) % c << endl << ((a % c) + (b % c)) % c << endl
		 << (a * b) % c << endl << ((a % c) * (b % c)) % c << endl;
}