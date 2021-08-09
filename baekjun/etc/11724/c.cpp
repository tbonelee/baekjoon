#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

unsigned short N;
unsigned int M;
unsigned short u, v;

vector<short> adj_lst[1001];
// vector < vector<int> > adj_lst;

char	visited[1001];

stack <int> S;

void dfs(int nod){	
	if (visited[nod] == 1)
		return ;
	visited[nod] = 1;
	S.push(nod);
	while (!S.empty()){
		int tmp = S.top();
		S.pop();
		for (auto &i : adj_lst[tmp]){
			if (visited[i] == 0){
				S.push(tmp);
				S.push(i);
				visited[i] = 1;
				break ;
			}
		}
	}

}

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
			dfs(t);
		}
	}

	cout << ret << "\n";

}