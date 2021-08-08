#include <iostream>

using namespace std;

int N, M, x, y, K;

int map[20][20];

int dice[7];

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
		if (ins == 1)
			go_east();
		else if (ins == 2)
			go_west();
		else if (ins == 3)
			go_north();
		else if (ins == 4)
			go_south();
	}
}