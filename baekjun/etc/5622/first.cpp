#include <iostream>

using namespace std;
// using std::string;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str; cin >> str;
	int ret = 0;
	for (auto &elem : str){
		if ((elem - 'A') / 3 <= 4)
			ret += (elem - 'A') / 3 + 3;
		else if (elem >= 'P' && elem <= 'S')
			ret += 8;
		else if (elem >= 'T' && elem <= 'V')
			ret += 9;
		else
			ret += 10;
	}
	cout << ret << "\n";
}