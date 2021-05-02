#include <cstdio>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int a, b; cin >> a >> b;
	int temp = b;
	// int blist[3];
	// int ret[3];
	// int ten = 1;
	for (int i = 0; i < 3; i++){
		cout << (b % 10 * a) << endl;
		// ret[i] = blist[i] * ten;
		// ten *= 10;
		b /= 10;
	}
	cout << a * temp << endl;
}