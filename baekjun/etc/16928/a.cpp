#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstring>

using namespace std;

int N, M;

unordered_map<int, int> ladder, snake;
queue<int> Q;

int dist[101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int tmp1, tmp2;
	for (int i = 0; i < N; i++){
		cin >> tmp1 >> tmp2;
		ladder[tmp1] = tmp2;
	}
	for (int i = 0; i < M; i++){
		cin >> tmp1 >> tmp2;
		snake[tmp1] = tmp2;
	}

	memset(dist, -1, sizeof(dist));
	dist[1] = 0;
	Q.push(1);
	while (!Q.empty()){
		int tmp = Q.front();
		Q.pop();
		for (int i = tmp + 1; i <= tmp + 6; i++){
			if (i <= 100){
				int value;
				if (ladder.count(i) != 0){
					if (dist[(value = ladder[i])] == -1){
						dist[value] = dist[tmp] + 1;
						Q.push(value);
					}
				}else if (snake.count(i) != 0){
					if (dist[(value = snake[i])] == -1){
						dist[value] = dist[tmp] + 1;
						Q.push(value);
					}
				}else if (dist[i] == -1){
					dist[i] = dist[tmp] + 1;
					Q.push(i);
				}
			}
		}
	}
	cout << dist[100] << "\n";
}