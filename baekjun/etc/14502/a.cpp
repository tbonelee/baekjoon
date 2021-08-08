#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, M;

int my_map[8][8];

int	ret;

int num_empty;

int to_subtract;

queue<pair<int, int> > Q;

vector<pair<int, int> > emptypos;

int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

int visited[8][8];

void	find2(){
	queue<pair<int, int> > q = Q;
	memset(visited, 0, sizeof(visited));
	while (!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();
		int i, j;
		for (int idx = 0; idx < 4; idx++){
			i = tmp.first + di[idx];
			j = tmp.second + dj[idx];
			if (!(i >= 0 && i < N && j >= 0 && j < M))
				continue ;
			if (my_map[i][j] == 0 && visited[i][j] == 0){
				to_subtract++;
				visited[i][j] = 1;
				q.push({i, j});
			}
		}
	}
	if (num_empty - to_subtract > ret)
	{
		ret = num_empty - to_subtract;
	}
	to_subtract = 0;
}

void	find(){
	for (int i = 0; i < num_empty - 2; i++){
		my_map[emptypos[i].first][emptypos[i].second] = 1;
		for (int j = i + 1; j < num_empty - 1; j++){
			my_map[emptypos[j].first][emptypos[j].second] = 1;
			for (int k = j + 1; k < num_empty; k++){
				my_map[emptypos[k].first][emptypos[k].second] = 1;
				find2();
				my_map[emptypos[k].first][emptypos[k].second] = 0;
			}
			my_map[emptypos[j].first][emptypos[j].second] = 0;
		}
		my_map[emptypos[i].first][emptypos[i].second] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int n = 0; n < N; n++){
		for (int m = 0; m < M; m++){
			cin >> my_map[n][m];
			if (my_map[n][m] == 0){
				emptypos.push_back({n, m});
			}else if (my_map[n][m] == 2){
				Q.push({n, m});
			}
		}
	}
	num_empty = emptypos.size();
	find();
	ret -= 3;
	cout << ret << "\n";
}