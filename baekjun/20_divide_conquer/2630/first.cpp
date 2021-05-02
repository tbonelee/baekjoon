// 시간복잡도 : O(n * n * log_2 {n}) -> 약 7만? (n == 2^7 case)
// 공간복잡도 : O(n ^ 2)

#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > board;

int result[2];
int n;

void dnq(int i_start, int i_end, int j_start, int j_end);

int main(){
	scanf("%d", &n);
	int temp = n;
	board.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &board[i][j]);
		}
	}
	dnq(0, n - 1, 0, n - 1);
	printf("%d\n%d\n", result[0], result[1]);
}

void dnq(int i_start, int i_end, int j_start, int j_end){
	int i_middle = (i_start + i_end) / 2;
	int j_middle = (j_start + j_end) / 2;
	if (i_start == i_end && j_start == j_end){
		result[board[i_start][j_start]]++;
		return ;
	}
	int first_color = board[i_start][j_start];
	int i, j;
	for (i = i_start; i <= i_end; i++){
		for (j = j_start; j <= j_end; j++){
			if (board[i][j] != first_color){
				dnq(i_start, i_middle, j_start, j_middle);
				dnq(i_start, i_middle, j_middle + 1, j_end);
				dnq(i_middle + 1, i_end, j_start, j_middle);
				dnq(i_middle + 1, i_end, j_middle + 1, j_end);
				break ;
			}
		}
		if (j != j_end + 1)
			break ;
	}
	if (i == i_end + 1 && j == j_end + 1)
		result[first_color]++;

}