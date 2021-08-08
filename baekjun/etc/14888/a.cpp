#include <iostream>

using namespace std;

int N;

int A[11];
int oper[4];

int min_ret = 1000000000;
int max_ret = -1000000000;

void fun(int idx, int ret, int add, int sub, int mult, int div){
	if (idx == N){
		if (ret < min_ret)
			min_ret = ret;
		if (ret > max_ret)
			max_ret = ret;
		return ;
	}
	if (add > 0)
		fun(idx + 1, ret + A[idx], add - 1, sub, mult, div);
	if (sub > 0)
		fun(idx + 1, ret - A[idx], add, sub - 1, mult, div);
	if (mult > 0)
		fun(idx + 1, ret * A[idx], add, sub, mult - 1, div);
	if (div > 0 && A[idx] != 0){
		fun(idx + 1, ret / A[idx], add, sub, mult, div - 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++){
		cin >> oper[i];
	}
	fun(1, A[0], oper[0], oper[1], oper[2], oper[3]);
	cout << max_ret << "\n" << min_ret << "\n";
}