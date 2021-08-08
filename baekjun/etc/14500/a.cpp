#include <iostream>

using namespace std;

int N, M;
int map[500][500];
int ret;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int pos_i = 0, pos_j = 0;
	int tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 3 < N) {
				tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (j + 3 < M) {
				tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (i + 1 < N && j + 1 < M) {
				tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (i + 2 < N && j + 1 < M) {
				tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (i + 2 < N && j - 1 >= 0) {
				tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (i + 1 < N && j + 2 < M) {
				tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (i + 1 < N && j - 2 >= 0) {
				tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j - 2];
				if (tmp > ret) {
					ret = tmp;
				}
				tmp = map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j - 2];
				if (tmp > ret) {
					ret = tmp;
				}
			}
			if (i + 1 < N && j - 1 >= 0 && j + 1 < M) {
				tmp = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 1][j + 1];
				if (tmp > ret) {
					ret = tmp;
				}
			}

		}
	}
	cout << ret << "\n";
}