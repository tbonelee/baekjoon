#include <iostream>

using namespace std;

int N, M, x, y, K;

int map[20][20];

int dice[7];

int dy[4] = {+1, -1, 0, 0};
int dx[4] = {0, 0, -1, +1};

void go_east()
{
	if (y + 1 >= M)
		return ;
	y += 1;
	int tmp;
	tmp = dice[4];
	dice[4] = dice[6];
	dice[6] = dice[3];
	dice[3] = dice[1];
	dice[1] = tmp;
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[1] << "\n";
}

void go_west()
{
	if (y - 1 <= -1)
		return ;
	y -= 1;
	int tmp;
	tmp = dice[4];
	dice[4] = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = tmp;
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[1] << "\n";
}

void go_south()
{
	if (x + 1 >= N)
		return ;
	x += 1;
	int tmp;
	tmp = dice[5];
	dice[5] = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = tmp;
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[1] << "\n";
}

void go_north()
{
	if (x - 1 <= -1)
		return ;
	x -= 1;
	int tmp;
	tmp = dice[5];
	dice[5] = dice[6];
	dice[6] = dice[2];
	dice[2] = dice[1];
	dice[1] = tmp;
	if (map[x][y] == 0) {
		map[x][y] = dice[6];
	}
	else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	cout << dice[1] << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int ins;
		cin >> ins;
		int nx = x + dx[ins - 1];
		int ny = y + dy[ins - 1];
		if (nx >= N || nx < 0 || ny >= M || ny < 0)
			continue ;
		if (ins == 1) {
			int tmp = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = dice[1];
			dice[1] = tmp;
		}
		else if (ins == 2) {
			int tmp = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = tmp;
		}
		else if (ins == 3) {
			int tmp = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = dice[1];
			dice[1] = tmp;
		}
		else if (ins == 4) {
			int tmp = dice[5];
			dice[5] = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = tmp;
		}
		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[6];
		} else {
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1] << "\n";
		x = nx, y = ny;
	}
}