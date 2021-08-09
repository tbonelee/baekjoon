#include <iostream>

using namespace std;

int T, M, N, x, y;

int ret;

int	gcd(int a, int b){
	while (b > 0){
		int r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

int	lcm(int a, int b){
	return (a * b / gcd(a, b));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++){
		cin >> M >> N >> x >> y;
		ret = -1;
		int tmp = x;

		int cnt = x;

		for (int j = 0; j < N; j++){
			int yy;
			if (tmp % N == 0)
				yy = N;
			else
				yy = tmp % N;
			if (yy == y)
				break;
			cnt += M;
			tmp = yy + M;
		}
		if (cnt < lcm(M, N))
			cout << cnt << "\n";
		else
			cout << -1 << "\n";
	}
}