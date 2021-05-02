#include <iostream>

using namespace std;

bool is_prime(int n){
	if (n == 1)
		return false;
	else{
		int i = 2;
		while (n % i != 0 && i * i < n)
			i++;
		if (i * i > n)
			return true;
		else
			return false;
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	while (1){
		int n; cin >> n;
		if (!n)
			return 0;
		int ret = 0;
		for (int i = n + 1; i <= 2 * n; i++){
			if (is_prime(i)){
				ret++;
			}
		}
		cout << ret << "\n";
	}
}