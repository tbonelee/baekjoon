#include <iostream>
#include <algorithm>

using namespace std;

void my_print(string a, string b){
	int aleft = a.size(), bleft = b.size();
	int temp;
	int toadd = 0;
	string ret(max(a.size(), b.size()), 0);
	int idx = max(a.size(), b.size()) - 1;
	while (aleft && bleft){
		temp = (a[aleft-- - 1] - '0') + (b[bleft-- - 1] - '0') + toadd;
		if (temp >= 10)
			toadd = 1;
		else
			toadd = 0;
		ret[idx--] = temp % 10 + '0';
	}
	while (aleft){
		temp = (a[aleft-- - 1] - '0') + toadd;
		if (temp >= 10)
			toadd = 1;
		else
			toadd = 0;
		ret[idx--] = temp % 10 + '0';
	}
	while (bleft){
		temp = (b[bleft-- - 1] - '0') + toadd;
		if (temp >= 10)
			toadd = 1;
		else
			toadd = 0;
		ret[idx--] = temp % 10 + '0';
	}
	if (toadd)
		cout << toadd;
	cout  << ret << "\n";
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a, b; cin >> a >> b;
	my_print(a, b);
}