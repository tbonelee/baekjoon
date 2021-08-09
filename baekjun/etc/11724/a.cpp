#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

unsigned short N;
unsigned int M;
unsigned short u, v;

vector<short> adj_lst[1001];

char	visited[1001];

queue <int> Q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> u >> v;
		adj_lst[u].push_back(v);
		adj_lst[v].push_back(u);
	}

	int ret = 0;
	for (int t = 1; t <= N; t++){
		if (visited[t] == 0){
			ret++;
			Q.push(t);
			visited[t] = 1;
			while (!Q.empty()){
				int tmp = Q.front();
				Q.pop();
				for (auto &i : adj_lst[tmp]){
					if (visited[i] == 0){
						Q.push(i);
						visited[i] = 1;
					}
				}
			}
		}
	}
	cout << ret << "\n";

}