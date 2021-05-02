#include <iostream>

using namespace std;

int arr[10001];

void cnt_self_num(int num){
	int ret = num;
	while (num){
		ret += num % 10;
        num /= 10;
	}
	if (ret <= 10000)
		arr[ret] = 1;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 9999; i++){
		cnt_self_num(i);
	}
	for (int i = 1; i <= 10000; i++)
		if (arr[i] == 0)
			cout << i << "\n";
}