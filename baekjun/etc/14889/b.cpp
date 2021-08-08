#include <iostream>
#include <vector>

using namespace std;

int N, S[20][20];

int ret_min = 1000000000;

vector<int> board;

void solve(){
	int ptr_start = 0, ptr_link = 0;

	for (int i = 0; i < N / 2 - 1; i++){
		for (int j = i + 1; j < N / 2; j++){
			ptr_start += S[board[i]][board[j]] + S[board[j]][board[i]];
		}
	}

	int rem[20];
	for (int i = 0; i < 20; i++){
		rem[i] = 0;
	}
	for (auto a : board){
		rem[a] = 1;
	}
	vector<int> rem_board;
	for (int i = 0; i < 20; i++){
		if (rem[i] == 0)
			rem_board.push_back(i);
	}
	for (int i = 0; i < N / 2 - 1; i++){
		for (int j = i + 1; j < N / 2; j++){
			ptr_link += S[rem_board[i]][rem_board[j]] + S[rem_board[j]][rem_board[i]];
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

void fun(int idx){
	if (idx == N)
		return ;
	if (board.size() == N / 2)
		solve();
	board.push_back(idx);
	fun(idx + 1);
	board.pop_back();
	fun(idx + 1);
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
	fun(0);
	cout << ret_min << "\n";
}