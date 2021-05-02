#include <iostream>
#include <vector>

using namespace std;

void dp(vector<vector<int> > &memo, vector<int> &board, int start, int end){
	if (start == end){
		memo[start][end] = true;
	}
	else if (start == end - 1){
		memo[start][end] = (board[start] == board[end]);
	}
	else{
		if (memo[start + 1][end - 1] == -1)
			dp(memo, board, start + 1, end - 1);
		memo[start][end] = memo[start + 1][end - 1] && (board[start] == board[end]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	cin >> m;
	vector<vector<int> > memo(n, vector<int>(n, -1));
	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < n; j++){
	// 		cout << memo[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for (int i = 0; i < m; i++){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		dp(memo, board, temp1 - 1, temp2 - 1);
		cout << memo[temp1 - 1][temp2 - 1] << "\n";
	}
}