#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int sum = 0;
	int i;
	for (i = 1; ; i++){
		sum += i;
		if (sum >= n)
			break ;
	}
	i++;
	if (i % 2 == 1){
		int denom = sum - n + 1;
		cout << i - denom << "/" << denom << "\n";
	}else{
		int numer = sum - n + 1;
		cout << numer << "/" << i - numer << "\n";
	}
}