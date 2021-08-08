#include <iostream>
#include <vector>

using namespace std;

int N, S[20][20];

int ret_min = 1000000000;

int check_board[20];

void solve(){
	int ptr_start = 0, ptr_link = 0;

	vector <int> member_start, member_link;

	for (int i = 0; i < N; i++){
		if (check_board[i] == 1){
			member_start.push_back(i);
		}else{
			member_link.push_back(i);
		}
	}
	for (auto i : member_start){
		for (auto j : member_start){
			if (i != j){
				ptr_start += S[i][j];
			}
		}
	}
	for (auto i : member_link){
		for (auto j : member_link){
			if (i != j){
				ptr_link += S[i][j];
			}
		}
	}
	int diff;
	if (ptr_start > ptr_link)
		diff = ptr_start - ptr_link;
	else
		diff = ptr_link - ptr_start;
	if (diff < ret_min)
		ret_min = diff;
}

void fun(int cnt, int idx){
	if (cnt == N / 2)
		solve();
	for (int i = idx + 1; i < N; i++){
		check_board[i] = 1;
		fun(cnt + 1, i);
		check_board[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> S[i][j];
		}
	}
	fun(0, -1);
	cout << ret_min << "\n";
}