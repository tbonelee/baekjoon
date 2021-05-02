#include <iostream>

using namespace std;

bool is_prime(int n){
	if (n == 1)
		return false;
	int i = 2;
	while (n % i != 0 && i * i <= n)
		i++;
	if (i * i > n)
		return true;
	else
		return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	for (int i = 0; i < t; i++){
		int n; cin >> n;
		for (int j = n / 2; j >= 2; j--){
			if (is_prime(j) && is_prime(n - j)){
				cout << j << " " << n - j << "\n";
				break ;
			}
		}
	}
}