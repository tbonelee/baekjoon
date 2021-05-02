#include <iostream>
#include <vector>

using namespace std;

int k, v, e;

void add_graph(vector<vector<int> > &adj_lists, int a, int b){
	adj_lists[a].push_back(b);
	adj_lists[b].push_back(a);
}

int dfs(vector<vector<int> > &adj_lists, vector<int> &color, int i, int colornum){
	color[i] = colornum;
	// visited[i] = true;
	for (int itemp = 0; itemp < adj_lists[i].size(); itemp++){
		if (color[adj_lists[i][itemp]] == 0){
			if (dfs(adj_lists, color, adj_lists[i][itemp], (colornum * (-1))) == -1)
				return -1;
		}else if (color[adj_lists[i][itemp]] == colornum)
			return -1;
	}
	return 0;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> v >> e;
		vector<vector<int> > adj_lists(v + 1);
		vector<int> color(v + 1, 0);
		for (int j = 0; j < e; j++){
			int a, b;
			cin >> a >> b;
			add_graph(adj_lists, a, b);
		}
		// for (int i = 1; i <= v; i++){
		// 	cout << "(" << i << ")";
		// 	for (auto &elem : adj_lists[i]){
		// 		cout << elem << " ";
		// 	}
		// 	cout << "\n";
		// }

		int cnt_dfs = 0;
		for (int i = 1; i <= v; i++){
			if (color[i] == 0){
				if (dfs(adj_lists, color, i, 1) == -1){
					cnt_dfs++;
					break;
				}
			}
		}
		if (cnt_dfs >= 1)
			cout << "NO\n";
		else
			cout << "YES\n";

	}
}