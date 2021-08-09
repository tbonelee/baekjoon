#include <iostream>
#include <cstring>

using namespace std;

int N;

int matrix[101][101];

int ret[101][101];

int visited[101];

void dfs(int start, int nod){
	if (visited[nod] == 1)
		return ;
	visited[nod] = 1;
	for (int i = 1; i <= N; i++){
		if (matrix[nod][i] == 1){
			if (nod != i){
				ret[start][i] = 1;
				dfs(start, i);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> matrix[i][j];
		}
	}

	for (int i = 1; i <= N; i++){
		memset(visited, 0, sizeof(int) * 101);
		dfs(i, i);
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}

}